#include "ChameleonPropertiesDialog.h"
#include "ui_ChameleonPropertiesDialog.h"

ChameleonPropertiesDialog::ChameleonPropertiesDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChameleonPropertiesDialog)
{
    ui->setupUi(this);
    this->name = name;
}

ChameleonPropertiesDialog::~ChameleonPropertiesDialog()
{
    delete ui;
}

void ChameleonPropertiesDialog::on_buttonBox_accepted()
{
    this->setVisible(false);
}

void ChameleonPropertiesDialog::on_buttonBox_rejected()
{
    this->setVisible(false);
}

void ChameleonPropertiesDialog::refreshData(QString devName, QHash<QString, Tango::DeviceAttribute> data) {

    ui->deviceName->setText(devName);

    /** PARAMETERS **/
    double _frameRate = data["frameRate"].DoubleSeq[0];
	double _frameRateMin = data["frameRateMin"].DoubleSeq[0];
	double _frameRateMax = data["frameRateMax"].DoubleSeq[0];
    bool _frameRateAuto = data["frameRateAuto"].BooleanSeq[0];
    bool _frameRateOnOff = data["frameRateOnOff"].BooleanSeq[0];

    double _exposure = data["exposure"].DoubleSeq[0];
	double _exposureMin = data["exposureMin"].DoubleSeq[0];
	double _exposureMax = data["exposureMax"].DoubleSeq[0];
    bool _exposureAuto = data["exposureAuto"].BooleanSeq[0];
    bool _exposureOnOff = data["exposureOnOff"].BooleanSeq[0];
    bool _exposureOnePush = data["exposureOnePush"].BooleanSeq[0];

    double _gamma = data["gamma"].DoubleSeq[0];
	double _gammaMin = data["gammaMin"].DoubleSeq[0];
	double _gammaMax = data["gammaMax"].DoubleSeq[0];
    bool _gammaOnOff = data["gammaOnOff"].BooleanSeq[0];

    double _gain = data["gain"].DoubleSeq[0];
	double _gainMin = data["gainMin"].DoubleSeq[0];
	double _gainMax = data["gainMax"].DoubleSeq[0];
    bool _gainAuto = data["gainAuto"].BooleanSeq[0];
    bool _gainOnePush = data["gainOnePush"].BooleanSeq[0];

    double _shutter = data["shutter"].DoubleSeq[0];
	double _shutterMin = data["shutterMin"].DoubleSeq[0];
	double _shutterMax = data["shutterMax"].DoubleSeq[0];
    bool _shutterAuto = data["shutterAuto"].BooleanSeq[0];
    bool _shutterOnePush = data["shutterOnePush"].BooleanSeq[0];

    int quality = data["quality"].LongSeq[0];


    ui->frameRateSlider->setValue((int)(_frameRate * 1000));
	ui->frameRateSlider->setMinimum((int)(_frameRateMin * 1000));
	ui->frameRateSlider->setMaximum((int)(_frameRateMax * 1000));
    ui->frameRateBox->setValue(_frameRate);
	ui->frameRateBox->setMinimum(_frameRateMin);
	ui->frameRateBox->setMaximum(_frameRateMax);
    ui->frameRateAuto->setChecked(_frameRateAuto);
    ui->frameRateOnOff->setChecked(_frameRateOnOff);

    ui->exposureSlider->setValue((int)(_exposure * 1000));
	ui->exposureSlider->setMinimum((int)(_exposureMin * 1000));
	ui->exposureSlider->setMaximum((int)(_exposureMax * 1000));
    ui->exposureBox->setValue(_exposure);
	ui->exposureBox->setMinimum(_exposureMin);
	ui->exposureBox->setMaximum(_exposureMax);
    ui->exposureAuto->setChecked(_exposureAuto);
    ui->exposureOnOff->setChecked(_exposureOnOff);
    ui->exposureOnePush->setChecked(_exposureOnePush);

    ui->gammaSlider->setValue((int)(_gamma * 1000));
	ui->gammaSlider->setMinimum((int)(_gammaMin * 1000));
	ui->gammaSlider->setMaximum((int)(_gammaMax * 1000));
    ui->gammaBox->setValue(_gamma);
	ui->gammaBox->setMinimum(_gammaMin);
	ui->gammaBox->setMaximum(_gammaMax);
    ui->gammaOnOff->setChecked(_gammaOnOff);

    ui->gainSlider->setValue((int)(_gain * 1000));
	ui->gainSlider->setMinimum((int)(_gainMin * 1000));
	ui->gainSlider->setMaximum((int)(_gainMax * 1000));
    ui->gainBox->setValue(_gain);
	ui->gainBox->setMinimum(_gainMin);
	ui->gainBox->setMaximum(_gainMax);
    ui->gainAuto->setChecked(_gainAuto);
    ui->gainOnePush->setChecked(_gainOnePush);

    ui->shutterSlider->setValue((int)(_shutter * 1000));
	ui->shutterSlider->setMinimum((int)(_shutterMin * 1000));
	ui->shutterSlider->setMaximum((int)(_shutterMax * 1000));
    ui->shutterBox->setValue(_shutter);
    ui->shutterAuto->setChecked(_shutterAuto);
    ui->shutterOnePush->setChecked(_shutterOnePush);

    ui->qualitySlider->setValue(quality);
    ui->qualityBox->setValue(quality);

    /** MEASUREMENTS **/

	double a = data["a"].DoubleSeq[0];
	double b = data["b"].DoubleSeq[0];
	double x = data["x"].DoubleSeq[0];
	double y = data["y"].DoubleSeq[0];
	double phi = data["phi"].DoubleSeq[0];

	ui->ABox->setValue(a);
	ui->BBox->setValue(b);
	ui->XBox->setValue(x);
	ui->YBox->setValue(y);
	ui->PhiBox->setValue(phi);

}

