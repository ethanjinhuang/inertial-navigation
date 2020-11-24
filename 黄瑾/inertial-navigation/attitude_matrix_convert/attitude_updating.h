/*
*************************************************************************************
*file:attitude_updating.h
*@Description:实现地理坐标系(g坐标系)下的姿态更新
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
using namespace std;
using namespace Eigen;

// 陀螺仪数据
class gyroscope
{
public:
	Vector3f omega_ibb = Eigen::Vector3f::Zero();
	//Matrix3f _x();
};

//Matrix3f gyroscope::_x()
//{
//	Matrix3f res = Eigen::Matrix3f::Zero();
//	res(0, 0) = 0; res(0,1) = 
//}

Direct_cosine_matrix attitude_update(Quaternion_vector Qnb,Vector3f delta_theta1,Vector3f delta_theta2, Vector3f position1, Vector3f Velocity, float T)
{
    /*
    *************************************************************************************
    *func: 计算姿态更新
    *@Param:    Qnb             载体系b相对于导航坐标系n的姿态旋转四元数
    *@Param:    delta_theta1    第一次角增量采样
    *@Param:    delta_theta2    第二次角增量采样
    *@Param:    position1       [L,B,H]初始位置的纬度、经度、大地高
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
    // 通用变量计算
    float sinl = sin(position1(0)), cosl = cos(position1(0)), tanl = tan(position1(0));    // 计算地理纬度为sin cos tan
    float Rm = earth.R_e * (1 - 2 * earth.e1 + 3 * earth.e1 * sinl * sinl);    // 计算子午圈主曲率半径
    float Rn = earth.R_e * (1 * earth.e1 * sinl * sinl);   // 计算卯酉圈主曲率半径
    float Rmh = Rm + position1(2); // 实际长度 子午圈曲率半径 + 大地高与椭球面的距离
    float Rnh = Rn + position1(2); // 实际长度 子午圈曲率半径 + 大地高与椭球面的距离
    

    // 地球（地球坐标系）绕自转轴旋转（地心惯性坐标系下）的角速度在导航坐标系下的投影
    Euler_angle omega_nie(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   
    // 计算惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    Euler_angle omega_nen(-Velocity(1) / Rmh, Velocity(0) / Rnh, Velocity(0) / Rnh * tanl); 
    // 求得n系相当于i系的旋转
    Euler_angle omega_nin(omega_nie + omega_nen);

	// 利用等效旋转矢量二子样算法计算在更新周期内 载体坐标系相对于地心惯性坐标系的变化bib （以等效旋转矢量形式表示）
	Euler_angle Phi_bib(delta_theta1 + delta_theta2 + 2.0 / 3 * delta_theta1.cross(delta_theta2));

    // 计算导航坐标系相对于地心惯性坐标系的变化，由于速度和位置引起的omega_nin的变化很小，
    // 因此可以用常值代替，其变化可以用一个时刻的变化率乘以采样周期
    Euler_angle Phi_nin(omega_nie.value * T);

    // ========课本算法
    Direct_cosine_matrix Cnm_nm_1(Phi_nin.EA2DCM().transpose());
    Direct_cosine_matrix Cbm_1_bm(Phi_bib.EA2DCM());
    Direct_cosine_matrix Cnm_bm(Cnm_nm_1.value);
    Direct_cosine_matrix Cnb_m_1(Qnb.QV2DCM());     // 载体系b相对于导航坐标系n的姿态阵,也就是在t(m-1)时刻有b系转换为n系的姿态捷联矩阵
    Direct_cosine_matrix Cnb_m(Cnm_nm_1.value * Cnb_m_1.value * Cbm_1_bm.value);    // 在t(m)时刻的捷联姿态矩阵
    return Cnb_m;
    //// ========严老师matlab算法
    //// 变化后等效旋转矢量
    //Euler_angle ea(Phi_bib.value - Cnb.value.transpose() * Phi_nin.value);
    //// 将变化后的等效旋转矢量变换为四元数表示
    //Quaternion_vector qv(ea.EA2QV());
    //// 进行姿态更新
    //Quaternion_vector Qnb(qv * Qnb);
    //return Qnb;
}
