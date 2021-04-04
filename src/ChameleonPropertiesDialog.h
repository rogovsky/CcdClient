#ifndef CHAMELEONPROPERTIESDIALOG_H
#define CHAMELEONPROPERTIESDIALOG_H

#include <QDialog>
#include <QString>
#include <QHash>
#include <tango.h>


namespace Ui {
class ChameleonPropertiesDialog;
}

class ChameleonPropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChameleonPropertiesDialog(QString name, QWidget *parent = 0);
    ~ChameleonPropertiesDialog();


signals:
    void propertyChanged(QString devName, Tango::DeviceAttribute attribute);

public slots:
    void refreshData(QString devName, QHash<QString, Tango::DeviceAttribute>);

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_frameRateSlider_sliderMoved(int val);

    void on_frameRateBox_editingFinished();

    void on_frameRateAuto_clicked(bool checked);

    void on_frameRateOnOff_clicked(bool checked);

    void on_exposureSlider_sliderMoved(int position);

    void on_exposureBox_editingFinished();

    void on_exposureAuto_clicked(bool checked);

    void on_exposureOnOff_clicked(bool checked);

    void on_exposureOnePush_clicked(bool checked);

    void on_gammaSlider_sliderMoved(int position);

    void on_gammaBox_editingFinished();

    void on_gammaOnOff_clicked(bool checked);

    void on_gainSlider_sliderMoved(int position);

    void on_gainBox_editingFinished();

    void on_gainAuto_clicked(bool checked);

    void on_gainOnePush_clicked(bool checked);

    void on_shutterSlider_sliderMoved(int position);

    void on_shutterBox_editingFinished();

    void on_shutterAuto_clicked(bool checked);

    void on_shutterOnePush_clicked(bool checked);


    void on_qualitySlider_sliderMoved(int position);

private:
    Ui::ChameleonPropertiesDialog *ui;

    QString name;
};

#endif // CHAMELEONPROPERTIESDIALOG_H
