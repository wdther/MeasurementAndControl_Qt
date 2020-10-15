/********************************************************************************
** Form generated from reading UI file 'gause.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSE_H
#define UI_GAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QtGaugeProgress.h"

QT_BEGIN_NAMESPACE

class Ui_Gause
{
public:
    QWidget *centralwidget;
    QtGaugeProgress *gauge;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gause)
    {
        if (Gause->objectName().isEmpty())
            Gause->setObjectName(QString::fromUtf8("Gause"));
        Gause->resize(430, 608);
        centralwidget = new QWidget(Gause);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gauge = new QtGaugeProgress(centralwidget);
        gauge->setObjectName(QString::fromUtf8("gauge"));
        gauge->setGeometry(QRect(40, 240, 341, 241));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(70, 110, 231, 51));
        Gause->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gause);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 430, 26));
        Gause->setMenuBar(menubar);
        statusbar = new QStatusBar(Gause);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Gause->setStatusBar(statusbar);

        retranslateUi(Gause);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), Gause, SLOT(valueChanged(int)));

        QMetaObject::connectSlotsByName(Gause);
    } // setupUi

    void retranslateUi(QMainWindow *Gause)
    {
        Gause->setWindowTitle(QCoreApplication::translate("Gause", "Gause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gause: public Ui_Gause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSE_H
