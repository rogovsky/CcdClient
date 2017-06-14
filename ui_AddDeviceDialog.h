/********************************************************************************
** Form generated from reading UI file 'AddDeviceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICEDIALOG_H
#define UI_ADDDEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDeviceDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *deviceNameLine;
    QComboBox *deviceType;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddDeviceDialog)
    {
        if (AddDeviceDialog->objectName().isEmpty())
            AddDeviceDialog->setObjectName(QStringLiteral("AddDeviceDialog"));
        AddDeviceDialog->resize(424, 130);
        gridLayout = new QGridLayout(AddDeviceDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        deviceNameLine = new QLineEdit(AddDeviceDialog);
        deviceNameLine->setObjectName(QStringLiteral("deviceNameLine"));

        gridLayout->addWidget(deviceNameLine, 1, 0, 1, 1);

        deviceType = new QComboBox(AddDeviceDialog);
        deviceType->setObjectName(QStringLiteral("deviceType"));
        deviceType->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(deviceType, 1, 2, 1, 1);

        label = new QLabel(AddDeviceDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddDeviceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);

        label_2 = new QLabel(AddDeviceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(AddDeviceDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);


        retranslateUi(AddDeviceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDeviceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDeviceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDeviceDialog)
    {
        AddDeviceDialog->setWindowTitle(QApplication::translate("AddDeviceDialog", "Add new device", 0));
        deviceNameLine->setText(QApplication::translate("AddDeviceDialog", "test/CcdCameraChameleon/dev1", 0));
        deviceType->clear();
        deviceType->insertItems(0, QStringList()
         << QApplication::translate("AddDeviceDialog", "CCD_Camera_Chameleon", 0)
         << QApplication::translate("AddDeviceDialog", "CCD_Camera_BINP", 0)
        );
        label->setText(QApplication::translate("AddDeviceDialog", "<html><head/><body><p><span style=\" font-weight:600; color:#6a6a6a;\">Example:</span><span style=\" color:#6a6a6a;\"> test/CcdCameraChameleon/dev1</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("AddDeviceDialog", "<b>Device name</b>", 0));
        label_3->setText(QApplication::translate("AddDeviceDialog", "<b>Device type</b>", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDeviceDialog: public Ui_AddDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICEDIALOG_H
