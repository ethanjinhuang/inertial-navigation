/*
 * @Descripttion: 
 * @version: V1.0
 * @Author: GimHuang
 * @Date: 2020-11-19 11:13:09
 * @LastEditors: GimHuang
 * @LastEditTime: 2020-11-20 14:45:05
 */

//#include<Eigen/Dense>
#include<iostream>
#include<math.h>
#include<vector>
#include<malloc.h>
using namespace std;

// 设定默认参数
#define R_e 6378160.0   // 地球半径（椭圆长半轴）
#define f 1 / 298.257   // 地球扁率
#define R_p (1 - f) * R_e  // 椭圆短半轴
#define e1 sqrt(R_e * R_e - R_p * R_p) / R_e    // 第一椭球偏心率
#define e2 sqrt(R_e * R_e - R_p * R_p) / R_p    // 第二椭球偏心率

// 函数声明
double* gcs2gc(double lambda, double L, double h);
double* gc2gcs(double x, double y, double z);
double acu_tan_l(double t, double x, double y, double z);

// 将大地坐标系转换为地心直角坐标系
double* gcs2gc(double lambda, double L, double h)
{
    double R_N = R_e / sqrt(1 - e1 * e1 * sin(L) * sin(L));  // 计算卯酉圈曲率半径
    double x = (R_N + h) * cos(L) * cos(lambda);
    double y = (R_N + h) * cos(L) * sin(lambda);
    double z = (R_N * (1 - e1 * e1) + h) * sin(L);
    double pos[] = {x, y, z};
    return pos;
}

// geodetic coordinate system to geocentric cartesian
// 将地心直角坐标系转换为大地坐标系
double* gc2gcs(double x, double y, double z)
{
    double lambda = atan2(y, x);
    double L = acu_tan_l(0, x, y, z);
    double R_N = R_e / sqrt(1 - e1 * e1 * sin(L) * sin(L));
    double h = sqrt(x * x + y * y) / cos(L) - R_N;
    double pos[] = {lambda, L, h};
    return pos;
}

// geocentric cartesian to geodetic coordinate system
// 迭代计算纬度L
double acu_tan_l(double t, double x, double y, double z)
{
    double ti = (1 / sqrt(x * x + y * y)) * (z + R_e * e1 * e1 * t / sqrt(1 + (1 - e1 * e1) * t * t));
    if (abs(ti - t) <= 1e-20)
        return atan(ti);
    else
        return acu_tan_l(ti, x, y, z);
}

double deg2rad(double degree)
{
    return degree*atan(-1)/180.0;
}

double rad2deg(double rad)
{
    return rad*180/atan(-1);
}

int main()
{
    double *pos;
    pos = gcs2gc(deg2rad(20),deg2rad(30),10000);
    cout<< pos[0]<<" "<< pos[1]<<" "<< pos[2]<<endl;
    pos = gc2gcs(pos[0], pos[1], pos[2]);
    cout<< pos[0]<<" "<< pos[1]<<" "<< pos[2]<<endl;
    return 0;
}