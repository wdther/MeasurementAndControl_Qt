/********************************************************************************
** Form generated from reading UI file 'dllread.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLLREAD_H
#define UI_DLLREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include "QtGaugeProgress.h"
#include "QtRoundProgressBar.h"

QT_BEGIN_NAMESPACE

class Ui_DllRead
{
public:
    QAction *waveconfig;
    QAction *speedconfig;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox_2;
    QWidget *page;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QChartView *WavechartView;
    QChartView *SpeedchartView;
    QToolBox *toolBox;
    QWidget *page1;
    QVBoxLayout *verticalLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *freq;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *freqn;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QSpinBox *channel;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *TestButton;
    QLineEdit *state;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *cardset;
    QLineEdit *cardsettips;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *cardquit;
    QLineEdit *cardquittips;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_2;
    QRadioButton *physics;
    QRadioButton *square;
    QRadioButton *sin;
    QRadioButton *saw;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *timeperiod;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *StartAcquire;
    QPushButton *StopAcquire;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *tips;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QSpinBox *upper;
    QtRoundProgressBar *speedpanel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QSpinBox *lower;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QSpinBox *ratio;
    QCheckBox *noTrans;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QtGaugeProgress *ampslide;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_6;
    QtGaugeProgress *freqslide;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QWidget *page_3;
    QPushButton *convert;

    void setupUi(QMainWindow *DllRead)
    {
        if (DllRead->objectName().isEmpty())
            DllRead->setObjectName(QString::fromUtf8("DllRead"));
        DllRead->resize(1120, 792);
        DllRead->setStyleSheet(QString::fromUtf8(""));
        waveconfig = new QAction(DllRead);
        waveconfig->setObjectName(QString::fromUtf8("waveconfig"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../icon/\350\256\276 \347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        waveconfig->setIcon(icon);
        speedconfig = new QAction(DllRead);
        speedconfig->setObjectName(QString::fromUtf8("speedconfig"));
        speedconfig->setIcon(icon);
        centralwidget = new QWidget(DllRead);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 10);
        toolBox_2 = new QToolBox(centralwidget);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        toolBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"3ds\";"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 662, 740));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 0, 5, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WavechartView = new QChartView(page);
        WavechartView->setObjectName(QString::fromUtf8("WavechartView"));
        WavechartView->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(WavechartView);

        SpeedchartView = new QChartView(page);
        SpeedchartView->setObjectName(QString::fromUtf8("SpeedchartView"));
        SpeedchartView->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(SpeedchartView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        toolBox_2->addItem(page, QString::fromUtf8("\351\242\221\347\216\207\346\263\242\345\275\242-\351\200\237\345\272\246\345\200\274"));

        horizontalLayout_2->addWidget(toolBox_2);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("3ds"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        toolBox->setFont(font);
        toolBox->setStyleSheet(QString::fromUtf8("font: 12pt \"3ds\";"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        page1->setGeometry(QRect(0, 0, 442, 666));
        verticalLayout_9 = new QVBoxLayout(page1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        scrollArea = new QScrollArea(page1);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 401, 900));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 900));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        freq = new QSpinBox(groupBox_3);
        freq->setObjectName(QString::fromUtf8("freq"));
        freq->setMaximum(10000);
        freq->setValue(4000);

        horizontalLayout_4->addWidget(freq);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        freqn = new QSpinBox(groupBox_3);
        freqn->setObjectName(QString::fromUtf8("freqn"));
        freqn->setMaximum(10000);
        freqn->setValue(1000);

        horizontalLayout_3->addWidget(freqn);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_7);

        channel = new QSpinBox(groupBox_3);
        channel->setObjectName(QString::fromUtf8("channel"));
        channel->setMinimum(1);
        channel->setMaximum(8);
        channel->setValue(5);

        horizontalLayout_11->addWidget(channel);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_8 = new QVBoxLayout(groupBox_7);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TestButton = new QPushButton(groupBox_7);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));

        horizontalLayout->addWidget(TestButton);

        state = new QLineEdit(groupBox_7);
        state->setObjectName(QString::fromUtf8("state"));

        horizontalLayout->addWidget(state);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        cardset = new QPushButton(groupBox_7);
        cardset->setObjectName(QString::fromUtf8("cardset"));

        horizontalLayout_12->addWidget(cardset);

        cardsettips = new QLineEdit(groupBox_7);
        cardsettips->setObjectName(QString::fromUtf8("cardsettips"));

        horizontalLayout_12->addWidget(cardsettips);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        cardquit = new QPushButton(groupBox_7);
        cardquit->setObjectName(QString::fromUtf8("cardquit"));

        horizontalLayout_13->addWidget(cardquit);

        cardquittips = new QLineEdit(groupBox_7);
        cardquittips->setObjectName(QString::fromUtf8("cardquittips"));

        horizontalLayout_13->addWidget(cardquittips);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_13);


        verticalLayout_10->addWidget(groupBox_7);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(10);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        physics = new QRadioButton(groupBox_4);
        physics->setObjectName(QString::fromUtf8("physics"));

        gridLayout_2->addWidget(physics, 0, 0, 1, 1);

        square = new QRadioButton(groupBox_4);
        square->setObjectName(QString::fromUtf8("square"));
        square->setChecked(true);

        gridLayout_2->addWidget(square, 0, 1, 1, 1);

        sin = new QRadioButton(groupBox_4);
        sin->setObjectName(QString::fromUtf8("sin"));

        gridLayout_2->addWidget(sin, 1, 0, 1, 1);

        saw = new QRadioButton(groupBox_4);
        saw->setObjectName(QString::fromUtf8("saw"));

        gridLayout_2->addWidget(saw, 1, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);

        verticalLayout_7->setStretch(0, 2);

        verticalLayout_10->addWidget(groupBox_4);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_5);

        timeperiod = new QDoubleSpinBox(groupBox);
        timeperiod->setObjectName(QString::fromUtf8("timeperiod"));
        timeperiod->setDecimals(1);
        timeperiod->setMaximum(20.000000000000000);
        timeperiod->setSingleStep(0.100000000000000);
        timeperiod->setValue(1.000000000000000);

        horizontalLayout_7->addWidget(timeperiod);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        StartAcquire = new QPushButton(groupBox);
        StartAcquire->setObjectName(QString::fromUtf8("StartAcquire"));

        horizontalLayout_5->addWidget(StartAcquire);

        StopAcquire = new QPushButton(groupBox);
        StopAcquire->setObjectName(QString::fromUtf8("StopAcquire"));

        horizontalLayout_5->addWidget(StopAcquire);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_2);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        tips = new QLineEdit(groupBox_2);
        tips->setObjectName(QString::fromUtf8("tips"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tips->sizePolicy().hasHeightForWidth());
        tips->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(tips);


        verticalLayout_10->addWidget(groupBox_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_9->addWidget(scrollArea);

        toolBox->addItem(page1, QString::fromUtf8("\345\210\235\345\247\213\345\214\226"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 442, 666));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, -1, 10, -1);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        upper = new QSpinBox(groupBox_5);
        upper->setObjectName(QString::fromUtf8("upper"));
        upper->setMaximum(5000);
        upper->setSingleStep(5);
        upper->setValue(4000);

        horizontalLayout_8->addWidget(upper);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 1, 1, 1);

        speedpanel = new QtRoundProgressBar(groupBox_5);
        speedpanel->setObjectName(QString::fromUtf8("speedpanel"));
        speedpanel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));

        gridLayout_3->addWidget(speedpanel, 0, 0, 4, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        lower = new QSpinBox(groupBox_5);
        lower->setObjectName(QString::fromUtf8("lower"));
        lower->setMaximum(100);
        lower->setSingleStep(5);

        horizontalLayout_9->addWidget(lower);


        gridLayout_3->addLayout(horizontalLayout_9, 1, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        ratio = new QSpinBox(groupBox_5);
        ratio->setObjectName(QString::fromUtf8("ratio"));
        ratio->setMinimum(1);
        ratio->setValue(16);

        horizontalLayout_10->addWidget(ratio);


        gridLayout_3->addLayout(horizontalLayout_10, 3, 1, 1, 1);

        noTrans = new QCheckBox(groupBox_5);
        noTrans->setObjectName(QString::fromUtf8("noTrans"));
        noTrans->setTristate(false);

        gridLayout_3->addWidget(noTrans, 2, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setRowStretch(3, 1);
        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 1);

        verticalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ampslide = new QtGaugeProgress(groupBox_6);
        ampslide->setObjectName(QString::fromUtf8("ampslide"));

        verticalLayout_5->addWidget(ampslide);

        pushButton = new QPushButton(groupBox_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_5->addWidget(pushButton);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        freqslide = new QtGaugeProgress(groupBox_6);
        freqslide->setObjectName(QString::fromUtf8("freqslide"));

        verticalLayout_6->addWidget(freqslide);

        pushButton_2 = new QPushButton(groupBox_6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_6->addWidget(pushButton_2);


        horizontalLayout_6->addLayout(verticalLayout_6);


        verticalLayout_3->addWidget(groupBox_6);

        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_3->addWidget(textEdit);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 1);
        toolBox->addItem(page_2, QString::fromUtf8("\344\277\241\345\217\267"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 442, 666));
        convert = new QPushButton(page_3);
        convert->setObjectName(QString::fromUtf8("convert"));
        convert->setGeometry(QRect(40, 50, 93, 28));
        toolBox->addItem(page_3, QString::fromUtf8("\346\265\213\350\257\225\351\241\265"));

        horizontalLayout_2->addWidget(toolBox);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 2);
        DllRead->setCentralWidget(centralwidget);

        retranslateUi(DllRead);

        toolBox_2->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DllRead);
    } // setupUi

    void retranslateUi(QMainWindow *DllRead)
    {
        DllRead->setWindowTitle(QCoreApplication::translate("DllRead", "DllRead", nullptr));
        waveconfig->setText(QCoreApplication::translate("DllRead", "\346\211\223\345\274\200\350\256\276\347\275\256\351\235\242\346\235\277", nullptr));
        speedconfig->setText(QCoreApplication::translate("DllRead", "\346\211\223\345\274\200\350\256\276\347\275\256\351\235\242\346\235\277", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page), QCoreApplication::translate("DllRead", "\351\242\221\347\216\207\346\263\242\345\275\242-\351\200\237\345\272\246\345\200\274", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DllRead", "\345\210\235\345\247\213\345\214\226", nullptr));
        label_2->setText(QCoreApplication::translate("DllRead", "\351\207\207\346\240\267\351\242\221\347\216\207", nullptr));
        label->setText(QCoreApplication::translate("DllRead", "\351\207\207\346\240\267\346\225\260", nullptr));
        label_7->setText(QCoreApplication::translate("DllRead", "\351\200\232\351\201\223", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("DllRead", "\351\207\207\351\233\206\345\215\241\346\265\213\350\257\225", nullptr));
        TestButton->setText(QCoreApplication::translate("DllRead", "\345\217\245\346\237\204\346\265\213\350\257\225", nullptr));
        cardset->setText(QCoreApplication::translate("DllRead", "\351\207\207\351\233\206\345\215\241\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        cardquit->setText(QCoreApplication::translate("DllRead", "\351\200\200\345\207\272\351\207\207\351\233\206\345\215\241", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DllRead", "\344\277\241\345\217\267\351\200\211\346\213\251", nullptr));
        physics->setText(QCoreApplication::translate("DllRead", "\351\207\207\351\233\206\345\215\241", nullptr));
        square->setText(QCoreApplication::translate("DllRead", "\346\226\271\346\263\242", nullptr));
        sin->setText(QCoreApplication::translate("DllRead", "\346\255\243\345\274\246\346\263\242", nullptr));
        saw->setText(QCoreApplication::translate("DllRead", "\344\270\211\350\247\222\346\263\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DllRead", "\345\233\276\345\275\242\347\273\230\345\210\266", nullptr));
        label_5->setText(QCoreApplication::translate("DllRead", "\345\210\267\346\226\260\345\233\276\345\275\242", nullptr));
        StartAcquire->setText(QCoreApplication::translate("DllRead", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        StopAcquire->setText(QCoreApplication::translate("DllRead", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DllRead", "\347\212\266\346\200\201\346\217\220\347\244\272", nullptr));
        toolBox->setItemText(toolBox->indexOf(page1), QCoreApplication::translate("DllRead", "\345\210\235\345\247\213\345\214\226", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("DllRead", "\351\200\237\345\272\246\344\273\252\350\241\250\347\233\230", nullptr));
        label_3->setText(QCoreApplication::translate("DllRead", "\344\270\212\351\231\220", nullptr));
        label_4->setText(QCoreApplication::translate("DllRead", "\344\270\213\351\231\220", nullptr));
        label_6->setText(QCoreApplication::translate("DllRead", "\350\275\254\351\200\237\346\257\224", nullptr));
        noTrans->setText(QCoreApplication::translate("DllRead", "   \346\227\240\350\275\254\346\215\242", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("DllRead", "\350\231\232\346\213\237\344\277\241\345\217\267", nullptr));
        pushButton->setText(QCoreApplication::translate("DllRead", "\345\271\205\345\200\274", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DllRead", "\351\242\221\347\216\207", nullptr));
        textEdit->setHtml(QCoreApplication::translate("DllRead", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'3ds'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\351\242\221\347\216\207=\351\233\266\347\202\271\344\270\252\346\225\260/2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\345\256\236\351\231\205\351\200\237\345\272\246=\351\242\221\347\216\207/\350\275\254\351\200\237\346\257\224/\351\207\207\346\240\267\345\221\250\346\234\237</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\"><span style=\" font-family:'SimSun';\">\350\275\254\351\200\237=\351\242\221\347\216\207/16*60/\351\207\207\346\240\267\345\221\250\346\234\237</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    =\351\242\221\347\216\207*3.75/\351\207\207\346\240\267\345\221\250\346\234\237</span></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("DllRead", "\344\277\241\345\217\267", nullptr));
        convert->setText(QCoreApplication::translate("DllRead", "\350\275\254\346\215\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("DllRead", "\346\265\213\350\257\225\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DllRead: public Ui_DllRead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLREAD_H
