#include "mainwindow.h"
#include "QtCharts"
QT_CHARTS_USE_NAMESPACE
#include "ui_mainwindow.h"
#include "QtDebug"
#include "QFileDialog"
#include "QMessageBox"
#include "QValidator"
#include "QDateTime"
#include "QDesktopServices"
#include "iostream"
#include "fstream"
#include "iomanip"
#include "vector"
#include "QStandardItemModel"
#include "read_imr_file.h"
#include "updating.h"
#include "public_func.h"
#include "global_variate.h"
#include "coordinate_convert.h"
#include "about_window.h"
#include "QRibbon/QRibbon.h"

// 变量声明
static QStandardItemModel* log_data;    // 定义log_data为全局变量，存放日志文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置icon
    setWindowIcon(QIcon("icon.ico"));
    // 设置 初始姿态 输入范围
    ui->lineEdit_roll->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_pitch->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_heading->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    // 设置 初始两个时刻位置 输入范围
    ui->lineEdit_log_1->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_log_2->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_lat_1->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_lat_2->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_hei_1->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    ui->lineEdit_hei_2->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
    // 设置 初始速度 输入范围
    ui->lineEdit_speed1_e->setValidator(new QDoubleValidator(-1000,1000,6,this));
    ui->lineEdit_speed2_e->setValidator(new QDoubleValidator(-1000,1000,6,this));
    ui->lineEdit_speed1_n->setValidator(new QDoubleValidator(-1000,1000,6,this));
    ui->lineEdit_speed2_n->setValidator(new QDoubleValidator(-1000,1000,6,this));
    ui->lineEdit_speed1_u->setValidator(new QDoubleValidator(-1000,1000,6,this));
    ui->lineEdit_speed2_u->setValidator(new QDoubleValidator(-1000,1000,6,this));
    // 设置 计算范围与间隔
    ui->lineEdit_total_num->setValidator(new QIntValidator(0,1000000,this));
    ui->lineEdit_output_interval->setValidator(new QIntValidator(1,100000,this));


    // 初始化日志功能
    // 创建全局变量，存放log文件
    //QStandardItemModel* log_data;
    log_data = new QStandardItemModel(this);
    ui->logview->setModel(log_data);
    // 设置字段列名
    log_data->setColumnCount(2);
    log_data->setHeaderData(0,Qt::Horizontal,"Time");
    log_data->setHeaderData(1,Qt::Horizontal,"Operation");
    // 设置列宽
    ui->logview->setColumnWidth(0,250);
    ui->logview->setColumnWidth(1,250);

    // 初始化进度条
    ui->progressBar->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 读取imr数据文件
void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"open file...";
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(tr("打开文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    //fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    fileDialog->setNameFilter(tr("imr(*.imr)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if (fileDialog->exec())
    {
      fileNames = fileDialog->selectedFiles();
    }
    QByteArray temp = fileNames[0].toLocal8Bit();
    char* filepath = temp.data();
    //imr_data imrdata;
    imrdata.read_data(filepath);
    QList<QString>fileinfo;
    // 设置输出表格
    QStandardItemModel* model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    // 设置列字段名
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"文件元素");
    model->setHeaderData(1,Qt::Horizontal,"属性");
    // 设置列宽
    ui->tableView->setColumnWidth(0,ui->tableView->width()/2);
    ui->tableView->setColumnWidth(1,ui->tableView->width()/2);
    // 添加数据
    model->setItem(0,0,new QStandardItem(" File path"));
    model->setItem(0,1,new QStandardItem(filepath));
    model->setItem(1,0,new QStandardItem(" Inertial resource manager program version number"));
    model->setItem(1,1,new QStandardItem(QString::number(imrdata.file_header->dVersionNumber)));
    model->setItem(2,0,new QStandardItem(" Calling program name"));
    model->setItem(2,1,new QStandardItem(imrdata.file_header->szProgramName));
    model->setItem(3,0,new QStandardItem(" Number of data"));
    model->setItem(3,1,new QStandardItem(QString::number(imrdata.file_data.size())));
    QString infomation = "Finished Reading IMR File:\n " + fileNames[0];
    QMessageBox::about(NULL, "Info", infomation);
    // 保存文件已读取状态
    process_check.is_imr_read = true;
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Open IMR File"));
    log_data->appendRow(log_info);

}

