/*
*************************************************************************************
*file:  updating.h
*@Description:实现地理坐标系(g坐标系)下的姿态、速度、位置更新
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：20/11/2020
*************************************************************************************
*/
#pragma once
#include<iostream>
#include<math.h>
#include<Eigen/Dense>
#include"attitude_matrix.h"
#include"earth_parameter.h"
#include"read_imr_file.h"
using namespace std;
using namespace Eigen;

// 建立结构体便于保存姿态更新结果
struct attitude_updating_data
{
    
    Euler_angle omega_nie;  // 地球（地球坐标系）绕自转轴旋转（地心惯性坐标系下）的角速度在导航坐标系下的投影
    Euler_angle omega_nen;  // 惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    Euler_angle omega_nin;  // 求得n系相当于i系的旋转
    Euler_angle Phi_bib;    // 载体坐标系相对于地心惯性坐标系的变化bib （以等效旋转矢量形式表示）
    Euler_angle Phi_nin;    //导航坐标系相对于地心惯性坐标系的变化
    Direct_cosine_matrix Cnb_m; // 在t(m)时刻的捷联姿态矩阵
};

struct speed_updating_data
{
    Vector3f v_nem; // 载体在导航系下的几何运动速度
};

struct position_updating_data
{
    Vector3f position;
};

struct input_data
{
    Direct_cosine_matrix Dnb;   // 上一时刻的用b系到n系的方向余弦阵
    //vector<Vector3f> delta_theta1;      // 第一次采样
    vector<Vector3f> delta_theta;      // 三次采样，理论上只会用到最后两次
    vector<Vector3f> position;          // 未变化前位置
    vector<Vector3f> Velocity;          // 载体运动的速度[E N U]
    float T;                    // 载体采样周期
};


// ===========================姿态、速度、位置更新===========================
class update
{
public:
    //  存放m-1时刻的方向余弦阵，存放m，m-1时刻的采样数据分别于vector[2],vecotr[1]，存放m-1时刻，m-2时刻的位置数据于vector[1],vector[0]，存放m-1,m-2时刻的速度数据于vector[1],vector[0], 存放采样周期
    update(Direct_cosine_matrix a1, vector<Vector3f> a2, vector<Vector3f> a3, vector<Vector3f> a4, vector<Vector3f> a5, double a7);
    input_data inputdata;   // 输入数据
    attitude_updating_data attitude_data;           // 姿态更新结果
    vector<speed_updating_data> speed_data;         // 速度更新结果，通常存放三次速度更新结果，[0] m-2 时刻的速度更新，[1]，m -1 时刻的速度更新，[2]，m 时刻的速度更新
    vector<position_updating_data> position_data;   // 位置更新结果，通常存放两次位置更新结果，[0] m-1 时刻的位置，[1]，m 时刻的位置
    void attitude_update(); // 姿态更新
    void speed_update();    // 速度更新
    void position_update(); // 位置更新
    // 定义通用变量
private:
    float sinl, cosl, tanl;
    float Rm;
    float Rn;
    float Rmh;
    float Rnh;
};


// 通常输入为1*3的vector向量，其中vector[0]表示m-2时刻的数据,vector[1]表示m-1时刻的数据,vector[2]表示当前m时刻的数据
update::update(Direct_cosine_matrix a1,vector<Vector3f> a2, vector<Vector3f> a3, vector<Vector3f> a4, vector<Vector3f> a5, double a7)
{
    // 初始化数据大小
    inputdata.delta_theta.resize(3);    
    inputdata.position.resize(3);
    inputdata.Velocity.resize(3);
    speed_data.resize(2);   // 第三个数据在其后pushback
    position_data.resize(1);// 第2个数据在其后pushback
    // 将输入数据转存至对象中
    // 存放m - 1时刻的方向余弦阵
    inputdata.Dnb = a1;
    // 存放m，m - 1时刻的采样数据分别于vector[2], vecotr[1]
    inputdata.delta_theta[2] = a3[1];
    inputdata.delta_theta[1] = a3[0];
    // 初始化存放m-2,m-1时刻的速度与vector[1], vecotr[0]
    speed_data[1].v_nem = a2[1];
    speed_data[0].v_nem = a2[0];
    // 存放m - 1时刻，m - 2时刻的位置数据于vector[1], vector[0]
    inputdata.position[1] = a4[1];
    inputdata.position[0] = a4[0];
    // 存放m , m - 1时刻的速度数据于vector[1], vector[0]
    inputdata.Velocity[2] = a5[1];
    inputdata.Velocity[1] = a5[0];
    // 存放初始位置
    position_data[0].position = a4[1];
    // 存放采样周期
    inputdata.T = a7;
}


