/********************************************************************************
** Form generated from reading UI file 'serialwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALWIDGET_H
#define UI_SERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_SerialWidget
{
public:
    QAction *config;
    QAction *pin;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QToolBox *toolBox_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *Receive_text_window;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *reascii;
    QRadioButton *rehex;
    QPushButton *clear_button2;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout;
    QTextEdit *send_text_window;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *seascii;
    QRadioButton *sehex;
    QPushButton *send_button;
    QPushButton *clear_button_1;
    QWidget *page_4;
    QGridLayout *gridLayout_3;
    QChartView *chartView;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *com;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *baud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *bit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *jiaoyan;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *stopbit;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *open_port;
    QPushButton *close_port;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_26;
    QRadioButton *default_deal;
    QRadioButton *custom_deal;
    QWidget *page_5;
    QHBoxLayout *horizontalLayout_25;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_17;
    QSpinBox *error;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QSpinBox *gap;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *StartDemarcate;
    QPushButton *ClearDemarcate;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_18;
    QSpinBox *Up_Down_Delay;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_14;
    QSpinBox *accelerateTime;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_15;
    QSpinBox *steadyTime;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QLineEdit *DemarcateTips;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *kbsetspeed;
    QSpinBox *kbspeed;
    QTextEdit *textEdit;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *version;
    QPushButton *stop;
    QPushButton *empty;
    QRadioButton *bytestream;
    QSpinBox *speed;
    QRadioButton *bytesingle;
    QLabel *label_6;
    QPushButton *displayspeed;
    QDoubleSpinBox *bytetime;
    QDoubleSpinBox *disspeed;
    QPushButton *setspeed;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_7;
    QLineEdit *hints;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QLabel *label_8;
    QDoubleSpinBox *pid_d;
    QDoubleSpinBox *pid_p;
    QDoubleSpinBox *pid_i;
    QLabel *label_10;
    QLabel *label_9;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *position;
    QRadioButton *increment;
    QRadioButton *stm32;
    QRadioButton *simupositon;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *encoder;
    QRadioButton *motor;
    QRadioButton *model;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *speedchart;
    QRadioButton *pwmchart;
    QRadioButton *demarcatechart;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QDoubleSpinBox *timeperiod;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *start;
    QPushButton *stoppid;
    QPushButton *clearseries;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_27;
    QTextEdit *tips;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *WritePidPara;
    QPushButton *InnerPid;
    QPushButton *OuterPid;

    void setupUi(QMainWindow *SerialWidget)
    {
        if (SerialWidget->objectName().isEmpty())
            SerialWidget->setObjectName(QString::fromUtf8("SerialWidget"));
        SerialWidget->resize(1195, 793);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/usb.png"), QSize(), QIcon::Normal, QIcon::Off);
        SerialWidget->setWindowIcon(icon);
        config = new QAction(SerialWidget);
        config->setObjectName(QString::fromUtf8("config"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        config->setIcon(icon1);
        pin = new QAction(SerialWidget);
        pin->setObjectName(QString::fromUtf8("pin"));
        pin->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/pin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pin->setIcon(icon2);
        centralwidget = new QWidget(SerialWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 650));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setSpacing(10);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 5, 5, 11);
        toolBox_2 = new QToolBox(centralwidget);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        toolBox_2->setContextMenuPolicy(Qt::ActionsContextMenu);
        toolBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"3ds\";"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 671, 703));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        groupBox_8 = new QGroupBox(page_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout = new QGridLayout(groupBox_8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Receive_text_window = new QTextEdit(groupBox_8);
        Receive_text_window->setObjectName(QString::fromUtf8("Receive_text_window"));

        verticalLayout_2->addWidget(Receive_text_window);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        reascii = new QRadioButton(groupBox_8);
        reascii->setObjectName(QString::fromUtf8("reascii"));
        reascii->setChecked(true);

        horizontalLayout_6->addWidget(reascii);

        rehex = new QRadioButton(groupBox_8);
        rehex->setObjectName(QString::fromUtf8("rehex"));
        rehex->setChecked(false);

        horizontalLayout_6->addWidget(rehex);

        clear_button2 = new QPushButton(groupBox_8);
        clear_button2->setObjectName(QString::fromUtf8("clear_button2"));

        horizontalLayout_6->addWidget(clear_button2);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(page_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_7 = new QGridLayout(groupBox_9);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        send_text_window = new QTextEdit(groupBox_9);
        send_text_window->setObjectName(QString::fromUtf8("send_text_window"));

        verticalLayout->addWidget(send_text_window);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        seascii = new QRadioButton(groupBox_9);
        seascii->setObjectName(QString::fromUtf8("seascii"));
        seascii->setChecked(false);

        horizontalLayout_7->addWidget(seascii);

        sehex = new QRadioButton(groupBox_9);
        sehex->setObjectName(QString::fromUtf8("sehex"));
        sehex->setChecked(true);

        horizontalLayout_7->addWidget(sehex);

        send_button = new QPushButton(groupBox_9);
        send_button->setObjectName(QString::fromUtf8("send_button"));

        horizontalLayout_7->addWidget(send_button);

        clear_button_1 = new QPushButton(groupBox_9);
        clear_button_1->setObjectName(QString::fromUtf8("clear_button_1"));

        horizontalLayout_7->addWidget(clear_button_1);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout_7->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_9);

        toolBox_2->addItem(page_2, QString::fromUtf8("\347\252\227\345\217\243\345\214\272"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 671, 703));
        gridLayout_3 = new QGridLayout(page_4);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 0, 5, 5);
        chartView = new QChartView(page_4);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setContextMenuPolicy(Qt::ActionsContextMenu);

        gridLayout_3->addWidget(chartView, 0, 0, 1, 1);

        toolBox_2->addItem(page_4, QString::fromUtf8("\350\257\257\345\267\256\346\233\262\347\272\277"));

        gridLayout_5->addWidget(toolBox_2, 0, 1, 1, 1);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        toolBox->setStyleSheet(QString::fromUtf8("font: 12pt \"3ds\";"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 504, 666));
        verticalLayout_10 = new QVBoxLayout(page);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        com = new QComboBox(groupBox);
        com->setObjectName(QString::fromUtf8("com"));

        horizontalLayout->addWidget(com);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        baud = new QComboBox(groupBox);
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->setObjectName(QString::fromUtf8("baud"));

        horizontalLayout_2->addWidget(baud);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        bit = new QComboBox(groupBox);
        bit->addItem(QString());
        bit->addItem(QString());
        bit->addItem(QString());
        bit->addItem(QString());
        bit->setObjectName(QString::fromUtf8("bit"));

        horizontalLayout_3->addWidget(bit);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        jiaoyan = new QComboBox(groupBox);
        jiaoyan->addItem(QString());
        jiaoyan->setObjectName(QString::fromUtf8("jiaoyan"));

        horizontalLayout_4->addWidget(jiaoyan);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        stopbit = new QComboBox(groupBox);
        stopbit->addItem(QString());
        stopbit->setObjectName(QString::fromUtf8("stopbit"));

        horizontalLayout_5->addWidget(stopbit);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        open_port = new QPushButton(groupBox);
        open_port->setObjectName(QString::fromUtf8("open_port"));

        horizontalLayout_13->addWidget(open_port);

        close_port = new QPushButton(groupBox);
        close_port->setObjectName(QString::fromUtf8("close_port"));

        horizontalLayout_13->addWidget(close_port);


        verticalLayout_7->addLayout(horizontalLayout_13);


        verticalLayout_10->addWidget(groupBox);

        groupBox_12 = new QGroupBox(page);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        verticalLayout_6 = new QVBoxLayout(groupBox_12);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        default_deal = new QRadioButton(groupBox_12);
        default_deal->setObjectName(QString::fromUtf8("default_deal"));
        default_deal->setChecked(true);

        horizontalLayout_26->addWidget(default_deal);

        custom_deal = new QRadioButton(groupBox_12);
        custom_deal->setObjectName(QString::fromUtf8("custom_deal"));

        horizontalLayout_26->addWidget(custom_deal);


        verticalLayout_6->addLayout(horizontalLayout_26);


        verticalLayout_10->addWidget(groupBox_12);

        verticalLayout_10->setStretch(0, 5);
        verticalLayout_10->setStretch(1, 1);
        toolBox->addItem(page, QString::fromUtf8("\344\270\262\345\217\243\350\256\276\347\275\256"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 504, 666));
        horizontalLayout_25 = new QHBoxLayout(page_5);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox_11 = new QGroupBox(page_5);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout_8 = new QVBoxLayout(groupBox_11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_17 = new QLabel(groupBox_11);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_23->addWidget(label_17);

        error = new QSpinBox(groupBox_11);
        error->setObjectName(QString::fromUtf8("error"));
        error->setMaximum(200);
        error->setSingleStep(5);
        error->setValue(20);

        horizontalLayout_23->addWidget(error);

        horizontalLayout_23->setStretch(0, 1);
        horizontalLayout_23->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_23);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_12 = new QLabel(groupBox_11);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        gap = new QSpinBox(groupBox_11);
        gap->setObjectName(QString::fromUtf8("gap"));
        gap->setMaximum(200);
        gap->setSingleStep(5);
        gap->setValue(50);

        horizontalLayout_16->addWidget(gap);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(15);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        StartDemarcate = new QPushButton(groupBox_11);
        StartDemarcate->setObjectName(QString::fromUtf8("StartDemarcate"));

        horizontalLayout_17->addWidget(StartDemarcate);

        ClearDemarcate = new QPushButton(groupBox_11);
        ClearDemarcate->setObjectName(QString::fromUtf8("ClearDemarcate"));

        horizontalLayout_17->addWidget(ClearDemarcate);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_17);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_18 = new QLabel(groupBox_11);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_24->addWidget(label_18);

        Up_Down_Delay = new QSpinBox(groupBox_11);
        Up_Down_Delay->setObjectName(QString::fromUtf8("Up_Down_Delay"));
        Up_Down_Delay->setMaximum(10000);
        Up_Down_Delay->setSingleStep(100);
        Up_Down_Delay->setValue(5000);

        horizontalLayout_24->addWidget(Up_Down_Delay);

        horizontalLayout_24->setStretch(0, 1);
        horizontalLayout_24->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_24);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(10);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_14 = new QLabel(groupBox_11);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_20->addWidget(label_14);

        accelerateTime = new QSpinBox(groupBox_11);
        accelerateTime->setObjectName(QString::fromUtf8("accelerateTime"));
        accelerateTime->setMaximum(5000);
        accelerateTime->setValue(1000);

        horizontalLayout_20->addWidget(accelerateTime);

        horizontalLayout_20->setStretch(0, 1);
        horizontalLayout_20->setStretch(1, 1);

        horizontalLayout_22->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(10);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_15 = new QLabel(groupBox_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_21->addWidget(label_15);

        steadyTime = new QSpinBox(groupBox_11);
        steadyTime->setObjectName(QString::fromUtf8("steadyTime"));
        steadyTime->setMaximum(5000);
        steadyTime->setValue(1000);

        horizontalLayout_21->addWidget(steadyTime);

        horizontalLayout_21->setStretch(0, 1);
        horizontalLayout_21->setStretch(1, 1);

        horizontalLayout_22->addLayout(horizontalLayout_21);


        verticalLayout_8->addLayout(horizontalLayout_22);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_13 = new QLabel(groupBox_11);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_18->addWidget(label_13);

        DemarcateTips = new QLineEdit(groupBox_11);
        DemarcateTips->setObjectName(QString::fromUtf8("DemarcateTips"));

        horizontalLayout_18->addWidget(DemarcateTips);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 3);

        verticalLayout_8->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(15);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        kbsetspeed = new QPushButton(groupBox_11);
        kbsetspeed->setObjectName(QString::fromUtf8("kbsetspeed"));

        horizontalLayout_19->addWidget(kbsetspeed);

        kbspeed = new QSpinBox(groupBox_11);
        kbspeed->setObjectName(QString::fromUtf8("kbspeed"));
        kbspeed->setMinimum(-4000);
        kbspeed->setMaximum(4000);
        kbspeed->setValue(1000);

        horizontalLayout_19->addWidget(kbspeed);

        horizontalLayout_19->setStretch(0, 1);
        horizontalLayout_19->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_19);


        verticalLayout_9->addWidget(groupBox_11);

        textEdit = new QTextEdit(page_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_9->addWidget(textEdit);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(1, 1);

        horizontalLayout_25->addLayout(verticalLayout_9);

        toolBox->addItem(page_5, QString::fromUtf8("\350\207\252\351\200\202\345\272\224\346\240\207\345\256\232"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 504, 666));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 0, 2, 2);
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -438, 477, 1100));
        scrollAreaWidgetContents->setMinimumSize(QSize(450, 1100));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        version = new QPushButton(groupBox_2);
        version->setObjectName(QString::fromUtf8("version"));

        gridLayout_4->addWidget(version, 4, 0, 1, 1);

        stop = new QPushButton(groupBox_2);
        stop->setObjectName(QString::fromUtf8("stop"));

        gridLayout_4->addWidget(stop, 4, 1, 1, 1);

        empty = new QPushButton(groupBox_2);
        empty->setObjectName(QString::fromUtf8("empty"));

        gridLayout_4->addWidget(empty, 6, 0, 1, 1);

        bytestream = new QRadioButton(groupBox_2);
        bytestream->setObjectName(QString::fromUtf8("bytestream"));
        bytestream->setChecked(true);

        gridLayout_4->addWidget(bytestream, 0, 1, 1, 1);

        speed = new QSpinBox(groupBox_2);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setMinimum(-10000);
        speed->setMaximum(20000);
        speed->setValue(1000);

        gridLayout_4->addWidget(speed, 5, 1, 1, 1);

        bytesingle = new QRadioButton(groupBox_2);
        bytesingle->setObjectName(QString::fromUtf8("bytesingle"));
        bytesingle->setChecked(false);

        gridLayout_4->addWidget(bytesingle, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 2, 0, 1, 1);

        displayspeed = new QPushButton(groupBox_2);
        displayspeed->setObjectName(QString::fromUtf8("displayspeed"));

        gridLayout_4->addWidget(displayspeed, 3, 0, 1, 1);

        bytetime = new QDoubleSpinBox(groupBox_2);
        bytetime->setObjectName(QString::fromUtf8("bytetime"));
        bytetime->setDecimals(3);
        bytetime->setValue(0.400000000000000);

        gridLayout_4->addWidget(bytetime, 2, 1, 1, 1);

        disspeed = new QDoubleSpinBox(groupBox_2);
        disspeed->setObjectName(QString::fromUtf8("disspeed"));
        disspeed->setMaximum(655.000000000000000);
        disspeed->setValue(234.560000000000002);

        gridLayout_4->addWidget(disspeed, 3, 1, 1, 1);

        setspeed = new QPushButton(groupBox_2);
        setspeed->setObjectName(QString::fromUtf8("setspeed"));

        gridLayout_4->addWidget(setspeed, 5, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_14->addWidget(label_7);

        hints = new QLineEdit(groupBox_2);
        hints->setObjectName(QString::fromUtf8("hints"));

        horizontalLayout_14->addWidget(hints);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 2);

        gridLayout_4->addLayout(horizontalLayout_14, 7, 0, 1, 2);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 5, -1, -1);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 0, 0, 1, 1);

        pid_d = new QDoubleSpinBox(groupBox_3);
        pid_d->setObjectName(QString::fromUtf8("pid_d"));
        pid_d->setDecimals(3);
        pid_d->setMinimum(-10.000000000000000);
        pid_d->setMaximum(1000.000000000000000);
        pid_d->setValue(0.020000000000000);

        gridLayout_6->addWidget(pid_d, 2, 1, 1, 1);

        pid_p = new QDoubleSpinBox(groupBox_3);
        pid_p->setObjectName(QString::fromUtf8("pid_p"));
        pid_p->setDecimals(3);
        pid_p->setMinimum(-10.000000000000000);
        pid_p->setMaximum(1000.000000000000000);
        pid_p->setValue(0.100000000000000);

        gridLayout_6->addWidget(pid_p, 0, 1, 1, 1);

        pid_i = new QDoubleSpinBox(groupBox_3);
        pid_i->setObjectName(QString::fromUtf8("pid_i"));
        pid_i->setDecimals(3);
        pid_i->setMinimum(-10.000000000000000);
        pid_i->setMaximum(1000.000000000000000);
        pid_i->setValue(0.500000000000000);

        gridLayout_6->addWidget(pid_i, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_4);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        position = new QRadioButton(groupBox_4);
        position->setObjectName(QString::fromUtf8("position"));
        position->setChecked(false);

        horizontalLayout_10->addWidget(position);

        increment = new QRadioButton(groupBox_4);
        increment->setObjectName(QString::fromUtf8("increment"));
        increment->setChecked(true);

        horizontalLayout_10->addWidget(increment);

        stm32 = new QRadioButton(groupBox_4);
        stm32->setObjectName(QString::fromUtf8("stm32"));

        horizontalLayout_10->addWidget(stm32);

        simupositon = new QRadioButton(groupBox_4);
        simupositon->setObjectName(QString::fromUtf8("simupositon"));
        simupositon->setChecked(false);

        horizontalLayout_10->addWidget(simupositon);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_5);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        encoder = new QRadioButton(groupBox_5);
        encoder->setObjectName(QString::fromUtf8("encoder"));

        horizontalLayout_11->addWidget(encoder);

        motor = new QRadioButton(groupBox_5);
        motor->setObjectName(QString::fromUtf8("motor"));
        motor->setChecked(false);

        horizontalLayout_11->addWidget(motor);

        model = new QRadioButton(groupBox_5);
        model->setObjectName(QString::fromUtf8("model"));
        model->setChecked(true);

        horizontalLayout_11->addWidget(model);


        verticalLayout_5->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        speedchart = new QRadioButton(groupBox_6);
        speedchart->setObjectName(QString::fromUtf8("speedchart"));
        speedchart->setChecked(true);

        horizontalLayout_12->addWidget(speedchart);

        pwmchart = new QRadioButton(groupBox_6);
        pwmchart->setObjectName(QString::fromUtf8("pwmchart"));
        pwmchart->setChecked(false);

        horizontalLayout_12->addWidget(pwmchart);

        demarcatechart = new QRadioButton(groupBox_6);
        demarcatechart->setObjectName(QString::fromUtf8("demarcatechart"));

        horizontalLayout_12->addWidget(demarcatechart);


        verticalLayout_5->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_4 = new QVBoxLayout(groupBox_7);
        verticalLayout_4->setSpacing(7);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(15);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        timeperiod = new QDoubleSpinBox(groupBox_7);
        timeperiod->setObjectName(QString::fromUtf8("timeperiod"));
        timeperiod->setDecimals(2);
        timeperiod->setValue(0.200000000000000);

        horizontalLayout_8->addWidget(timeperiod);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        start = new QPushButton(groupBox_7);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout_9->addWidget(start);

        stoppid = new QPushButton(groupBox_7);
        stoppid->setObjectName(QString::fromUtf8("stoppid"));

        horizontalLayout_9->addWidget(stoppid);

        clearseries = new QPushButton(groupBox_7);
        clearseries->setObjectName(QString::fromUtf8("clearseries"));

        horizontalLayout_9->addWidget(clearseries);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);

        verticalLayout_5->addWidget(groupBox_7);

        groupBox_13 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        horizontalLayout_27 = new QHBoxLayout(groupBox_13);
        horizontalLayout_27->setSpacing(0);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        tips = new QTextEdit(groupBox_13);
        tips->setObjectName(QString::fromUtf8("tips"));

        horizontalLayout_27->addWidget(tips);


        verticalLayout_5->addWidget(groupBox_13);

        groupBox_10 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_10);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        WritePidPara = new QPushButton(groupBox_10);
        WritePidPara->setObjectName(QString::fromUtf8("WritePidPara"));

        horizontalLayout_15->addWidget(WritePidPara);

        InnerPid = new QPushButton(groupBox_10);
        InnerPid->setObjectName(QString::fromUtf8("InnerPid"));

        horizontalLayout_15->addWidget(InnerPid);

        OuterPid = new QPushButton(groupBox_10);
        OuterPid->setObjectName(QString::fromUtf8("OuterPid"));

        horizontalLayout_15->addWidget(OuterPid);


        verticalLayout_5->addWidget(groupBox_10);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 2);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 1);
        verticalLayout_5->setStretch(4, 1);
        verticalLayout_5->setStretch(5, 1);
        verticalLayout_5->setStretch(6, 3);
        verticalLayout_5->setStretch(7, 1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("PID\350\260\203\351\200\237"));

        gridLayout_5->addWidget(toolBox, 0, 0, 1, 1);

        gridLayout_5->setColumnStretch(0, 3);
        gridLayout_5->setColumnStretch(1, 4);
        SerialWidget->setCentralWidget(centralwidget);

        retranslateUi(SerialWidget);

        toolBox_2->setCurrentIndex(0);
        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SerialWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SerialWidget)
    {
        SerialWidget->setWindowTitle(QCoreApplication::translate("SerialWidget", "MainWindow", nullptr));
        config->setText(QCoreApplication::translate("SerialWidget", "\345\233\276\345\275\242\350\256\276\347\275\256", nullptr));
        pin->setText(QCoreApplication::translate("SerialWidget", "\347\275\256\351\241\266", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("SerialWidget", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        reascii->setText(QCoreApplication::translate("SerialWidget", "ASCII\347\240\201", nullptr));
        rehex->setText(QCoreApplication::translate("SerialWidget", "Hex", nullptr));
        clear_button2->setText(QCoreApplication::translate("SerialWidget", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("SerialWidget", "\345\215\225\346\235\241\345\217\221\351\200\201", nullptr));
        seascii->setText(QCoreApplication::translate("SerialWidget", "ASCII\347\240\201", nullptr));
        sehex->setText(QCoreApplication::translate("SerialWidget", "Hex", nullptr));
        send_button->setText(QCoreApplication::translate("SerialWidget", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        clear_button_1->setText(QCoreApplication::translate("SerialWidget", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_2), QCoreApplication::translate("SerialWidget", "\347\252\227\345\217\243\345\214\272", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_4), QCoreApplication::translate("SerialWidget", "\350\257\257\345\267\256\346\233\262\347\272\277", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SerialWidget", "\347\253\257\345\217\243\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("SerialWidget", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SerialWidget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        baud->setItemText(0, QCoreApplication::translate("SerialWidget", "115200", nullptr));
        baud->setItemText(1, QCoreApplication::translate("SerialWidget", "9600", nullptr));
        baud->setItemText(2, QCoreApplication::translate("SerialWidget", "300", nullptr));
        baud->setItemText(3, QCoreApplication::translate("SerialWidget", "1200", nullptr));
        baud->setItemText(4, QCoreApplication::translate("SerialWidget", "2400", nullptr));
        baud->setItemText(5, QCoreApplication::translate("SerialWidget", "4800", nullptr));
        baud->setItemText(6, QCoreApplication::translate("SerialWidget", "14400", nullptr));
        baud->setItemText(7, QCoreApplication::translate("SerialWidget", "19200", nullptr));
        baud->setItemText(8, QCoreApplication::translate("SerialWidget", "28800", nullptr));

        label_3->setText(QCoreApplication::translate("SerialWidget", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        bit->setItemText(0, QCoreApplication::translate("SerialWidget", "8", nullptr));
        bit->setItemText(1, QCoreApplication::translate("SerialWidget", "5", nullptr));
        bit->setItemText(2, QCoreApplication::translate("SerialWidget", "6", nullptr));
        bit->setItemText(3, QCoreApplication::translate("SerialWidget", "7", nullptr));

        label_4->setText(QCoreApplication::translate("SerialWidget", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        jiaoyan->setItemText(0, QCoreApplication::translate("SerialWidget", "0", nullptr));

        label_5->setText(QCoreApplication::translate("SerialWidget", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stopbit->setItemText(0, QCoreApplication::translate("SerialWidget", "1", nullptr));

        open_port->setText(QCoreApplication::translate("SerialWidget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        close_port->setText(QCoreApplication::translate("SerialWidget", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("SerialWidget", "\344\270\262\345\217\243\345\215\217\350\256\256", nullptr));
        default_deal->setText(QCoreApplication::translate("SerialWidget", "\351\273\230\350\256\244\345\215\217\350\256\256", nullptr));
        custom_deal->setText(QCoreApplication::translate("SerialWidget", "\350\207\252\345\256\232\344\271\211\345\215\217\350\256\256", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("SerialWidget", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("SerialWidget", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        label_17->setText(QCoreApplication::translate("SerialWidget", "\345\256\271\350\256\270\350\257\257\345\267\256", nullptr));
        label_12->setText(QCoreApplication::translate("SerialWidget", "\346\240\207\345\256\232\351\227\264\350\267\235", nullptr));
        StartDemarcate->setText(QCoreApplication::translate("SerialWidget", "\345\274\200\345\247\213\346\240\207\345\256\232", nullptr));
        ClearDemarcate->setText(QCoreApplication::translate("SerialWidget", "\346\270\205\351\231\244\346\240\207\345\256\232", nullptr));
        label_18->setText(QCoreApplication::translate("SerialWidget", "\346\255\243\345\217\215\350\275\254\344\270\255\351\227\264\345\273\266\346\227\266", nullptr));
        label_14->setText(QCoreApplication::translate("SerialWidget", "\345\212\240\351\200\237\347\255\211\345\276\205", nullptr));
        label_15->setText(QCoreApplication::translate("SerialWidget", "\347\250\263\345\256\232\346\243\200\346\265\213", nullptr));
        label_13->setText(QCoreApplication::translate("SerialWidget", "\346\217\220\347\244\272\357\274\232", nullptr));
        kbsetspeed->setText(QCoreApplication::translate("SerialWidget", "\344\276\235\347\205\247\346\240\207\345\256\232\350\256\276\345\256\232\351\200\237\345\272\246", nullptr));
        textEdit->setHtml(QCoreApplication::translate("SerialWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'3ds'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\207\345\256\232\350\247\204\345\210\231\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\273\2161450\345\274\200\345\247\213\344\273\245\346\214\207\345\256\232\347\232\204\346\240\207\345\256\232\351\227\264\350\267\235\357\274\214\345\217\221\351\200\201pwm\350\204\211\345\256\275\346\214\207\344\273\244\345\273\266\346\227\266t1\343\200\220\345\212\240\351\200\237\347\255\211\347\255\211\343\200\221\357\274\214\345\274\200\345\247\213\346\265\213\351\207\217\351"
                        "\200\237\345\272\246\357\274\214\344\270\255\351\227\264\345\273\266\346\227\266t2\343\200\220\347\250\263\345\256\232\346\243\200\346\265\213\343\200\221\357\274\214\346\265\213\351\207\217\351\200\237\345\272\246\343\200\202\344\270\244\346\254\241\346\265\213\351\207\217\351\200\237\345\272\246\345\260\217\344\272\216\343\200\220\345\256\271\350\256\270\350\257\257\345\267\256\343\200\221\350\275\254\350\241\250\347\244\272\351\200\237\345\272\246\347\250\263\345\256\232\357\274\214\350\256\260\345\275\225\351\200\237\345\272\246,\345\220\246\345\210\231\347\273\247\347\273\255\345\273\266\346\227\266\343\200\202\345\210\260pwm\345\210\260\350\276\2761100\346\227\266\347\273\223\346\235\237\343\200\202\344\273\2161550\345\274\200\345\247\213\345\210\2601900\347\273\223\346\235\237\343\200\202\350\207\252\345\212\250\345\201\234\346\255\242\346\240\207\345\256\232\357\274\214\347\273\230\345\210\266\346\240\207\345\256\232\346\233\262\347\272\277\357\274\214\350\256\241\347\256\227\346\213\237\345\220\210\345"
                        "\207\275\346\225\260\343\200\202\345\220\216\347\273\255\350\256\276\345\256\232\351\200\237\345\272\246\351\200\232\350\277\207\346\213\237\345\220\210\347\232\204\345\207\275\346\225\260\357\274\214\350\207\252\345\212\250\350\256\241\347\256\227\345\207\272\345\220\210\351\200\202\347\232\204pwm\343\200\202</p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("SerialWidget", "\350\207\252\351\200\202\345\272\224\346\240\207\345\256\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SerialWidget", "\346\211\213\345\212\250\346\216\247\345\210\266", nullptr));
        version->setText(QCoreApplication::translate("SerialWidget", "\347\211\210\346\234\254\345\217\267", nullptr));
        stop->setText(QCoreApplication::translate("SerialWidget", "\345\201\234\346\255\242\350\275\254\345\212\250", nullptr));
        empty->setText(QCoreApplication::translate("SerialWidget", "\347\251\272\346\214\207\344\273\244", nullptr));
        bytestream->setText(QCoreApplication::translate("SerialWidget", "\345\255\227\350\212\202\346\265\201", nullptr));
        bytesingle->setText(QCoreApplication::translate("SerialWidget", "\345\215\225\345\255\227\350\212\202", nullptr));
        label_6->setText(QCoreApplication::translate("SerialWidget", "\345\255\227\350\212\202\345\221\250\346\234\237", nullptr));
        displayspeed->setText(QCoreApplication::translate("SerialWidget", "\346\230\276\347\244\272\351\200\237\345\272\246", nullptr));
        setspeed->setText(QCoreApplication::translate("SerialWidget", "\350\256\276\345\256\232\351\200\237\345\272\246", nullptr));
        label_7->setText(QCoreApplication::translate("SerialWidget", "\346\217\220\347\244\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SerialWidget", "\345\217\202\346\225\260", nullptr));
        label_8->setText(QCoreApplication::translate("SerialWidget", "\346\257\224\344\276\213 P", nullptr));
        label_10->setText(QCoreApplication::translate("SerialWidget", "\345\276\256\345\210\206 D", nullptr));
        label_9->setText(QCoreApplication::translate("SerialWidget", "\347\247\257\345\210\206 I", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("SerialWidget", "PID\347\261\273\345\236\213", nullptr));
        position->setText(QCoreApplication::translate("SerialWidget", "\344\275\215\347\275\256\345\274\217", nullptr));
        increment->setText(QCoreApplication::translate("SerialWidget", "\345\242\236\351\207\217\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        stm32->setToolTip(QCoreApplication::translate("SerialWidget", "STM32\346\214\207\347\232\204\345\234\250\347\274\226\347\240\201\345\231\250\346\250\241\345\274\217\344\270\213\350\260\203\347\224\250STM32\345\206\205\351\203\250\347\232\204Pid\346\216\247\345\210\266\345\231\250\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        stm32->setText(QCoreApplication::translate("SerialWidget", "STM32", nullptr));
#if QT_CONFIG(tooltip)
        simupositon->setToolTip(QCoreApplication::translate("SerialWidget", "\344\270\215\344\274\232\350\256\260\345\275\225\345\216\206\345\217\262\350\257\257\345\267\256", nullptr));
#endif // QT_CONFIG(tooltip)
        simupositon->setText(QCoreApplication::translate("SerialWidget", "Simulink\345\236\213", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("SerialWidget", "\350\242\253\346\216\247\345\257\271\350\261\241\344\277\241\345\217\267\346\272\220", nullptr));
        encoder->setText(QCoreApplication::translate("SerialWidget", "\347\274\226\347\240\201\345\231\250", nullptr));
        motor->setText(QCoreApplication::translate("SerialWidget", "\351\207\207\351\233\206\345\215\241", nullptr));
        model->setText(QCoreApplication::translate("SerialWidget", "\346\225\260\345\255\246\346\250\241\345\236\213", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("SerialWidget", "\346\230\276\347\244\272\346\233\262\347\272\277", nullptr));
        speedchart->setText(QCoreApplication::translate("SerialWidget", "\351\200\237\345\272\246\346\216\247\345\210\266", nullptr));
        pwmchart->setText(QCoreApplication::translate("SerialWidget", "Pwm\346\216\247\345\210\266", nullptr));
        demarcatechart->setText(QCoreApplication::translate("SerialWidget", "\346\240\207\345\256\232\346\233\262\347\272\277", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("SerialWidget", "\346\216\247\345\210\266\346\214\207\344\273\244", nullptr));
        label_11->setText(QCoreApplication::translate("SerialWidget", "\346\216\247\345\210\266\345\221\275\344\273\244\351\227\264\351\232\224\357\274\232", nullptr));
        start->setText(QCoreApplication::translate("SerialWidget", "\345\274\200\345\247\213\346\240\241\346\255\243", nullptr));
        stoppid->setText(QCoreApplication::translate("SerialWidget", "\345\201\234\346\255\242\346\240\241\346\255\243", nullptr));
        clearseries->setText(QCoreApplication::translate("SerialWidget", "\346\270\205\351\231\244\345\233\276\345\275\242", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("SerialWidget", "\344\277\241\346\201\257", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("SerialWidget", "\347\274\226\347\240\201\345\231\250\346\211\251\345\261\225", nullptr));
        WritePidPara->setText(QCoreApplication::translate("SerialWidget", "\345\206\231\345\205\245Pid\345\217\202\346\225\260", nullptr));
        InnerPid->setText(QCoreApplication::translate("SerialWidget", "\345\206\205\351\203\250Pid", nullptr));
        OuterPid->setText(QCoreApplication::translate("SerialWidget", "\345\244\226\351\203\250Pid", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("SerialWidget", "PID\350\260\203\351\200\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialWidget: public Ui_SerialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALWIDGET_H
