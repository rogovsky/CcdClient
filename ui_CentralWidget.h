/********************************************************************************
** Form generated from reading UI file 'CentralWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTRALWIDGET_H
#define UI_CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CentralWidget
{
public:
    QGridLayout *gridLayout;
    QGridLayout *layout;

    void setupUi(QWidget *CentralWidget)
    {
        if (CentralWidget->objectName().isEmpty())
            CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        CentralWidget->resize(578, 471);
        gridLayout = new QGridLayout(CentralWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layout = new QGridLayout();
        layout->setObjectName(QStringLiteral("layout"));

        gridLayout->addLayout(layout, 0, 0, 1, 1);


        retranslateUi(CentralWidget);

        QMetaObject::connectSlotsByName(CentralWidget);
    } // setupUi

    void retranslateUi(QWidget *CentralWidget)
    {
        CentralWidget->setWindowTitle(QApplication::translate("CentralWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class CentralWidget: public Ui_CentralWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWIDGET_H
