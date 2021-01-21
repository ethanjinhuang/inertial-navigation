/********************************************************************************
** Form generated from reading UI file 'qribbon.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRIBBON_H
#define UI_QRIBBON_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRibbon
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widgetContainer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTitleBar;
    QLabel *labelTitle;
    QPushButton *pushButtonStyle;
    QPushButton *pushButtonMinimum;
    QPushButton *pushButtonFullScreen;
    QPushButton *pushButtonClose;
    QGridLayout *gridLayout;
    QWidget *widgetMenuBar_2;
    QPushButton *pushButtonMaxTab;
    QTabWidget *tabWidgetMenuBar;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QFrame *line;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QToolButton *toolButton_8;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *widgetMenuBar;
    QPushButton *pushButtonMinimizeTab;
    QWidget *widgetBottomBar;

    void setupUi(QMenuBar *QRibbon)
    {
        if (QRibbon->objectName().isEmpty())
            QRibbon->setObjectName(QString::fromUtf8("QRibbon"));
        QRibbon->resize(994, 146);
        QRibbon->setMinimumSize(QSize(0, 146));
        QRibbon->setMaximumSize(QSize(16777215, 16777215));
        QRibbon->setWindowOpacity(1.000000000000000);
        QRibbon->setLayoutDirection(Qt::LeftToRight);
        QRibbon->setAutoFillBackground(false);
        QRibbon->setStyleSheet(QString::fromUtf8(""));
        QRibbon->setDefaultUp(false);
        QRibbon->setNativeMenuBar(false);
        horizontalLayout_3 = new QHBoxLayout(QRibbon);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widgetContainer = new QWidget(QRibbon);
        widgetContainer->setObjectName(QString::fromUtf8("widgetContainer"));
        widgetContainer->setMinimumSize(QSize(0, 161));
        widgetContainer->setAutoFillBackground(false);
        widgetContainer->setStyleSheet(QString::fromUtf8("QProgressIndicator {\n"
"  qproperty-color: rgb(2, 65, 132);\n"
"}\n"
"\n"
"\n"
"QToolTip {\n"
"  border: 1px solid rgb(255,255,255);\n"
"  background: white;\n"
"  color: rgb(51, 51, 51);\n"
"}\n"
"\n"
"/**********\350\217\234\345\215\225\346\240\217**********/\n"
"QMenuBar {\n"
"  background: rgb(255,255,255);\n"
"  border: 1px solid rgb(255,255,255);\n"
"  border-left: none;\n"
"  border-right: none;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"  border: 1px solid transparent;\n"
"  padding: 5px 10px 5px 10px;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:enabled {\n"
"  color: rgb(2, 65, 132);\n"
"}\n"
"\n"
"QMenuBar::item:!enabled {\n"
"  color: rgb(155, 155, 155);\n"
"}\n"
"\n"
"QMenuBar::item:enabled:selected {\n"
"  border-top-color: rgb(255,255,255);\n"
"  border-bottom-color: rgb(255,255,255);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"/**********\350\217\234\345\215\225**********/\n"
"QMenu {\n"
"  border: 1px solid rgb(255,255,255);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"Q"
                        "Menu::item:enabled {\n"
"  color: rgb(84, 84, 84);\n"
"}\n"
"\n"
"QMenu::item:!enabled {\n"
"  color: rgb(155, 155, 155);\n"
"}\n"
"\n"
"QMenu::item:enabled:selected {\n"
"  color: rgb(2, 65, 132);\n"
"  background: rgba(255, 255, 255, 200);\n"
"}\n"
"\n"
"QMenu::separator {\n"
"  height: 1px;\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"/**********\347\212\266\346\200\201\346\240\217**********/\n"
"QStatusBar {\n"
"  background: rgb(255,255,255);\n"
"  border: 1px solid rgb(255,255,255);\n"
"  border-left: none;\n"
"  border-right: none;\n"
"  border-bottom: none;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"  border: none;\n"
"  border-right: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"/**********\345\210\206\347\273\204\346\241\206**********/\n"
"QGroupBox {\n"
"  font-size: 15px;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  border-radius: 4px;\n"
"  margin-top: 14px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"  color: rgb(56, 99, 154);\n"
"  top: -12px;\n"
"  left: 10px;\n"
"}\n"
"\n"
"QHeaderView {\n"
"  border"
                        ": none;\n"
"  border-bottom: 2px solid rgb(43,87,154);\n"
"  background: transparent;\n"
"  min-height: 30px;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal {\n"
"  border: none;\n"
"  color: rgb(2, 65, 132);\n"
"  background: transparent;\n"
"  padding-left: 5px;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal:hover {\n"
"  color: white;\n"
"  background: rgb(0, 78, 161);\n"
"}\n"
"\n"
"QHeaderView::section:horizontal:pressed {\n"
"  color: white;\n"
"  background: rgb(6, 94, 187);\n"
"}\n"
"\n"
"QHeaderView::section:!first {\n"
"  border-left: 1px solid rgba(0, 78, 161, 100);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"  width: 13px;\n"
"  height: 11px;\n"
"  padding-right: 5px;\n"
"  image: url(:/White/topArrow);\n"
"  subcontrol-position: center right;\n"
"}\n"
"\n"
"QHeaderView::up-arrow:hover,\n"
"QHeaderView::up-arrow:pressed {\n"
"  image: url(:/White/topArrowHover);\n"
"}\n"
"\n"
"QHeaderView::down-arrow {\n"
"  width: 13px;\n"
"  height: 11px;\n"
"  padding-right: 5px;\n"
"  image: url(:/White/bottomAr"
                        "row);\n"
