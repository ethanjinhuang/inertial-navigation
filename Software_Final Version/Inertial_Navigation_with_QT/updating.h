#pragma once
#ifndef UPDATING_H
#define UPDATING_H
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
#include<Eigen3/Eigen/Dense>
#include"attitude_matrix.h"
#include"earth_parameter.h"
#include"read_imr_file.h"
#include"public_func.h"
using namespace std;
using namespace Eigen;

// 建立结构体便于保存姿态更新结果
struct attitude_updating_data
{
    Euler_angle omega_nie;  // 地球（地球坐标系）绕自转轴旋转（地心惯性坐标系下）的角速度在导航坐标系下的投影
    Euler_angle omega_nen;  // 惯导系统在地球表面附近移动因地球表面弯曲而引起的n系旋转
    Euler_angle omega_nin;  // 求得n系相当于i系的旋转
    Equivalent_rotation_vector Phi_bib;    // 载体坐标系相对于地心惯性坐标系的变化bib （以等效旋转矢量形式表示）
    Equivalent_rotation_vector Phi_nin;    //导航坐标系相对于地心惯性坐标系的变化
    Direct_cosine_matrix Cnb_m; // 在t(m)时刻的捷联姿态矩阵
};

struct speed_updating_data
{
    Vector3d v_nem; // 载体在导航系下的几何运动速度
};

struct position_updating_data
{
    Vector3d position;
};

struct input_data
{
    Direct_cosine_matrix Dnb;   // 上一时刻的用b系到n系的方向余弦阵
    //vector<Vector3d> delta_theta1;      // 第一次采样
    vector<Vector3d> delta_theta;      // 三次采样，理论上只会用到最后两次
    vector<Vector3d> position;          // 未变化前位置
    vector<Vector3d> Velocity;          // 载体运动的速度[E N U]
    double T = 0;                    // 载体采样周期
};

// ===========================姿态、速度、位置更新===========================
class update
{
public:
    // 存放m-1时刻的方向余弦阵，存放m，m-1时刻的采样数据分别于vector[2],vecotr[1]，存放m-1时刻，m-2时刻的位置数据于vector[1],vector[0]，存放m-1,m-2时刻的速度数据于vector[1],vector[0], 存放采样周期
    update(Direct_cosine_matrix a1, vector<Vector3d> a2, vector<Vector3d> a3, vector<Vector3d> a4, vector<Vector3d> a5, double a7);
    void initialize(Direct_cosine_matrix a1, vector<Vector3d> a2, vector<Vector3d> a3, vector<Vector3d> a4, vector<Vector3d> a5, double a7);    // 初始化函数
    input_data inputdata;   // 输入数据
    attitude_updating_data attitude_data;           // 姿态更新结果
    vector<speed_updating_data> speed_data;         // 速度更新结果，通常存放三次速度更新结果，[0] m-2 时刻的速度更新，[1]，m -1 时刻的速度更新，[2]，m 时刻的速度更新
    vector<position_updating_data> position_data;   // 位置更新结果，通常存放三次位置更新结果，[0] m-2 时刻的位置，[1]，m-1 时刻的位置，[2]，m 时刻的速度更新
    vector<position_updating_data> position_result; // 存放结果
    void attitude_update();		// 姿态更新
    void speed_update();		// 速度更新
    void position_update();		// 位置更新
    void initial_alignment();	// 初始对准
    // 定义通用变量
private:
    double sinl, cosl, tanl;
    double Rm;
    double Rn;
    double Rmh;
    double Rnh;
};


#endif // UPDATING_H
