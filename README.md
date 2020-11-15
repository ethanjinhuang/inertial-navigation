# Inertial-navigation

> Shandong University of Science and Technology  
> 		College of Geodesy and Geomatics
> 		Geomatics Engineering（Marine Surveying and Mapping）2018-1 
> 		Contributors: 黄瑾 
> 		e-mail: 201801020510@sdust.edu.cn

## :desktop_computer:Appliance

 `Microsoft Visual Studio 2015 `, `PyCharm Professional 2020.2.3`, `MATLAB 2020a`

## :gear:Language

C++	Python	MATLAB

 ## :1st_place_medal:Task

* [x] Build the transform method between four difference Coordinate transformation mode with CPP.
* [x] Using MATLAB and Python to achieve the program.
* [x] Geodetic coordinate transformation with CPP
* [x] Geodetic coordinate transformation with python 

## :two_men_holding_hands:Group Members

- 黄瑾
- 潘宗龙
- 孟怡君

## :office:Total Work

Our Group Finished all Tasks with three differences language. Including CPP, Python, MATLAB.

![image-20201115161057062](.\picture\image-20201115161057062.png)

## :page_facing_up:Theory
### Attitude Matrix

This Examination accomplished the transformation between Euler Angle, Direction Cosine Matrix, Quaternion and Equivalent Rotation Vector.

We will introduce the CPP code as an example for the program.

#### 1.  Class
Create the class  for different methods. Using operator overloading, destructor, etc.
```cpp
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
```
#### 2. Method 

详情参照：严恭敏 翁浚，捷联惯导算法与组合导航原理，西北工业大学出版社，2019

P 245-248 achieve the three differences attitude describes transformation.(Euler Angle, Direction Cosine Matrix and Quaternion)

P 233  achieve the Equivalent Rotation Vector to Quaternion

---
###  Coordinate transformation
In this section, we will use python code as an example to show the arithmetic.

The method could be found in page 51.

```python
from numpy import sin, cos, sqrt, arctan2, arctan, pi
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
    L = acu_tan_l(0, x, y, z)
    R_N = R_e / sqrt(1 - e1 * e1 * sin(L) * sin(L))
    h = sqrt(x * x + y * y) / cos(L) - R_N
    return lam, L, h
# 迭代计算纬度L
def acu_tan_l(t, x, y, z):
    ti = (1 / sqrt(x * x + y * y)) * (z + R_e * e1 * e1 * t / sqrt(1 + (1 - e1 * e1) * t * t))
    if abs(ti - t) <= 1e-20:
        return arctan(ti)
    else:
        return acu_tan_l(ti, x, y, z)
```



## :question:Introduction

==How to use==:

> Attitude Matrix

- **STEP 1**  Create the  Object

  ```cpp
  Euler_angle ea(initional_data);
  Direct_cosine_matrix dcm(ea.EA2DCM());
  Quaternion_vector qv(ea.EA2QV());
  Equivalent_rotation_vector erv(ea.EA2ERV());
  ```

- **STEP 2** Transform function

  ```cpp
  // 欧拉角
  ea.EA2DCM();
  ea.EA2ERV();
  ea.EA2QV();
  // 等效旋转矢量
  erv.ERV2DCM();
  erv.ERV2EA();
  erv.ERV2QV();
  // 四元数
  qv.QV2DCM();
  qv.QV2EA();
  qv.QV2ERV();
  // 方向余弦阵
  dcm.DCM2EA();
  dcm.DCM2ERV();
  dcm.DCM2QV();
  ```
  
