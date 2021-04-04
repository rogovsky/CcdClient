#
#

UI_DIR = .uic
MOC_DIR = .moc
RCC_DIR = .qrc
OBJECTS_DIR = .obj

TARGET = CcdClient
TEMPLATE = app

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
    INCLUDEPATH +=
    LIBS +=
} else {
    INCLUDEPATH +=
    LIBS +=

    #CONFIG += c++11
    include( src/3rd_party/qjson.pri )
}

if ( 1 ) {
    CONFIG += link_pkgconfig
    PKGCONFIG += tango libjpeg
} else {
    LIBS += -L/usr/lib/x86_64-linux-gnu/
    LIBS += -ltango
    LIBS += -lomniORB4
    LIBS += -lomnithread
    LIBS += -L/usr/lib -ljpeg

    INCLUDEPATH += /usr/include/tango
    INCLUDEPATH += /usr/include/omniORB4
    INCLUDEPATH += /usr/include/omnithread
}

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

FORMS += \
    AddDeviceDialog.ui \
    ChameleonPropertiesDialog.ui \
    ImageWidget.ui \
    CentralWidget.ui

RESOURCES += \
    etc/resources/ccdclient.qrc