// 保存初始数据
void MainWindow::on_pushButton_2_clicked()
{
    if (!process_check.is_imr_read)
    {
        QMessageBox::warning(NULL, "Worning", "Please Check Imr File is Loaded!");
        return;
    }

    // 保存初始值
    // 初始方向余弦阵
    Vector3d temp;temp<<deg2rad(ui->lineEdit_heading->text().toDouble()),deg2rad(ui->lineEdit_pitch->text().toDouble()),deg2rad(ui->lineEdit_roll->text().toDouble());
    initial_data.begin_rotation<<temp;
    initial_data.begin_dcm.value = initial_data.begin_rotation.EA2DCM();
    // 前两次采样数据
    Vector3d temp1; temp1 << deg2rad(imrdata.file_data[1].gx), deg2rad(imrdata.file_data[1].gy), deg2rad(imrdata.file_data[1].gz);	// m-1
    Vector3d temp2; temp2 << deg2rad(imrdata.file_data[2].gx), deg2rad(imrdata.file_data[2].gy), deg2rad(imrdata.file_data[2].gz);	// m
    initial_data.delta_theta.push_back(temp1);initial_data.delta_theta.push_back(temp2);
    // 初始化存放m-2,m-1时刻的速度与vector[1], vecotr[0]
    temp1<<ui->lineEdit_speed1_e->text().toDouble(),ui->lineEdit_speed1_n->text().toDouble(),ui->lineEdit_speed1_u->text().toDouble();
    temp1<<ui->lineEdit_speed2_e->text().toDouble(),ui->lineEdit_speed2_n->text().toDouble(),ui->lineEdit_speed2_u->text().toDouble();
    initial_data.speed.push_back(temp1); initial_data.speed.push_back(temp2);
    // m -1， m-2 时刻的位置数据
    // 位置的格式为 L B H 纬度 经度 大地高
    temp1<<ui->lineEdit_lat_1->text().toDouble(),ui->lineEdit_log_1->text().toDouble(),ui->lineEdit_hei_1->text().toDouble();
    temp2<<ui->lineEdit_lat_2->text().toDouble(),ui->lineEdit_log_2->text().toDouble(),ui->lineEdit_hei_2->text().toDouble();
    initial_data.position.push_back(temp1), initial_data.position.push_back(temp2);
    //存放m , m - 1时刻的速度变化量数据于vector[1], vector[0]
    temp1 << imrdata.file_data[1].ax, imrdata.file_data[1].ay, imrdata.file_data[1].az;	// m-2
    temp2 << imrdata.file_data[2].ax, imrdata.file_data[2].ay, imrdata.file_data[2].az;	// m-1
    initial_data.velocity.push_back(temp1); initial_data.velocity.push_back(temp2);
    // 存放采样周期
    initial_data.T = imrdata.file_header[0].dDataRateHz;
    QMessageBox::about(NULL, "Info", "Success Save Initial Data!");
    process_check.is_initial_data = true;   // 保存初始值已赋值状态
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Save Initial Data"));
    log_data->appendRow(log_info);

}

