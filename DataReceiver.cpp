#include <QErrorMessage>
#include <vector>
#include <string>
#include <iostream>
#include <QTime>
#include "DataReceiver.h"
#include <fstream>

using namespace std;

DataReceiver::DataReceiver(QObject *parent) : QThread(parent){

}

DataReceiver::DataReceiver(QVector<QString> devNames, QObject *parent) : QThread(parent) {
	bool exception = false;
	QVector<QString> missingDevices;

	for (QString devName : devNames) {
		try {
			std::string str = devName.toStdString();
			devices[devName] = new Tango::DeviceProxy(str.data());
			playTable[devName] = true;
		} catch(Tango::ConnectionFailed) {
			QString str;
			str += "Connection failed";
			QErrorMessage* err = new QErrorMessage(NULL);
			err->setAttribute(Qt::WA_DeleteOnClose);
			err->showMessage(str);
		} catch(Tango::DevFailed) {
			missingDevices.push_back(devName);
			exception = true;
		}
	}

	if(exception) {
		QString str;
		str += "Devices:\n";
		for (int i = 0; i < missingDevices.size(); i++) {
			str += missingDevices[i];
			str += '\n';
		}
		str += "not in database.";
		QErrorMessage* err = new QErrorMessage(NULL);
		err->setAttribute(Qt::WA_DeleteOnClose);
		err->showMessage(str);
	}


	//this->start();
}

DataReceiver::~DataReceiver() {
	for (QString key : devices.keys()) {
		Tango::DeviceProxy *device = devices[key];
		devices.remove(key);
		delete device;
	}
}

/** SOME FUNCTIONS **/
Tango::DeviceProxy * DataReceiver::getDevice(QString devName) {
	if (devices.contains(devName)) {
		return devices[devName];
	} else {
		return NULL;
	}
}

/** THREAD **/
void DataReceiver::run() {
	QTime t1;
	while (running) {
		t1.start();

		if (devices.keys().size() == 0)
			break;

		globalPlay.lock();
		mutex.lock();

		/** BEGIN RECIEVING **/

		//data.clear();

		int abc = 0;

		for (QString key : devices.keys()) {
			if (!playTable[key])
				continue;
			try {

				Tango::DeviceProxy * device = devices[key];


				//std::cout << "get_attribute_list()" << std::endl;
				std::vector<std::string>* attrNames = device->get_attribute_list();

				//std::cout << "read_attributes()" << std::endl;
				std::vector<Tango::DeviceAttribute> *attributes = device->read_attributes(*attrNames);

				QHash<QString,Tango::DeviceAttribute> attrHash;
				//std::cout << "for()" << std::endl;
				for (unsigned int i = 0; i < attributes->size(); i++) {
					Tango::DeviceAttribute& attr = (*attributes)[i];
					attrHash[QString(attr.get_name().data())] = attr;
				}

				delete attrNames;
				delete attributes;

				//data[key] = attrHash;
				//if (data.size() > 0)
				emit updateData(key, attrHash);



			} catch(Tango::CommunicationFailed) {
				std::cout << "CommunicationFailed" << std::endl;
				abc++;
			} catch(Tango::ConnectionFailed) {

			} catch(Tango::DevFailed) {
				this->closeDevice(key);
			}

		}

		/** END RECIEVING **/

		/** EMITTING SIGNAL **/


		mutex.unlock();
		globalPlay.unlock();

		std::cout << 1000.0 / (float)t1.elapsed() << std::endl;

	}
}

