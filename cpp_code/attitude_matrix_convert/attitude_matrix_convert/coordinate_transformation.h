#pragma once
#include<iostream>
#include<math.h>
#include<Eigen\Dense>
using namespace std;
using namespace Eigen;
#define PI 3.1415927
//地球参数
struct Earth_parameter
{
	double radius = 6378160;		// 地球半径
	double f = 1 / 298.3;			// 地球扁率
	double a = 6378137.0;			// 地球长轴
	double b = 6356752.314;			// 地球短轴
	double e1 = sqrt(2 * f - f*f);	// 地球偏心率
	double e2 = e1*e1;
}earth;

//大地坐标系转换为地心空间直角坐标系
Vector3f convert_BLH2XYZ(Vector3f input)
{
	float B = B*PI / 180;
	float L = L*PI / 180;
}