void MainWindow::on_pushButton_3_clicked()
{
    if (!process_check.is_imr_read||!process_check.is_initial_data)
    {
        QMessageBox::warning(NULL, "Worning", "Please Check Imr File is Loaded or Initial data!");
        return;
    }
    // 计算时间 与 输出间隔
    int total_num = ui->lineEdit_total_num->text().toInt();
    int output_interval = ui->lineEdit_output_interval->text().toInt();
    // 开始计算
    // 计算第一次
    class update update_process(initial_data.begin_dcm,initial_data.speed,
                          initial_data.delta_theta,initial_data.position,
                                initial_data.velocity,2.0/initial_data.T);
    update_process.attitude_update();
    update_process.speed_update();
    update_process.position_update();
    double L = update_process.position_data[1].position(0);
    double B = update_process.position_data[1].position(1);
    double H = update_process.position_data[1].position(2);
    Vector3d BLH,XYZ;
    BLH << B, L, H;
    XYZ = gcs2gc(BLH);
    //std::cout << std::setprecision(12) << XYZ[0] << std::endl << XYZ[1] << std::endl << XYZ[2] << std::endl << std::endl;

    //===================================输出====================================
    // 设置输出到表格
    QStandardItemModel* model = new QStandardItemModel(this);
    ui->tableView_result->setModel(model);
    // 设置字段名
    model->setColumnCount(3);   // 三列分别为XYZ
    model->setHeaderData(0,Qt::Horizontal,"X");
    model->setHeaderData(1,Qt::Horizontal,"Y");
    model->setHeaderData(2,Qt::Horizontal,"Z");
    // 设置列宽
    ui->tableView_result->setColumnWidth(0,180);
    ui->tableView_result->setColumnWidth(1,180);
    ui->tableView_result->setColumnWidth(2,180);
    // 添加数据
    model->setItem(0,0,new QStandardItem(QString::number(XYZ[0],'f',6)));
    model->setItem(0,1,new QStandardItem(QString::number(XYZ[1],'f',6)));
    model->setItem(0,2,new QStandardItem(QString::number(XYZ[2],'f',6)));
    // ==========================================================================

    // 计算第二次
    // 初始方向余弦阵
    initial_data.begin_dcm = update_process.attitude_data.Cnb_m;
    // m,m-1 次采样delta数据
    Vector3d temp1;temp1 << deg2rad(imrdata.file_data[2].gx), deg2rad(imrdata.file_data[2].gy), deg2rad(imrdata.file_data[2].gz);	// m-1
    Vector3d temp2; temp2 << deg2rad(imrdata.file_data[3].gx), deg2rad(imrdata.file_data[3].gy), deg2rad(imrdata.file_data[3].gz);	// m
    initial_data.delta_theta.clear(); initial_data.delta_theta.push_back(temp1); initial_data.delta_theta.push_back(temp2);
    // 初始化存放m-2,m-1时刻的速度与vector[1], vecotr[0]
    temp1 = update_process.speed_data[1].v_nem;	// m-2
    temp2 = update_process.speed_data[2].v_nem;	// m-1
    initial_data.speed.clear(); initial_data.speed.push_back(temp1); initial_data.speed.push_back(temp2);
    // m -1， m-2 时刻的位置数据
    temp1 << 36 + 5.55256 / 3600, 120 + 5.0 / 60 + 57.10715 / 3600, 87.421;	// m-2
    temp2 = update_process.position_data[1].position;	// m-1
    initial_data.position.clear(); initial_data.position.push_back(temp1), initial_data.position.push_back(temp2);

    //存放m , m - 1时刻的速度变化量数据于vector[1], vector[0]
    temp1 << imrdata.file_data[2].ax, imrdata.file_data[2].ay, imrdata.file_data[2].az;	// m-1
    temp2 << imrdata.file_data[3].ax, imrdata.file_data[3].ay, imrdata.file_data[3].az;	// m
    initial_data.velocity.clear(); initial_data.velocity.push_back(temp1); initial_data.velocity.push_back(temp2);
    // 存放采样周期
    initial_data.T = imrdata.file_header[0].dDataRateHz;

    // ===============================================================================================
    update_process.initialize(initial_data.begin_dcm, initial_data.speed, initial_data.delta_theta,
                              initial_data.position, initial_data.velocity, 2.0 / initial_data.T);
    update_process.attitude_update();
    update_process.speed_update();
    update_process.position_update();
    int data_table_num = 1;    // 设置显示表格的初始位置，进行累加
    // 循环计算
    ui->label_12->setText("Processing Progress ");
    ui->progressBar->setRange(0,total_num-1);
    for (int i = 4; i <= total_num; i++)
        {
            // 更新初始方向余弦阵
            initial_data.begin_dcm = update_process.attitude_data.Cnb_m;
            // m,m-1 次采样delta数据
            //temp1 << data.file_data[i-1].gx, data.file_data[i-1].gy, data.file_data[i-1].gz;	// m-1
            //temp2 << data.file_data[i].gx, data.file_data[i].gy, data.file_data[i].gz;			// m
            temp1 << deg2rad(imrdata.file_data[i - 1].gx), deg2rad(imrdata.file_data[i - 1].gy), deg2rad(imrdata.file_data[i - 1].gz);	// m-1
            temp2 << deg2rad(imrdata.file_data[i].gx), deg2rad(imrdata.file_data[i].gy), deg2rad(imrdata.file_data[i].gz);	// m
            initial_data.delta_theta.clear(); initial_data.delta_theta.push_back(temp1); initial_data.delta_theta.push_back(temp2);
            // 初始化存放m-2,m-1时刻的速度与vector[1], vecotr[0]
            temp1 = update_process.speed_data[1].v_nem;	// m-2
            temp2 = update_process.speed_data[2].v_nem;	// m-1
            initial_data.speed.clear(); initial_data.speed.push_back(temp1); initial_data.speed.push_back(temp2);
            // m -1， m-2 时刻的位置数据
            temp1 = update_process.position_data[0].position;	// m-2
            temp2 = update_process.position_data[1].position;	// m-1
            initial_data.position.clear(); initial_data.position.push_back(temp1), initial_data.position.push_back(temp2);
            //存放m , m - 1时刻的速度变化量数据于vector[1], vector[0]
            temp1 << imrdata.file_data[i - 1].ax, imrdata.file_data[i - 1].ay, imrdata.file_data[i - 1].az;	// m-1
            temp2 << imrdata.file_data[i].ax, imrdata.file_data[i].ay, imrdata.file_data[i].az;			// m
            initial_data.velocity.clear(); initial_data.velocity.push_back(temp1); initial_data.velocity.push_back(temp2);
            // 存放采样周期
           initial_data. T = imrdata.file_header[0].dDataRateHz;

            // ===============================================================================================
            update_process.initialize(initial_data.begin_dcm, initial_data.speed, initial_data.delta_theta,
                                      initial_data.position, initial_data.velocity, 2.0 / initial_data.T);
            update_process.attitude_update();
            update_process.speed_update();
            update_process.position_update();
            // ===============================================================================================
            Euler_angle ea;
            L = update_process.position_data[1].position(0);
            B = update_process.position_data[1].position(1);
            H = update_process.position_data[1].position(2);
            BLH << B, L, H;
            XYZ = gcs2gc(BLH);
            final_position.push_back(XYZ);
            if (i % output_interval == 0)
            {
                // 在表格中添加数据
                model->setItem(data_table_num,0,new QStandardItem(QString::number(XYZ[0],'f',6)));
                model->setItem(data_table_num,1,new QStandardItem(QString::number(XYZ[1],'f',6)));
                model->setItem(data_table_num,2,new QStandardItem(QString::number(XYZ[2],'f',6)));
                // 累加
                data_table_num ++;
            }
            ui->progressBar->setValue(i);
        }
    process_check.is_data_caculation = true;
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Data Caculation"));
    log_data->appendRow(log_info);
}

