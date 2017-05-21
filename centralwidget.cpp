#include "centralwidget.h"
#include "ui_CentralWidget.h"
#include <QFileDialog>

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
}

CentralWidget::~CentralWidget() {
    delete ui;
    if (widgets.size() > 0) {
        for (QString key : widgets.keys()) {
            for (ImageWidget *widget : widgets[key]) {
                widgets[key].removeOne(widget);
                delete widget;
            }
            widgets.remove(key);
        }
    }

}

void CentralWidget::updateData(QString key, QHash<QString, Tango::DeviceAttribute> data) {
    if (widgets.contains(key)) {
        for (ImageWidget *widget : widgets[key]) {

            connect(this, SIGNAL(refresh(QString,QHash<QString,Tango::DeviceAttribute>)),
                    widget, SLOT(setAttributes(QString,QHash<QString,Tango::DeviceAttribute>)));

        }

        emit refresh(key, data);

        for (ImageWidget *widget : widgets[key]) {

            disconnect(this, SIGNAL(refresh(QString,QHash<QString,Tango::DeviceAttribute>)),
                       widget, SLOT(setAttributes(QString,QHash<QString,Tango::DeviceAttribute>)));

        }
    }
}

void CentralWidget::addImageWidget(QString devName, DeviceType type) {
    ImageWidget* widget = new ImageWidget(devName, type);

    connect(widget, SIGNAL(attributeChanged(QString,Tango::DeviceAttribute)),
            this, SLOT(changeAttribute(QString,Tango::DeviceAttribute)));
    connect(widget, SIGNAL(play(QString)), this, SLOT(playProxy(QString)));
    connect(widget, SIGNAL(pause(QString)), this, SLOT(pauseProxy(QString)));
	connect(widget, SIGNAL(close(ImageWidget *)), this, SLOT(closeDeviceProxy(ImageWidget *)));
	connect(widget, SIGNAL(saveImage(ImageWidget*)), this, SLOT(getFullImageSlot(ImageWidget*)));

    if (!widgets.contains(devName)) {
        QVector<ImageWidget*> qvector;
        widgets[devName] = qvector;
    }
    widgets[devName].push_back(widget);
    ui->layout->addWidget(widget, _row, _col);
    if (_col == 3) {
        _col = 0;
        _row++;
    } else
        _col++;
}

void CentralWidget::closeImageWidget(QString devName, int id) {
    if (!widgets.contains(devName))
        return;

    ImageWidget* widget = widgets[devName][id];

    ui->layout->removeWidget(widget);
    widgets[devName].remove(id);
    if (widgets[devName].size() == 0)
        widgets.remove(devName);
    delete widget;

    _col--;
    if (_col < 0) {
        _row--;
        _col = 3;
    }
}

void CentralWidget::changeAttribute(QString devName, Tango::DeviceAttribute attribute) {
    emit attributeChanged(devName, attribute);
}

void CentralWidget::closeDeviceProxy(ImageWidget *widget) {

    for (QString key : widgets.keys()) {
        for (ImageWidget *w : widgets[key]) {
            if ( w == widget ) {
                int id = widgets[key].indexOf(w);
                this->closeImageWidget(key, id);
                if (widgets[key].size() == 0)
                    emit closeDevice(key);
            }
        }
    }
}

void CentralWidget::getFullImageSlot(ImageWidget* widget) {
	saveFullImageToFile_widget = widget;
	if (widget != NULL)
		emit getFullImage(widget->getName());
}

void CentralWidget::saveFullImageToFile(QString devName, std::vector<unsigned char> image, int width, int height) {
	QString fileName = QFileDialog::getSaveFileName(NULL,
													tr("Save File"),
													QString("~/image.png"),
													tr("*.png (*.png);;*.bmp (*.bmp);;*.jpg (*.jpg)"));
	if (fileName != "") {
		QString upperCase = fileName.toUpper();

		QImage qimage(image.data(), width, height, QImage::Format_Grayscale8);
		if (upperCase.endsWith(".PNG")) {
			qimage.save(fileName, "PNG");
		} else if (upperCase.endsWith(".JPG")) {
			qimage.save(fileName, "JPG", 100);
		} else if (upperCase.endsWith(".BMP")) {
			qimage.save(fileName, "BMP");
		} else {
			fileName.append(".png");
			qimage.save(fileName, "PNG");
		}
	} else {
		//error
	}
}

void CentralWidget::receiveImage(QString devName, std::vector<unsigned char> data, int width, int height) {
	saveFullImageToFile(devName, data, width, height);
}

