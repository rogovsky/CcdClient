#include "ImageWidget.h"
#include "ui_ImageWidget.h"

#include <QPainter>
#include <QPen>
#include <QMenu>
#include <QAction>
#include <QErrorMessage>
#include <math.h>

#include <iostream>
#include <fstream>

using namespace Tango;


ImageWidget::ImageWidget(QString name, DeviceType type, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ImageWidget)
{
    ui->setupUi(this);

    this->name = name;
    this->type = type;

    if (type == CCD_Camera_Chameleon) {
        propertiesDialog = new ChameleonPropertiesDialog(name, parent);
    } else if (type == CCD_Camera_BINP) {

    }

    QColor color;
    for (int i = 0; i < 255; i++) {
        if ((255.0 - (double)i) / 255.0 * 360.0 > 240) {
			color.setHsv(240, 200, (360.0 - (255.0 - (double)i) / 255.0 * 360.0) / 120.0 * 200.0);
        } else {
			color.setHsv((255.0 - (double)i) / 255.0 * 360.0, 200, 200);
        }

        colorTable.append(color.rgb());
    }
	color.setRgb(200, 200, 200);
    colorTable.append(color.rgb());

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
        this, SLOT(showContextMenu(const QPoint&)));

    connect(propertiesDialog, SIGNAL(propertyChanged(QString,Tango::DeviceAttribute)),
            this, SLOT(changeAttribute(QString,Tango::DeviceAttribute)));
    connect(this, SIGNAL(attributesChanged(QString, QHash<QString,Tango::DeviceAttribute>)),
            propertiesDialog, SLOT(refreshData(QString, QHash<QString,Tango::DeviceAttribute>)));

	t.start();

	played = true;

	this->update();
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::drawMeasurements(QPainter &painter, int x0, int y0, double cX, double cY, double sX, double sY, double phi) {

    //QPen pen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPen mesurementsPen(QColor(168, 0, 255), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	//QPen textPen(QColor(140, 140, 140), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(mesurementsPen);


    painter.save();
	painter.translate(QPoint(x0 + cX, y0 + cY));
	painter.rotate(phi);

    painter.setPen(mesurementsPen);
    //cout << cX << " " << cY << " " << sX << " " << sY << " " << phi << endl;

	painter.drawEllipse(-sX, -sY, 2 * sX, 2 * sY);

//    painter.drawLine(-(int)sX, 0, (int)sX, 0);
//    painter.drawLine(0, -(int)sY, 0, (int)sY);
//    painter.drawLine(-(int)sX, -5, -(int)sX, 5);
//	painter.drawLine((int)sX, -5, (int)sX, 5);
//    painter.drawLine(-5, -(int)sY, 5, -(int)sY);
//	painter.drawLine(-5, (int)sY, 5, (int)sY);

	painter.restore();
}

