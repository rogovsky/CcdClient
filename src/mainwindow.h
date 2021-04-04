#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QHash>
#include <QString>
#include <QThread>

#include <tango.h>

#include "DataReceiver.h"
#include "centralwidget.h"
#include "DeviceType.h"

typedef QHash<QString, Tango::DeviceAttribute> MyHashData;
typedef Tango::DeviceAttribute TangoAttribute;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //view
    QToolBar *toolBar;
    QWidget *spacer;

    CentralWidget *centralWidget;

    DataReceiver *dataReceiver;
	QThread *dataReceiverThread;

public:
    MainWindow(QWidget *parent = 0);
    MainWindow(QString filestate, QWidget *parent = 0);
    ~MainWindow();

    void retranslateUI();

signals:
    void play(QString devName);
    void pause(QString devName);
	void setExposure(QString devName);
    void closeDevice(QString devName);

    void addDevice(QString devName, DeviceType type);

public slots:
    void exit();
    void toolBarAddDevice();
    void toolBarOpenState();
    void toolBarSaveState();

    void toolBarProperties();
    void toolBarAbout();

    void toolBarPlay();
    void toolBarPause();
    void toolBarClose();

    void resizeEvent(QResizeEvent *event);

};

Q_DECLARE_METATYPE(MyHashData)
Q_DECLARE_METATYPE(TangoAttribute)
Q_DECLARE_METATYPE(DeviceType)

#endif // MAINWINDOW_H