- **STEP 3** Check code

  ```cpp
  void main()
  {
  	// test 
  	Vector3f initional_data;
  	initional_data << 1, 1, 1;
  	//Euler Angle
  	Euler_angle ea(initional_data);
  	cout << "## Euler angle ##" << endl;
  	ea.show();
  	cout << endl << "## Euler 2 Direct cosine matrix ##" << endl;
  	Direct_cosine_matrix dcm(ea.EA2DCM());
  	dcm.show();
  	cout << endl << "## Eulor 2 Quaternion ##" << endl;
  	Quaternion_vector qv(ea.EA2QV());
  	qv.show();
  	cout << endl << "## Eulor 2 Equivalent rotation vector ##" << endl;
  	Equivalent_rotation_vector erv(ea.EA2ERV());
  	erv.show();
  
  	cout << endl << endl << "## Direct cosine matrix ##" << endl;
  	dcm.show();
  	cout << endl << "## Direct cosine matrix 2 Euler angle ##" << endl;
  	ea << dcm.DCM2EA();
  	ea.show();
  	cout << endl << "## Direct cosine matrix 2 Quaternion ##" << endl;
  	qv << dcm.DCM2QV();
  	qv.show();
  	cout << endl << "## Direct cosine matrix 2 Equivalent rotation vector ##" << endl;
  	erv << dcm.DCM2ERV();
  	erv.show();
  
  	cout << endl << endl << "## Quaternion vector ##" << endl;
  	qv.show();
  	cout << endl << "## Quaternion 2 Euler angle ##" << endl;
  	ea << qv.QV2EA();
  	ea.show();
  	cout << endl << "## Quaternion 2 Direct cosine matrix ##" << endl;
  	dcm << qv.QV2DCM();
  	dcm.show();
  	cout << endl << "## Quaternion 2 Equivalent rotation vector ##" << endl;
  	erv << qv.QV2ERV();
  	erv.show();
  
  	cout << endl << endl << "## Equivalent_rotation_vector ##" << endl;
  	erv.show();
  	cout << endl << "## Equivalent_rotation_vector 2 Quaternion ##" << endl;
  	qv << erv.ERV2QV();
  	qv.show();
  	cout << endl << "## Equivalent_rotation_vector 2 Euler angle ##" << endl;
  	ea << erv.ERV2EA();
  	ea.show();
  	cout << endl << "## Equivalent_rotation_vector 2 Direct cosine matrix ##" << endl;
  	dcm << erv.ERV2DCM();
  	dcm.show();
      
      system("pause");
  }
  ```

  

- **STEP 4** Check Result 

![image-20201115115440915](.\picture\image-20201115115440915.png)

```
## Euler angle ##
1
1
1
## Euler 2 Direct cosine matrix ##
-0.303897 -0.454649  0.837222
 0.837222  0.291927  0.462426
-0.454649  0.841471  0.291927
## Eulor 2 Quaternion ##
0.565676
0.167519
0.570941
0.167519
## Eulor 2 Equivalent rotation vector ##
0.393915
 1.34255
0.393915
## Direct cosine matrix ##
-0.303897 -0.454649  0.837222
 0.837222  0.291927  0.462426
-0.454649  0.841471  0.291927
## Direct cosine matrix 2 Euler angle ##
1
1
1
## Direct cosine matrix 2 Quaternion ##
0.565676
0.167519
0.570941
0.570942
## Direct cosine matrix 2 Equivalent rotation vector ##
0.393915
 1.34255
 1.34255
## Quaternion vector ##
0.565676
0.167519
0.570941
0.570942
## Quaternion 2 Euler angle ##
1
1
1
## Quaternion 2 Direct cosine matrix ##
-0.303897 -0.454649  0.837222
 0.837222  0.291927  0.462426
-0.454649  0.841471  0.291927
## Quaternion 2 Equivalent rotation vector ##
0.393915
 1.34255
 1.34255
## Equivalent_rotation_vector ##
0.393915
 1.34255
 1.34255
## Equivalent_rotation_vector 2 Quaternion ##
0.565676
0.167519
0.570941
0.570942
## Equivalent_rotation_vector 2 Euler angle ##
1
1
1
## Equivalent_rotation_vector 2 Direct cosine matrix ##
-0.303897 -0.454649  0.837222
 0.837222  0.291927  0.462426
-0.454649  0.841471  0.291927
```
Checking through difference method, acquiring a consistent result.

---

> Coordinate Tranform

**Checking function**

```python
def deg2rad(degree):
    return degree * pi / 180

def rad2deg(rad):
    return rad * 180 / pi

x, y, z = gcs2gc(deg2rad(20), deg2rad(30), 10000)

l, L, h = gc2gcs(x, y, z)

print('x: {} y: {} z: {}'.format(x, y, z))
print('l: {} L: {} h: {}'.format(rad2deg(l), rad2deg(L), h))
```

**result**

![image-20201115122929437](.\picture\image-20201115122929437.png)

```
D:\ProgramData\Anaconda\python.exe "D:/GitHub/inertial navigation/python_code/coordinate_tranform.py"
input l: 20 L: 30 h: 10000
x: 5203018.682855053 y: 1893743.9288901808 z: 3175385.1539686834
l: 19.999999999999996 L: 29.999999999999993 h: 10000.000000000931

Process finished with exit code 0
```



## :email: Connection

https://github.com/GimHuang

![image-20201115104627037](.\picture\image-20201115104627037.png)

Github: `[Private]` https://github.com/GimHuang/inertial-navigation.git



