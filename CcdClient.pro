#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T15:26:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CcdClient
TEMPLATE = app

SOURCES += \
    DeviceType.cpp \
    DataReceiver.cpp \
    mousepressableslider.cpp \
    AddDeviceDialog.cpp \
    ChameleonPropertiesDialog.cpp \
    ImageWidget.cpp \
    centralwidget.cpp \
    mainwindow.cpp \
    main.cpp \

HEADERS += \
    DeviceType.h \
    DataReceiver.h \
    mousepressableslider.h \
    AddDeviceDialog.h \
    ChameleonPropertiesDialog.h \
    ImageWidget.h \
    centralwidget.h \
    mainwindow.h \

LIBS += /usr/local/lib/libtango.so
LIBS += /usr/lib/libomniORB4.so
LIBS += /usr/lib/libomnithread.so
LIBS += -L/usr/lib -ljpeg

INCLUDEPATH += /usr//local/include/tango
INCLUDEPATH += /usr/local/omniORB4
INCLUDEPATH += /usr/local/omnithread

FORMS += \
    AddDeviceDialog.ui \
    ChameleonPropertiesDialog.ui \
    ImageWidget.ui \
    CentralWidget.ui