"  subcontrol-position: center right;\n"
"}\n"
"\n"
"QHeaderView::down-arrow:hover,\n"
"QHeaderView::down-arrow:pressed {\n"
"  image: url(:/White/bottomArrowHover);\n"
"}\n"
"\n"
"QTableView {\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: rgb(255,255,255);\n"
"  gridline-color: lightgray;\n"
"}\n"
"\n"
"QTableView::item {\n"
"  padding-left: 5px;\n"
"  padding-right: 5px;\n"
"  border: none;\n"
"  background: white;\n"
"  border-right: 1px solid rgb(255,255,255);\n"
"  border-bottom: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"  color: rgba(0, 0, 0, 255);\n"
"  background: rgba(255, 255, 255, 100);\n"
"}\n"
"\n"
"QTableView::item:selected:!active {\n"
"  color: rgb(65, 65, 65);\n"
"}\n"
"\n"
"QTableView::indicator {\n"
"  width: 20px;\n"
"  height: 20px;\n"
"}\n"
"\n"
"QTableView::indicator:enabled:unchecked {\n"
"  image: url(:/White/checkBox);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:unchecked:hover {\n"
"  image: url(:/White/checkBox);\n"
"}\n"
"/*QTa"
                        "bleView::indicator:enabled:unchecked:pressed {\n"
"        image: url(:/White/checkBoxPressed);\n"
"}*/\n"
"QTableView::indicator:enabled:checked {\n"
"  image: url(:/White/checkBoxChecked);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:checked:hover {\n"
"  image: url(:/White/checkBoxChecked);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:checked:pressed {\n"
"  image: url(:/White/checkBoxCheckedPressed);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:indeterminate {\n"
"  image: url(:/White/checkBoxIndeterminate);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:indeterminate:hover {\n"
"  image: url(:/White/checkBoxIndeterminateHover);\n"
"}\n"
"\n"
"QTableView::indicator:enabled:indeterminate:pressed {\n"
"  image: url(:/White/checkBoxIndeterminatePressed);\n"
"}\n"
"\n"
"/**********\346\273\232\345\212\250\346\235\241-\346\260\264\345\271\263**********/\n"
"QScrollBar:horizontal {\n"
"  height: 20px;\n"
"  background: transparent;\n"
"  margin-top: 3px;\n"
"  margin-bottom: 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:"
                        "horizontal {\n"
"  height: 20px;\n"
"  min-width: 30px;\n"
"  background: rgb(165, 195, 225);\n"
"  margin-left: 15px;\n"
"  margin-right: 15px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"  background: rgb(165, 195, 225);\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"  width: 15px;\n"
"  background: transparent;\n"
"  image: url(:/White/arrowLeft);\n"
"  subcontrol-position: left;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"  width: 15px;\n"
"  background: transparent;\n"
"  image: url(:/White/arrowRight);\n"
"  subcontrol-position: right;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover {\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover {\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"  background: transparent;\n"
"}\n"
"\n"
"/**********\346\273\232\345\212\250\346\235\241-\345\236\202\347\233\264**********/\n"
"QScrollBar:vertical {\n"
"  width: 20px;\n"
"  "
                        "background: transparent;\n"
"  margin-left: 3px;\n"
"  margin-right: 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"  width: 20px;\n"
"  min-height: 30px;\n"
"  background: rgb(165, 195, 225);\n"
"  margin-top: 15px;\n"
"  margin-bottom: 15px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"  background: rgb(165, 195, 225);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"  height: 15px;\n"
"  background: transparent;\n"
"  image: url(:/White/topArrow);\n"
"  subcontrol-position: top;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"  height: 15px;\n"
"  background: transparent;\n"
"  image: url(:/White/bottomArrow);\n"
"  subcontrol-position: bottom;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover {\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover {\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"  background: transparent;\n"
"}\n"
"\n"
"QScrollBar#verticalScrollBar:vertical {\n"
""
                        "  margin-top: 30px;\n"
"}\n"
"\n"
"/**********\344\270\213\346\213\211\345\210\227\350\241\250**********/\n"
"QComboBox {\n"
"  height: 25px;\n"
"  border-radius: 4px;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: transparent;\n"
"}\n"
"\n"
"QComboBox:enabled {\n"
"  color: rgb(84, 84, 84);\n"
"}\n"
"\n"
"QComboBox:!enabled {\n"
"  color: rgb(80, 80, 80);\n"
"}\n"
"\n"
"QComboBox:enabled:hover,\n"
"QComboBox:enabled:focus {\n"
"  color: rgb(51, 51, 51);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"  width: 20px;\n"
"  border: none;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QComboBox::drop-down:hover {\n"
"  background: rgba(255, 255, 255, 30);\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"  width: 10px;\n"
"  height: 10px;\n"
"  image: url(:/White/arrowBottom);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on {\n"
"  /**top: 1px;**/\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  border: 1px solid rgb(255,255,255);\n"
"  background: white;\n"
"  outline: none;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::it"
                        "em {\n"
"  height: 25px;\n"
"  color: rgb(73, 73, 73);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:selected {\n"
"  background: rgb(255,255,255);\n"
"  color: rgb(2, 65, 132);\n"
"}\n"
"\n"
"/**********\350\277\233\345\272\246\346\235\241**********/\n"
"QProgressBar {\n"
"  border: none;\n"
"  text-align: center;\n"
"  color: white;\n"
"  background: rgb(173, 202, 232);\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"  background: rgb(16, 135, 209);\n"
"}\n"
"\n"
"QProgressBar {\n"
"  border: none;\n"
"  text-align: center;\n"
"  color: white;\n"
"  background-color: transparent;\n"
"  background-image: url(\":/White/progressBar\");\n"
"  background-repeat: repeat-x;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"  border: none;\n"
"  background-color: transparent;\n"
"  background-image: url(\":/White/progressBarChunk\");\n"
"  background-repeat: repeat-x;\n"
"}\n"
"\n"
"/**********\345\244\215\351\200\211\346\241\206**********/\n"
"QCheckBox {\n"
"  spacing: 5px;\n"
"}\n"
"\n"
"QCheckBox:enabled:checked {\n"
"  colo"
                        "r: rgb(2, 65, 132);\n"