void update::attitude_update()
{
    /*
    *************************************************************************************
    *func: 计算姿态更新
    *@Param:    Dnb             载体系b相对于导航坐标系n的方向余弦阵
    *@Param:    delta_theta1    第一次角增量采样
    *@Param:    delta_theta2    第二次角增量采样
    *@Param:    inputdata.position       [L,B,H]初始位置的纬度、经度、大地高
    *@Param:    Velocity        载体运动的线速度 [Vx, Vy, 0] 或者 [Ve, Vn, 0]
    *@Param:    T               姿态更新周期
    *@Param:
    *@Return:
    *@Note:
    *creator：Jin Huang
    *organization:sdust
    *e-mail:kim.huang.j@qq.com
    *************************************************************************************
    */
    // m 时刻
    sinl = sin(inputdata.position[2](0)); cosl = cos(inputdata.position[2](0)); tanl = tan(inputdata.position[2](0));    // 计算m时刻的地理纬度为sin cos tan
    Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    Rmh = Rm + inputdata.position[2](2); // 实际m时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Rnh = Rn + inputdata.position[2](2); // 实际m时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    double g_m = earth.g0 * (1 + 5.27094e-3 * sinl * sinl + 2.32718e-5 * sinl * sinl * sinl * sinl) - 3.086e-6 * inputdata.position[2](2);    // 计算m时刻的当地重力加速度
    Euler_angle omega_nie_m(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   // 计算m时刻的w_nie，地球自转引起的导航系旋转
    Euler_angle omega_nen_m(-inputdata.Velocity[2](1) / Rmh, inputdata.Velocity[2](0) / Rnh, inputdata.Velocity[2](0) / Rnh * tanl);    //计算m时刻惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转

    // 地球（地球坐标系）绕自转轴旋转（地心惯性坐标系下）的角速度在导航坐标系下的投影
    Euler_angle omega_nie(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   
    attitude_data.omega_nie = omega_nie;
    // 计算惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    Euler_angle omega_nen(-inputdata.Velocity[2](1) / Rmh, inputdata.Velocity[2](0) / Rnh, inputdata.Velocity[2](0) / Rnh * tanl);
    attitude_data.omega_nen = omega_nen;
    // 求得n系相当于i系的旋转
    Euler_angle omega_nin(omega_nie + omega_nen);
    attitude_data.omega_nin = omega_nin;

	// 利用等效旋转矢量二子样算法计算在更新周期内 载体坐标系相对于地心惯性坐标系的变化bib （以等效旋转矢量形式表示）
	Euler_angle Phi_bib(inputdata.delta_theta[1] + inputdata.delta_theta[2] + 2.0 / 3 * inputdata.delta_theta[1].cross(inputdata.delta_theta[2]));
    attitude_data.Phi_bib = Phi_bib;

    // 计算导航坐标系相对于地心惯性坐标系的变化，由于速度和位置引起的omega_nin的变化很小，
    // 因此可以用常值代替，其变化可以用一个时刻的变化率乘以采样周期
    Euler_angle Phi_nin(omega_nie.value * inputdata.T);
    attitude_data.Phi_nin = Phi_nin;

    // ========课本算法
    Direct_cosine_matrix Cnm_nm_1(Phi_nin.EA2DCM().transpose());
    Direct_cosine_matrix Cbm_1_bm(Phi_bib.EA2DCM());
    Direct_cosine_matrix Cnm_bm(Cnm_nm_1.value);
    Direct_cosine_matrix Cnb_m_1(inputdata.Dnb.value);     // 载体系b相对于导航坐标系n的姿态阵,也就是在t(m-1)时刻有b系转换为n系的姿态捷联矩阵
    Direct_cosine_matrix Cnb_m(Cnm_nm_1.value * Cnb_m_1.value * Cbm_1_bm.value);    // 在t(m)时刻的捷联姿态矩阵
    attitude_data.Cnb_m = Cnb_m;
}


void update::speed_update()
{
    /*
    *************************************************************************************
    *func:  speed_update
    *@Param:
    *@Param:
    *@Return:
    *@Note: 进行速度更新计算
    *creator：Jin Huang
    *organization:sdust
    *e-mail:kim.huang.j@qq.com
    *************************************************************************************
    */
    // 计算三个时刻的重力加速度
    // m 时刻
    //sinl = sin(inputdata.position[2](0)); cosl = cos(inputdata.position[2](0)); tanl = tan(inputdata.position[2](0));    // 计算m时刻的地理纬度为sin cos tan
    //Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    //Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    //Rmh = Rm + inputdata.position[2](2); // 实际m时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    //Rnh = Rn + inputdata.position[2](2); // 实际m时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    //double g_m = earth.g0 * (1 + 5.27094e-3 * sinl * sinl + 2.32718e-5 * sinl * sinl * sinl * sinl) - 3.086e-6 * inputdata.position[2](2);    // 计算m时刻的当地重力加速度
    //Euler_angle omega_nie_m(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   // 计算m时刻的w_nie，地球自转引起的导航系旋转
    //Euler_angle omega_nen_m(-inputdata.Velocity[2](1) / Rmh, inputdata.Velocity[2](0) / Rnh, inputdata.Velocity[2](0) / Rnh * tanl);    //计算m时刻惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    
    // m-1 时刻
    sinl = sin(inputdata.position[1](0)); cosl = cos(inputdata.position[1](0)); tanl = tan(inputdata.position[1](0));    // 计算地理纬度为 m-1 时刻的 sin cos tan
    Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    Rmh = Rm + inputdata.position[1](2); // 实际m-1时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Rnh = Rn + inputdata.position[1](2); // 实际m-1时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    double g_m_1 = earth.g0 * (1 + 5.27094e-3 * sinl * sinl + 2.32718e-5 * sinl * sinl * sinl * sinl) - 3.086e-6 * inputdata.position[1](2);    // 计算m-1时刻的当地重力加速度
    Euler_angle omega_nie_m_1(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   // 计算m-1时刻的w_nie，地球自转引起的导航系旋转
    Euler_angle omega_nen_m_1(-inputdata.Velocity[1](1) / Rmh, inputdata.Velocity[1](0) / Rnh, inputdata.Velocity[1](0) / Rnh * tanl);    //计算m-1时刻惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转

                                                                             
    // m-2 时刻
    sinl = sin(inputdata.position[0](0)); cosl = cos(inputdata.position[0](0)); tanl = tan(inputdata.position[0](0));    // 计算地理纬度为 m-2 时刻的 sin cos tan
    Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    Rmh = Rm + inputdata.position[0](2); // 实际m-2时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Rnh = Rn + inputdata.position[0](2); // 实际m-2时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    double g_m_2 = earth.g0 * (1 + 5.27094e-3 * sinl * sinl + 2.32718e-5 * sinl * sinl * sinl * sinl) - 3.086e-6 * inputdata.position[0](2);    // 计算m-2时刻的当地重力加速度
    Euler_angle omega_nie_m_2(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   // 计算m-2时刻的w_nie，地球自转引起的导航系旋转
    Euler_angle omega_nen_m_2(-inputdata.Velocity[1](1) / Rmh, inputdata.Velocity[1](0) / Rnh, inputdata.Velocity[1](0) / Rnh * tanl);    //计算m-2时刻惯导系统在地球表面附近移动因地球表面弯曲而引起的
    

    // 外推法计算 四个参数
    Euler_angle omega_nie_m_05((3 * omega_nie_m_1.value - omega_nie_m_2.value) / 2);
    Euler_angle omega_nen_m_05((3 * omega_nen_m_1.value - omega_nen_m_2.value) / 2);
    Vector3f v_n_m_05 = ((3 * speed_data[1].v_nem - speed_data[0].v_nem) / 2);
    Vector3f g_m_05 = Eigen::Vector3f::Zero();
    g_m_05(2) = -(3 * g_m_1 - g_m_2) / 2;
    
    // 计算有害加速度的速度增量
    Vector3f delta_v_ncorg = (-(2 * omega_nie_m_05.value + omega_nen_m_05.value).cross(v_n_m_05) + g_m_05) * inputdata.T;

    // 比力速度增量计算

    // 计算速度的旋转误差补偿量delta_v_brot
    Vector3f delta_v_brot = 0.5 * attitude_data.omega_nin.value.cross(inputdata.Velocity[2] + inputdata.Velocity[1]);   // delta v 由两次采样的变化之和表示
    // 计算划桨误差补偿量delta_v_bscul
    Vector3f delta_v_bscul = 2.0 / 3 * (inputdata.delta_theta[1].cross(inputdata.Velocity[2]) + inputdata.Velocity[1].cross(inputdata.delta_theta[2]));
    //Vector3f delta_v_bscul = 
    // 计算比力引起的速度变化delta_v_nsf
    Matrix3f I = Eigen::Matrix3f::Identity();
    Vector3f delta_v_nsf = (I - inputdata.T / 2 * (omega_nie_m_05 + omega_nen_m_05).EA2ssm()) * attitude_data.Cnb_m.value * (inputdata.Velocity[2] + delta_v_brot + delta_v_bscul);

    // inputdata.T / 2 是否正确？？？？？？

    //计算运载体在导航系下的几何运动速度
    Vector3f v_nm = speed_data[0].v_nem + delta_v_nsf + delta_v_ncorg;
    speed_updating_data v_nm_m; v_nm_m.v_nem = v_nm;
    speed_data.push_back(v_nm_m);   // 将 m 时刻的速度更新结果增加到内存中
}


void update::position_update()
{
    /*
    *************************************************************************************
    *func:  position_update
    *@Param:
    *@Param:
    *@Return:
    *@Note: 进行姿态更新计算
    *creator：Jin Huang
    *organization:sdust
    *e-mail:kim.huang.j@qq.com
    *************************************************************************************
    */
    // 计算M_pv
    // m-1 时刻
    sinl = sin(inputdata.position[1](0)); cosl = cos(inputdata.position[1](0)); tanl = tan(inputdata.position[1](0));    // 计算地理纬度为 m-1 时刻的 sin cos tan
    Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    Rmh = Rm + inputdata.position[1](2); // 实际m-1时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Rnh = Rn + inputdata.position[1](2); // 实际m-1时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Matrix3f M_pv_m_1 = Eigen::Matrix3f::Zero();
    M_pv_m_1(0, 1) = 1.0 / Rmh;
    M_pv_m_1(1, 0) = 1.0 / (cosl * Rnh);
    M_pv_m_1(2, 2) = 1;

    // m-2 时刻
    sinl = sin(inputdata.position[0](0)); cosl = cos(inputdata.position[0](0)); tanl = tan(inputdata.position[0](0));    // 计算地理纬度为 m-2 时刻的 sin cos tan
    Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    Rmh = Rm + inputdata.position[0](2); // 实际m-2时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Rnh = Rn + inputdata.position[0](2); // 实际m-2时刻长度 子午圈曲率半径 + 大地高与椭球面的距离
    Matrix3f M_pv_m_2 = Eigen::Matrix3f::Zero();
    M_pv_m_2(0, 1) = 1.0 / Rmh;
    M_pv_m_2(1, 0) = 1.0 / (cosl * Rnh);
    M_pv_m_2(2, 2) = 1;

    // 外推法计算M_pv_05m
    Matrix3f M_pv_05m = Eigen::Matrix3f::Zero();
    M_pv_05m = (3 * M_pv_m_1 - M_pv_m_2) / 2;
    position_updating_data p_m;
    p_m.position = position_data[0].position + M_pv_05m * (speed_data[0].v_nem + speed_data[1].v_nem) * inputdata.T;    // 计算更新后位置
    // 将更新后位置储存
    position_data.push_back(p_m);
}
