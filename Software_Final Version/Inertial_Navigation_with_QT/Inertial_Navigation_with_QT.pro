QT       += core gui
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QRibbon/QRibbon.cpp \
    about_window.cpp \
    attitude_matrix.cpp \
    coordinate_convert.cpp \
    earth_parameter.cpp \
    global_variate.cpp \
    main.cpp \
    mainwindow.cpp \
    public_func.cpp \
    read_imr_file.cpp \
    updating.cpp

HEADERS += \
    QRibbon/QRibbon.h \
    about_window.h \
    attitude_matrix.h \
    coordinate_convert.h \
    earth_parameter.h \
    global_variate.h \
    mainwindow.h \
    public_func.h \
    read_imr_file.h \
    updating.h

FORMS += \
    QRibbon/qribbon.ui \
    about_window.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH+=..//Eigen3/Eigen3
#   采用并行编译方式
# QMAKE_CXXFLAGS += /MP

RESOURCES += \
    QRibbon/QRibbon.qrc \
    icon.qrc
RC_FILE=icon.rc

DISTFILES += \
    QRibbon/Resource/icon/open.ico
