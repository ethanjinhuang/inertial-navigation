#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionAbout_triggered();

    void on_actionHelp_Document_triggered();

    void on_actionSave_file_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_actionOpen_file_triggered();

    void on_actionSave_Image_triggered();

    void on_actionSave_log_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
