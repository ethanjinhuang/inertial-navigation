# ==================================================
# !/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author : KimHuang
# @Organization : SDUST
# @E-mail: kim.huang.j@qq.com
# @Site : 
# @Time : 2020/11/14 9:06
# @File : coordinate_tranform.py
# @Software: PyCharm
# @Desc : 
# ==================================================
# import numpy as np
from numpy import sin, cos, sqrt, arctan2, arctan

# 常数
R_e = 6378160.0  # 地球半径（椭圆长半轴）
f = 1 / 298.257  # 地球扁率
R_p = (1 - f) * R_e  # 椭圆短半轴
e1 = sqrt(R_e * R_e - R_p * R_p) / R_e  # 第一椭球偏心率
e2 = sqrt(R_e * R_e - R_p * R_p) / R_p  # 第二椭球偏心率


# geodetic coordinate system to geocentric cartesian
# 大地坐标系转换为地心直角坐标系
def gcs2gc(lam, L, h):
    R_N = R_e / sqrt(1 - e1 * e1 * sin(L) * sin(L))  # 计算卯酉圈曲率半径
    x = (R_N + h) * cos(L) * cos(lam)
    y = (R_N + h) * cos(L) * sin(lam)
    z = (R_N * (1 - e1 * e1) + h) * sin(L)
    return x, y, z


# geocentric cartesian to geodetic coordinate system
# 地心直角坐标系转换为大地坐标系
def gc2gcs(x, y, z):
    lam = arctan2(y, x)
    L = acu_tanl(0, x, y, z)
    R_N = R_e / sqrt(1 - e1 * e1 * sin(L) * sin(L))
    h = sqrt(x * x + y * y) / cos(L) - R_N
    return lam, L, h


# 迭代计算纬度L
def acu_tanl(t, x, y, z):
    ti = (1 / sqrt(x * x + y * y)) * (z + R_e * e1 * e1 * t / sqrt(1 + (1 - e1 * e1) * t * t))
    if abs(ti - t) <= 1e-20:
        return arctan(ti)
    else:
        return acu_tanl(ti, x, y, z)


# check main
x, y, z = gcs2gc(1, 1, 100)

l, L, h = gc2gcs(x, y, z)

print('x: {} y: {} z: {}'.format(x, y, z))
print('l: {} L: {} h: {}'.format(l, L, h))