"}\n"
"\n"
"QCheckBox:enabled:!checked {\n"
"  color: rgb(70, 71, 73);\n"
"}\n"
"\n"
"QCheckBox:enabled:hover {\n"
"  color: rgb(0, 78, 161);\n"
"}\n"
"\n"
"QCheckBox:!enabled {\n"
"  color: rgb(80, 80, 80);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"  width: 20px;\n"
"  height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/White/checkBox);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"  image: url(:/White/checkBox);\n"
"}\n"
"/*QCheckBox::indicator:unchecked:pressed {\n"
"        image: url(:/White/checkBoxPressed);\n"
"}*/\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/White/checkBoxChecked);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover {\n"
"  image: url(:/White/checkBoxChecked);\n"
"}\n"
"/*QCheckBox::indicator:checked:pressed {\n"
"        image: url(:/White/checkBoxCheckedPressed);\n"
"}\n"
"QCheckBox::indicator:indeterminate {\n"
"        image: url(:/White/checkBoxIndeterminate);\n"
"}*/\n"
"/*QCheckBox::indicator:indeterminate:ho"
                        "ver {\n"
"        image: url(:/White/checkBoxIndeterminateHover);\n"
"}*/\n"
"/*QCheckBox::indicator:indeterminate:pressed {\n"
"        image: url(:/White/checkBoxIndeterminatePressed);\n"
"}*/\n"
"\n"
"/**********\345\215\225\351\200\211\346\241\206**********/\n"
"QRadioButton {\n"
"  spacing: 5px;\n"
"}\n"
"\n"
"QRadioButton:enabled:checked {\n"
"  color: rgb(2, 65, 132);\n"
"}\n"
"\n"
"QRadioButton:enabled:!checked {\n"
"  color: rgb(70, 71, 73);\n"
"}\n"
"\n"
"QRadioButton:enabled:hover {\n"
"  color: rgb(0, 78, 161);\n"
"}\n"
"\n"
"QRadioButton:!enabled {\n"
"  color: rgb(80, 80, 80);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"  width: 20px;\n"
"  height: 20px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"  image: url(:/White/radioButton);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"  image: url(:/White/radioButton);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"  image: url(:/White/radioButton);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"  image: u"
                        "rl(:/White/radioButtonChecked);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"  image: url(:/White/radioButtonChecked);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"  image: url(:/White/radioButtonChecked);\n"
"}\n"
"\n"
"/**********\350\276\223\345\205\245\346\241\206**********/\n"
"QLineEdit {\n"
"  border-radius: 4px;\n"
"  height: 25px;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: white;\n"
"}\n"
"\n"
"QLineEdit:enabled {\n"
"  color: rgb(84, 84, 84);\n"
"}\n"
"\n"
"QLineEdit:enabled:hover,\n"
"QLineEdit:enabled:focus {\n"
"  color: rgb(51, 51, 51);\n"
"}\n"
"\n"
"QLineEdit:!enabled {\n"
"  color: rgb(80, 80, 80);\n"
"}\n"
"\n"
"/**********\346\226\207\346\234\254\347\274\226\350\276\221\346\241\206**********/\n"
"QTextEdit {\n"
"  border: 1px solid rgb(43,87,154);\n"
"  color: rgb(70, 71, 73);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"/**********\346\273\232\345\212\250\345\214\272\345\237\237**********/\n"
"QScrollArea {\n"
"  border: 1px solid rgb(43,87"
                        ",154);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"\n"
"/**********\345\276\256\350\260\203\345\231\250**********/\n"
"QSpinBox,\n"
"QDoubleSpinBox {\n"
"  border-radius: 4px;\n"
"  min-height: 24px;\n"
"  min-width: 40px;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: white;\n"
"}\n"
"\n"
"QSpinBox:enabled,\n"
"QDoubleSpinBox:enabled {\n"
"  color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"QSpinBox:enabled:hover,\n"
"QSpinBox:enabled:focus {\n"
"  color: rgb(51, 51, 51);\n"
"}\n"
"\n"
"QSpinBox:!enabled,\n"
"QDoubleSpinBox:!enabled {\n"
"  color: rgb(210, 210, 210);\n"
"  background: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button,\n"
"QDoubleSpinBox::up-button {\n"
"  subcontrol-origin: border;\n"
"  subcontrol-position: top right; /* position at the top right corner */\n"
"  /* border-left: 1px solid rgb(255,255,255); */\n"
"  width: 18px;\n"
"  height: 12px;\n"
"  border-top-right-radius: 4px;\n"
"  image: url(:/White/topArrow);\n"
"}\n"
"\n"
"QSpinBox::up-button:!enabled {\n"
"  background: transp"
                        "arent;\n"
"}\n"
"\n"
"QSpinBox::up-button:enabled:hover {\n"
"  background: rgb(255, 255, 255, 30);\n"
"}\n"
"\n"
"QSpinBox::down-button,\n"
"QDoubleSpinBox::down-button {\n"
"  /* border-left: 1px solid rgb(255,255,255); */\n"
"  width: 18px;\n"
"  height: 12px;\n"
"  border-bottom-right-radius: 4px;\n"
"  image: url(:/White/bottomArrow);\n"
"  subcontrol-origin: border;\n"
"  subcontrol-position: bottom right; /* position at bottom right corner */\n"
"}\n"
"\n"
"QSpinBox::down-button:!enabled {\n"
"  background: transparent;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"  background: rgb(255, 255, 255, 30);\n"
"}\n"
"\n"
"\n"
"/**********\346\214\211\351\222\256**********/\n"
"QToolButton#nsccButton {\n"
"  border: none;\n"
"  color: rgb(2, 65, 132);\n"
"  background: transparent;\n"
"  padding: 10px;\n"
"  qproperty-icon: url(:/White/nscc);\n"
"  qproperty-iconsize: 32px 32px;\n"
"  qproperty-toolbuttonstyle: ToolButtonTextUnderIcon;\n"
"}\n"
"\n"
"QToolButton#nsccButton:hover {\n"
"  background: rgb(255"
                        ",255,255);\n"
