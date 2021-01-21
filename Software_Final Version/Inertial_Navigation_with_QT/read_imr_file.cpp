#include"read_imr_file.h"

void imr_data::read_imr_header(fstream& imrfile, IMR_Header* imrheader)
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

void imr_data::read_imr_data(fstream& imrfile, vector<adj_IMR_Record>& adj_data, IMR_Header imr_header)
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
#ifdef IsCorrect
        if (!imr_header.bDeltaTheta)	// 对陀螺仪测的的陀螺量加以改正--->得到 度/s m/s^2
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
#endif // IsCorrect

#ifndef IsCorrect	// 对陀螺仪测的的陀螺量加以改正--->得到 度 m/s
        if (!imr_header.bDeltaTheta)
        {
            temp_data->gx = (double)imr_data->gx;
            temp_data->gy = (double)imr_data->gy;
            temp_data->gz = (double)imr_data->gz;
        }
        else
        {
            temp_data->gx = imr_data->gx * imr_header.dGyroScaleFactor;
            temp_data->gy = imr_data->gy * imr_header.dGyroScaleFactor;
            temp_data->gz = imr_data->gz * imr_header.dGyroScaleFactor;
        }
        if (!imr_header.bDeltaVelocity)
        {
            temp_data->ax = (double)imr_data->ax;
            temp_data->ay = (double)imr_data->ay;
            temp_data->az = (double)imr_data->az;
        }
        else
        {
            temp_data->ax = imr_data->ax * imr_header.dAccelScaleFactor;
            temp_data->ay = imr_data->ay * imr_header.dAccelScaleFactor;
            temp_data->az = imr_data->az * imr_header.dAccelScaleFactor;
        }
#endif // !IsCorrect

        adj_data.push_back(*temp_data);
    }
    imrfile.close();
}

void imr_data::read_data(char* file_path)
{
    file_header = new IMR_Header;
    fstream imrfile(file_path, ios::in | ios::binary);	// 打开文件
    if (imrfile)
    {
        read_imr_header(imrfile, file_header);	// 读取头文件
        read_imr_data(imrfile, file_data, *file_header);	// 读取数据文件
        std::cout << "Finish Reading, The total data num is: " << file_data.size() << endl;
    }
    else
    {
        cerr << "Open file error!" << endl;
        exit(0);
    }
}

void imr_data::initial()
{
    // 初始化、重置对象
    file_header = new IMR_Header;
    file_data.clear();
}
