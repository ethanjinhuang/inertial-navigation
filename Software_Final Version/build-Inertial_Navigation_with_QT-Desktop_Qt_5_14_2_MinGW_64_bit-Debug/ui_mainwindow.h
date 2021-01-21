/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionHelp_Document;
    QAction *actionOpen_file;
    QAction *actionSave_file;
    QAction *actionSave_Image;
    QAction *actionSave_log;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QGridLayout *left_gridLayout;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_hei_1;
    QLineEdit *lineEdit_log_1;
    QLineEdit *lineEdit_speed2_u;
    QLabel *label_2;
    QLabel *label_9;
    QLineEdit *lineEdit_hei_2;
    QLineEdit *lineEdit_pitch;
    QLineEdit *lineEdit_lat_2;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_10;
    QLineEdit *lineEdit_log_2;
    QLineEdit *lineEdit_speed1_n;
    QLineEdit *lineEdit_lat_1;
    QLabel *label_7;
    QLineEdit *lineEdit_speed1_e;
    QLineEdit *lineEdit_speed1_u;
    QLabel *label_3;
    QLineEdit *lineEdit_output_interval;
    QLineEdit *lineEdit_roll;
    QLabel *label;
    QLineEdit *lineEdit_heading;
    QLineEdit *lineEdit_speed2_n;
    QLineEdit *lineEdit_total_num;
    QLineEdit *lineEdit_speed2_e;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QGridLayout *gridLayout_3;
    QTableView *logview;
    QChartView *widget;
    QTableView *tableView_result;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1980, 790);
        MainWindow->setDocumentMode(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/about.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout->setIcon(icon);
        actionHelp_Document = new QAction(MainWindow);
        actionHelp_Document->setObjectName(QString::fromUtf8("actionHelp_Document"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/help.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionHelp_Document->setIcon(icon1);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon2);
        actionSave_file = new QAction(MainWindow);
        actionSave_file->setObjectName(QString::fromUtf8("actionSave_file"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_file->setIcon(icon3);
        actionSave_Image = new QAction(MainWindow);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/save_image.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Image->setIcon(icon4);
        actionSave_log = new QAction(MainWindow);
        actionSave_log->setObjectName(QString::fromUtf8("actionSave_log"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/QRibbon/Resource/icon/save_log.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_log->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        left_gridLayout = new QGridLayout();
        left_gridLayout->setObjectName(QString::fromUtf8("left_gridLayout"));
        left_gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        left_gridLayout->addWidget(tableView, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(19);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(0, -1, -1, -1);
        lineEdit_hei_1 = new QLineEdit(centralwidget);
        lineEdit_hei_1->setObjectName(QString::fromUtf8("lineEdit_hei_1"));

        gridLayout->addWidget(lineEdit_hei_1, 5, 2, 1, 1);

        lineEdit_log_1 = new QLineEdit(centralwidget);
        lineEdit_log_1->setObjectName(QString::fromUtf8("lineEdit_log_1"));

        gridLayout->addWidget(lineEdit_log_1, 5, 1, 1, 1);

        lineEdit_speed2_u = new QLineEdit(centralwidget);
        lineEdit_speed2_u->setObjectName(QString::fromUtf8("lineEdit_speed2_u"));

        gridLayout->addWidget(lineEdit_speed2_u, 9, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_9, 7, 0, 1, 3);

        lineEdit_hei_2 = new QLineEdit(centralwidget);
        lineEdit_hei_2->setObjectName(QString::fromUtf8("lineEdit_hei_2"));

        gridLayout->addWidget(lineEdit_hei_2, 6, 2, 1, 1);

        lineEdit_pitch = new QLineEdit(centralwidget);
        lineEdit_pitch->setObjectName(QString::fromUtf8("lineEdit_pitch"));

        gridLayout->addWidget(lineEdit_pitch, 2, 1, 1, 1);

        lineEdit_lat_2 = new QLineEdit(centralwidget);
        lineEdit_lat_2->setObjectName(QString::fromUtf8("lineEdit_lat_2"));

        gridLayout->addWidget(lineEdit_lat_2, 6, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 3);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_8, 4, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_6, 4, 2, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_10, 10, 1, 1, 1);

        lineEdit_log_2 = new QLineEdit(centralwidget);
        lineEdit_log_2->setObjectName(QString::fromUtf8("lineEdit_log_2"));

        gridLayout->addWidget(lineEdit_log_2, 6, 1, 1, 1);

        lineEdit_speed1_n = new QLineEdit(centralwidget);
        lineEdit_speed1_n->setObjectName(QString::fromUtf8("lineEdit_speed1_n"));

        gridLayout->addWidget(lineEdit_speed1_n, 8, 1, 1, 1);

        lineEdit_lat_1 = new QLineEdit(centralwidget);
        lineEdit_lat_1->setObjectName(QString::fromUtf8("lineEdit_lat_1"));

        gridLayout->addWidget(lineEdit_lat_1, 5, 0, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        lineEdit_speed1_e = new QLineEdit(centralwidget);
        lineEdit_speed1_e->setObjectName(QString::fromUtf8("lineEdit_speed1_e"));

        gridLayout->addWidget(lineEdit_speed1_e, 8, 0, 1, 1);

        lineEdit_speed1_u = new QLineEdit(centralwidget);
        lineEdit_speed1_u->setObjectName(QString::fromUtf8("lineEdit_speed1_u"));

        gridLayout->addWidget(lineEdit_speed1_u, 8, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        lineEdit_output_interval = new QLineEdit(centralwidget);
        lineEdit_output_interval->setObjectName(QString::fromUtf8("lineEdit_output_interval"));

        gridLayout->addWidget(lineEdit_output_interval, 11, 1, 1, 1);

        lineEdit_roll = new QLineEdit(centralwidget);
        lineEdit_roll->setObjectName(QString::fromUtf8("lineEdit_roll"));

        gridLayout->addWidget(lineEdit_roll, 2, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_heading = new QLineEdit(centralwidget);
        lineEdit_heading->setObjectName(QString::fromUtf8("lineEdit_heading"));

        gridLayout->addWidget(lineEdit_heading, 2, 0, 1, 1);

        lineEdit_speed2_n = new QLineEdit(centralwidget);
        lineEdit_speed2_n->setObjectName(QString::fromUtf8("lineEdit_speed2_n"));

        gridLayout->addWidget(lineEdit_speed2_n, 9, 1, 1, 1);

        lineEdit_total_num = new QLineEdit(centralwidget);
        lineEdit_total_num->setObjectName(QString::fromUtf8("lineEdit_total_num"));

        gridLayout->addWidget(lineEdit_total_num, 11, 0, 1, 1);

        lineEdit_speed2_e = new QLineEdit(centralwidget);
        lineEdit_speed2_e->setObjectName(QString::fromUtf8("lineEdit_speed2_e"));

        gridLayout->addWidget(lineEdit_speed2_e, 9, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_4, 0, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(145, 40));

        verticalLayout->addWidget(pushButton_5);


        gridLayout->addLayout(verticalLayout, 0, 3, 12, 1);


        left_gridLayout->addLayout(gridLayout, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, left_gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        logview = new QTableView(centralwidget);
        logview->setObjectName(QString::fromUtf8("logview"));

        gridLayout_3->addWidget(logview, 1, 0, 1, 1);

        widget = new QChartView(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(400, 400));

        gridLayout_3->addWidget(widget, 0, 0, 1, 2);

        tableView_result = new QTableView(centralwidget);
        tableView_result->setObjectName(QString::fromUtf8("tableView_result"));

        gridLayout_3->addWidget(tableView_result, 1, 1, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1980, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen_file);
        menu->addAction(actionSave_file);
        menu->addAction(actionSave_Image);
        menu->addAction(actionSave_log);
        menu_2->addSeparator();
        menu_2->addAction(actionAbout);
        menuHelp->addAction(actionHelp_Document);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\203\257\346\200\247\345\257\274\350\210\252\346\225\260\346\215\256\350\247\243\347\256\227\350\275\257\344\273\266_\347\276\216\345\214\226", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionHelp_Document->setText(QCoreApplication::translate("MainWindow", "Help Document", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        actionSave_file->setText(QCoreApplication::translate("MainWindow", "Save file", nullptr));
        actionSave_Image->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        actionSave_log->setText(QCoreApplication::translate("MainWindow", "Save log", nullptr));
        lineEdit_hei_1->setText(QCoreApplication::translate("MainWindow", "87.421", nullptr));
        lineEdit_log_1->setText(QCoreApplication::translate("MainWindow", "120.099196", nullptr));
        lineEdit_speed2_u->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pitching", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Initial Speeds of beginning 2 times</span></p></body></html>", nullptr));
        lineEdit_hei_2->setText(QCoreApplication::translate("MainWindow", "87.421", nullptr));
        lineEdit_pitch->setText(QCoreApplication::translate("MainWindow", "0.4794", nullptr));
        lineEdit_lat_2->setText(QCoreApplication::translate("MainWindow", "36.001542", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Initial Positions of begining 2 times</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Caculate Times", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Output Interval", nullptr));
        lineEdit_log_2->setText(QCoreApplication::translate("MainWindow", "120.099196", nullptr));
        lineEdit_speed1_n->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_lat_1->setText(QCoreApplication::translate("MainWindow", "36.001542", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        lineEdit_speed1_e->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_speed1_u->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rolling", nullptr));
        lineEdit_output_interval->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        lineEdit_roll->setText(QCoreApplication::translate("MainWindow", "-0.6394", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Heading", nullptr));
        lineEdit_heading->setText(QCoreApplication::translate("MainWindow", "172.2331", nullptr));
        lineEdit_speed2_n->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_total_num->setText(QCoreApplication::translate("MainWindow", "36000", nullptr));
        lineEdit_speed2_e->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Initial Angle</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open IMR File", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Save Initial Data", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Show Figure", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Initial alignment", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Initial Software", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Processing progress ", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "Software Info", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