"}\n"
"\n"
"QToolButton#transferButton {\n"
"  border: none;\n"
"  color: rgb(2, 65, 132);\n"
"  background: transparent;\n"
"  padding: 10px;\n"
"  qproperty-icon: url(:/White/transfer);\n"
"  qproperty-iconsize: 32px 32px;\n"
"  qproperty-toolbuttonstyle: ToolButtonTextUnderIcon;\n"
"}\n"
"\n"
"\n"
"/**********\346\214\211\351\222\256**********/\n"
"QPushButton {\n"
"  border-radius: 4px;\n"
"  border: none;\n"
"  width: 75px;\n"
"  height: 25px;\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"  background: rgb(120, 170, 220);\n"
"  color: white;\n"
"}\n"
"\n"
"QPushButton:!enabled {\n"
"  background: rgb(180, 180, 180);\n"
"  color: white;\n"
"}\n"
"\n"
"QPushButton:enabled:hover {\n"
"  background: rgb(100, 160, 220);\n"
"}\n"
"\n"
"QPushButton:enabled:pressed {\n"
"  background: rgb(0, 78, 161);\n"
"}\n"
"\n"
"/*****************\346\240\207\351\242\230\346\240\217\346\214\211\351\222\256*******************/\n"
"QDockWidget {\n"
"  font-weight: bold;\n"
"  color: white;\n"
"}\n"
"\n"
"/* \346\240\207"
                        "\351\242\230\350\256\276\347\275\256 */\n"
"QDockWidget::title {\n"
"  text-align: left;\n"
"  color: white;\n"
"  background: rgb(255,255,255);\n"
"  padding-left: 10px;\n"
"}\n"
"\n"
"QSlider::groove {\n"
"  background: rgb(232, 241, 252);\n"
"  border: 1px solid #999999;\n"
"}\n"
"\n"
"QSlider::add-page {\n"
"  background: rgb(232, 241, 252);\n"
"  border: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QSlider::sub-page {\n"
"  background: rgba(111, 156, 207, 160);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"  height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"  margin: 1px 0;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"  width: 6px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"  margin: 0 1px;\n"
"}\n"
"\n"
"QSlider::handle {\n"
"  background: rgb(255,255,255);\n"
"  border: 1px solid rgb(255,255,255);\n"
"  border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal "
                        "{\n"
"  width: 8px;\n"
"  margin: -6px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"  height: 8px;\n"
"  margin: 0 -6px; /* expand outside the groove */\n"
"}\n"
"\n"
"QToolBox:tab {\n"
"  color: #eee;\n"
"  background: rgb(255,255,255);\n"
"  border: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QToolBox:tab:selected {\n"
"  font-weight: bold;\n"
"  background: rgb(60, 110, 150);\n"
"  color: white;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
"QToolBox QWidget {\n"
"  margin: 0;\n"
"  padding: 0;\n"
"  border: 0px solid rgb(255,255,255);\n"
"}\n"
"\n"
"/* * {\n"
"  qproperty-normalColor: rgb(65, 65, 65);\n"
"  qproperty-disableColor: rgb(180, 180, 180);\n"
"  qproperty-highlightColor: rgb(0, 160, 230);\n"
"  qproperty-errorColor: red;\n"
"} */\n"
"\n"
"\n"
"QTreeView {\n"
"  show-decoration-selected: 0;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"QTreeView QHeaderView:sect"
                        "ion {\n"
"  height: 36px;\n"
"}\n"
"\n"
"QTreeView::indicator:checked {\n"
"  image: url(:/Resource/icon/eye.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked {\n"
"  image: url(:/Resource/icon/eyeClosed.png);\n"
"}\n"
"\n"
"QTreeView::indicator:indeterminate {\n"
"  image: url(:/Resource/icon/eyeClosed.png);\n"
"}\n"
"\n"
"/*\n"
"QTreeView::item,QTreeWidget::item {\n"
"    height: 25px;\n"
"    color: #eee;\n"
"    border: none;\n"
"    background-color: rgba(100,100,100,0);\n"
"}\n"
"\n"
"QTreeView::item:hover, QTreeView::branch:hover,\n"
"QTreeWidget::item:hover, QTreeWidget::branch:hover { \n"
"    background-color: rgba(100, 100, 100, 40);\n"
"}\n"
"\n"
"QTreeView::item:selected { \n"
"    background-color: rgba(200, 200, 200, 50);\n"
"    font-weight:bold;\n"
"}*/\n"
"\n"
"QTreeView::branch,\n"
"QTreeWidget::branch {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item,\n"
"QTreeWidget::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/Resource/icon"
                        "/vline.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item,\n"
"QTreeWidget::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/Resource/icon/branch-more.png) 0;\n"
"    \n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item,\n"
"QTreeWidget::branch:!has-children:!has-siblings:adjoins-item{\n"
"    border-image: url(:/Resource/icon/branch-end.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings,\n"
"QTreeWidget::branch:has-children:!has-siblings:closed,\n"
"QTreeWidget::branch:closed:has-children:has-siblings \n"
"{\n"
"    border-image: none;\n"
"    image: url(:/Resource/icon/branch-closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings,\n"
"QTreeWidget::branch:open:has-children:!has-siblings,\n"
"QTreeWidget::branch:open:has-children:has-siblings  {\n"
"   border-image: none;\n"
"   image: url(:/Resource/icon"
                        "/branch-open.png);\n"
