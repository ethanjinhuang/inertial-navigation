#pragma once
#ifndef EARTH_PARAMETER_H
#define EARTH_PARAMETER_H
/*
*************************************************************************************
*file:	erath_parameter.h
*@Description:	存放地球固有参数
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：20/11/2020
*************************************************************************************
*/
#include<math.h>
#define PI acos(-1)	//定义PI
//地球参数
struct Earth_parameter
{
public:
    const double R_e = 6378160.0;		        // 地球半径
    const double f = 1 / 298.257;			        // 地球扁率
    const double R_p = (1 - f) * R_e;			// 地球短轴
    const double e1 = sqrt(R_e * R_e - R_p * R_p) / R_e;	// 地球第一偏心率
    const double e2 = sqrt(R_e * R_e - R_p * R_p) / R_p;	// 地球第二偏心率
    const double phi_ie = 7.2921151467e-5;  // 地球自转角速率
    const double g0 = 9.7803267714; // 地球重力常数
};

extern struct Earth_parameter earth;

#endif // EARTH_PARAMETER_H
