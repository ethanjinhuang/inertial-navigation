#include "public_func.h"

double deg2rad(double deg)
{
    return (deg * PI) / 180.0;
}

double rad2deg(double rad)
{
    return rad * 180 / PI;
}

double sind(double deg)
{
    return sin(deg2rad(deg));
}

double cosd(double deg)
{
    return cos(deg2rad(deg));
}

double tand(double deg)
{
    return tan(deg2rad(deg));
}

double Vector_max(vector<double> &input)    // 寻找 vector 中最大值
{
    vector<double>::iterator findmax = max_element(std::begin(input),std::end(input));
    return *findmax;
}

double Vector_min(vector<double> &input)    // 寻找 vector 中最小值
{
    vector<double>::iterator findmin = min_element(std::begin(input),std::end(input));
    return *findmin;
}

double Modulus(Vector3d &input)
{
    return (sqrt(input[0]*input[0]+input[1]*input[1]+input[2]*input[2]));
}

double chart_axis_max(vector<double> &input1,vector<double> &input2,vector<double> &input3)
{
    double max1 = Vector_max(input1);
    double max2 = Vector_max(input2);
    double max3 = Vector_max(input3);
    return max(max(max1,max2),max3);
}
double chart_axis_min(vector<double> &input1,vector<double> &input2,vector<double> &input3)
{
    double min1 = Vector_min(input1);
    double min2 = Vector_min(input2);
    double min3 = Vector_min(input3);
    return min(min(min1,min2),min3);
}