"}\n"
"\n"
"\n"
"/*\345\216\273\351\231\244\347\204\246\347\202\271\350\231\232\347\272\277\346\241\206*/\n"
"QWidget:focus\n"
"{\n"
"    outline: none;\n"
"}\n"
"\n"
"\n"
"QListView {\n"
"  show-decoration-selected: 0;\n"
"  border: 1px solid rgb(43,87,154);\n"
"  background: rgb(255,255,255);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"/*///////////////////////////////////////////////////*/\n"
"\n"
"\n"
"\n"
"  QMainWindow::separator {\n"
"      background:rgb(224,224,224);\n"
"      width: 1px; /* when vertical */\n"
"      height: 1px; /* when horizontal */\n"
"  }\n"
"\n"
"  QMainWindow::separator:hover {\n"
"      border-color:rgb(43,87,154);\n"
"      color:rgb(43,87,154);\n"
"\n"
"\n"
"  }\n"
"\n"
"\n"
"QWidget#widgetContainer,QWidget#widgetContainer > *{\n"
"\n"
"	background:rgb(33,115,70);\n"
"	background:rgb(183,71,42);\n"
"	background:rgb(43,87,154);\n"
"	color:#fff;\n"
"	font-family:'simhei';\n"
"	font-size:11pt;\n"
"}\n"
"\n"
"QTabBar{\n"
"	background:rgb(43,87,154);\n"
"}\n"
""
                        "\n"
"\n"
"QTabBar::tab {\n"
"      background:rgb(43,87,154);\n"
"      min-width: 12ex;\n"
"      padding: 2px;\n"
"	  height:24px;\n"
"	  padding:2px 12px;\n"
"	  color:#fff;\n"
"  }\n"
"\n"
"QTabBar::tab:selected {\n"
"      background: rgb(243,243,243);\n"
"	  color: rgb(10, 10, 10);\n"
"color: rgb(10, 10, 10);\n"
"color: rgb(43,87,154);\n"
"\n"
"  }\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"     background:rgba(0,0,0,40);\n"
"  }\n"
"\n"
"\n"
"\n"
"QTabBar::tab:selected {\n"
"      border-color: #9B9B9B;\n"
"      border-bottom-color: #C2C7CB; /* same as pane color */\n"
"  }\n"
"\n"
"QTabBar::tab:!selected {\n"
"      margin-top: 0px; /* make non-selected tabs look smaller */\n"
"  }\n"
"\n"
"\n"
"\n"
"\n"
"QDockWidget {\n"
"     border: 1px solid rgb(255,0,255);\n"
"	 margin:0px;\n"
"	 color:rgb(240,240,240);\n"
"     background: #fff;\n"
"	color:rgb(10,10,10);\n"
"color:#eee;\n"
"	titlebar-close-icon: url(:/Resources/icon/dockwidget-close.png);\n"
"     titlebar-normal-icon: url(:/Resources/icon/dock"
                        "widget-float.png);\n"
" }\n"
"\n"
" QDockWidget::title {\n"
"     text-align: left; /* align the text to the left */\n"
"     background: rgb(230,230,230);\n"
"    background:rgb(43,87,154);\n"
"	 padding:6px 4px;\n"
"	 font-size:30pt;\n"
"\n"
"\n"
" }\n"
"\n"
" QDockWidget::close-button, QDockWidget::float-button {\n"
"     border: 1px solid transparent;\n"
"     width: 24px;\n"
"	 height:24px;\n"
" }\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover {\n"
"      background: rgb(177,177,177);\n"
"	background:rgba(0,0,0,40);\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed {\n"
"     padding: 1px -1px -1px 1px;\n"
"background:rgba(0,0,0,80);\n"
" }\n"
"\n"
" QDockWidget::close-button {\n"
"      subcontrol-position: top right;\n"
"      subcontrol-origin: margin;\n"
"	top:-1px;\n"
"	right:4px;\n"
"      position: absolute;\n"
"  }\n"
"\n"
" QDockWidget::float-button {\n"
"      subcontrol-position: top right;\n"
"      subcontrol-origin: margin;\n"
"	to"
                        "p:-1px;\n"
"      position: absolute;\n"
"	right:26px;\n"
"  }\n"
"\n"
"\n"
"QMainWindow QWidget#centralwidget{\n"
"	background:white;\n"
"}\n"
"\n"
"\n"
"\n"
"/*Qmenu Style Sheets*/\n"
"QMenu {\n"
"    background-color: rgb(243,243,243); /* sets background of the menu \350\256\276\347\275\256\346\225\264\344\270\252\350\217\234\345\215\225\345\214\272\345\237\237\347\232\204\350\203\214\346\231\257\350\211\262\357\274\214\346\210\221\347\224\250\347\232\204\346\230\257\347\231\275\350\211\262\357\274\232white*/\n"
"    border: 1px solid rgb(226,241,250);/*\346\225\264\344\270\252\350\217\234\345\215\225\345\214\272\345\237\237\347\232\204\350\276\271\346\241\206\347\262\227\347\273\206\343\200\201\346\240\267\345\274\217\343\200\201\351\242\234\350\211\262*/\n"
"\n"
"}\n"
" \n"
"QMenu::item {\n"
"    /* sets background of menu item. set this to something non-transparent\n"
"        if you want menu color and menu item color to be different */\n"
"    background-color: transparent;\n"
"    padding:3px 25px;/*\350"
                        "\256\276\347\275\256\350\217\234\345\215\225\351\241\271\346\226\207\345\255\227\344\270\212\344\270\213\345\222\214\345\267\246\345\217\263\347\232\204\345\206\205\350\276\271\350\267\235\357\274\214\346\225\210\346\236\234\345\260\261\346\230\257\350\217\234\345\215\225\344\270\255\347\232\204\346\235\241\347\233\256\345\267\246\345\217\263\344\270\212\344\270\213\346\234\211\344\272\206\351\227\264\351\232\224*/\n"
