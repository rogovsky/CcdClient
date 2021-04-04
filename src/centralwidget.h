#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHash>
#include <QVector>
#include <QThread>
#include <QGridLayout>
#include <QString>
#include <tango.h>
#include "ImageWidget.h"
#include "DeviceType.h"

namespace Ui
{
class CentralWidget;
}

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

    void addCamera(QString& name, DeviceType type);

signals:
    void play(QString);
    void pause(QString);
    void setExposure(QString);
    void closeDevice(QString);
    void attributeChanged(QString, Tango::DeviceAttribute);
    void refresh(QString, QHash<QString, Tango::DeviceAttribute>);
    void getFullImage(QString devName);

public slots:
    void updateData(QString, QHash<QString, Tango::DeviceAttribute>);
    void addImageWidget(QString, DeviceType type);
    void closeImageWidget(QString, int id);
    void changeAttribute(QString, Tango::DeviceAttribute);
    void playProxy(QString devName)
    {
        emit play(devName);
    }
    void pauseProxy(QString devName)
    {
        emit pause(devName);
    }
    void setExposureProxy(QString devName)
    {
        emit setExposure(devName);
    }
    void closeDeviceProxy(ImageWidget *widget);
    void getFullImageSlot(ImageWidget *);
    void saveFullImageToFile(QString devName, std::vector<unsigned char> data, int width, int height);
    void receiveImage(QString devName, std::vector<unsigned char> data, int width, int height);

private:
    QHash<QString, QVector<ImageWidget *>> widgets;
    QGridLayout *layout;

    Ui::CentralWidget *ui;

    ImageWidget *saveFullImageToFile_widget;

    int _row = 0, _col = 0;
};

#endif // CENTRALWIDGET_H