void ImageWidget::paintEvent(QPaintEvent *e) {
    updateMutex.lock();

    int thisWidth = this->width();
    int thisHeight = this->height();
    int imageWidth = image.width();
    int imageHeight = image.height();

	if (scale > 1.0)
		scale = 1.0;
	else if (scale < 0.01)
		scale = 0.01;

    QPainter painter;
    painter.begin(this);
    painter.fillRect(0, 0, thisWidth, thisHeight, Qt::black);
    QPen pen(QColor(140, 140, 140), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPen mesurementsPen(QColor(168, 0, 255), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    double cX, cY;
    double sX, sY;
    double phi;

    if (image.isNull()) {
        QString str = "Image is null";
        painter.drawText(thisWidth / 2, thisHeight / 2, str);
    } else {

        if ((float)thisWidth / (float)thisHeight > (float)imageWidth / (float)imageHeight) {
            QImage scaledImage = image.scaledToHeight(thisHeight);
            int x0 = thisWidth / 2 - scaledImage.width() / 2;
            int y0 = thisHeight / 2 - scaledImage.height() / 2;

            painter.drawImage(x0, y0, scaledImage);

            painter.setPen(mesurementsPen);

			cX = (X / (double)imageHeight * (double)thisHeight) * scale;
			cY = (Y / (double)imageHeight * (double)thisHeight) * scale;
			sX = (A / (double)imageHeight * (double)thisHeight) * scale;
			sY = (B / (double)imageHeight * (double)thisHeight) * scale;
			phi = Phi;

			if (sX != 0 && sY != 0) {
				painter.save();
				drawMeasurements(painter, x0, y0, cX, cY, sX, sY, Phi);
				painter.restore();
			}


        } else {
            QImage scaledImage = image.scaledToWidth(thisWidth);

            int x0 = thisWidth / 2 - scaledImage.width() / 2;
            int y0 = thisHeight / 2 - scaledImage.height() / 2;

            painter.drawImage(x0, y0, scaledImage);

			painter.setPen(mesurementsPen);

			cX = (int)(X / (double)imageWidth * (double)thisWidth) * scale;
			cY = (int)(Y / (double)imageWidth * (double)thisWidth) * scale;
			sX = (int)(A / (double)imageWidth * (double)thisWidth) * scale;
			sY = (int)(B / (double)imageWidth * (double)thisWidth) * scale;
			phi = Phi;
			if (sX != 0 && sY != 0) {
				painter.save();
				drawMeasurements(painter, x0, y0, cX, cY, sX, sY, Phi);
				painter.restore();
			}

        }
	}

	fpsCurr += 1000.0 / (double)t.elapsed();
	fpsCounter++;
    t.start();
    painter.setPen(pen);

	if (fpsCounter >= (int)fpsDev) {
		fps = fpsCurr / (double)fpsCounter;
		fpsCounter = 0;
		fpsCurr = 0;
	}

    painter.setFont(QFont("Ubuntu-mono", 8, QFont::Bold));
    painter.drawText(10, 15, QString::asprintf("fps = %.1f", fps));
	painter.drawText(10, 27, QString::asprintf("x = %.1f", X));
	painter.drawText(10, 39, QString::asprintf("y = %.1f", Y));
	painter.drawText(10, 51, QString::asprintf("a = %.1f", A));
	painter.drawText(10, 63, QString::asprintf("b = %.1f", B));
	painter.drawText(10, 75, QString::asprintf("phi = %.1f", Phi));

    QFrame::paintEvent(e);
    updateMutex.unlock();
}

int abc = 0;
void ImageWidget::setAttributes(QString devName, QHash<QString, Tango::DeviceAttribute> data) {
    updateMutex.lock();

	try {
		std::vector<unsigned char> imageVector;
		data["imageEncodedJpeg"] >> imageVector;

		scale = data["scale"].DoubleSeq[0];
		fpsDev = data["frameRate"].DoubleSeq[0];

		//cout << scale << endl;

		imageWidth = data["imageWidth"].LongSeq[0];
		imageHeight = data["imageHeight"].LongSeq[0];

		QImage im;
		im.loadFromData(imageVector.data(), imageVector.size(), "JPG");
		im = im.convertToFormat(QImage::Format_Indexed8);
		im.setColorTable(colorTable);

		image = im;

		data.remove("imageEncodedJpeg");

		X = data["x"].DoubleSeq[0];
		Y = data["y"].DoubleSeq[0];
		A = data["a"].DoubleSeq[0];
		B = data["b"].DoubleSeq[0];
		Phi = data["phi"].DoubleSeq[0];

		if (propertiesDialog->isVisible()) {
			emit attributesChanged(devName, data);
		}

	} catch(Tango::DevFailed) {

	}

    updateMutex.unlock();

    update();
}

void ImageWidget::showContextMenu(const QPoint& pos) {

    QPoint globalPos = this->mapToGlobal(pos);

    QMenu menu;

	menu.addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/256x256/mimetypes/image.png")), "Save image", this, SLOT(contextSaveImage()));

	if (!played)
        menu.addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/player_play.png")), "Play", this, SLOT(contextPlay()));
    else
        menu.addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/player_pause.png")), "Pause", this, SLOT(contextPause()));

    menu.addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/edit-delete.png")), "Close device", this, SLOT(contextClose()));

    menu.addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/256x256/categories/preferences-system.png")), "Properties", this, SLOT(showPropertiesDialog()));

    menu.exec(globalPos);
}

void ImageWidget::showPropertiesDialog() {
    propertiesDialog->show();
}

void ImageWidget::contextPlay() {
    played = true;
    emit play(name);
}

void ImageWidget::contextPause() {
    played = false;
    emit pause(name);
}

void ImageWidget::contextClose() {
    emit close(this);
}

void ImageWidget::contextSaveImage() {
	cout << "saveImage" << endl;
	emit saveImage(this);
}

void ImageWidget::changeAttribute(QString camera, Tango::DeviceAttribute attribute) {
    emit attributeChanged(camera, attribute);
}

int ImageWidget::decodeJpeg(unsigned char *src, unsigned long src_size, unsigned char **buffer, int *size, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    int pixel_size;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_mem_src(&cinfo, src, src_size);

    (void)jpeg_read_header(&cinfo, TRUE);

    cinfo.output_width = 1280;
    cinfo.output_height = 960;
    cinfo.output_components = 1;
    cinfo.out_color_space = JCS_GRAYSCALE;


    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    pixel_size = cinfo.output_components;

    *size = *width * *height * pixel_size;
    *buffer = new unsigned char[*size];

    int row_stride = cinfo.output_width * cinfo.output_components;

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = *buffer + (cinfo.output_scanline) * row_stride;

        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    return 0;
}

void ImageWidget::resizeEvent(QResizeEvent *event) {
	QFrame::resizeEvent(event);

	double _scale = 1.0;

	double p1 = (double)this->width() / (double)this->height();
	double p2 = (double)this->imageWidth / (double)this->imageHeight;

	if (p1 > p2) {
		_scale = (double)this->height() / (double)this->imageHeight;
	} else {
		_scale = (double)this->width() / (double)this->imageWidth;
	}

	Tango::DeviceAttribute attr("scale", _scale);
	emit attributeChanged(name, attr);
}
