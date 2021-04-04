#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#if QT_VERSION >= 0x050000
#else
    #define QStringLiteral(str) QString::fromUtf8("" str "", sizeof(str) - 1)
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mw;

    if (mw.objectName().isEmpty())
    {
        mw.setObjectName(QStringLiteral("MainWindow"));
    }
    mw.resize(640, 480);

    QIcon icon;
    QString iconThemeName = QStringLiteral("gtk2");
    if (QIcon::hasThemeIcon(iconThemeName))
    {
        icon = QIcon::fromTheme(iconThemeName);
    }
    else
    {
        icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::On);
    }
    mw.setWindowIcon(icon);

    mw.show();

    return app.exec();
}
