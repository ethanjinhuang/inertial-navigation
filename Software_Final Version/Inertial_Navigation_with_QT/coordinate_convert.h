#pragma once
#ifndef COORDINATE_CONVERT_H
#define COORDINATE_CONVERT_H
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
#include<Eigen3\Eigen\Dense>
#include"earth_parameter.h"
#include"public_func.h"
using namespace std;
using namespace Eigen;

// 声明
Vector3d gcs2gc(double lambda, double L, double h);         // 大地坐标转换为地心直角坐标
Vector3d gc2gcs(double x, double y, double z);              // 地心直角坐标转换为大地坐标
Vector3d gcs2gc(Vector3d BLH);                              // 大地坐标转换为地心直角坐标
Vector3d gc2gcs(Vector3d XYZ);                              // 地心直角坐标转换为大地坐标
Vector3d gc2gcs(double x, double y, double z);              // 地心直角坐标转换为大地坐标
double acu_tan_l(double t, double x, double y, double z);   // 迭代计算 大地纬度L


#endif // COORDINATE_CONVERT_H