/** SLOTS **/
void DataReceiver::addDevice(QString devName, DeviceType type) {

//	for (int i = 1; i <= 8; i++) {
//		if (devName == QString::number(i)) {
//			emit addDeviceIsSuccessful(devName, type);
//			return;
//		}
//	}
	mutex.lock();

	try {
		if (!devices.contains(devName)) {
			devices[devName] = new Tango::DeviceProxy(devName.toStdString().data());
			playTable[devName] = true;
			int eventId = devices[devName]->subscribe_event("imageEncodedJpeg", Tango::DATA_READY_EVENT, this);
			if (!events.contains(devName)) {
				QVector<int> v;
				events[devName] = v;
			}

			events[devName].push_back(eventId);

			attrNames[devName] = getAttrNames(type);
			saveStateAttrNames[devName] = getSaveStateAttrNames(type);

		}

		emit addDeviceIsSuccessful(devName, type);

	} catch(Tango::ConnectionFailed) {
		QString str;
		str += "Connection failed\n";
		QErrorMessage* err = new QErrorMessage(NULL);
		err->setAttribute(Qt::WA_DeleteOnClose);
		err->showMessage(str);
	} catch(Tango::EventSystemFailed esf) {
		QString str;
		str += "Failed to subscribe data ready event \n";
		str += "Device ";
		str += devName;
		str += " errors:\n";
		for (int err = 0; err < esf.errors.length(); err++) {
			str += QString(esf.errors[err].desc.in());
			str += "\n";
		}

		QErrorMessage* err = new QErrorMessage(NULL);
		err->setAttribute(Qt::WA_DeleteOnClose);
		err->showMessage(str);
	} catch(Tango::DevFailed df) {
		QString str;
		str += "Device ";
		str += devName;
		str += " errors: ";
		for (int err = 0; err < df.errors.length(); err++) {
			str += QString(df.errors[err].desc.in());
			str.append('\n');
		}
		QErrorMessage* err = new QErrorMessage(NULL);
		err->setAttribute(Qt::WA_DeleteOnClose);
		err->showMessage(str);
	}

	mutex.unlock();

	//    if (!this->isRunning()) {
	//        this->start();
	//    }

}

void DataReceiver::closeDevice(QString devName) {

	mutex.lock();


	if (devName == "") {
		for (QString key : devices.keys()) {
			try {
				Tango::DeviceProxy * device = devices[key];
				for (int eventId : events[key]) {
					try {
						device->unsubscribe_event(eventId);
					} catch (Tango::EventSystemFailed) {

					}
				}

				devices.remove(key);
				delete device;

				emit deviceClosed(key);
			} catch (Tango::DevFailed) {

			}
		}
	} else if (devices.contains(devName)) {
		try {
			Tango::DeviceProxy * device = devices[devName];
			for (int eventId : events[devName]) {
				try {
					device->unsubscribe_event(eventId);
				} catch (Tango::EventSystemFailed) {

				}
			}
			devices.remove(devName);
			delete device;

			emit deviceClosed(devName);
		} catch (Tango::DevFailed) {

		}
	}

	mutex.unlock();

}

void DataReceiver::play(QString devName) {
	try {
		if (devName == "") {

			for (QString key : devices.keys()) {
				devices[key]->command_inout("play");
			}
		} else {
			if (devices.contains(devName)) {
				devices[devName]->command_inout("play");
			}
		}

		playTable[devName] = true;
	} catch (Tango::DevFailed) {

	}
}

void DataReceiver::pause(QString devName) {
	try {
		if (devName == "") {

			for (QString key : devices.keys()) {
				devices[key]->command_inout("pause");
			}
		} else {
			if (devices.contains(devName)) {
				devices[devName]->command_inout("pause");
			}
		}

		playTable[devName] = false;
	} catch (Tango::DevFailed) {

	}
}

void DataReceiver::close() {
	running = false;
}

void DataReceiver::setAttribute(QString devName, Tango::DeviceAttribute attribute) {
	if (devices.contains(devName)) {
		try {
			devices[devName]->write_attribute(attribute);
		} catch(Tango::DevFailed df) {

			QString str;
			str += "Device ";
			str += devName;
			str += " errors:\n";
			for (int err = 0; err < df.errors.length(); err++) {
				str += QString(df.errors[err].desc.in());
				str += "\n";
			}
			QErrorMessage* err = new QErrorMessage(NULL);
			err->setAttribute(Qt::WA_DeleteOnClose);
			err->showMessage(str);
		}
	} else {
		QString str;
		str += "Device ";
		str += devName;
		str += " not in database.";
		QErrorMessage* err = new QErrorMessage(NULL);
		err->setAttribute(Qt::WA_DeleteOnClose);
		err->showMessage(str);
	}
}