// 图表显示
void MainWindow::on_pushButton_4_clicked()
{
    if(!process_check.is_load_data)
    {
        if ((!process_check.is_imr_read||!process_check.is_initial_data||!process_check.is_data_caculation))
        {
            QMessageBox::warning(NULL, "Worning", "Please Check Imr File is Loaded, Initial data or Data cacualtion!");
            return;
        }
    }
    QChart* chart = new QChart();
    // 绘制X轴变化
    QLineSeries *series_x = new QLineSeries();
    vector<double>xerror;
    for (quint32 i = 0; i < final_position.size(); i++)
    {
        series_x->append(i, final_position[i](0)-final_position[0](0));
        xerror.push_back(final_position[i](0)-final_position[0](0));
    }
    series_x->setName("X errors");
    chart->addSeries(series_x);
    // 绘制Y轴变化
    QLineSeries *series_y = new QLineSeries();
    vector<double>yerror;
    for (quint32 i = 0; i < final_position.size(); i++)
    {
        series_y->append(i, final_position[i](1)-final_position[0](1));
        yerror.push_back(final_position[i](1)-final_position[0](1));
    }
    series_y->setName("Y errors");
    chart->addSeries(series_y);
    // 绘制Z轴变化
    QLineSeries *series_z = new QLineSeries();
    vector<double>zerror;
    for (quint32 i = 0; i < final_position.size(); i++)
    {
        series_z->append(i, final_position[i](2)-final_position[0](2));
        zerror.push_back(final_position[i](2)-final_position[0](2));
    }
    series_z->setName("Z errors");
    chart->addSeries(series_z);
    // 设置标题
    chart->setTitle("XYZ Errors");
    // 设置坐标轴 label
    QValueAxis* axisX = new QValueAxis;
    axisX->setTitleText("Times per 0.02 sec");
    axisX->setRange(0,ui->lineEdit_total_num->text().toInt());
    QValueAxis* axisY = new QValueAxis;
    axisY->setTitleText("Error with initial position (m)");
    axisY->setRange(chart_axis_min(xerror,yerror,zerror),chart_axis_max(xerror,yerror,zerror));
    // 为序列设置坐标轴
    chart->setAxisX(axisX,series_x);chart->setAxisX(axisX,series_y);chart->setAxisX(axisX,series_z);
    chart->setAxisY(axisY,series_x);chart->setAxisY(axisY,series_y);chart->setAxisY(axisY,series_z);
    //chart->createDefaultAxes();  // 基于已添加到图表的 series 来创建默认的坐标轴
    ui->widget->setChart(chart); // 将图表绑定到视图
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Show Figure"));
    log_data->appendRow(log_info);
}

