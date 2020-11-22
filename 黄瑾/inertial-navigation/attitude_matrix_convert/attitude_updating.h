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

Quaternion_vector attitude_update(Quaternion_vector Qnb,Vector3f delta_theta1,Vector3f delta_theta2, Vector3f position1, Vector3f Velocity, float delta_t)
{
    /*
    *************************************************************************************
    *func: 计算姿态更新
    *@Param:    Qnb             载体系b相对于导航坐标系n的姿态旋转四元数
    *@Param:    delta_theta1    第一次角增量采样
    *@Param:    delta_theta2    第二次角增量采样
    *@Param:    position1       [L,B,H]初始位置的纬度、经度、大地高
    *@Param:    Velocity        载体运动的线速度 [Vx, Vy, 0] 或者 [Ve, Vn, 0]
    *@Param:    delta_t         姿态更新周期
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
    Direct_cosine_matrix Cnb(Qnb.QV2DCM()); // 载体系b相对于导航坐标系n的姿态阵
    // 地球（地球坐标系）绕自转轴旋转（地心惯性坐标系下）的角速度在导航坐标系下的投影
    Euler_angle phi_nie(0, earth.phi_ie * cosl, earth.phi_ie * sinl);   
    // 计算惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    Euler_angle phi_nen(-Velocity(1) / Rmh, Velocity(0) / Rnh, Velocity(0) / Rnh * tanl);  
	//求得角增量（欧拉角）表示的等效旋转矢量二子样算法
	Euler_angle Phi(delta_theta1 + delta_theta2 + 2.0 / 3 * delta_theta1.cross(delta_theta2));
    // 求得
    Euler_angle phi_nin(phi_nie + phi_nen);
    // 求得一个姿态更新周期内的角度变化
    Euler_angle theta(phi_nin.value * delta_t);
    // 变化后等效旋转矢量
    Euler_angle ea(Phi.value - Cnb.value.transpose() * theta.value);
    // 将变化后的等效旋转矢量变换为四元数表示
    Quaternion_vector qv(ea.EA2QV());
    // 进行姿态更新
    Quaternion_vector Qnb(qv * Qnb);
    return Qnb;
}
