/********************************************************************************
** Form generated from reading UI file 'ImageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ImageWidget
{
public:

    void setupUi(QFrame *ImageWidget)
    {
        if (ImageWidget->objectName().isEmpty())
            ImageWidget->setObjectName(QStringLiteral("ImageWidget"));
        ImageWidget->resize(400, 300);
        ImageWidget->setFrameShape(QFrame::StyledPanel);
        ImageWidget->setFrameShadow(QFrame::Sunken);
        ImageWidget->setLineWidth(5);

        retranslateUi(ImageWidget);

        QMetaObject::connectSlotsByName(ImageWidget);
    } // setupUi

    void retranslateUi(QFrame *ImageWidget)
    {
        ImageWidget->setWindowTitle(QApplication::translate("ImageWidget", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageWidget: public Ui_ImageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
