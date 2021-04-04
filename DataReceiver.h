#ifndef DATARECEIVER_H
#define DATARECEIVER_H


#include <QThread>
#include <QVector>
#include <QString>
#include <QHash>
#include <QMutex>
#include <tango.h>
#include "DeviceType.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QErrorMessage>

class DataReceiver : public QThread, public Tango::CallBack
{
    Q_OBJECT
private:
	QObject *parent;

	QErrorMessage* err = new QErrorMessage(NULL);

    QHash<QString, QHash<QString, Tango::DeviceAttribute>> data;
    QHash<QString, Tango::DeviceProxy*> devices;
	QHash<QString, std::vector<std::string>> attrNames;
	QHash<QString, std::vector<std::string>> saveStateAttrNames;
    QHash<QString, QVector<int>> events;
    QHash<QString, bool> playTable;
    QMutex globalPlay;

    QMutex mutex;
public:
    void push_event(Tango::DataReadyEventData *dred);

    explicit DataReceiver(QObject *parent = NULL);
    explicit DataReceiver(QVector<QString> devNames, QObject *parent = NULL);

    ~DataReceiver();


    Tango::DeviceProxy * getDevice(QString devName);

	QJsonObject getDeviceState(QString devName);



signals:
    void updateData(QString devName, QHash<QString, Tango::DeviceAttribute> data);
    void addDeviceIsSuccessful(QString devName, DeviceType type);
    void deviceClosed(QString);

	void getFullImage_done(QString devName, std::vector<unsigned char> data, int width, int height);

public slots:
    void addDevice(QString devName, DeviceType type); //
    void closeDevice(QString devName);//
    void play(QString devName);//
    void pause(QString devName);//
	void setExposure(QString devName);
	void setAttribute(QString devName, Tango::DeviceAttribute attribute);

	void getFullImage(QString devName);

    void close();
};

#endif // DATARECEIVER_H
