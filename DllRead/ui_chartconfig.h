/********************************************************************************
** Form generated from reading UI file 'chartconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTCONFIG_H
#define UI_CHARTCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartConfig
{
public:
    QAction *actDraw;
    QAction *actQuit;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actZoomReset;
    QWidget *centralWidget;
    QGridLayout *gridLayout_12;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *editTitle;
    QPushButton *btnSetTitle;
    QPushButton *btnSetTitleFont;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QCheckBox *chkLegendVisible;
    QCheckBox *chkBoxLegendBackground;
    QPushButton *btnLegendFont;
    QPushButton *btnLegendlabelColor;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSpinBox *spinMarginLeft;
    QSpinBox *spinMarginRight;
    QSpinBox *spinMarginBottom;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinMarginTop;
    QLabel *label_4;
    QPushButton *btnSetMargin;
    QLabel *label_12;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_10;
    QLabel *label_6;
    QComboBox *cBoxAnimation;
    QLabel *label_8;
    QComboBox *cBoxTheme;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioSeries0;
    QRadioButton *radioSeries1;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_3;
    QPushButton *btnSeriesName;
    QLineEdit *editSeriesName;
    QCheckBox *chkSeriesVisible;
    QCheckBox *chkPointVisible;
    QPushButton *btnSeriesColor;
    QPushButton *btnSeriesPen;
    QLabel *label_5;
    QSlider *sliderSeriesOpacity;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *chkPointLabelVisible;
    QPushButton *btnSeriesLabColor;
    QPushButton *btnSeriesLabFont;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioSeriesLabFormat0;
    QRadioButton *radioSeriesLabFormat1;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioX;
    QRadioButton *radioY;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *spinAxisMin;
    QLabel *label_11;
    QDoubleSpinBox *spinAxisMax;
    QCheckBox *chkBoxVisible;
    QPushButton *btnSetAxisRange;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QLineEdit *editAxisTitle;
    QPushButton *btnAxisSetTitleFont;
    QPushButton *btnAxisSetTitle;
    QCheckBox *chkBoxAxisTitle;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton;
    QLineEdit *editAxisLabelFormat;
    QPushButton *btnAxisLabelColor;
    QPushButton *btnAxisLabelFont;
    QCheckBox *chkBoxLabelsVisible;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout;
    QCheckBox *chkGridLineVisible;
    QPushButton *btnGridLineColor;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_5;
    QPushButton *btnAxisLinePenColor;
    QSpinBox *spinTickCount;
    QCheckBox *chkAxisLineVisible;
    QLabel *label_9;
    QPushButton *btnAxisLinePen;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QLabel *label_10;
    QSpinBox *spinMinorTickCount;
    QCheckBox *chkMinorTickVisible;
    QPushButton *btnMinorColor;
    QPushButton *btnMinorPen;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *ChartConfig)
    {
        if (ChartConfig->objectName().isEmpty())
            ChartConfig->setObjectName(QString::fromUtf8("ChartConfig"));
        ChartConfig->resize(442, 750);
        ChartConfig->setMinimumSize(QSize(368, 0));
        ChartConfig->setMaximumSize(QSize(522, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        ChartConfig->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ChartConfig->setWindowIcon(icon);
        actDraw = new QAction(ChartConfig);
        actDraw->setObjectName(QString::fromUtf8("actDraw"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/828.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDraw->setIcon(icon1);
        actQuit = new QAction(ChartConfig);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actZoomIn = new QAction(ChartConfig);
        actZoomIn->setObjectName(QString::fromUtf8("actZoomIn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/418.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon3);
        actZoomOut = new QAction(ChartConfig);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/416.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon4);
        actZoomReset = new QAction(ChartConfig);
        actZoomReset->setObjectName(QString::fromUtf8("actZoomReset"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/414.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomReset->setIcon(icon5);
        centralWidget = new QWidget(ChartConfig);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(355, 0));
        centralWidget->setMaximumSize(QSize(528, 16777215));
        gridLayout_12 = new QGridLayout(centralWidget);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(260, 0));
        toolBox->setMaximumSize(QSize(500, 16777215));
        toolBox->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 420, 583));
        gridLayout_11 = new QGridLayout(page);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(3, 3, 3, 3);
        scrollArea_2 = new QScrollArea(page);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 391, 611));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        editTitle = new QLineEdit(groupBox);
        editTitle->setObjectName(QString::fromUtf8("editTitle"));

        gridLayout_2->addWidget(editTitle, 0, 0, 1, 1);

        btnSetTitle = new QPushButton(groupBox);
        btnSetTitle->setObjectName(QString::fromUtf8("btnSetTitle"));

        gridLayout_2->addWidget(btnSetTitle, 0, 1, 1, 1);

        btnSetTitleFont = new QPushButton(groupBox);
        btnSetTitleFont->setObjectName(QString::fromUtf8("btnSetTitleFont"));

        gridLayout_2->addWidget(btnSetTitleFont, 1, 0, 1, 2);


        verticalLayout_4->addWidget(groupBox);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout_9->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_9->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_4);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_9->addWidget(radioButton_3, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_9->addWidget(radioButton_4, 1, 1, 1, 1);

        chkLegendVisible = new QCheckBox(groupBox_4);
        chkLegendVisible->setObjectName(QString::fromUtf8("chkLegendVisible"));
        chkLegendVisible->setChecked(true);

        gridLayout_9->addWidget(chkLegendVisible, 2, 0, 1, 1);

        chkBoxLegendBackground = new QCheckBox(groupBox_4);
        chkBoxLegendBackground->setObjectName(QString::fromUtf8("chkBoxLegendBackground"));

        gridLayout_9->addWidget(chkBoxLegendBackground, 2, 1, 1, 1);

        btnLegendFont = new QPushButton(groupBox_4);
        btnLegendFont->setObjectName(QString::fromUtf8("btnLegendFont"));

        gridLayout_9->addWidget(btnLegendFont, 3, 0, 1, 1);

        btnLegendlabelColor = new QPushButton(groupBox_4);
        btnLegendlabelColor->setObjectName(QString::fromUtf8("btnLegendlabelColor"));

        gridLayout_9->addWidget(btnLegendlabelColor, 3, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinMarginLeft = new QSpinBox(groupBox_2);
        spinMarginLeft->setObjectName(QString::fromUtf8("spinMarginLeft"));
        spinMarginLeft->setMinimum(10);
        spinMarginLeft->setMaximum(500);

        gridLayout->addWidget(spinMarginLeft, 1, 1, 1, 1);

        spinMarginRight = new QSpinBox(groupBox_2);
        spinMarginRight->setObjectName(QString::fromUtf8("spinMarginRight"));
        spinMarginRight->setMinimum(10);
        spinMarginRight->setMaximum(500);

        gridLayout->addWidget(spinMarginRight, 2, 1, 1, 1);

        spinMarginBottom = new QSpinBox(groupBox_2);
        spinMarginBottom->setObjectName(QString::fromUtf8("spinMarginBottom"));
        spinMarginBottom->setMinimum(10);
        spinMarginBottom->setMaximum(500);

        gridLayout->addWidget(spinMarginBottom, 4, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        spinMarginTop = new QSpinBox(groupBox_2);
        spinMarginTop->setObjectName(QString::fromUtf8("spinMarginTop"));
        spinMarginTop->setMinimum(10);
        spinMarginTop->setMaximum(500);

        gridLayout->addWidget(spinMarginTop, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        btnSetMargin = new QPushButton(groupBox_2);
        btnSetMargin->setObjectName(QString::fromUtf8("btnSetMargin"));

        gridLayout->addWidget(btnSetMargin, 5, 0, 1, 2);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 2);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_15 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_10 = new QGridLayout(groupBox_15);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_6 = new QLabel(groupBox_15);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_6, 0, 0, 1, 1);

        cBoxAnimation = new QComboBox(groupBox_15);
        cBoxAnimation->addItem(QString());
        cBoxAnimation->addItem(QString());
        cBoxAnimation->addItem(QString());
        cBoxAnimation->addItem(QString());
        cBoxAnimation->setObjectName(QString::fromUtf8("cBoxAnimation"));

        gridLayout_10->addWidget(cBoxAnimation, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_15);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_8, 1, 0, 1, 1);

        cBoxTheme = new QComboBox(groupBox_15);
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->setObjectName(QString::fromUtf8("cBoxTheme"));

        gridLayout_10->addWidget(cBoxTheme, 1, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_15);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_11->addWidget(scrollArea_2, 0, 0, 1, 1);

        toolBox->addItem(page, icon, QString::fromUtf8("\345\233\276\350\241\250\350\256\276\347\275\256"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 98, 93));
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(3, 3, 3, 3);
        scrollArea_3 = new QScrollArea(page_2);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 260, 486));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox_12 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(groupBox_12);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioSeries0 = new QRadioButton(groupBox_12);
        radioSeries0->setObjectName(QString::fromUtf8("radioSeries0"));
        radioSeries0->setChecked(true);

        horizontalLayout_3->addWidget(radioSeries0);

        radioSeries1 = new QRadioButton(groupBox_12);
        radioSeries1->setObjectName(QString::fromUtf8("radioSeries1"));

        horizontalLayout_3->addWidget(radioSeries1);


        verticalLayout_9->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        gridLayout_3 = new QGridLayout(groupBox_13);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnSeriesName = new QPushButton(groupBox_13);
        btnSeriesName->setObjectName(QString::fromUtf8("btnSeriesName"));

        gridLayout_3->addWidget(btnSeriesName, 0, 0, 1, 1);

        editSeriesName = new QLineEdit(groupBox_13);
        editSeriesName->setObjectName(QString::fromUtf8("editSeriesName"));

        gridLayout_3->addWidget(editSeriesName, 0, 1, 1, 1);

        chkSeriesVisible = new QCheckBox(groupBox_13);
        chkSeriesVisible->setObjectName(QString::fromUtf8("chkSeriesVisible"));
        chkSeriesVisible->setChecked(true);

        gridLayout_3->addWidget(chkSeriesVisible, 1, 0, 1, 1);

        chkPointVisible = new QCheckBox(groupBox_13);
        chkPointVisible->setObjectName(QString::fromUtf8("chkPointVisible"));

        gridLayout_3->addWidget(chkPointVisible, 1, 1, 1, 1);

        btnSeriesColor = new QPushButton(groupBox_13);
        btnSeriesColor->setObjectName(QString::fromUtf8("btnSeriesColor"));

        gridLayout_3->addWidget(btnSeriesColor, 2, 0, 1, 1);

        btnSeriesPen = new QPushButton(groupBox_13);
        btnSeriesPen->setObjectName(QString::fromUtf8("btnSeriesPen"));

        gridLayout_3->addWidget(btnSeriesPen, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_13);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        sliderSeriesOpacity = new QSlider(groupBox_13);
        sliderSeriesOpacity->setObjectName(QString::fromUtf8("sliderSeriesOpacity"));
        sliderSeriesOpacity->setMaximum(10);
        sliderSeriesOpacity->setPageStep(2);
        sliderSeriesOpacity->setValue(10);
        sliderSeriesOpacity->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(sliderSeriesOpacity, 3, 1, 1, 1);


        verticalLayout_9->addWidget(groupBox_13);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        chkPointLabelVisible = new QCheckBox(groupBox_3);
        chkPointLabelVisible->setObjectName(QString::fromUtf8("chkPointLabelVisible"));

        verticalLayout_7->addWidget(chkPointLabelVisible);

        btnSeriesLabColor = new QPushButton(groupBox_3);
        btnSeriesLabColor->setObjectName(QString::fromUtf8("btnSeriesLabColor"));

        verticalLayout_7->addWidget(btnSeriesLabColor);

        btnSeriesLabFont = new QPushButton(groupBox_3);
        btnSeriesLabFont->setObjectName(QString::fromUtf8("btnSeriesLabFont"));

        verticalLayout_7->addWidget(btnSeriesLabFont);

        groupBox_14 = new QGroupBox(groupBox_3);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        verticalLayout_6 = new QVBoxLayout(groupBox_14);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        radioSeriesLabFormat0 = new QRadioButton(groupBox_14);
        radioSeriesLabFormat0->setObjectName(QString::fromUtf8("radioSeriesLabFormat0"));
        radioSeriesLabFormat0->setChecked(true);

        verticalLayout_6->addWidget(radioSeriesLabFormat0);

        radioSeriesLabFormat1 = new QRadioButton(groupBox_14);
        radioSeriesLabFormat1->setObjectName(QString::fromUtf8("radioSeriesLabFormat1"));

        verticalLayout_6->addWidget(radioSeriesLabFormat1);


        verticalLayout_7->addWidget(groupBox_14);


        verticalLayout_9->addWidget(groupBox_3);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_10->addWidget(scrollArea_3);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/dis3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon6, QString::fromUtf8("\346\233\262\347\272\277\350\256\276\347\275\256"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 98, 93));
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 283, 939));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_7);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioX = new QRadioButton(groupBox_7);
        radioX->setObjectName(QString::fromUtf8("radioX"));
        radioX->setChecked(true);

        horizontalLayout_2->addWidget(radioX);

        radioY = new QRadioButton(groupBox_7);
        radioY->setObjectName(QString::fromUtf8("radioY"));
        radioY->setChecked(false);

        horizontalLayout_2->addWidget(radioY);


        verticalLayout_2->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_4 = new QGridLayout(groupBox_8);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        spinAxisMin = new QDoubleSpinBox(groupBox_8);
        spinAxisMin->setObjectName(QString::fromUtf8("spinAxisMin"));
        spinAxisMin->setMinimum(-1000.000000000000000);
        spinAxisMin->setMaximum(1000.000000000000000);

        gridLayout_4->addWidget(spinAxisMin, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        spinAxisMax = new QDoubleSpinBox(groupBox_8);
        spinAxisMax->setObjectName(QString::fromUtf8("spinAxisMax"));
        spinAxisMax->setMinimum(-1000.000000000000000);
        spinAxisMax->setMaximum(10000.000000000000000);
        spinAxisMax->setValue(10.000000000000000);

        gridLayout_4->addWidget(spinAxisMax, 1, 1, 1, 1);

        chkBoxVisible = new QCheckBox(groupBox_8);
        chkBoxVisible->setObjectName(QString::fromUtf8("chkBoxVisible"));
        chkBoxVisible->setChecked(true);

        gridLayout_4->addWidget(chkBoxVisible, 2, 0, 1, 2);

        btnSetAxisRange = new QPushButton(groupBox_8);
        btnSetAxisRange->setObjectName(QString::fromUtf8("btnSetAxisRange"));

        gridLayout_4->addWidget(btnSetAxisRange, 3, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_8);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        editAxisTitle = new QLineEdit(groupBox_6);
        editAxisTitle->setObjectName(QString::fromUtf8("editAxisTitle"));

        gridLayout_6->addWidget(editAxisTitle, 0, 1, 1, 2);

        btnAxisSetTitleFont = new QPushButton(groupBox_6);
        btnAxisSetTitleFont->setObjectName(QString::fromUtf8("btnAxisSetTitleFont"));

        gridLayout_6->addWidget(btnAxisSetTitleFont, 1, 2, 1, 1);

        btnAxisSetTitle = new QPushButton(groupBox_6);
        btnAxisSetTitle->setObjectName(QString::fromUtf8("btnAxisSetTitle"));

        gridLayout_6->addWidget(btnAxisSetTitle, 0, 0, 1, 1);

        chkBoxAxisTitle = new QCheckBox(groupBox_6);
        chkBoxAxisTitle->setObjectName(QString::fromUtf8("chkBoxAxisTitle"));
        chkBoxAxisTitle->setChecked(true);

        gridLayout_6->addWidget(chkBoxAxisTitle, 1, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_6);

        groupBox_10 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        gridLayout_7 = new QGridLayout(groupBox_10);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton = new QPushButton(groupBox_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_7->addWidget(pushButton, 0, 0, 1, 1);

        editAxisLabelFormat = new QLineEdit(groupBox_10);
        editAxisLabelFormat->setObjectName(QString::fromUtf8("editAxisLabelFormat"));

        gridLayout_7->addWidget(editAxisLabelFormat, 0, 1, 1, 1);

        btnAxisLabelColor = new QPushButton(groupBox_10);
        btnAxisLabelColor->setObjectName(QString::fromUtf8("btnAxisLabelColor"));

        gridLayout_7->addWidget(btnAxisLabelColor, 1, 0, 1, 1);

        btnAxisLabelFont = new QPushButton(groupBox_10);
        btnAxisLabelFont->setObjectName(QString::fromUtf8("btnAxisLabelFont"));

        gridLayout_7->addWidget(btnAxisLabelFont, 1, 1, 1, 1);

        chkBoxLabelsVisible = new QCheckBox(groupBox_10);
        chkBoxLabelsVisible->setObjectName(QString::fromUtf8("chkBoxLabelsVisible"));
        chkBoxLabelsVisible->setChecked(true);

        gridLayout_7->addWidget(chkBoxLabelsVisible, 2, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout = new QVBoxLayout(groupBox_11);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chkGridLineVisible = new QCheckBox(groupBox_11);
        chkGridLineVisible->setObjectName(QString::fromUtf8("chkGridLineVisible"));
        chkGridLineVisible->setChecked(true);

        verticalLayout->addWidget(chkGridLineVisible);

        btnGridLineColor = new QPushButton(groupBox_11);
        btnGridLineColor->setObjectName(QString::fromUtf8("btnGridLineColor"));

        verticalLayout->addWidget(btnGridLineColor);

        pushButton_10 = new QPushButton(groupBox_11);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);


        verticalLayout_2->addWidget(groupBox_11);

        groupBox_9 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_5 = new QGridLayout(groupBox_9);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        btnAxisLinePenColor = new QPushButton(groupBox_9);
        btnAxisLinePenColor->setObjectName(QString::fromUtf8("btnAxisLinePenColor"));

        gridLayout_5->addWidget(btnAxisLinePenColor, 3, 0, 1, 2);

        spinTickCount = new QSpinBox(groupBox_9);
        spinTickCount->setObjectName(QString::fromUtf8("spinTickCount"));
        spinTickCount->setMinimum(1);
        spinTickCount->setMaximum(1000);
        spinTickCount->setValue(10);

        gridLayout_5->addWidget(spinTickCount, 0, 1, 1, 1);

        chkAxisLineVisible = new QCheckBox(groupBox_9);
        chkAxisLineVisible->setObjectName(QString::fromUtf8("chkAxisLineVisible"));
        chkAxisLineVisible->setChecked(true);

        gridLayout_5->addWidget(chkAxisLineVisible, 1, 0, 1, 2);

        label_9 = new QLabel(groupBox_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        btnAxisLinePen = new QPushButton(groupBox_9);
        btnAxisLinePen->setObjectName(QString::fromUtf8("btnAxisLinePen"));

        gridLayout_5->addWidget(btnAxisLinePen, 2, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_9);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_10, 0, 0, 1, 1);

        spinMinorTickCount = new QSpinBox(groupBox_5);
        spinMinorTickCount->setObjectName(QString::fromUtf8("spinMinorTickCount"));
        spinMinorTickCount->setValue(4);

        gridLayout_8->addWidget(spinMinorTickCount, 0, 1, 1, 1);

        chkMinorTickVisible = new QCheckBox(groupBox_5);
        chkMinorTickVisible->setObjectName(QString::fromUtf8("chkMinorTickVisible"));

        gridLayout_8->addWidget(chkMinorTickVisible, 1, 0, 1, 2);

        btnMinorColor = new QPushButton(groupBox_5);
        btnMinorColor->setObjectName(QString::fromUtf8("btnMinorColor"));

        gridLayout_8->addWidget(btnMinorColor, 2, 0, 1, 2);

        btnMinorPen = new QPushButton(groupBox_5);
        btnMinorPen->setObjectName(QString::fromUtf8("btnMinorPen"));

        gridLayout_8->addWidget(btnMinorPen, 3, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/39.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon7, QString::fromUtf8("\345\235\220\346\240\207\350\275\264\350\256\276\347\275\256"));

        gridLayout_12->addWidget(toolBox, 0, 0, 1, 1);

        ChartConfig->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ChartConfig);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ChartConfig->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actDraw);
        mainToolBar->addAction(actZoomIn);
        mainToolBar->addAction(actZoomOut);
        mainToolBar->addAction(actZoomReset);
        mainToolBar->addAction(actQuit);

        retranslateUi(ChartConfig);
        QObject::connect(actQuit, SIGNAL(triggered()), ChartConfig, SLOT(close()));

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChartConfig);
    } // setupUi

    void retranslateUi(QMainWindow *ChartConfig)
    {
        ChartConfig->setWindowTitle(QCoreApplication::translate("ChartConfig", "QChart\347\273\230\345\233\276\350\257\246\347\273\206\345\212\237\350\203\275", nullptr));
        actDraw->setText(QCoreApplication::translate("ChartConfig", "\345\210\267\346\226\260\347\273\230\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        actDraw->setToolTip(QCoreApplication::translate("ChartConfig", "\345\210\267\346\226\260\347\273\230\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("ChartConfig", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("ChartConfig", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomIn->setText(QCoreApplication::translate("ChartConfig", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("ChartConfig", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("ChartConfig", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("ChartConfig", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomReset->setText(QCoreApplication::translate("ChartConfig", "\345\216\237\345\247\213\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomReset->setToolTip(QCoreApplication::translate("ChartConfig", "\350\277\230\345\216\237\344\270\272\345\216\237\345\247\213\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("ChartConfig", "\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(tooltip)
        btnSetTitle->setToolTip(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\346\240\207\351\242\230\346\226\207\345\255\227", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSetTitle->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256", nullptr));
        btnSetTitleFont->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\346\240\207\351\242\230\345\255\227\344\275\223", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("ChartConfig", "\345\233\276\344\276\213", nullptr));
        radioButton->setText(QCoreApplication::translate("ChartConfig", "\344\270\212\346\226\271", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ChartConfig", "\344\270\213\346\226\271", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ChartConfig", "\345\267\246\344\276\247", nullptr));
        radioButton_4->setText(QCoreApplication::translate("ChartConfig", "\345\217\263\344\276\247", nullptr));
        chkLegendVisible->setText(QCoreApplication::translate("ChartConfig", "\345\233\276\344\276\213\345\217\257\350\247\201", nullptr));
        chkBoxLegendBackground->setText(QCoreApplication::translate("ChartConfig", "\350\203\214\346\231\257\345\217\257\350\247\201", nullptr));
        btnLegendFont->setText(QCoreApplication::translate("ChartConfig", "\345\255\227\344\275\223", nullptr));
        btnLegendlabelColor->setText(QCoreApplication::translate("ChartConfig", "\346\240\207\347\255\276\351\242\234\350\211\262", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ChartConfig", "\350\276\271\350\267\235", nullptr));
        label_3->setText(QCoreApplication::translate("ChartConfig", "\344\270\212\350\276\271\350\267\235", nullptr));
        label->setText(QCoreApplication::translate("ChartConfig", "\345\267\246\350\276\271\350\267\235", nullptr));
        label_2->setText(QCoreApplication::translate("ChartConfig", "\345\217\263\350\276\271\350\267\235", nullptr));
        label_4->setText(QCoreApplication::translate("ChartConfig", "\344\270\213\350\276\271\350\267\235", nullptr));
        btnSetMargin->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\350\276\271\350\267\235", nullptr));
        label_12->setText(QCoreApplication::translate("ChartConfig", "\344\277\256\346\224\271", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("ChartConfig", "\345\212\250\347\224\273\346\225\210\346\236\234", nullptr));
        label_6->setText(QCoreApplication::translate("ChartConfig", "\345\212\250\347\224\273\346\225\210\346\236\234", nullptr));
        cBoxAnimation->setItemText(0, QCoreApplication::translate("ChartConfig", "NoAnimation", nullptr));
        cBoxAnimation->setItemText(1, QCoreApplication::translate("ChartConfig", "GridAxisAnimations", nullptr));
        cBoxAnimation->setItemText(2, QCoreApplication::translate("ChartConfig", "SeriesAnimations", nullptr));
        cBoxAnimation->setItemText(3, QCoreApplication::translate("ChartConfig", "AllAnimations", nullptr));

        label_8->setText(QCoreApplication::translate("ChartConfig", "\344\270\273  \351\242\230", nullptr));
        cBoxTheme->setItemText(0, QCoreApplication::translate("ChartConfig", "Light", nullptr));
        cBoxTheme->setItemText(1, QCoreApplication::translate("ChartConfig", "BlueCerulean", nullptr));
        cBoxTheme->setItemText(2, QCoreApplication::translate("ChartConfig", "Dark", nullptr));
        cBoxTheme->setItemText(3, QCoreApplication::translate("ChartConfig", "BrownSand", nullptr));
        cBoxTheme->setItemText(4, QCoreApplication::translate("ChartConfig", "BlueNcs", nullptr));
        cBoxTheme->setItemText(5, QCoreApplication::translate("ChartConfig", "HighContrast", nullptr));
        cBoxTheme->setItemText(6, QCoreApplication::translate("ChartConfig", "BlueIcy", nullptr));
        cBoxTheme->setItemText(7, QCoreApplication::translate("ChartConfig", "Qt", nullptr));

        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("ChartConfig", "\345\233\276\350\241\250\350\256\276\347\275\256", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("ChartConfig", "\351\200\211\346\213\251\346\223\215\344\275\234\345\272\217\345\210\227", nullptr));
        radioSeries0->setText(QCoreApplication::translate("ChartConfig", "\347\263\273\345\210\2271", nullptr));
        radioSeries1->setText(QCoreApplication::translate("ChartConfig", "\347\263\273\345\210\2272", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("ChartConfig", "\346\233\262\347\272\277\345\244\226\350\247\202", nullptr));
        btnSeriesName->setText(QCoreApplication::translate("ChartConfig", "\345\272\217\345\210\227\345\220\215\347\247\260", nullptr));
        editSeriesName->setText(QCoreApplication::translate("ChartConfig", "\351\232\217\346\234\272\346\233\262\347\272\277", nullptr));
        chkSeriesVisible->setText(QCoreApplication::translate("ChartConfig", "\345\272\217\345\210\227\345\217\257\350\247\201", nullptr));
        chkPointVisible->setText(QCoreApplication::translate("ChartConfig", "\346\225\260\346\215\256\347\202\271\345\217\257\350\247\201", nullptr));
        btnSeriesColor->setText(QCoreApplication::translate("ChartConfig", "\346\233\262\347\272\277\351\242\234\350\211\262", nullptr));
        btnSeriesPen->setText(QCoreApplication::translate("ChartConfig", "\346\233\262\347\272\277Pen", nullptr));
        label_5->setText(QCoreApplication::translate("ChartConfig", "\351\200\217\346\230\216\345\272\246", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ChartConfig", "\346\225\260\346\215\256\347\202\271\346\240\207\347\255\276", nullptr));
        chkPointLabelVisible->setText(QCoreApplication::translate("ChartConfig", "\346\225\260\346\215\256\347\202\271\346\240\207\347\255\276\345\217\257\350\247\201", nullptr));
        btnSeriesLabColor->setText(QCoreApplication::translate("ChartConfig", "\346\240\207\347\255\276\351\242\234\350\211\262", nullptr));
        btnSeriesLabFont->setText(QCoreApplication::translate("ChartConfig", "\346\240\207\347\255\276\345\255\227\344\275\223", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("ChartConfig", "\346\240\207\347\255\276\346\240\274\345\274\217", nullptr));
        radioSeriesLabFormat0->setText(QCoreApplication::translate("ChartConfig", "@yPoint", nullptr));
        radioSeriesLabFormat1->setText(QCoreApplication::translate("ChartConfig", "(@xPoint, @yPoint)", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("ChartConfig", "\346\233\262\347\272\277\350\256\276\347\275\256", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\345\235\220\346\240\207\350\275\264\345\257\271\350\261\241", nullptr));
        radioX->setText(QCoreApplication::translate("ChartConfig", "X\350\275\264", nullptr));
        radioY->setText(QCoreApplication::translate("ChartConfig", "Y\350\275\264", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("ChartConfig", "\345\235\220\346\240\207\350\275\264\346\200\273\344\275\223", nullptr));
        label_7->setText(QCoreApplication::translate("ChartConfig", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("ChartConfig", "\346\234\200\345\244\247\345\200\274", nullptr));
        chkBoxVisible->setText(QCoreApplication::translate("ChartConfig", "isVisible", nullptr));
        btnSetAxisRange->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\345\235\220\346\240\207\350\214\203\345\233\264", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("ChartConfig", "\350\275\264\346\240\207\351\242\230", nullptr));
        editAxisTitle->setText(QCoreApplication::translate("ChartConfig", "time(secs)", nullptr));
        btnAxisSetTitleFont->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        btnAxisSetTitle->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\346\240\207\351\242\230", nullptr));
        chkBoxAxisTitle->setText(QCoreApplication::translate("ChartConfig", "isTitleVisible", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("ChartConfig", "\350\275\264\345\210\273\345\272\246\346\240\207\347\255\276", nullptr));
        pushButton->setText(QCoreApplication::translate("ChartConfig", "\346\240\207\347\255\276\346\240\274\345\274\217", nullptr));
        editAxisLabelFormat->setText(QCoreApplication::translate("ChartConfig", "%.1f", nullptr));
        btnAxisLabelColor->setText(QCoreApplication::translate("ChartConfig", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        btnAxisLabelFont->setText(QCoreApplication::translate("ChartConfig", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        chkBoxLabelsVisible->setText(QCoreApplication::translate("ChartConfig", "labelsVisible", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("ChartConfig", "GridLine", nullptr));
        chkGridLineVisible->setText(QCoreApplication::translate("ChartConfig", "isGridLineVisible", nullptr));
        btnGridLineColor->setText(QCoreApplication::translate("ChartConfig", "gridLineColor", nullptr));
        pushButton_10->setText(QCoreApplication::translate("ChartConfig", "gridLinePen", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("ChartConfig", "Axis and Ticks", nullptr));
        btnAxisLinePenColor->setText(QCoreApplication::translate("ChartConfig", "linePenColor", nullptr));
        chkAxisLineVisible->setText(QCoreApplication::translate("ChartConfig", "isLineVisible", nullptr));
        label_9->setText(QCoreApplication::translate("ChartConfig", "Tick\344\270\252\346\225\260", nullptr));
        btnAxisLinePen->setText(QCoreApplication::translate("ChartConfig", "linePen", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("ChartConfig", "MinorTick", nullptr));
        label_10->setText(QCoreApplication::translate("ChartConfig", "MinorTick\344\270\252\346\225\260", nullptr));
        chkMinorTickVisible->setText(QCoreApplication::translate("ChartConfig", "isMinorGridLineVisible", nullptr));
        btnMinorColor->setText(QCoreApplication::translate("ChartConfig", "minorGridLineColor", nullptr));
        btnMinorPen->setText(QCoreApplication::translate("ChartConfig", "minorGridLinePen", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("ChartConfig", "\345\235\220\346\240\207\350\275\264\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartConfig: public Ui_ChartConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTCONFIG_H
