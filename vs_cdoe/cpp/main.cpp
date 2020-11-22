#include<iostream>
#include<Eigen/Dense>
#include"attitude_matrix.h"
//#include"Transformation.h"
using namespace std;
using namespace Eigen;

#define attitude_matrix
//#define transformation

void main()
{
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

#ifdef transformation
	//澶у湴->鍦板績
	geodeticToGeocentric func0;
	Geocentric c(20.22, 30.33, 100.211, func0);
	stdVectord v0(c.getCoordinate());
	cout << "(X,Y,Z)" << endl;
	for (auto i : v0)
	{
		cout << i << endl;
	}
	cout << endl;
	//鍦板績->澶у湴
	cout << "(lamda,L,h)" << endl;
	geocentricToGeodetic func1;
	Geodetic g(c.getCoordinate(), func1);
	stdVectord v(g.getCoordinate());
	for (auto i:v)
	{
		cout << i << endl;
	}

	//大地->地心
	Geocentric c0(g.getCoordinate(), func0);
	stdVectord v2(c0.getCoordinate());
	cout << "(X,Y,Z)" << endl;
	for (auto i : v2)
	{
		cout << i << endl;
	}

#endif // transformation

	

	system("pause");
}