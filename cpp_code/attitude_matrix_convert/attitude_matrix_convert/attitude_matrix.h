//===============================================================
//程序实现了 四元数、方向余弦阵、欧拉角之间的相互转换				*
//																*
//	First edit:		09/11/2020									*
//	Last edit:		10/11/2020									*
//	Author:			GimHuang									*
//	Org:			SDUST										*
//	e-mail:			kim.huang.j@qq.com							*
//																*
//===============================================================
#pragma once
#include<iostream>
#include<Eigen\Dense>
#include<math.h>
using namespace Eigen;
using namespace std;

//类声明
class Euler_angle;
class Direct_cosine_matrix;
class Quaternion_vector;

// 欧拉角
class Euler_angle
{
public:
	Vector3f value = Eigen::Vector3f::Zero();
	Euler_angle() { value = Eigen::Vector3f::Zero(); }
	Euler_angle(float phi, float theta, float gamma);
	Euler_angle(Vector3f input_vector);
	//transform function
	Matrix3f EA2DCM();	// 欧拉角 --> 方向余弦阵
	Vector4f EA2QV();	// 欧拉角 --> 四元数
	Vector3f EA2ERV();	// 欧拉角 --> 等效旋转矢量
	// Basic function
	void show();
	void initialize() { value =  Eigen::Vector3f::Zero(); };		//初始化
	void operator<<(Vector3f vector3);			//重载<<，便于向量赋值
	void operator=(Euler_angle input);	//重载=，便于对象间赋值
};
// 方向余弦阵
class Direct_cosine_matrix
{
public:
	Matrix3f value = Eigen::Matrix3f::Zero();
	Direct_cosine_matrix() { value = Eigen::Matrix3f::Zero(); }
	Direct_cosine_matrix(Matrix3f input_matrix);
	//transform function
	Vector3f DCM2EA();	// 方向余弦阵 --> 欧拉角
	Vector4f DCM2QV();	// 方向余弦阵 --> 四元数
	Vector3f DCM2ERV();	// 方向余弦阵 --> 等效旋转矢量
	// Basic function
	void show();
	void initialize() { value = Eigen::Matrix3f::Zero(); };		//初始化
	void operator<<(Matrix3f matrix3);			//重载<<，便于向量赋值
	void operator=(Direct_cosine_matrix input);	//重载=，便于对象间赋值
};

// 四元数
class Quaternion_vector
{
public:
	Vector4f value = Eigen::Vector4f::Zero();
	Quaternion_vector() {value = Eigen::Vector4f::Zero();}
	Quaternion_vector(Vector4f &input);
	//transform function
	Vector3f QV2EA();	//四元数 --> 欧拉角
	Matrix3f QV2DCM();	//四元数 --> 方向余弦阵
	Vector3f QV2ERV();	//四元数 --> 等效旋转矢量
	// Basic function
	void show();
	void initialize() { value = Eigen::Vector4f::Zero(); };		//初始化
	void operator<<(Vector4f &matrix3);		//重载<<，便于向量赋值
	void operator=(Quaternion_vector &input);//重载=，便于对象间赋值
	
};

// 等效旋转矢量
class Equivalent_rotation_vector
{
public:
	Vector3f value = Eigen::Vector3f::Zero();
	Equivalent_rotation_vector(){ value = Eigen::Vector3f::Zero(); }
	Equivalent_rotation_vector(Vector3f input);
	//transform function
	Vector4f ERV2QV();	//等效旋转矢量 --> 四元数
	Matrix3f ERV2DCM();	//等效旋转矢量 --> 方向余弦阵
	Vector3f ERV2EA();	//等效旋转矢量 --> 欧拉角
	// Basic function
	void show();
	void initialize() { value = Eigen::Vector3f::Zero(); };		//初始化
	void operator<<(Vector3f &vector3);							//重载<<，便于向量赋值
	void operator=(Equivalent_rotation_vector &input);		//重载=，便于对象间赋值
};