void DataReceiver::push_event(Tango::PipeEventData *ped) {
	try {
		Tango::DeviceProxy *device = ped->device;

		Tango::DevicePipe *pipe = ped->pipe_value;

		QHash<QString, Tango::DeviceAttribute> attrHash;

		for (unsigned int i = 0; i < pipe->get_data_elt_nb(); i++) {
			std::string str = pipe->get_data_elt_name(i);

			int type = pipe->get_data_elt_type(i);

			switch (type) {
			case Tango::DEV_DOUBLE: {
				double val1;
				(*pipe)[str] >> val1;

				Tango::DeviceAttribute attr(str, val1);
				attrHash[QString(str.data())] = attr;
				break;
			}
			case Tango::DEV_BOOLEAN: {
				bool val2;
				(*pipe)[str] >> val2;
				Tango::DeviceAttribute attr(str, val2);
				attrHash[QString(str.data())] = attr;
				break;
			}
			case Tango::DEV_LONG: {
				int val3;
				(*pipe)[str] >> val3;
				Tango::DeviceAttribute attr(str, val3);
				attrHash[QString(str.data())] = attr;
				break;
			}
			case Tango::DEVVAR_CHARARRAY: {
				std::vector<unsigned char> val4;
				(*pipe)[str] >> val4;
				Tango::DeviceAttribute attr(str, val4);
				attrHash[QString(str.data())] = attr;
				break;
			}
			}
		}
		if (attrHash.size() > 0)
			emit updateData(devices.key(device), attrHash);
	} catch(Tango::DevFailed) {
		std::cout << "dev failed" << std::endl;
	}
}

QTime t;
void DataReceiver::push_event(Tango::DataReadyEventData *dred) {
	try {
		Tango::DeviceProxy * device = dred->device;
		if (devices.key(device).isNull())
			return;
		//std::cout << "get_attribute_list()" << std::endl;

		QString devName = devices.key(device);

		vector<std::string> names = attrNames[devName];

		//std::cout << "read_attributes()" << std::endl;
		vector<Tango::DeviceAttribute> *attributes = device->read_attributes(names);

		QHash<QString,Tango::DeviceAttribute> attrHash;
		//std::cout << "for()" << std::endl;
		for (unsigned int i = 0; i < attributes->size(); i++) {
			Tango::DeviceAttribute& attr = (*attributes)[i];
			attrHash[QString(attr.get_name().data())] = attr;
		}

		delete attributes;

		QString key = devices.key(device);
		emit updateData(key, attrHash);

		//std::cout << 1000.0 / (float)t.elapsed() << std::endl;
		//t.start();

	} catch(Tango::DevFailed) {

	}
}


void DataReceiver::getFullImage(QString devName) {
	try {
		Tango::DeviceProxy* device = devices[devName];
		if (device != NULL) {
			Tango::DeviceAttribute attr1 = device->read_attribute("fullImage");
			Tango::DeviceAttribute attr2 = device->read_attribute("imageWidth");
			Tango::DeviceAttribute attr3 = device->read_attribute("imageHeight");

			std::vector<unsigned char> image;
			int width, height;
			attr1 >> image;
			width = attr2.LongSeq[0];
			height = attr3.LongSeq[0];

			emit getFullImage_done(devName, image, width, height);
		}
	} catch (Tango::DevFailed) {

	}
}

QJsonObject DataReceiver::getDeviceState(QString devName) {
	QJsonObject json;
	if (devName != "") {

		Tango::DeviceProxy * device = devices[devName];
		vector<Tango::DeviceAttribute> *attributes = device->read_attributes(saveStateAttrNames[devName]);
		QJsonObject jobj;
		for (Tango::DeviceAttribute attr : *attributes) {
			QString name(attr.get_name().data());
			switch (attr.get_type()) {
			case 1:
				jobj.insert(name, QJsonValue(attr.BooleanSeq[0]));
				break;
			case 3:
				jobj.insert(name, QJsonValue(attr.LongSeq[0]));
				break;
			case 5:
				jobj.insert(name, QJsonValue(attr.DoubleSeq[0]));
				break;
			}
		}
		json.insert(devName, QJsonValue(jobj));
		delete attributes;
	} else {
		for (QString key : devices.keys()) {
			Tango::DeviceProxy * device = devices[key];
			QJsonObject jobj;

			vector<Tango::DeviceAttribute> *attributes = device->read_attributes(saveStateAttrNames[key]);
			for (Tango::DeviceAttribute attr : *attributes) {
				QString name(attr.get_name().data());
				switch (attr.get_type()) {
				case 1:
					jobj.insert(name, QJsonValue(attr.BooleanSeq[0]));
					break;
				case 3:
					jobj.insert(name, QJsonValue(attr.LongSeq[0]));
					break;
				case 5:
					jobj.insert(name, QJsonValue(attr.DoubleSeq[0]));
					break;
				}
			}
			delete attributes;
			json.insert(key, QJsonValue(jobj));
		}
	}
	return json;
}