void MainWindow::on_actionAbout_triggered()
{
    about_window *aboutwindow = new about_window(this);
    aboutwindow->show();
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Show About"));
    log_data->appendRow(log_info);
}

void MainWindow::on_actionHelp_Document_triggered()
{
    QDesktopServices::openUrl(QUrl("D:/Gitee/InertialNavigation_CurriculumDesign/HuangJin/Help_doc/Help.md"));
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Open help document"));
    log_data->appendRow(log_info);
}

void MainWindow::on_actionSave_file_triggered()
{
    // 保存计算结果到文件
    if (!process_check.is_data_caculation)
    {
        QMessageBox::warning(NULL, "Worning", "Only clicke after the result been cacualted");
        return;
    }
    QList<QStandardItem*>log_info;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Open File"),"",tr("Position Data Files (*.txt)"));
    if (!fileName.isNull())
    {
        fstream file(fileName.toStdString(),std::ios::out|std::ios::trunc);
        if(!file.is_open())
        {
            QMessageBox::warning(NULL, "Worning", "Thie file Open failed.");
            return;
        }
        int data_num = final_position.size();
        file.fill(0);
        file.flags(ios::left|ios::fixed);
        for(int i=0;i<data_num;i++)
        {
            file.width(14);
            file<<final_position[i][0]<<"\t"<<final_position[i][1]<<"\t"<<final_position[i][2]<<setprecision(8)<<endl;
        }
        file.close();
        log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Successful saving to file"));
        log_data->appendRow(log_info);
    }
    else
    {
        log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Cancel saving to file"));
        log_data->appendRow(log_info);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    // 复原函数，避免修改参数需要重新打开程序
    // 新增初始状态
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Start Initial"));
    log_data->appendRow(log_info);
    // 重置读取文件
    process_check.is_imr_read = false;
    imrdata.initial();
    log_info.clear();
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("IMR File Initial"));
    log_data->appendRow(log_info);
    // 重置初始数据
    initial_data.begin_rotation.initialize();   //
    initial_data.begin_dcm.initialize();        // 初始方向余弦阵
    initial_data.delta_theta.clear();           // 前两次采样数据
    initial_data.speed.clear();                 // 前两时刻的速度
    initial_data.position.clear();              // 前两时刻的位置数据
    initial_data.velocity.clear();              // 前两时刻的速度变化量
    process_check.is_initial_data = false;
    log_info.clear();
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Initial Data Initial"));
    log_data->appendRow(log_info);
    // 重置计算函数
    final_position.clear(); // 清空结果
    process_check.is_data_caculation = false;
    process_check.is_load_data = false; // 将读取自文件的数据也同样清除
    log_info.clear();
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Simulation Position Initial"));
    log_data->appendRow(log_info);
    // 重置进度条
    ui->progressBar->setValue(0);
    // 重置文件显示
    QStandardItemModel* model1 = new QStandardItemModel(this);
    ui->tableView->setModel(model1);
    model1->setColumnCount(2);
    model1->setHeaderData(0,Qt::Horizontal,"文件元素");
    model1->setHeaderData(1,Qt::Horizontal,"属性");
    // 重置结果显示
    QStandardItemModel* model2 = new QStandardItemModel(this);
    ui->tableView_result->setModel(model2);
    model2->setColumnCount(3);   // 三列分别为XYZ
    model2->setHeaderData(0,Qt::Horizontal,"X");
    model2->setHeaderData(1,Qt::Horizontal,"Y");
    model2->setHeaderData(2,Qt::Horizontal,"Z");
    // 重置图表
    QChart* chart = new QChart();
    ui->widget->setChart(chart);

}

void MainWindow::on_pushButton_6_clicked()
{
    if (!process_check.is_imr_read||!process_check.is_initial_data)
    {
        QMessageBox::warning(NULL, "Worning", "Please load the IMR data and Initial data");
        return;
    }
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Initial alignment"));
    log_data->appendRow(log_info);
    QMessageBox::about(NULL, "Info", "Successful Initial alignment");
}

