#pragma once
#ifndef GLOBAL_VARIATE_H
#define GLOBAL_VARIATE_H

#include "updating.h"
//#include "coordinate_convert.h"
#include "attitude_matrix.h"


// 创建文件读取对象
extern imr_data imrdata;

// 初始值类
class initial_data
{
public:
    Euler_angle begin_rotation;
    Direct_cosine_matrix begin_dcm;
    vector<Vector3d> delta_theta;
    vector<Vector3d> speed;
    vector<Vector3d> position;
    vector<Vector3d> velocity;
    double T;
};

class process_check
{
public:
    bool is_imr_read=false;
    bool is_initial_data=false;
    bool is_data_caculation = false;
    bool is_initial = false;
    bool is_load_data = false;
};


extern vector<Vector3d> final_position;

extern initial_data initial_data;
extern process_check process_check;

#endif // GLOBAL_VARIATE_H
