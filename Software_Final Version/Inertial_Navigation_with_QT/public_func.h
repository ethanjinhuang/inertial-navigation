#pragma once
#ifndef FUBLIC_FUNC_H
#define FUBLIC_FUNC_H
/*
*************************************************************************************
*file: public_func
*@Description:
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：//2020
*************************************************************************************
*/
#include<math.h>
#include "vector"
#include "algorithm"
#include "Eigen3/Eigen/Dense"
using namespace std;
using namespace Eigen;
#define PI acos(-1)

double deg2rad(double deg);
double rad2deg(double rad);
double sind(double deg);
double cosd(double deg);
double tand(double deg);
double Vector_max(vector<double> &input);
double Vector_min(vector<double> &input);
double Modulus(Vector3d &input);
double chart_axis_max(vector<double> &input1,vector<double> &input2,vector<double> &input3);
double chart_axis_min(vector<double> &input1,vector<double> &input2,vector<double> &input3);
#endif // FUBLIC_FUNC_H
