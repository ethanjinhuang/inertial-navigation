#include "about_window.h"
#include "ui_about_window.h"
#include <QDesktopServices>
#include <QUrl>

about_window::about_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about_window)
{
    ui->setupUi(this);
}

about_window::~about_window()
{
    delete ui;
}

void about_window::on_pushButton_2_clicked()
{
    this->close();
}

void about_window::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("mailto:201801020510@sdust.edu.cn")));

}
