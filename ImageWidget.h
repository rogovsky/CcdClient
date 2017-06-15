#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QFrame>
#include <QMouseEvent>
#include <QHash>
#include <tango.h>
#include <QWindow>
#include <QTime>
#include <QMutex>

#include "ChameleonPropertiesDialog.h"
#include "DeviceType.h"

#include <jpeglib.h>

namespace Ui {
class ImageWidget;
}

class ImageWidget : public QFrame
{
    Q_OBJECT

private:

    QString name;
    DeviceType type;

    QImage image;
    QVector<QRgb> colorTable;
	int imageWidth = 1280, imageHeight = 960;

    double scale = 1.0;

    unsigned char *buffer = NULL;
    QMutex updateMutex;

    QDialog *propertiesDialog = 0;

	double X = 0, Y = 0;
	double A = 0, B = 0;
	double Phi = 0;

    bool played = false;

    QTime t;

	int fpsCounter = 0;
	double fps = 15.0;
	double fpsDev = 15.0;
	double fpsCurr = 0;

    void drawMeasurements(QPainter &painter, int x0, int y0, double cx, double cy, double sx, double sY, double phi);

public:
    explicit ImageWidget(QString name, DeviceType type, QWidget *parent = 0);
    ~ImageWidget();

	QString getName() { return name; }

	QVector<QRgb> getColorTable() { return colorTable; }

signals:
    void attributesChanged(QString devName, QHash<QString, Tango::DeviceAttribute>);
	void attributeChanged(QString devName, Tango::DeviceAttribute attribute);
    void play(QString);
    void pause(QString);
	void setExposure(QString);
    void close(ImageWidget*);
	void saveImage(ImageWidget*);

public slots:
    void setAttributes(QString devName, QHash<QString, Tango::DeviceAttribute>);
    void changeAttribute(QString camera, Tango::DeviceAttribute attribute);
    void showPropertiesDialog();
    void contextPlay();
    void contextPause();
	void contextSetExposure();
    void contextClose();
	void contextSaveImage();

    void showContextMenu(const QPoint&);

private:
	void paintEvent(QPaintEvent *e);

    int decodeJpeg(unsigned char *src, unsigned long src_size, unsigned char **buffer, int *size, int *width, int *height);

	void resizeEvent(QResizeEvent *event);

private:
    Ui::ImageWidget *ui;
};

#endif // IMAGEWIDGET_H
