#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T15:26:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CcdClient
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += tango libjpeg

SOURCES += main.cpp\
	mainwindow.cpp \
    centralwidget.cpp \
    mousepressableslider.cpp \
    AddDeviceDialog.cpp \
    ChameleonPropertiesDialog.cpp \
    ImageWidget.cpp \
    DataReceiver.cpp \
    DeviceType.cpp

HEADERS  += mainwindow.h \
    centralwidget.h \
    mousepressableslider.h \
    AddDeviceDialog.h \
    ChameleonPropertiesDialog.h \
    ImageWidget.h \
    DataReceiver.h \
    DeviceType.h

#LIBS += /usr/local/lib/libtango.so
#LIBS += /usr/lib/libomniORB4.so
#LIBS += /usr/lib/libomnithread.so
#LIBS += -L/usr/lib -ljpeg
LIBS += -L/usr/lib/tango

INCLUDEPATH += /usr/include/tango
INCLUDEPATH += /usr/local/omniORB4
INCLUDEPATH += /usr/local/omnithread

FORMS += \
    AddDeviceDialog.ui \
    ChameleonPropertiesDialog.ui \
    ImageWidget.ui \
    CentralWidget.ui