void MainWindow::on_actionOpen_file_triggered()
{
    // 读取已经存取的数据，显示展示
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Open data file"));
    log_data->appendRow(log_info);
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Position Data Files (*.txt)"));
    if (!fileName.isNull())
    {
        // 打开文件
        fstream file(fileName.toStdString(),std::ios::in);
        if(!file.is_open())
        {
            QMessageBox::warning(NULL, "Worning", "Thie file Open failed.");
            return;
        }
        double x,y,z;
        vector<Vector3d> position;
        Vector3d temp;
        while(!file.eof())
        {
            file>>x>>y>>z;
            temp<<x,y,z;
            position.push_back(temp);
        }

        // 显示位置坐标
        // 设置输出到表格
        QStandardItemModel* model = new QStandardItemModel(this);
        ui->tableView_result->setModel(model);
        // 设置字段名
        model->setColumnCount(3);   // 三列分别为XYZ
        model->setHeaderData(0,Qt::Horizontal,"X");
        model->setHeaderData(1,Qt::Horizontal,"Y");
        model->setHeaderData(2,Qt::Horizontal,"Z");
        // 设置列宽
        ui->tableView_result->setColumnWidth(0,180);
        ui->tableView_result->setColumnWidth(1,180);
        ui->tableView_result->setColumnWidth(2,180);

        int data_table_num = 0;    // 设置显示表格的初始位置，进行累加
        int total_data = position.size();
        ui->label_12->setText("Loading Position Data");
        ui->progressBar->setRange(0,total_data-1);
        for(int i =0;i<total_data-1;i++)
        {
            model->setItem(data_table_num,0,new QStandardItem(QString::number(position[i][0],'f',6)));
            model->setItem(data_table_num,1,new QStandardItem(QString::number(position[i][1],'f',6)));
            model->setItem(data_table_num,2,new QStandardItem(QString::number(position[i][2],'f',6)));
            data_table_num++;
            ui->progressBar->setValue(i+1);
        }
        log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Successfully open data file"));
        log_data->appendRow(log_info);
        QString information = "Successful load "+fileName;
        QMessageBox::about(NULL, "Open File",information);
        // 将数据保存于全局变量中，便于绘图
        final_position.clear();
        final_position = position;

        process_check.is_load_data = true;
    }
    else
    {
        log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Cancel open data file"));
        log_data->appendRow(log_info);
    }
}

void MainWindow::on_actionSave_Image_triggered()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("保存图像"));
    fileDialog->setDirectory(".");
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString fileName;
    if (fileDialog->exec())
    {
        fileName = fileDialog->selectedFiles()[0];
    }
    qDebug()<<fileName;
    if(fileName.size()>0)
    {
        QScreen * screen = QGuiApplication::primaryScreen();
        QPixmap p = screen->grabWindow(ui->widget->winId());
        QImage image = p.toImage();
        image.save(fileName);
    }
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Save Image"));
    log_data->appendRow(log_info);
}


void MainWindow::on_actionSave_log_triggered()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("保存日志"));
    fileDialog->setDirectory(".");
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setNameFilter(tr("txt(*.txt)"));
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString fileName;
    if (fileDialog->exec())
    {
        fileName = fileDialog->selectedFiles()[0];
    }
    QFile file(fileName);
    QString str;
    if (file.open(QFile::WriteOnly|QFile::Text))
    {
        QTextStream out(&file);
        QTableView* Qv=ui->logview;
        for(int i=0;i<Qv->model()->columnCount();i++)
        {
            out<<Qv->model()->headerData(i,Qt::Horizontal).toString()<<"\t\t\t";
        }
        out<<"\n";
        for(int i=0;i<Qv->model()->rowCount();i++)
        {
            QString str="";
            for(int j=0;j<Qv->model()->columnCount();j++)
            {
                str += (Qv->model()->data(Qv->model()->index(i,j)).toString()+"\t");
            }
            out<<(str+"\n");
        }

    }
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Save Log"));
    log_data->appendRow(log_info);
}

void MainWindow::on_actionChange_Skin_triggered()
{
    QRibbon::install(this);
    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(193, 210, 240)}");
    this->show();
    QList<QStandardItem*>log_info;
    log_info.append(new QStandardItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));log_info.append(new QStandardItem("Change Skin"));
    log_data->appendRow(log_info);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QMainWindow::paintEvent(e);
}
