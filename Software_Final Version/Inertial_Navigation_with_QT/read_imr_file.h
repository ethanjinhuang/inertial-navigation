#pragma once
#ifndef READ_IMR_FILE_H
#define READ_IMR_FILE_H
/*
*************************************************************************************
*file:	read_imr_file.h
*@Description: 定义imr格式数据构成，读取IMR格式的数据文件（文件头、数据体）
*creator：Jin Huang
*organization:sdust
*e-mail:kim.huang.j@qq.com
*datetime：22/11/2020
*************************************************************************************
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// ----------------------------------------------------------------------------------
// 如果定义则将数值改正至 m/s^2 和 deg/sec
//#define IsCorrect
// ----------------------------------------------------------------------------------

// 定义数据格式
#define int8_t unsigned char
//#define int32_t int
#define unit8_t char
//#define time_type long double

// 定义结构体，整个结构体长度为512字节
struct IMR_Header
{
    char szHeader[8];				// "$IMURAW\0"
    int8_t bIsIntelOrMotorola;		// 0 表示小字节， 1表示大字节
    double dVersionNumber;			// 惯性资源管理器程序版本号
    int32_t bDeltaTheta;			// 0 接下来的数据将以变化的角度速率读取
                                    // 1 （默认）接下来的数据将被读取为delta，即角增量
    int32_t bDeltaVelocity;			// 0 接下来的数据将以变化的加速度读取
                                    // 1 （默认）接下来的数据将被读取为速度，即速度增量
    double dDataRateHz;				// IMU 的采样率 (Hz)
    double dGyroScaleFactor;		// bDeltaTheta == 0 将陀螺仪的测量值乘以该值得到 度/秒
                                    // bDeltaTheta == 1 将陀螺仪的测量值乘以该值得到 度，然后乘以dDataRateHz得到 度/秒
    double dAccelScaleFactor;		// bDeltaVelocity == 0 将实测数据乘以该值得到 m/s^2
                                    // bDeltaVelocity == 1 将实测数据乘以该值得到 m/s， 再乘以dDataRateHz就得到 m/s^2
    int32_t iUtcOrGpsTime;			// 将时间标记定义为一周的GPS或UTC秒
                                    // iUtcOrGpsTime == 0 未知，默认为GPS
                                    // iUtcOrGpsTime == 1 时间标签是每周的UTC秒
                                    // iUtcOrGpsTime == 2 时间标签是每周的GPS秒
    int32_t iRcvTimeOrCorrTime;		// 定义时间标记是否在第二个标称的顶部或为接收机时间偏差进行校正
    double dTimeTagBias;			// GPS和IMU时间标签之间的偏差
    char szImuName[32];				// 使用的IMU名称
    unit8_t reserved1[4];			// 暂无，留空
    char szProgramName[32];			// 调用程序名称
    char tCreate[12];				// 创建文件时间
    bool bLeverArmValid;			// 如果IMU至主GNSS天线的杆臂存储在此标头中，则为此项值为真
    int32_t lXoffset;				// 杠杆臂X mm
    int32_t lYoffset;				// 杠杆臂Y mm
    int32_t lZoffset;				// 杠杆臂Z mm
    int8_t Reserved[354];			// 留作未来使用
};

// The single header, which is a total of 512 bytes long,
// is followed by a structure of the following type for each IMU measurement epoch

struct IMR_Record
{
    double Time;		// 当前观测的时间
    int32_t gx;			// 关于IMU x轴的缩放陀螺测量量
    int32_t gy;			// 关于IMU y轴的缩放陀螺测量量
    int32_t gz;			// 关于IMU z轴的缩放陀螺测量量
    int32_t ax;			// 关于IMU x轴的缩放加速测量
    int32_t ay;			// 关于IMU y轴的缩放加速测量
    int32_t az;			// 关于IMU z轴的缩放加速测量
};

struct adj_IMR_Record
{
    double Time;		// 当前观测的时间
    double gx;			// 关于IMU x轴的缩放陀螺测量量
    double gy;			// 关于IMU y轴的缩放陀螺测量量
    double gz;			// 关于IMU z轴的缩放陀螺测量量
    double ax;			// 关于IMU x轴的缩放加速测量
    double ay;			// 关于IMU y轴的缩放加速测量
    double az;			// 关于IMU z轴的缩放加速测量
};

class imr_data
{
public:
    IMR_Header* file_header;
    vector<adj_IMR_Record> file_data;
    void read_data(char* filepath);
    void initial();
private:
    void read_imr_header(fstream& imrfile, IMR_Header* imrheader);
    void read_imr_data(fstream& imrfile, vector<adj_IMR_Record>& adj_data, IMR_Header imr_header);
};


#endif // READ_IMR_FILE_H