"    margin:0px 2px;/*\350\256\276\347\275\256\350\217\234\345\215\225\351\241\271\347\232\204\345\244\226\350\276\271\350\267\235*/\n"
"    /*border-bottom:1px solid #DBDBDB;\344\270\272\350\217\234\345\215\225\351\241\271\344\271\213\351\227\264\346\267\273\345\212\240\346\250\252\347\272\277\351\227\264\351\232\224*/\n"
"	color:rgb(10,10,10);\n"
"	font-weight:bold;\n"
"}\n"
" \n"
"QMenu::item:selected { /* when user selects item using mouse or keyboard */\n"
"    background-color: rgb(177,177,177);/*\350\277\231\344\270\200\345\217\245\346\230\257\350\256\276\347\275\256\350\217\234\345\215\225"
                        "\351\241\271\351\274\240\346\240\207\347\273\217\350\277\207\351\200\211\344\270\255\347\232\204\346\240\267\345\274\217*/\n"
"color:rgb(10,10,10);\n"
"}\n"
"\n"
"\n"
"QWidget#widgetContainer{\n"
"	margin:0;\n"
"	padding:0;\n"
"}\n"
"\n"
"\n"
"/*\n"
"QTabWidget:pane,QWidget#widgetMenuBar{\n"
"	border-bottom:1px solid rgb(224,224,224);\n"
"}\n"
"*/\n"
"\n"
"\n"
"QWidget#widgetBottomBar{\n"
"border-bottom:1px solid blue;\n"
"	background:blue;\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
"QTabWidget .QWidget{ \n"
"\n"
"background: rgb(243,243,243);\n"
"\n"
"}\n"
"\n"
"QToolTip{\n"
"	color:black;\n"
"}\n"
"\n"
" QTabWidget#tabWidgetMenuBar::pane { /* The tab widget frame */\n"
"      border-top: 0px solid #eee;\n"
"border-width:0;\n"
"	 background: rgb(243,243,243);\n"
"	padding:1px 1px;\n"
"  }\n"
"\n"
"  QTabWidget#tabWidgetMenuBar::tab-bar {\n"
"      left: 2px; /* move to the right by 5px */\n"
"	/*height:32px;*/\n"
"border-width:0;\n"
"\n"
"  }\n"
"\n"
"/*QTabWidget#tabWidgetMenuBar QTabBar {\n"
"      background: rgb(255,0"
                        ",0);\n"
"  }*/\n"
"\n"
"  /* Style the tab using the tab sub-control. Note that\n"
"      it reads QTabBar _not_ QTabWidget */\n"
"  QTabWidget#tabWidgetMenuBar QTabBar::tab {\n"
"      background: transparent;\n"
"      min-width: 12ex;\n"
"      padding: 2px;\n"
"	  height:30px;\n"
"	  padding:2px 12px;\n"
"	  color:#fff;\n"
"border-width:0;\n"
"  }\n"
"\n"
"  QTabWidget#tabWidgetMenuBar QTabBar::tab:selected {\n"
"      background: rgb(243,243,243);\n"
"	  color: rgb(10, 10, 10);\n"
"color: rgb(10, 10, 10);\n"
"color: rgb(183,71,42);\n"
"	color:rgb(43,87,154);\n"
"  }\n"
"\n"
"QTabWidget#tabWidgetMenuBar QTabBar::tab:hover:!selected {\n"
"     background:rgba(0,0,0,40);\n"
"  }\n"
"\n"
"\n"
"\n"
" QTabWidget#tabWidgetMenuBar QTabBar::tab:selected {\n"
"      border-color: #9B9B9B;\n"
"      border-bottom-color: #C2C7CB; /* same as pane color */\n"
"  }\n"
"\n"
"  QTabWidget#tabWidgetMenuBar QTabBar::tab:!selected {\n"
"      margin-top: 0px; /* make non-selected tabs look smaller */\n"
"  }\n"
"\n"
"\n"
"QW"
                        "idget#widgetContent{\n"
"	background:white;\n"
"}\n"
"\n"
"QToolButton{\n"
"	background:transparent;\n"
"	border:0px solid gray;\n"
"	color: rgb(10, 10, 10);\n"
"	margin:0;\n"
"}\n"
"\n"
"QToolButton{\n"
"	padding-bottom:10px;\n"
"}\n"
"\n"
"QToolButton:hover,QToolButton:checked{\n"
"	border:1px solid rgba(100,100,100,100);\n"
"	border-radius:2px;\n"
"	background:rgb(198,198,198);\n"
"}\n"
"\n"
"QToolButton::menu-button {\n"
"    \n"
"      /* 16px width + 4px for border = 20px allocated above */\n"
"      width: 16px;\n"
"	subcontrol-origin:margin;\n"
"subcontrol-position: bottom center;\n"
"	bottom:0px;\n"
"	left:0px;\n"
"	height:10px;\n"
"	width:100%\n"
" }\n"
"\n"
"\n"
"\n"
"QMenu {\n"
"\n"
"    border: 1px solid rgb(226,241,250);\n"
"}\n"
" \n"
"QMenu::item {\n"
"    background-color: transparent;\n"
"    padding:3px 25px;\n"
"    margin:0px 2px;\n"
"	color:rgb(240,240,240);\n"
"	font-weight:bold;\n"
"}\n"
"QMenu::item:selected { \n"
"    background-color: #999999;\n"
"}\n"
"\n"
"\n"
"QPushButton,QPushBut"
                        "ton#pushButtonStyle,QPushButton#pushButtonMinimizeTab,QPushButton#pushButtonMaxTab,QPushButton#pushButtonClose,QPushButton#pushButtonFullScreen,QPushButton#pushButtonMinimum{\n"
