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
class Equivalent_rotation_vector;

// 欧拉角
class Euler_angle
{
public:
	Vector3d value = Eigen::Vector3d::Zero();
	Euler_angle() { value = Eigen::Vector3d::Zero(); }
	Euler_angle(Euler_angle& input) { value = input.value; }	// 对象初始化
	Euler_angle(double phi, double theta, double gamma);	// 数值初始化
	Euler_angle(Vector3d input_vector);	// Vector3d初始化
	//transform function
	Matrix3d EA2DCM();	// 欧拉角 --> 方向余弦阵
	Vector4d EA2QV();	// 欧拉角 --> 四元数
	Vector3d EA2ERV();	// 欧拉角 --> 等效旋转矢量
	// caculate function
	Matrix3d EA2ssm();	//Skew-symmetric matrix	欧拉角 --> 反对称阵ssm
	// Basic function
	void show();
	void initialize() { value =  Eigen::Vector3d::Zero(); };		//初始化
	void operator<<(Vector3d vector3);			// 重载<<，便于向量赋值
	void operator=(Euler_angle input);	// 重载=，便于对象间赋值
	//Euler_angle operator*(Euler_angle& input);	// 重载*，便于进行乘法运算
	Euler_angle operator+(Euler_angle& input);
};
// 方向余弦阵
class Direct_cosine_matrix
{
public:
	Matrix3d value = Eigen::Matrix3d::Zero();
	Direct_cosine_matrix() { value = Eigen::Matrix3d::Zero(); }
	Direct_cosine_matrix(Direct_cosine_matrix& input) { value = input.value; }	// 对象初始化
	Direct_cosine_matrix(Matrix3d input_matrix);
	//transform function
	Vector3d DCM2EA();	// 方向余弦阵 --> 欧拉角
	Vector4d DCM2QV();	// 方向余弦阵 --> 四元数
	Vector3d DCM2ERV();	// 方向余弦阵 --> 等效旋转矢量
	// Basic function
	void show();
	void initialize() { value = Eigen::Matrix3d::Zero(); };		//初始化
	void operator<<(Matrix3d matrix3);			//重载<<，便于向量赋值
	void operator=(Direct_cosine_matrix input);	//重载=，便于对象间赋值
};

// 四元数
class Quaternion_vector
{
public:
	Vector4d value = Eigen::Vector4d::Zero();
	Quaternion_vector() {value = Eigen::Vector4d::Zero();}
	Quaternion_vector(Quaternion_vector& input) { value = input.value; }	// 对象初始化
	Quaternion_vector(Vector4d &input);
	//transform function
	Vector3d QV2EA();	//四元数 --> 欧拉角
	Matrix3d QV2DCM();	//四元数 --> 方向余弦阵
	Vector3d QV2ERV();	//四元数 --> 等效旋转矢量
	// Basic function
	void show();
	void initialize() { value = Eigen::Vector4d::Zero(); };		//初始化
	void operator<<(Vector4d &matrix3);		//重载<<，便于向量赋值
	void operator=(Quaternion_vector &input);//重载=，便于对象间赋值
	Quaternion_vector operator*(Quaternion_vector& input);	//重载四元数相乘
	
};

// 等效旋转矢量
class Equivalent_rotation_vector
{
public:
	Vector3d value = Eigen::Vector3d::Zero();
	Equivalent_rotation_vector(){ value = Eigen::Vector3d::Zero(); }
	Equivalent_rotation_vector(Equivalent_rotation_vector& input) { value = input.value; }	// 对象初始化
	Equivalent_rotation_vector(Vector3d input);
	//transform function
	Vector4d ERV2QV();	//等效旋转矢量 --> 四元数
	Matrix3d ERV2DCM();	//等效旋转矢量 --> 方向余弦阵
	Vector3d ERV2EA();	//等效旋转矢量 --> 欧拉角
	// Basic function
	void show();
	void initialize() { value = Eigen::Vector3d::Zero(); };		//初始化
	void operator<<(Vector3d &vector3);							//重载<<，便于向量赋值
	void operator=(Equivalent_rotation_vector &input);		//重载=，便于对象间赋值
};

