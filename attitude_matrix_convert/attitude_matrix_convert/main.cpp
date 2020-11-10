#include <iostream>
#include <Eigen\Dense>
#include"attitude_matrix.h"
using namespace std;
using namespace Eigen;
void main()
{
	//Vector3f value=Eigen::Vector3f::Zero();
	//cout << value << endl;
	Euler_angle ea1(1,2,3);
	ea1.show();
	Direct_cosine_matrix dcm(ea1.EA2DCM());
	dcm.show();
	//dcm.show();
	//*dcm.show();
	//Direct_cosine_matrix dcm;
	//dcm.value(1,1) = 1;
	//dcm.show();
	system("pause");
}