"	background:transparent;\n"
"	font-weight:bold;\n"
"	margin:0px;\n"
"	border:0px solid #fff;\n"
"	outline:none;\n"
"}\n"
"\n"
"QPushButton:hover,QPushButton#pushButtonFullScreen:hover,QPushButton#pushButtonMinimum:hover,QPushButton#pushButtonMaxTab:hover{\n"
"	background:rgba(0,0,0,40);\n"
"}\n"
"\n"
"QPushButton:pressed,QPushButton#pushButtonFullScreen:pressed,QPushButton#pushButtonMinimum:pressed,QPushButton#pushButtonMaxTab:pressed{\n"
"	background:rgba(0,0,0,80);\n"
"	padding-top:3px;\n"
"}\n"
"\n"
"QPushButton#pushButtonClose:hover{\n"
"	background:rgba(232,17,35,255);\n"
"}\n"
"\n"
"QPushButton#pushButtonClose:pressed{\n"
"	background:rgba(232,17,35,200);\n"
"}\n"
"\n"
"QPushButton#pushButtonMinimizeTab,QPushButton#pushButtonMaxTab{\n"
"	color: rgb(112, 112, 112);\n"
"}\n"
"\n"
"QPushButton#pushButtonMinimizeTab:hover,QPushButto"
                        "n#pushButtonMaxTab:hover{\n"
