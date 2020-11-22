#include <iostream>
#include <Eigen\Dense>
#include"attitude_matrix.h"
#include"coordinate_convert.h"
#include"earth_parameter.h"
//#include"Transformation.h"
using namespace std;
using namespace Eigen;

//#define attitude_matrix
//#define transformation

void main()
{
	//验证姿态表示方法间转换
#ifdef attitude_matrix
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



#endif // attidtude_matrix
	//验证大地坐标与地心直角坐标间转换
#ifdef transformation
	Vector3f BLH(deg2rad(20), deg2rad(30), 10000);
	cout << BLH << endl;
	Vector3f xyz = gcs2gc(BLH);
	cout << xyz << endl;
	BLH = gc2gcs(xyz);
	cout << BLH << endl;
#endif // transformation
	Vector4f x;
	x << 1, 2, 3, 4;
	Quaternion_vector qv1(x);
	qv1.show();
	Quaternion_vector qv2(qv1 * qv1);
	qv2.show();

	system("pause");
}