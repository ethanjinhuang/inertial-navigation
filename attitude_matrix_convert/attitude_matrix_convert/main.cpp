#include <iostream>
#include <Eigen\Dense>
#include"attitude_matrix.h"
using namespace std;
using namespace Eigen;
void main()
{
	// test 
	Vector3f initional_data;
	initional_data << 1, 2, 3;
	//Euler Angle
	Euler_angle ea(initional_data);
	cout << "## Euler angle ##" << endl;
	ea.show();
	cout << "## Euler 2 Direct cosine matrix ##" << endl;
	Direct_cosine_matrix dcm(ea.EA2DCM());
	dcm.show();
	cout << "## Eulor 2 Quaternion ##" << endl;
	Quaternion_vector qv(ea.EA2QV());
	qv.show();

	cout << endl << "## Direct cosine matrix ##" << endl;
	dcm.show();
	cout << "## Direct cosine matrix 2 Euler angle ##" << endl;
	ea << dcm.DCM2EA();
	ea.show();
	cout << "## Direct cosine matrix 2 Quaternion ##" << endl;
	qv << dcm.DCM2QV();
	qv.show();

	cout << endl << "## Quaternion vector ##" << endl;
	qv.show();
	cout << "## Quaternion 2 Euler angle ##" << endl;
	ea << qv.QV2EA();
	ea.show();
	cout << "## Quaternion 2 Direct cosine matrix ##" << endl;
	dcm << qv.QV2DCM();
	dcm.show();

	system("pause");
}