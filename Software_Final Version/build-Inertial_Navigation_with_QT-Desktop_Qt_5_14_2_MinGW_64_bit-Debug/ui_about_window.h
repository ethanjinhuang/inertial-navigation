/********************************************************************************
** Form generated from reading UI file 'about_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_WINDOW_H
#define UI_ABOUT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about_window
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *about_window)
    {
        if (about_window->objectName().isEmpty())
            about_window->setObjectName(QString::fromUtf8("about_window"));
        about_window->resize(526, 295);
        centralwidget = new QWidget(about_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(centralwidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        about_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(about_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 526, 26));
        about_window->setMenuBar(menubar);
        statusbar = new QStatusBar(about_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        about_window->setStatusBar(statusbar);

        retranslateUi(about_window);

        QMetaObject::connectSlotsByName(about_window);
    } // setupUi

    void retranslateUi(QMainWindow *about_window)
    {
        about_window->setWindowTitle(QCoreApplication::translate("about_window", "Software Info", nullptr));
        label->setText(QCoreApplication::translate("about_window", "Author: HuangJin\n"
"e-mail: 201801020510@sdust.edu.cn\n"
"Org: ShandongUniversity of Science and Technology,\n"
"     College of Geodesy and Geomatics,\n"
"     Geomatics Engineering\357\274\210Marine Surveying and Mapping\357\274\2112018", nullptr));
        label_2->setText(QCoreApplication::translate("about_window", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">Info</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("about_window", "Contact us", nullptr));
        pushButton_2->setText(QCoreApplication::translate("about_window", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about_window: public Ui_about_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_WINDOW_H