void ChameleonPropertiesDialog::on_frameRateSlider_sliderMoved(int val)
{
    Tango::DeviceAttribute attr("frameRate", (double)val / 1000.0);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_frameRateBox_editingFinished()
{
    double val = ui->frameRateBox->value();
    Tango::DeviceAttribute attr("frameRate", val);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_frameRateAuto_clicked(bool checked)
{
    Tango::DeviceAttribute attr("frameRateAuto", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_frameRateOnOff_clicked(bool checked)
{
    Tango::DeviceAttribute attr("frameRateOnOff", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_exposureSlider_sliderMoved(int position)
{
    Tango::DeviceAttribute attr("exposure", (double)position / 1000.0);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_exposureBox_editingFinished()
{
    double val = ui->exposureBox->value();
    Tango::DeviceAttribute attr("exposure", val);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_exposureAuto_clicked(bool checked)
{
    Tango::DeviceAttribute attr("exposureAuto", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_exposureOnOff_clicked(bool checked)
{
    Tango::DeviceAttribute attr("exposureOnOff", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_exposureOnePush_clicked(bool checked)
{
    Tango::DeviceAttribute attr("exposureOnePush", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gammaSlider_sliderMoved(int position)
{
    Tango::DeviceAttribute attr("gamma", (double)position / 1000.0);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gammaBox_editingFinished()
{
    double val = ui->gammaBox->value();
    Tango::DeviceAttribute attr("gamma", val);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gammaOnOff_clicked(bool checked)
{
    Tango::DeviceAttribute attr("gammaOnOff", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gainSlider_sliderMoved(int position)
{
    Tango::DeviceAttribute attr("gain", (double)position / 1000.0);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gainBox_editingFinished()
{
    double val = ui->gainBox->value();
    Tango::DeviceAttribute attr("gain", val);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gainAuto_clicked(bool checked)
{
    Tango::DeviceAttribute attr("gainAuto", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_gainOnePush_clicked(bool checked)
{
    Tango::DeviceAttribute attr("gainOnePush", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_shutterSlider_sliderMoved(int position)
{
    Tango::DeviceAttribute attr("shutter", (double)position / 1000.0);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_shutterBox_editingFinished()
{
    double val = ui->shutterBox->value();
    Tango::DeviceAttribute attr("shutter", val);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_shutterAuto_clicked(bool checked)
{
    Tango::DeviceAttribute attr("shutterAuto", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_shutterOnePush_clicked(bool checked)
{
    Tango::DeviceAttribute attr("shutterOnePush", checked);
    emit propertyChanged(name, attr);
}

void ChameleonPropertiesDialog::on_qualitySlider_sliderMoved(int position) {
    Tango::DeviceAttribute attr("quality", position);
    emit propertyChanged(name, attr);
}
