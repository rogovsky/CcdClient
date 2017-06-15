#include "AddDeviceDialog.h"
#include "ui_AddDeviceDialog.h"
#include <iostream>
#include <QFile>

using namespace std;

AddDeviceDialog::AddDeviceDialog(QWidget *parent) :
    QDialog(parent),
	ui(new Ui::AddDeviceDialog) {
    ui->setupUi(this);
	QFile file("lastcam.txt");
	if (file.open(QIODevice::ReadOnly)){
		line = new char[255];
		file.readLine(line, 255);
		ui->deviceNameLine->setText(QString(line));
		file.close();
	} else {
		ui->deviceNameLine->setText(QString(""));
	}
}

AddDeviceDialog::~AddDeviceDialog() {
    delete ui;
	if (line != NULL)
		delete[] line;
}

void AddDeviceDialog::on_buttonBox_accepted() {
    QString devName = ui->deviceNameLine->text();
    QString strType = ui->deviceType->currentText();
    DeviceType type;
    if (strType == "CCD_Camera_Chameleon")
        type = CCD_Camera_Chameleon;
    else if (strType == "CCD_Camera_BINP")
        type = CCD_Camera_BINP;

	QFile file("lastcam.txt");
	if (file.open(QIODevice::WriteOnly)) {
		file.write(devName.toStdString().data(), devName.length());
		file.close();
	}

    emit addDevice(devName, type);
    this->close();
}

void AddDeviceDialog::on_buttonBox_rejected() {
    this->close();
}
