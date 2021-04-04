#include "mainwindow.h"
#include <iostream>
#include <QDialog>
#include "AddDeviceDialog.h"
#include <QJsonObject>
#include <QJsonDocument>

#if QT_VERSION >= 0x050000
#else
    #define QStringLiteral(str) QString::fromUtf8("" str "", sizeof(str) - 1)
#endif

#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QTextStream>
#include <QApplication>


#include <tango.h>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    if (this->objectName().isEmpty())
        this->setObjectName(QStringLiteral("MainWindow"));
    this->resize(640, 480);
    QIcon icon;
    QString iconThemeName = QStringLiteral("gtk2");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::On);
    }
    this->setWindowIcon(icon);

    toolBar = new QToolBar("toolBar", this);
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/48x48/actions/add.png")), "New device", this, SLOT(toolBarAddDevice()));
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/document-open.png")), "Open state", this, SLOT(toolBarOpenState()));
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/document-save.png")), "Save state", this, SLOT(toolBarSaveState()));
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/player_play.png")), "Play", this, SLOT(toolBarPlay()));
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/player_pause.png")), "Pause", this, SLOT(toolBarPause()));
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/player_stop.png")), "Close", this, SLOT(toolBarClose()));
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/256x256/categories/preferences-system.png")), "Properties", this, SLOT(toolBarProperties()));
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/help-about.png")), "About", this, SLOT(toolBarAbout()));
    spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    toolBar->addWidget(spacer);
    toolBar->addAction(QPixmap(QStringLiteral("/usr/share/icons/gnome/24x24/actions/application-exit.png")), "Exit", this, SLOT(exit()));

    this->addToolBar(Qt::TopToolBarArea, toolBar);

    centralWidget = new CentralWidget(this);

    this->setCentralWidget(centralWidget);

    this->retranslateUI();

    qRegisterMetaType<MyHashData>("QHash<QString,Tango::DeviceAttribute>");
	qRegisterMetaType<TangoAttribute>("Tango::DeviceAttribute>");
	qRegisterMetaType<DeviceType>("DeviceType");

	dataReceiver = new DataReceiver(this);
//	dataReceiverThread = new QThread();
//	dataReceiver->moveToThread(dataReceiverThread);
    //connections DataReceiver <-> MainWindow
    connect(this, SIGNAL(play(QString)), dataReceiver, SLOT(play(QString)));
    connect(this, SIGNAL(pause(QString)), dataReceiver, SLOT(pause(QString)));
	connect(this, SIGNAL(setExposure(QString)), dataReceiver, SLOT(setExposure(QString)));
	connect(this, SIGNAL(closeDevice(QString)), dataReceiver, SLOT(closeDevice(QString)));

    //connections DataReceiver <-> CentralWidget
    connect(dataReceiver, SIGNAL(addDeviceIsSuccessful(QString,DeviceType)),
            centralWidget, SLOT(addImageWidget(QString,DeviceType)));
    connect(dataReceiver, SIGNAL(updateData(QString,QHash<QString,Tango::DeviceAttribute>)),
            centralWidget, SLOT(updateData(QString,QHash<QString,Tango::DeviceAttribute>)));
    connect(centralWidget, SIGNAL(play(QString)), dataReceiver, SLOT(play(QString)));
    connect(centralWidget, SIGNAL(pause(QString)), dataReceiver, SLOT(pause(QString)));
	connect(centralWidget, SIGNAL(setExposure(QString)), dataReceiver, SLOT(setExposure(QString)));
    connect(centralWidget, SIGNAL(closeDevice(QString)), dataReceiver, SLOT(closeDevice(QString)));
    connect(centralWidget, SIGNAL(attributeChanged(QString,Tango::DeviceAttribute)),
            dataReceiver, SLOT(setAttribute(QString,Tango::DeviceAttribute)));
	connect(centralWidget, SIGNAL(getFullImage(QString)), dataReceiver, SLOT(getFullImage(QString)));
	connect(dataReceiver, SIGNAL(getFullImage_done(QString,std::vector<unsigned char>,int,int)),
			centralWidget, SLOT(receiveImage(QString,std::vector<unsigned char>,int,int)));
}

MainWindow::MainWindow(QString filestate, QWidget *parent) : QMainWindow(parent){
	std::cout << filestate.toStdString() << std::endl;
}

MainWindow::~MainWindow() {
    delete dataReceiver;
    delete centralWidget;
    delete toolBar;
}

void MainWindow::retranslateUI() {
    this->setWindowTitle("Chameleon Tango Client");
}


void MainWindow::exit() {
    std::cout << "exit()" << std::endl;
	QApplication::quit();
}

void MainWindow::toolBarAddDevice() {
    AddDeviceDialog dialog(this);
    connect(&dialog, SIGNAL(addDevice(QString, DeviceType)), dataReceiver, SLOT(addDevice(QString, DeviceType)));
    dialog.exec();
}

void MainWindow::toolBarOpenState() {
    std::cout << "open()" << std::endl;
}

void MainWindow::toolBarSaveState() {
	QJsonObject json = dataReceiver->getDeviceState("");
	QJsonDocument doc(json);

	QString fileName = QFileDialog::getSaveFileName(this, "Save state", "~/", tr("*.ccd (*.ccd)"));

	if (fileName != "") {
		if (!fileName.endsWith(".ccd"))
			fileName.append(".ccd");
		QFile file(fileName);
		if (file.open(QIODevice::WriteOnly)) {
			file.write(doc.toJson());
		}
	}
}

void MainWindow::toolBarProperties() {
	emit setExposure("");
}

void MainWindow::toolBarAbout() {
    std::cout << "about()" << std::endl;
}

void MainWindow::toolBarPlay() {
    emit play("");
}

void MainWindow::toolBarPause() {
    emit pause("");
}

void MainWindow::toolBarClose() {
    emit closeDevice("");
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
}
