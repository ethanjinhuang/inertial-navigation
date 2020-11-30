/*
*************************************************************************************
*file:
*@Description:
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：16/11/2020
*************************************************************************************
*/
#pragma once
#include<iostream>
#include<math.h>
#include<Eigen\Dense>
#include"earth_parameter.h"
using namespace std;
using namespace Eigen;

// 声明
Vector3d gcs2gc(double lambda, double L, double h);         // 大地坐标转换为地心直角坐标
Vector3d gc2gcs(double x, double y, double z);              // 地心直角坐标转换为大地坐标
Vector3d gcs2gc(Vector3d BLH);                              // 大地坐标转换为地心直角坐标
Vector3d gc2gcs(Vector3d XYZ);                              // 地心直角坐标转换为大地坐标
Vector3d gc2gcs(double x, double y, double z);              // 地心直角坐标转换为大地坐标
double acu_tan_l(double t, double x, double y, double z);   // 迭代计算 大地纬度L

// geodetic coordinate system to geocentric cartesian
//大地坐标系转换为地心空间直角坐标系
Vector3d gcs2gc(double lambda, double L, double h)
{
    double R_N = earth.R_e / sqrt(1 - earth.e1 * earth.e1 * sin(L) * sin(L));  // 计算卯酉圈曲率半径
    double x = (R_N + h) * cos(L) * cos(lambda);
    double y = (R_N + h) * cos(L) * sin(lambda);
    double z = (R_N * (1 - earth.e1 * earth.e1) + h) * sin(L);
    Vector3d res = Eigen::Vector3d::Zero();
    res << x, y, z;
    return res;
}

// geocentric cartesian to geodetic coordinate system
// 将地心直角坐标系转换为大地坐标系
Vector3d gc2gcs(double x, double y, double z)
{
    double lambda = atan2(y, x);
    double L = acu_tan_l(0, x, y, z);
    double R_N = earth.R_e / sqrt(1 - earth.e1 * earth.e1 * sin(L) * sin(L));
    double h = sqrt(x * x + y * y) / cos(L) - R_N;
    Vector3d res = Eigen::Vector3d::Zero();
    res << lambda, L, h;
    return res;
}
// 大地坐标转换为地心直角坐标
Vector3d gcs2gc(Vector3d BLH)          
{
    double lambda = BLH(0), L = BLH(1), h = BLH(2);
    double R_N = earth.R_e / sqrt(1 - earth.e1 * earth.e1 * sin(L) * sin(L));  // 计算卯酉圈曲率半径
    double x = (R_N + h) * cos(L) * cos(lambda);
    double y = (R_N + h) * cos(L) * sin(lambda);
    double z = (R_N * (1 - earth.e1 * earth.e1) + h) * sin(L);
    Vector3d res = Eigen::Vector3d::Zero();
    res << x, y, z;
    return res;
}
// 地心直角坐标转换为大地坐标
Vector3d gc2gcs(Vector3d XYZ)
{
    double x = XYZ(0), y = XYZ(1), z = XYZ(2);
    double lambda = atan2(y, x);
    double L = acu_tan_l(0, x, y, z);
    double R_N = earth.R_e / sqrt(1 - earth.e1 * earth.e1 * sin(L) * sin(L));
    double h = sqrt(x * x + y * y) / cos(L) - R_N;
    Vector3d res = Eigen::Vector3d::Zero();
    res << lambda, L, h;
    return res;
}


// 迭代计算纬度L
double acu_tan_l(double t, double x, double y, double z)
{
    double ti = (1 / sqrt(x * x + y * y)) * (z + earth.R_e * earth.e1 * earth.e1 * t / sqrt(1 + (1 - earth.e1 * earth.e1) * t * t));
    if (abs(ti - t) <= 1e-20)
        return atan(ti);
    else
        return acu_tan_l(ti, x, y, z);
}

double deg2rad(double degree)
{
    return degree * PI / 180.0;
}

double rad2deg(double rad)
{
    return rad * 180 / PI;
}