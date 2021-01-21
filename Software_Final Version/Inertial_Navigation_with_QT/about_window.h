#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QMainWindow>

namespace Ui {
class about_window;
}

class about_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit about_window(QWidget *parent = nullptr);
    ~about_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::about_window *ui;
};

#endif // ABOUT_WINDOW_H