"	background:rgb(177,177,177);\n"
"}\n"
"\n"
"\n"
" QPushButton::menu-indicator {\n"
"      image: none;\n"
"      subcontrol-origin: padding;\n"
"      subcontrol-position: bottom right;\n"
"  }"));
        verticalLayout = new QVBoxLayout(widgetContainer);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutTitleBar = new QHBoxLayout();
        horizontalLayoutTitleBar->setSpacing(6);
        horizontalLayoutTitleBar->setObjectName(QString::fromUtf8("horizontalLayoutTitleBar"));
        horizontalLayoutTitleBar->setContentsMargins(100, -1, 0, -1);
        labelTitle = new QLabel(widgetContainer);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setAlignment(Qt::AlignCenter);

        horizontalLayoutTitleBar->addWidget(labelTitle);

        pushButtonStyle = new QPushButton(widgetContainer);
        pushButtonStyle->setObjectName(QString::fromUtf8("pushButtonStyle"));
        pushButtonStyle->setMinimumSize(QSize(32, 32));
        pushButtonStyle->setMaximumSize(QSize(32, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButtonStyle->setFont(font);
        pushButtonStyle->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        pushButtonStyle->setAutoDefault(false);
        pushButtonStyle->setFlat(true);

        horizontalLayoutTitleBar->addWidget(pushButtonStyle);

        pushButtonMinimum = new QPushButton(widgetContainer);
        pushButtonMinimum->setObjectName(QString::fromUtf8("pushButtonMinimum"));
        pushButtonMinimum->setMinimumSize(QSize(46, 32));
        pushButtonMinimum->setMaximumSize(QSize(36, 32));
        pushButtonMinimum->setStyleSheet(QString::fromUtf8(""));
        pushButtonMinimum->setAutoDefault(false);
        pushButtonMinimum->setFlat(true);

        horizontalLayoutTitleBar->addWidget(pushButtonMinimum);

        pushButtonFullScreen = new QPushButton(widgetContainer);
        pushButtonFullScreen->setObjectName(QString::fromUtf8("pushButtonFullScreen"));
        pushButtonFullScreen->setMinimumSize(QSize(46, 32));
        pushButtonFullScreen->setMaximumSize(QSize(36, 32));
        pushButtonFullScreen->setAutoDefault(false);
        pushButtonFullScreen->setFlat(true);

        horizontalLayoutTitleBar->addWidget(pushButtonFullScreen);

        pushButtonClose = new QPushButton(widgetContainer);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setMinimumSize(QSize(46, 32));
        pushButtonClose->setMaximumSize(QSize(36, 32));
        pushButtonClose->setAutoDefault(false);
        pushButtonClose->setFlat(true);

        horizontalLayoutTitleBar->addWidget(pushButtonClose);


        verticalLayout->addLayout(horizontalLayoutTitleBar);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetMenuBar_2 = new QWidget(widgetContainer);
        widgetMenuBar_2->setObjectName(QString::fromUtf8("widgetMenuBar_2"));
        widgetMenuBar_2->setMinimumSize(QSize(90, 34));
        widgetMenuBar_2->setMaximumSize(QSize(16777215, 34));
        widgetMenuBar_2->setStyleSheet(QString::fromUtf8(""));
        pushButtonMaxTab = new QPushButton(widgetMenuBar_2);
        pushButtonMaxTab->setObjectName(QString::fromUtf8("pushButtonMaxTab"));
        pushButtonMaxTab->setGeometry(QRect(60, 10, 24, 14));
        pushButtonMaxTab->setMinimumSize(QSize(24, 14));
        pushButtonMaxTab->setMaximumSize(QSize(24, 14));
        pushButtonMaxTab->setStyleSheet(QString::fromUtf8(""));
        pushButtonMaxTab->setFlat(true);

        gridLayout->addWidget(widgetMenuBar_2, 0, 1, 1, 1);

        tabWidgetMenuBar = new QTabWidget(widgetContainer);
        tabWidgetMenuBar->setObjectName(QString::fromUtf8("tabWidgetMenuBar"));
        tabWidgetMenuBar->setMinimumSize(QSize(0, 34));
        tabWidgetMenuBar->setMaximumSize(QSize(16777215, 6666));
        tabWidgetMenuBar->setStyleSheet(QString::fromUtf8(""));
        tabWidgetMenuBar->setElideMode(Qt::ElideNone);
        tabWidgetMenuBar->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(tab);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../workspace/UMVision/UMVision/icon/folder-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_4->setAutoRaise(true);
        toolButton_4->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(tab);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../workspace/UMVision/UMVision/icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon1);
        toolButton_5->setIconSize(QSize(32, 32));
        toolButton_5->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_5->setAutoRaise(true);
        toolButton_5->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_5);

        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(1, 0));
        line->setMaximumSize(QSize(1, 16777215));
        line->setStyleSheet(QString::fromUtf8("border-color:rgb(177,177,177);\n"
"background-color:rgb(177,177,177);\n"
"color:rgb(177,177,177);\n"
"width:2px;"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(line);

        toolButton_6 = new QToolButton(tab);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../workspace/UMVision/UMVision/icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon2);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setPopupMode(QToolButton::DelayedPopup);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_6->setAutoRaise(true);
        toolButton_6->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(tab);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setStyleSheet(QString::fromUtf8(""));
        toolButton_7->setIcon(icon2);
        toolButton_7->setIconSize(QSize(32, 32));
        toolButton_7->setCheckable(true);
        toolButton_7->setChecked(true);
        toolButton_7->setPopupMode(QToolButton::DelayedPopup);
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_7->setAutoRaise(true);
        toolButton_7->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_7);

        horizontalSpacer = new QSpacerItem(903, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tabWidgetMenuBar->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        toolButton_8 = new QToolButton(tab_2);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setGeometry(QRect(0, 3, 51, 71));
        toolButton_8->setStyleSheet(QString::fromUtf8(""));
        toolButton_8->setIcon(icon);
        toolButton_8->setIconSize(QSize(32, 32));
        toolButton_8->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_8->setAutoRaise(true);
        toolButton_8->setArrowType(Qt::NoArrow);
        tabWidgetMenuBar->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidgetMenuBar->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidgetMenuBar->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidgetMenuBar->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidgetMenuBar->addTab(tab_6, QString());

        gridLayout->addWidget(tabWidgetMenuBar, 0, 0, 2, 1);

        widgetMenuBar = new QWidget(widgetContainer);
        widgetMenuBar->setObjectName(QString::fromUtf8("widgetMenuBar"));
        widgetMenuBar->setMinimumSize(QSize(90, 0));
        widgetMenuBar->setMaximumSize(QSize(16777215, 16777215));
        widgetMenuBar->setStyleSheet(QString::fromUtf8(".QWidget{\n"
"background: rgb(243,243,243);\n"
"border-left:1px solid gray;\n"
"}"));
        pushButtonMinimizeTab = new QPushButton(widgetMenuBar);
        pushButtonMinimizeTab->setObjectName(QString::fromUtf8("pushButtonMinimizeTab"));
        pushButtonMinimizeTab->setGeometry(QRect(60, 60, 24, 14));
        pushButtonMinimizeTab->setMinimumSize(QSize(24, 14));
        pushButtonMinimizeTab->setMaximumSize(QSize(24, 14));
        pushButtonMinimizeTab->setStyleSheet(QString::fromUtf8(""));
        pushButtonMinimizeTab->setFlat(true);

        gridLayout->addWidget(widgetMenuBar, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widgetBottomBar = new QWidget(widgetContainer);
        widgetBottomBar->setObjectName(QString::fromUtf8("widgetBottomBar"));
        widgetBottomBar->setMinimumSize(QSize(0, 1));
        widgetBottomBar->setMaximumSize(QSize(16777215, 1));

        verticalLayout->addWidget(widgetBottomBar);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_3->addWidget(widgetContainer);


        retranslateUi(QRibbon);

        tabWidgetMenuBar->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(QRibbon);
    } // setupUi

    void retranslateUi(QMenuBar *QRibbon)
    {
        QRibbon->setWindowTitle(QCoreApplication::translate("QRibbon", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("QRibbon", "\350\277\231\346\230\257\346\240\207\351\242\230", nullptr));
        pushButtonStyle->setText(QCoreApplication::translate("QRibbon", "\342\230\272", nullptr));
        pushButtonMinimum->setText(QCoreApplication::translate("QRibbon", "\342\200\225", nullptr));
        pushButtonFullScreen->setText(QCoreApplication::translate("QRibbon", "\342\230\220", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("QRibbon", "\303\227", nullptr));
        pushButtonMaxTab->setText(QCoreApplication::translate("QRibbon", "\342\256\237", nullptr));
        toolButton_4->setText(QCoreApplication::translate("QRibbon", "\346\211\223\345\274\200", nullptr));
        toolButton_5->setText(QCoreApplication::translate("QRibbon", "\347\262\230\350\264\264", nullptr));
        toolButton_6->setText(QCoreApplication::translate("QRibbon", "\351\200\200\345\207\272", nullptr));
        toolButton_7->setText(QCoreApplication::translate("QRibbon", "\351\200\200\345\207\272", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab), QCoreApplication::translate("QRibbon", "\346\226\207\344\273\266", nullptr));
        toolButton_8->setText(QCoreApplication::translate("QRibbon", "\346\211\223\345\274\200", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab_2), QCoreApplication::translate("QRibbon", "\347\274\226\350\276\221", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab_3), QCoreApplication::translate("QRibbon", "\347\252\227\344\275\223", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab_4), QCoreApplication::translate("QRibbon", "\350\247\206\345\233\276", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab_5), QCoreApplication::translate("QRibbon", "\350\256\276\347\275\256", nullptr));
        tabWidgetMenuBar->setTabText(tabWidgetMenuBar->indexOf(tab_6), QCoreApplication::translate("QRibbon", "\345\270\256\345\212\251", nullptr));
        pushButtonMinimizeTab->setText(QCoreApplication::translate("QRibbon", "\342\256\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRibbon: public Ui_QRibbon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRIBBON_H
