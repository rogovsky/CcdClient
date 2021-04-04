#
#

UI_DIR = .uic
MOC_DIR = .moc
RCC_DIR = .qrc
OBJECTS_DIR = .obj

TARGET = CcdClient
TEMPLATE = app
VERSION = 1.0

DEPENDPATH  += . src
INCLUDEPATH += . src
LIBS +=

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
    src/DeviceType.cpp \
    src/DataReceiver.cpp \
    src/mousepressableslider.cpp \
    src/AddDeviceDialog.cpp \
    src/ChameleonPropertiesDialog.cpp \
    src/ImageWidget.cpp \
    src/centralwidget.cpp \
    src/mainwindow.cpp \
    src/main.cpp \

HEADERS += \
    src/DeviceType.h \
    src/DataReceiver.h \
    src/mousepressableslider.h \
    src/AddDeviceDialog.h \
    src/ChameleonPropertiesDialog.h \
    src/ImageWidget.h \
    src/centralwidget.h \
    src/mainwindow.h \

FORMS += \
    src/ui/AddDeviceDialog.ui \
    src/ui/ChameleonPropertiesDialog.ui \
    src/ui/ImageWidget.ui \
    src/ui/CentralWidget.ui

RESOURCES += \
    etc/resources/ccdclient.qrc

OTHER_FILES += \
    src/3rd_party/README.md \
    README.md \

ICON_FILES += \
    etc/resources/icons/24x24/actions/application-exit.png \
    etc/resources/icons/24x24/actions/document-open.png \
    etc/resources/icons/24x24/actions/document-save.png \
    etc/resources/icons/24x24/actions/edit-delete.png \
    etc/resources/icons/24x24/actions/help-about.png \
    etc/resources/icons/24x24/actions/player_pause.png \
    etc/resources/icons/24x24/actions/player_play.png \
    etc/resources/icons/24x24/actions/player_stop.png \
    etc/resources/icons/24x24/categories/preferences-system.png \
    etc/resources/icons/256x256/categories/preferences-system.png \
    etc/resources/icons/256x256/mimetypes/image.png \
    etc/resources/icons/48x48/actions/add.png \

DISTFILES += \
    $$OTHER_FILES \
    $$ICON_FILES \
