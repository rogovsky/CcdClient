#include "AddDeviceDialog.h"
#include "ui_AddDeviceDialog.h"
#include <iostream>

using namespace std;

AddDeviceDialog::AddDeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDeviceDialog)
{
    ui->setupUi(this);
}

AddDeviceDialog::~AddDeviceDialog()
{
    delete ui;
}

void AddDeviceDialog::on_buttonBox_accepted() {
    QString devName = ui->deviceNameLine->text();
    QString strType = ui->deviceType->currentText();
    DeviceType type;
    if (strType == "CCD_Camera_Chameleon")
        type = CCD_Camera_Chameleon;
    else if (strType == "CCD_Camera_BINP")
        type = CCD_Camera_BINP;

    emit addDevice(devName, type);
    this->close();
}

void AddDeviceDialog::on_buttonBox_rejected() {
    this->close();
}
