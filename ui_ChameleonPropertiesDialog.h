/********************************************************************************
** Form generated from reading UI file 'ChameleonPropertiesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAMELEONPROPERTIESDIALOG_H
#define UI_CHAMELEONPROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "mousepressableslider.h"

QT_BEGIN_NAMESPACE

class Ui_ChameleonPropertiesDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *deviceProperties;
    QGridLayout *gridLayout_2;
    QGroupBox *parametersOfCameraBox;
    QGridLayout *gridLayout_5;
    QLabel *label_18;
    QLabel *label_17;
    QCheckBox *gammaOnOff;
    QLabel *label_19;
    QCheckBox *gainOnePush;
    QCheckBox *frameRateOnOff;
    QCheckBox *gainAuto;
    QLabel *exposureLabel;
    QLabel *frameRateLabel;
    MousePressableSlider *frameRateSlider;
    MousePressableSlider *gammaSlider;
    MousePressableSlider *shutterSlider;
    QDoubleSpinBox *exposureBox;
    QDoubleSpinBox *gammaBox;
    QDoubleSpinBox *shutterBox;
    QDoubleSpinBox *gainBox;
    QLabel *dB;
    QLabel *ms;
    QCheckBox *shutterAuto;
    QCheckBox *exposureOnOff;
    QCheckBox *frameRateAuto;
    QCheckBox *exposureOnePush;
    QCheckBox *exposureAuto;
    QLabel *fps;
    QCheckBox *shutterOnePush;
    QLabel *eV;
    MousePressableSlider *gainSlider;
    QLabel *shutterLabel;
    QLabel *gammaLabel;
    QLabel *gainLabel;
    MousePressableSlider *exposureSlider;
    QDoubleSpinBox *frameRateBox;
    QLabel *qualityLabel;
    MousePressableSlider *qualitySlider;
    QSpinBox *qualityBox;
    QGroupBox *deviceNameBox;
    QGridLayout *gridLayout_3;
    QLineEdit *deviceName;
    QSpacerItem *horizontalSpacer;
    QGroupBox *beamMeasurementsBox;
    QGridLayout *gridLayout_6;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *YBox;
    QLabel *xLabel;
    QLabel *yLabel;
    QDoubleSpinBox *XBox;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *ABox;
    QDoubleSpinBox *BBox;
    QFrame *line_2;
    QFrame *line;
    QDoubleSpinBox *PhiBox;

    void setupUi(QDialog *ChameleonPropertiesDialog)
    {
        if (ChameleonPropertiesDialog->objectName().isEmpty())
            ChameleonPropertiesDialog->setObjectName(QStringLiteral("ChameleonPropertiesDialog"));
        ChameleonPropertiesDialog->setWindowModality(Qt::WindowModal);
        ChameleonPropertiesDialog->resize(607, 515);
        gridLayout = new QGridLayout(ChameleonPropertiesDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(ChameleonPropertiesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        tabWidget = new QTabWidget(ChameleonPropertiesDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        deviceProperties = new QWidget();
        deviceProperties->setObjectName(QStringLiteral("deviceProperties"));
        gridLayout_2 = new QGridLayout(deviceProperties);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        parametersOfCameraBox = new QGroupBox(deviceProperties);
        parametersOfCameraBox->setObjectName(QStringLiteral("parametersOfCameraBox"));
        gridLayout_5 = new QGridLayout(parametersOfCameraBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_18 = new QLabel(parametersOfCameraBox);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_5->addWidget(label_18, 0, 5, 1, 1);

        label_17 = new QLabel(parametersOfCameraBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_5->addWidget(label_17, 0, 4, 1, 1);

        gammaOnOff = new QCheckBox(parametersOfCameraBox);
        gammaOnOff->setObjectName(QStringLiteral("gammaOnOff"));

        gridLayout_5->addWidget(gammaOnOff, 3, 5, 1, 1);

        label_19 = new QLabel(parametersOfCameraBox);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_5->addWidget(label_19, 0, 6, 1, 1);

        gainOnePush = new QCheckBox(parametersOfCameraBox);
        gainOnePush->setObjectName(QStringLiteral("gainOnePush"));

        gridLayout_5->addWidget(gainOnePush, 4, 6, 1, 1);

        frameRateOnOff = new QCheckBox(parametersOfCameraBox);
        frameRateOnOff->setObjectName(QStringLiteral("frameRateOnOff"));
        frameRateOnOff->setChecked(true);

        gridLayout_5->addWidget(frameRateOnOff, 1, 5, 1, 1);

        gainAuto = new QCheckBox(parametersOfCameraBox);
        gainAuto->setObjectName(QStringLiteral("gainAuto"));
        gainAuto->setChecked(false);

        gridLayout_5->addWidget(gainAuto, 4, 4, 1, 1);

        exposureLabel = new QLabel(parametersOfCameraBox);
        exposureLabel->setObjectName(QStringLiteral("exposureLabel"));
        exposureLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(exposureLabel, 2, 0, 1, 1);

        frameRateLabel = new QLabel(parametersOfCameraBox);
        frameRateLabel->setObjectName(QStringLiteral("frameRateLabel"));
        frameRateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(frameRateLabel, 1, 0, 1, 1);

        frameRateSlider = new MousePressableSlider(parametersOfCameraBox);
        frameRateSlider->setObjectName(QStringLiteral("frameRateSlider"));
        frameRateSlider->setMinimum(333);
        frameRateSlider->setMaximum(16291);
        frameRateSlider->setValue(15100);
        frameRateSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(frameRateSlider, 1, 1, 1, 1);

        gammaSlider = new MousePressableSlider(parametersOfCameraBox);
        gammaSlider->setObjectName(QStringLiteral("gammaSlider"));
        gammaSlider->setMinimum(500);
        gammaSlider->setMaximum(4000);
        gammaSlider->setValue(1000);
        gammaSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(gammaSlider, 3, 1, 1, 1);

        shutterSlider = new MousePressableSlider(parametersOfCameraBox);
        shutterSlider->setObjectName(QStringLiteral("shutterSlider"));
        shutterSlider->setMinimum(5);
        shutterSlider->setMaximum(66641);
        shutterSlider->setValue(10000);
        shutterSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(shutterSlider, 5, 1, 1, 1);

        exposureBox = new QDoubleSpinBox(parametersOfCameraBox);
        exposureBox->setObjectName(QStringLiteral("exposureBox"));
        exposureBox->setMinimum(-7.58);
        exposureBox->setMaximum(2.41);

        gridLayout_5->addWidget(exposureBox, 2, 2, 1, 1);

        gammaBox = new QDoubleSpinBox(parametersOfCameraBox);
        gammaBox->setObjectName(QStringLiteral("gammaBox"));
        gammaBox->setMinimum(0.5);
        gammaBox->setMaximum(4);
        gammaBox->setValue(1);

        gridLayout_5->addWidget(gammaBox, 3, 2, 1, 1);

        shutterBox = new QDoubleSpinBox(parametersOfCameraBox);
        shutterBox->setObjectName(QStringLiteral("shutterBox"));
        shutterBox->setMinimum(0.01);
        shutterBox->setMaximum(66.64);
        shutterBox->setValue(10);

        gridLayout_5->addWidget(shutterBox, 5, 2, 1, 1);

        gainBox = new QDoubleSpinBox(parametersOfCameraBox);
        gainBox->setObjectName(QStringLiteral("gainBox"));
        gainBox->setMinimum(-5.63);
        gainBox->setMaximum(24);
        gainBox->setValue(0);

        gridLayout_5->addWidget(gainBox, 4, 2, 1, 1);

        dB = new QLabel(parametersOfCameraBox);
        dB->setObjectName(QStringLiteral("dB"));

        gridLayout_5->addWidget(dB, 4, 3, 1, 1);

        ms = new QLabel(parametersOfCameraBox);
        ms->setObjectName(QStringLiteral("ms"));

        gridLayout_5->addWidget(ms, 5, 3, 1, 1);

        shutterAuto = new QCheckBox(parametersOfCameraBox);
        shutterAuto->setObjectName(QStringLiteral("shutterAuto"));
        shutterAuto->setChecked(false);

        gridLayout_5->addWidget(shutterAuto, 5, 4, 1, 1);

        exposureOnOff = new QCheckBox(parametersOfCameraBox);
        exposureOnOff->setObjectName(QStringLiteral("exposureOnOff"));
        exposureOnOff->setChecked(true);

        gridLayout_5->addWidget(exposureOnOff, 2, 5, 1, 1);

        frameRateAuto = new QCheckBox(parametersOfCameraBox);
        frameRateAuto->setObjectName(QStringLiteral("frameRateAuto"));
        frameRateAuto->setChecked(false);

        gridLayout_5->addWidget(frameRateAuto, 1, 4, 1, 1);

        exposureOnePush = new QCheckBox(parametersOfCameraBox);
        exposureOnePush->setObjectName(QStringLiteral("exposureOnePush"));

        gridLayout_5->addWidget(exposureOnePush, 2, 6, 1, 1);

        exposureAuto = new QCheckBox(parametersOfCameraBox);
        exposureAuto->setObjectName(QStringLiteral("exposureAuto"));
        exposureAuto->setChecked(false);

        gridLayout_5->addWidget(exposureAuto, 2, 4, 1, 1);

        fps = new QLabel(parametersOfCameraBox);
        fps->setObjectName(QStringLiteral("fps"));

        gridLayout_5->addWidget(fps, 1, 3, 1, 1);

        shutterOnePush = new QCheckBox(parametersOfCameraBox);
        shutterOnePush->setObjectName(QStringLiteral("shutterOnePush"));

        gridLayout_5->addWidget(shutterOnePush, 5, 6, 1, 1);

        eV = new QLabel(parametersOfCameraBox);
        eV->setObjectName(QStringLiteral("eV"));

        gridLayout_5->addWidget(eV, 2, 3, 1, 1);

        gainSlider = new MousePressableSlider(parametersOfCameraBox);
        gainSlider->setObjectName(QStringLiteral("gainSlider"));
        gainSlider->setMinimum(-5630);
        gainSlider->setMaximum(24000);
        gainSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(gainSlider, 4, 1, 1, 1);

        shutterLabel = new QLabel(parametersOfCameraBox);
        shutterLabel->setObjectName(QStringLiteral("shutterLabel"));
        shutterLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(shutterLabel, 5, 0, 1, 1);

        gammaLabel = new QLabel(parametersOfCameraBox);
        gammaLabel->setObjectName(QStringLiteral("gammaLabel"));
        gammaLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(gammaLabel, 3, 0, 1, 1);

        gainLabel = new QLabel(parametersOfCameraBox);
        gainLabel->setObjectName(QStringLiteral("gainLabel"));
        gainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(gainLabel, 4, 0, 1, 1);

        exposureSlider = new MousePressableSlider(parametersOfCameraBox);
        exposureSlider->setObjectName(QStringLiteral("exposureSlider"));
        exposureSlider->setMinimum(-7585);
        exposureSlider->setMaximum(2414);
        exposureSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(exposureSlider, 2, 1, 1, 1);

        frameRateBox = new QDoubleSpinBox(parametersOfCameraBox);
        frameRateBox->setObjectName(QStringLiteral("frameRateBox"));
        frameRateBox->setMinimum(0.33);
        frameRateBox->setMaximum(16.29);
        frameRateBox->setValue(15.1);

        gridLayout_5->addWidget(frameRateBox, 1, 2, 1, 1);

        qualityLabel = new QLabel(parametersOfCameraBox);
        qualityLabel->setObjectName(QStringLiteral("qualityLabel"));
        qualityLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(qualityLabel, 6, 0, 1, 1);

        qualitySlider = new MousePressableSlider(parametersOfCameraBox);
        qualitySlider->setObjectName(QStringLiteral("qualitySlider"));
        qualitySlider->setMinimum(1);
        qualitySlider->setMaximum(100);
        qualitySlider->setSingleStep(1);
        qualitySlider->setValue(75);
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(qualitySlider, 6, 1, 1, 1);

        qualityBox = new QSpinBox(parametersOfCameraBox);
        qualityBox->setObjectName(QStringLiteral("qualityBox"));
        qualityBox->setMinimum(1);
        qualityBox->setMaximum(100);
        qualityBox->setValue(75);

        gridLayout_5->addWidget(qualityBox, 6, 2, 1, 1);


        gridLayout_2->addWidget(parametersOfCameraBox, 1, 0, 1, 1);

        deviceNameBox = new QGroupBox(deviceProperties);
        deviceNameBox->setObjectName(QStringLiteral("deviceNameBox"));
        gridLayout_3 = new QGridLayout(deviceNameBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        deviceName = new QLineEdit(deviceNameBox);
        deviceName->setObjectName(QStringLiteral("deviceName"));
        deviceName->setMaximumSize(QSize(16777173, 16777215));
        deviceName->setReadOnly(true);

        gridLayout_3->addWidget(deviceName, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_2->addWidget(deviceNameBox, 0, 0, 1, 1);

        beamMeasurementsBox = new QGroupBox(deviceProperties);
        beamMeasurementsBox->setObjectName(QStringLiteral("beamMeasurementsBox"));
        gridLayout_6 = new QGridLayout(beamMeasurementsBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_3 = new QLabel(beamMeasurementsBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 0, 7, 1, 1);

        label = new QLabel(beamMeasurementsBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 4, 1, 1);

        label_2 = new QLabel(beamMeasurementsBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 0, 5, 1, 1);

        YBox = new QDoubleSpinBox(beamMeasurementsBox);
        YBox->setObjectName(QStringLiteral("YBox"));
        YBox->setReadOnly(true);
        YBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        YBox->setMaximum(960);
        YBox->setValue(468.98);

        gridLayout_6->addWidget(YBox, 1, 2, 1, 1);

        xLabel = new QLabel(beamMeasurementsBox);
        xLabel->setObjectName(QStringLiteral("xLabel"));

        gridLayout_6->addWidget(xLabel, 0, 0, 1, 1);

        yLabel = new QLabel(beamMeasurementsBox);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        gridLayout_6->addWidget(yLabel, 0, 2, 1, 1);

        XBox = new QDoubleSpinBox(beamMeasurementsBox);
        XBox->setObjectName(QStringLiteral("XBox"));
        XBox->setReadOnly(true);
        XBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        XBox->setMaximum(1290);
        XBox->setValue(369.11);

        gridLayout_6->addWidget(XBox, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 8, 1, 1);

        ABox = new QDoubleSpinBox(beamMeasurementsBox);
        ABox->setObjectName(QStringLiteral("ABox"));
        ABox->setReadOnly(true);
        ABox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ABox->setMaximum(1280);
        ABox->setValue(71.98);

        gridLayout_6->addWidget(ABox, 1, 4, 1, 1);

        BBox = new QDoubleSpinBox(beamMeasurementsBox);
        BBox->setObjectName(QStringLiteral("BBox"));
        BBox->setReadOnly(true);
        BBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BBox->setMaximum(960);
        BBox->setValue(151.08);

        gridLayout_6->addWidget(BBox, 1, 5, 1, 1);

        line_2 = new QFrame(beamMeasurementsBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_2, 0, 6, 2, 1);

        line = new QFrame(beamMeasurementsBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 0, 3, 2, 1);

        PhiBox = new QDoubleSpinBox(beamMeasurementsBox);
        PhiBox->setObjectName(QStringLiteral("PhiBox"));
        PhiBox->setReadOnly(true);
        PhiBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PhiBox->setMaximum(360);
        PhiBox->setValue(53.09);

        gridLayout_6->addWidget(PhiBox, 1, 7, 1, 1);


        gridLayout_2->addWidget(beamMeasurementsBox, 2, 0, 1, 1);

        tabWidget->addTab(deviceProperties, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(ChameleonPropertiesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChameleonPropertiesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChameleonPropertiesDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChameleonPropertiesDialog);
    } // setupUi

    void retranslateUi(QDialog *ChameleonPropertiesDialog)
    {
        ChameleonPropertiesDialog->setWindowTitle(QApplication::translate("ChameleonPropertiesDialog", "Properties", 0));
        parametersOfCameraBox->setTitle(QApplication::translate("ChameleonPropertiesDialog", "Parameters of camera", 0));
        label_18->setText(QApplication::translate("ChameleonPropertiesDialog", "On/Off", 0));
        label_17->setText(QApplication::translate("ChameleonPropertiesDialog", "Auto", 0));
        gammaOnOff->setText(QString());
        label_19->setText(QApplication::translate("ChameleonPropertiesDialog", "One push", 0));
        gainOnePush->setText(QString());
        frameRateOnOff->setText(QString());
        gainAuto->setText(QString());
        exposureLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Exposure", 0));
        frameRateLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Frame rate", 0));
        dB->setText(QApplication::translate("ChameleonPropertiesDialog", "<html><head/><body><p><span style=\" color:#797979;\">dB</span></p></body></html>", 0));
        ms->setText(QApplication::translate("ChameleonPropertiesDialog", "<html><head/><body><p><span style=\" color:#797979;\">ms</span></p></body></html>", 0));
        shutterAuto->setText(QString());
        exposureOnOff->setText(QString());
        frameRateAuto->setText(QString());
        exposureOnePush->setText(QString());
        exposureAuto->setText(QString());
        fps->setText(QApplication::translate("ChameleonPropertiesDialog", "<html><head/><body><p><span style=\" color:#797979;\">fps</span></p></body></html>", 0));
        shutterOnePush->setText(QString());
        eV->setText(QApplication::translate("ChameleonPropertiesDialog", "<html><head/><body><p><span style=\" color:#797979;\">eV</span></p></body></html>", 0));
        shutterLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Shutter", 0));
        gammaLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Gamma", 0));
        gainLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Gain", 0));
        qualityLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "Quality", 0));
        deviceNameBox->setTitle(QApplication::translate("ChameleonPropertiesDialog", "Device name", 0));
        deviceName->setText(QApplication::translate("ChameleonPropertiesDialog", "test/CcdCameraChameleon/dev1", 0));
        beamMeasurementsBox->setTitle(QApplication::translate("ChameleonPropertiesDialog", "Beam measurements", 0));
        label_3->setText(QApplication::translate("ChameleonPropertiesDialog", "phi", 0));
        label->setText(QApplication::translate("ChameleonPropertiesDialog", "a", 0));
        label_2->setText(QApplication::translate("ChameleonPropertiesDialog", "b", 0));
        xLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "x", 0));
        yLabel->setText(QApplication::translate("ChameleonPropertiesDialog", "y", 0));
        tabWidget->setTabText(tabWidget->indexOf(deviceProperties), QApplication::translate("ChameleonPropertiesDialog", "Device", 0));
    } // retranslateUi

};

namespace Ui {
    class ChameleonPropertiesDialog: public Ui_ChameleonPropertiesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAMELEONPROPERTIESDIALOG_H
