#pragma once
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

// 定义数据格式
#define int8_t unsigned char
#define int32_t int
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


void read_imr_header(fstream &imrfile, IMR_Header *imrheader)
{
	/*
	*************************************************************************************
	*func:	read_imr_header
	*@Param:	fstream &imrfile 文件类
	*@Param:	IMR_Header *imrheader 结构体指针，存放文件头数据
	*@Return:
	*@Note:	读取imr头文件
	*creator：Jin Huang
	*organization:sdust
	*e-mail:kim.huang.j@qq.com
	*************************************************************************************
	*/
	for (int i = 0; i < 8; i++)
	{
		imrfile.read((char*)&imrheader->szHeader[i], sizeof(char));
	}
	imrfile.read((char*)&imrheader->bIsIntelOrMotorola, sizeof(int8_t));
	imrfile.read((char*)&imrheader->dVersionNumber, sizeof(double));
	imrfile.read((char*)&imrheader->bDeltaTheta, sizeof(int32_t));
	imrfile.read((char*)&imrheader->bDeltaVelocity, sizeof(int32_t));
	imrfile.read((char*)&imrheader->dDataRateHz, sizeof(double));
	imrfile.read((char*)&imrheader->dGyroScaleFactor, sizeof(double));
	imrfile.read((char*)&imrheader->dAccelScaleFactor, sizeof(double));
	imrfile.read((char*)&imrheader->iUtcOrGpsTime, sizeof(int32_t));
	imrfile.read((char*)&imrheader->iRcvTimeOrCorrTime, sizeof(int32_t));
	imrfile.read((char*)&imrheader->dTimeTagBias, sizeof(double));
	for (int i = 0; i < 32; i++)
	{
		imrfile.read((char*)&imrheader->szImuName[i], sizeof(char));
	}
	for (int i = 0; i < 4; i++)
	{
		imrfile.read((char*)&imrheader->reserved1[i], sizeof(unit8_t));
	}
	for (int i = 0; i < 32; i++)
	{
		imrfile.read((char*)&imrheader->szProgramName[i], sizeof(char));
	}
	for (int i = 0; i < 12; i++)
	{
		imrfile.read((char*)&imrheader->tCreate[i], sizeof(char));
	}
	
	imrfile.read((char*)&imrheader->bLeverArmValid, sizeof(bool));
	imrfile.read((char*)&imrheader->lXoffset, sizeof(int32_t));
	imrfile.read((char*)&imrheader->lYoffset, sizeof(int32_t));
	imrfile.read((char*)&imrheader->lZoffset, sizeof(int32_t));
	for (int i = 0; i < 354; i++)
	{
		imrfile.read((char*)&imrheader->Reserved[i], sizeof(int8_t));
	}
	//imrfile.close();
}



void read_imr_data(fstream& imrfile, vector<adj_IMR_Record> &adj_data, IMR_Header imr_header)
{

	/*
	*************************************************************************************
	*func:		read_imr_data
	*@Param:	fstream& imrfile 文件类
	*@Param:	vector<adj_IMR_Record> &adj_data 利用vector 存放的校正后imr数据的结构体数组
	*@Param:	IMR_Header imr_header imr数据文件头
	*@Return:
	*@Note:		读取imr数据部分，并通过imr_header 进行校正，通过vector<adj_IMR_Record> &adj_data 返回
	*creator：Jin Huang
	*organization:sdust
	*e-mail:kim.huang.j@qq.com
	*************************************************************************************
	*/
	imrfile.seekg(512, ios::beg);	// 跳过文件头部分
	IMR_Record* imr_data = new IMR_Record;
	adj_IMR_Record* temp_data = new adj_IMR_Record;
	while (!imrfile.eof())
	{
		imrfile.read((char*)imr_data, sizeof(IMR_Record));
		temp_data->Time = imr_data->Time;
		if (!imr_header.bDeltaTheta)	// 对陀螺仪测的的陀螺量加以改正
		{
			temp_data->gx = imr_data->gx * imr_header.dGyroScaleFactor;
			temp_data->gy = imr_data->gy * imr_header.dGyroScaleFactor;
			temp_data->gz = imr_data->gz * imr_header.dGyroScaleFactor;
		}
		else
		{
			temp_data->gx = imr_data->gx * imr_header.dGyroScaleFactor * imr_header.dDataRateHz;
			temp_data->gy = imr_data->gy * imr_header.dGyroScaleFactor * imr_header.dDataRateHz;
			temp_data->gz = imr_data->gz * imr_header.dGyroScaleFactor * imr_header.dDataRateHz;
		}
		if (!imr_header.bDeltaVelocity)
		{
			temp_data->ax = imr_data->ax * imr_header.dAccelScaleFactor;
			temp_data->ay = imr_data->ay * imr_header.dAccelScaleFactor;
			temp_data->az = imr_data->az * imr_header.dAccelScaleFactor;
		}
		else
		{
			temp_data->ax = imr_data->ax * imr_header.dAccelScaleFactor * imr_header.dDataRateHz;
			temp_data->ay = imr_data->ay * imr_header.dAccelScaleFactor * imr_header.dDataRateHz;
			temp_data->az = imr_data->az * imr_header.dAccelScaleFactor * imr_header.dDataRateHz;
		}
		adj_data.push_back(*temp_data);
	}
	imrfile.close();
}
