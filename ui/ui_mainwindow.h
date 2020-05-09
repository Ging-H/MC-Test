/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionCurve;
    QAction *actionbalck;
    QAction *actionorigenral;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QPushButton *btnOpenPort;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QCheckBox *ckbStatus;
    QFrame *line;
    QCheckBox *ckbFOCD;
    QCheckBox *ckbOverV;
    QCheckBox *ckbUnderV;
    QCheckBox *ckbOverH;
    QCheckBox *ckbSU;
    QCheckBox *ckbSFB;
    QCheckBox *ckbOverC;
    QCheckBox *ckbSW;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QPushButton *btnStart;
    QPushButton *btnStopRamp;
    QPushButton *btnStartStop;
    QPushButton *btnStop;
    QPushButton *btnAlignment;
    QPushButton *btnFaultAck;
    QPushButton *btnReset;
    QComboBox *cbbCtrlMode;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QPushButton *btnPosKp;
    QSpinBox *spbPosKp;
    QPushButton *btnPosKi;
    QSpinBox *spbPosKi;
    QPushButton *btnPosKd;
    QSpinBox *spbPosKd;
    QPushButton *btnRamp;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *spbPosDuration;
    QDoubleSpinBox *spbPosTarget;
    QDoubleSpinBox *spbCurrentPos;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnSpdKp;
    QSpinBox *spbSpdKp;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnSpdKi;
    QSpinBox *spbSpdKi;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnSpdTarget;
    QDoubleSpinBox *spbSpdTarget;
    QPushButton *btnSpdRamp;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *spbSpdRampTarget;
    QDoubleSpinBox *spbSpdDuration;
    QSpinBox *spbSpeed;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QPushButton *btnCurrentRef;
    QPushButton *btnIdKp;
    QSpacerItem *verticalSpacer;
    QSpinBox *spbIqKp;
    QPushButton *btnIqKi;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *spbIqRef;
    QDoubleSpinBox *spbIdRef;
    QPushButton *btnIdKi;
    QSpinBox *spbIdKi;
    QSpinBox *spbIdKp;
    QSpinBox *spbFlux;
    QPushButton *btnIqKp;
    QSpinBox *spbIqKi;
    QSpinBox *spbTorque;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOtherCMD;
    QComboBox *cbbMotorNum;
    QComboBox *cbbFrameID;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cbbRegAddr;
    QComboBox *cbbCMD;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *txtOtherCMD;
    QLineEdit *txtOtherRx;
    QListWidget *lstLog;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(871, 510);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/general/general/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionCurve = new QAction(MainWindow);
        actionCurve->setObjectName(QStringLiteral("actionCurve"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/general/general/Curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCurve->setIcon(icon1);
        actionbalck = new QAction(MainWindow);
        actionbalck->setObjectName(QStringLiteral("actionbalck"));
        actionorigenral = new QAction(MainWindow);
        actionorigenral->setObjectName(QStringLiteral("actionorigenral"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        QGBSerialConfig = new QGroupBox(centralWidget);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy);
        QGBSerialConfig->setMinimumSize(QSize(171, 0));
        QGBSerialConfig->setMaximumSize(QSize(171, 221));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        gridLayout_7 = new QGridLayout(QGBSerialConfig);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(3, 3, 3, 3);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(6);
        gridLayout_3->setVerticalSpacing(9);
        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbbDataBit->sizePolicy().hasHeightForWidth());
        cbbDataBit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        cbbDataBit->setFont(font);
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy2);
        cbbPortNum->setFont(font);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        sizePolicy1.setHeightForWidth(cbbVerify->sizePolicy().hasHeightForWidth());
        cbbVerify->setSizePolicy(sizePolicy1);
        cbbVerify->setFont(font);
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setEnabled(true);
        sizePolicy1.setHeightForWidth(cbbStopBit->sizePolicy().hasHeightForWidth());
        cbbStopBit->setSizePolicy(sizePolicy1);
        cbbStopBit->setFont(font);
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        sizePolicy1.setHeightForWidth(cbbBaud->sizePolicy().hasHeightForWidth());
        cbbBaud->setSizePolicy(sizePolicy1);
        cbbBaud->setFont(font);
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 2);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/general/general/view-refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);
        btnRefresh->setIconSize(QSize(30, 25));

        gridLayout_7->addWidget(btnRefresh, 1, 0, 1, 1);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(5);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnOpenPort->sizePolicy().hasHeightForWidth());
        btnOpenPort->setSizePolicy(sizePolicy4);
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/general/general/com_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/general/general/com_connect_1.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon3);
        btnOpenPort->setIconSize(QSize(30, 25));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_7->addWidget(btnOpenPort, 1, 1, 1, 1);


        gridLayout_4->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setMinimumSize(QSize(129, 221));
        groupBox_3->setMaximumSize(QSize(129, 221));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(2);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(3, 3, 3, 3);
        ckbStatus = new QCheckBox(groupBox_3);
        ckbStatus->setObjectName(QStringLiteral("ckbStatus"));
        ckbStatus->setEnabled(true);
        ckbStatus->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_ok.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbStatus->setIconSize(QSize(14, 14));
        ckbStatus->setCheckable(true);
        ckbStatus->setTristate(true);

        gridLayout_10->addWidget(ckbStatus, 0, 0, 1, 1);

        line = new QFrame(groupBox_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line, 1, 0, 1, 1);

        ckbFOCD = new QCheckBox(groupBox_3);
        ckbFOCD->setObjectName(QStringLiteral("ckbFOCD"));
        ckbFOCD->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbFOCD->setTristate(true);

        gridLayout_10->addWidget(ckbFOCD, 2, 0, 1, 1);

        ckbOverV = new QCheckBox(groupBox_3);
        ckbOverV->setObjectName(QStringLiteral("ckbOverV"));
        ckbOverV->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbOverV->setTristate(true);

        gridLayout_10->addWidget(ckbOverV, 3, 0, 1, 1);

        ckbUnderV = new QCheckBox(groupBox_3);
        ckbUnderV->setObjectName(QStringLiteral("ckbUnderV"));
        ckbUnderV->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbUnderV->setTristate(true);

        gridLayout_10->addWidget(ckbUnderV, 4, 0, 1, 1);

        ckbOverH = new QCheckBox(groupBox_3);
        ckbOverH->setObjectName(QStringLiteral("ckbOverH"));
        ckbOverH->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbOverH->setTristate(true);

        gridLayout_10->addWidget(ckbOverH, 5, 0, 1, 1);

        ckbSU = new QCheckBox(groupBox_3);
        ckbSU->setObjectName(QStringLiteral("ckbSU"));
        ckbSU->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbSU->setTristate(true);

        gridLayout_10->addWidget(ckbSU, 6, 0, 1, 1);

        ckbSFB = new QCheckBox(groupBox_3);
        ckbSFB->setObjectName(QStringLiteral("ckbSFB"));
        ckbSFB->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbSFB->setTristate(true);

        gridLayout_10->addWidget(ckbSFB, 7, 0, 1, 1);

        ckbOverC = new QCheckBox(groupBox_3);
        ckbOverC->setObjectName(QStringLiteral("ckbOverC"));
        ckbOverC->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbOverC->setTristate(true);

        gridLayout_10->addWidget(ckbOverC, 8, 0, 1, 1);

        ckbSW = new QCheckBox(groupBox_3);
        ckbSW->setObjectName(QStringLiteral("ckbSW"));
        ckbSW->setStyleSheet(QString::fromUtf8("/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/general/general/check3_faultNone.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/general/general/check3_faultNow.png);\n"
"}\n"
"/*\351\273\230\350\256\244-\344\270\211\346\200\201*/\n"
"QCheckBox::indicator::indeterminate { \n"
"    image: url(:/general/general/check3_faultOccurred.png);\n"
"}"));
        ckbSW->setTristate(true);

        gridLayout_10->addWidget(ckbSW, 9, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(161, 221));
        groupBox_2->setMaximumSize(QSize(161, 221));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(2);
        gridLayout_6->setVerticalSpacing(5);
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        btnStart = new QPushButton(groupBox_2);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnStart, 1, 0, 1, 2);

        btnStopRamp = new QPushButton(groupBox_2);
        btnStopRamp->setObjectName(QStringLiteral("btnStopRamp"));
        sizePolicy5.setHeightForWidth(btnStopRamp->sizePolicy().hasHeightForWidth());
        btnStopRamp->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnStopRamp, 4, 0, 1, 2);

        btnStartStop = new QPushButton(groupBox_2);
        btnStartStop->setObjectName(QStringLiteral("btnStartStop"));
        sizePolicy5.setHeightForWidth(btnStartStop->sizePolicy().hasHeightForWidth());
        btnStartStop->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnStartStop, 3, 0, 1, 2);

        btnStop = new QPushButton(groupBox_2);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        sizePolicy5.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnStop, 2, 0, 1, 2);

        btnAlignment = new QPushButton(groupBox_2);
        btnAlignment->setObjectName(QStringLiteral("btnAlignment"));
        sizePolicy5.setHeightForWidth(btnAlignment->sizePolicy().hasHeightForWidth());
        btnAlignment->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnAlignment, 5, 0, 1, 2);

        btnFaultAck = new QPushButton(groupBox_2);
        btnFaultAck->setObjectName(QStringLiteral("btnFaultAck"));
        sizePolicy5.setHeightForWidth(btnFaultAck->sizePolicy().hasHeightForWidth());
        btnFaultAck->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnFaultAck, 7, 0, 1, 1);

        btnReset = new QPushButton(groupBox_2);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        sizePolicy5.setHeightForWidth(btnReset->sizePolicy().hasHeightForWidth());
        btnReset->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(btnReset, 0, 0, 1, 2);

        cbbCtrlMode = new QComboBox(groupBox_2);
        cbbCtrlMode->setObjectName(QStringLiteral("cbbCtrlMode"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cbbCtrlMode->sizePolicy().hasHeightForWidth());
        cbbCtrlMode->setSizePolicy(sizePolicy6);

        gridLayout_6->addWidget(cbbCtrlMode, 7, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(191, 221));
        groupBox->setMaximumSize(QSize(191, 16777215));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(2);
        gridLayout_8->setVerticalSpacing(10);
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        btnPosKp = new QPushButton(groupBox);
        btnPosKp->setObjectName(QStringLiteral("btnPosKp"));
        sizePolicy5.setHeightForWidth(btnPosKp->sizePolicy().hasHeightForWidth());
        btnPosKp->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(btnPosKp, 0, 0, 1, 1);

        spbPosKp = new QSpinBox(groupBox);
        spbPosKp->setObjectName(QStringLiteral("spbPosKp"));
        sizePolicy5.setHeightForWidth(spbPosKp->sizePolicy().hasHeightForWidth());
        spbPosKp->setSizePolicy(sizePolicy5);
        spbPosKp->setMaximum(65535);

        gridLayout_8->addWidget(spbPosKp, 0, 1, 1, 1);

        btnPosKi = new QPushButton(groupBox);
        btnPosKi->setObjectName(QStringLiteral("btnPosKi"));
        sizePolicy5.setHeightForWidth(btnPosKi->sizePolicy().hasHeightForWidth());
        btnPosKi->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(btnPosKi, 1, 0, 1, 1);

        spbPosKi = new QSpinBox(groupBox);
        spbPosKi->setObjectName(QStringLiteral("spbPosKi"));
        sizePolicy5.setHeightForWidth(spbPosKi->sizePolicy().hasHeightForWidth());
        spbPosKi->setSizePolicy(sizePolicy5);
        spbPosKi->setMaximum(65535);

        gridLayout_8->addWidget(spbPosKi, 1, 1, 1, 1);

        btnPosKd = new QPushButton(groupBox);
        btnPosKd->setObjectName(QStringLiteral("btnPosKd"));
        sizePolicy5.setHeightForWidth(btnPosKd->sizePolicy().hasHeightForWidth());
        btnPosKd->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(btnPosKd, 2, 0, 1, 1);

        spbPosKd = new QSpinBox(groupBox);
        spbPosKd->setObjectName(QStringLiteral("spbPosKd"));
        sizePolicy5.setHeightForWidth(spbPosKd->sizePolicy().hasHeightForWidth());
        spbPosKd->setSizePolicy(sizePolicy5);
        spbPosKd->setMaximum(65535);

        gridLayout_8->addWidget(spbPosKd, 2, 1, 1, 1);

        btnRamp = new QPushButton(groupBox);
        btnRamp->setObjectName(QStringLiteral("btnRamp"));
        sizePolicy5.setHeightForWidth(btnRamp->sizePolicy().hasHeightForWidth());
        btnRamp->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(btnRamp, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        spbPosDuration = new QDoubleSpinBox(groupBox);
        spbPosDuration->setObjectName(QStringLiteral("spbPosDuration"));
        spbPosDuration->setMaximum(1e+21);

        gridLayout->addWidget(spbPosDuration, 2, 1, 1, 1);

        spbPosTarget = new QDoubleSpinBox(groupBox);
        spbPosTarget->setObjectName(QStringLiteral("spbPosTarget"));
        spbPosTarget->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbPosTarget->setMinimum(-1e+9);
        spbPosTarget->setMaximum(1e+9);
        spbPosTarget->setValue(0);

        gridLayout->addWidget(spbPosTarget, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout, 3, 1, 1, 1);

        spbCurrentPos = new QDoubleSpinBox(groupBox);
        spbCurrentPos->setObjectName(QStringLiteral("spbCurrentPos"));
        spbCurrentPos->setEnabled(false);
        spbCurrentPos->setFocusPolicy(Qt::NoFocus);
        spbCurrentPos->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbCurrentPos->setDecimals(3);
        spbCurrentPos->setMaximum(1e+19);

        gridLayout_8->addWidget(spbCurrentPos, 4, 0, 1, 2);


        gridLayout_4->addWidget(groupBox, 0, 3, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(171, 0));
        groupBox_4->setMaximumSize(QSize(171, 16777215));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(2);
        gridLayout_9->setVerticalSpacing(10);
        gridLayout_9->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnSpdKp = new QPushButton(groupBox_4);
        btnSpdKp->setObjectName(QStringLiteral("btnSpdKp"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(btnSpdKp->sizePolicy().hasHeightForWidth());
        btnSpdKp->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(btnSpdKp);

        spbSpdKp = new QSpinBox(groupBox_4);
        spbSpdKp->setObjectName(QStringLiteral("spbSpdKp"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(5);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(spbSpdKp->sizePolicy().hasHeightForWidth());
        spbSpdKp->setSizePolicy(sizePolicy8);
        spbSpdKp->setMaximum(65535);

        horizontalLayout_3->addWidget(spbSpdKp);


        gridLayout_9->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnSpdKi = new QPushButton(groupBox_4);
        btnSpdKi->setObjectName(QStringLiteral("btnSpdKi"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(btnSpdKi->sizePolicy().hasHeightForWidth());
        btnSpdKi->setSizePolicy(sizePolicy9);

        horizontalLayout_4->addWidget(btnSpdKi);

        spbSpdKi = new QSpinBox(groupBox_4);
        spbSpdKi->setObjectName(QStringLiteral("spbSpdKi"));
        sizePolicy8.setHeightForWidth(spbSpdKi->sizePolicy().hasHeightForWidth());
        spbSpdKi->setSizePolicy(sizePolicy8);
        spbSpdKi->setMaximum(65535);

        horizontalLayout_4->addWidget(spbSpdKi);


        gridLayout_9->addLayout(horizontalLayout_4, 1, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btnSpdTarget = new QPushButton(groupBox_4);
        btnSpdTarget->setObjectName(QStringLiteral("btnSpdTarget"));
        sizePolicy7.setHeightForWidth(btnSpdTarget->sizePolicy().hasHeightForWidth());
        btnSpdTarget->setSizePolicy(sizePolicy7);

        horizontalLayout_5->addWidget(btnSpdTarget);

        spbSpdTarget = new QDoubleSpinBox(groupBox_4);
        spbSpdTarget->setObjectName(QStringLiteral("spbSpdTarget"));
        sizePolicy8.setHeightForWidth(spbSpdTarget->sizePolicy().hasHeightForWidth());
        spbSpdTarget->setSizePolicy(sizePolicy8);
        spbSpdTarget->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbSpdTarget->setDecimals(0);
        spbSpdTarget->setMinimum(-1e+9);
        spbSpdTarget->setMaximum(1e+9);
        spbSpdTarget->setValue(0);

        horizontalLayout_5->addWidget(spbSpdTarget);


        gridLayout_9->addLayout(horizontalLayout_5, 2, 0, 1, 2);

        btnSpdRamp = new QPushButton(groupBox_4);
        btnSpdRamp->setObjectName(QStringLiteral("btnSpdRamp"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(btnSpdRamp->sizePolicy().hasHeightForWidth());
        btnSpdRamp->setSizePolicy(sizePolicy10);

        gridLayout_9->addWidget(btnSpdRamp, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy11);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy11.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy11);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        spbSpdRampTarget = new QDoubleSpinBox(groupBox_4);
        spbSpdRampTarget->setObjectName(QStringLiteral("spbSpdRampTarget"));
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(3);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(spbSpdRampTarget->sizePolicy().hasHeightForWidth());
        spbSpdRampTarget->setSizePolicy(sizePolicy12);
        spbSpdRampTarget->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbSpdRampTarget->setDecimals(0);
        spbSpdRampTarget->setMinimum(-1e+9);
        spbSpdRampTarget->setMaximum(1e+9);
        spbSpdRampTarget->setValue(0);

        gridLayout_2->addWidget(spbSpdRampTarget, 0, 1, 1, 1);

        spbSpdDuration = new QDoubleSpinBox(groupBox_4);
        spbSpdDuration->setObjectName(QStringLiteral("spbSpdDuration"));
        sizePolicy12.setHeightForWidth(spbSpdDuration->sizePolicy().hasHeightForWidth());
        spbSpdDuration->setSizePolicy(sizePolicy12);
        spbSpdDuration->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbSpdDuration->setDecimals(0);
        spbSpdDuration->setMaximum(1e+21);

        gridLayout_2->addWidget(spbSpdDuration, 2, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 3, 1, 1, 1);

        spbSpeed = new QSpinBox(groupBox_4);
        spbSpeed->setObjectName(QStringLiteral("spbSpeed"));
        spbSpeed->setEnabled(false);
        spbSpeed->setFocusPolicy(Qt::NoFocus);
        spbSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbSpeed->setMinimum(-999999999);
        spbSpeed->setMaximum(999999999);
        spbSpeed->setValue(0);

        gridLayout_9->addWidget(spbSpeed, 4, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_4, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(171, 0));
        groupBox_5->setMaximumSize(QSize(171, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        btnCurrentRef = new QPushButton(groupBox_5);
        btnCurrentRef->setObjectName(QStringLiteral("btnCurrentRef"));
        sizePolicy5.setHeightForWidth(btnCurrentRef->sizePolicy().hasHeightForWidth());
        btnCurrentRef->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(btnCurrentRef, 4, 0, 1, 1);

        btnIdKp = new QPushButton(groupBox_5);
        btnIdKp->setObjectName(QStringLiteral("btnIdKp"));
        sizePolicy5.setHeightForWidth(btnIdKp->sizePolicy().hasHeightForWidth());
        btnIdKp->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(btnIdKp, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 7, 0, 1, 2);

        spbIqKp = new QSpinBox(groupBox_5);
        spbIqKp->setObjectName(QStringLiteral("spbIqKp"));
        sizePolicy5.setHeightForWidth(spbIqKp->sizePolicy().hasHeightForWidth());
        spbIqKp->setSizePolicy(sizePolicy5);
        spbIqKp->setMaximum(65535);

        gridLayout_5->addWidget(spbIqKp, 0, 1, 1, 1);

        btnIqKi = new QPushButton(groupBox_5);
        btnIqKi->setObjectName(QStringLiteral("btnIqKi"));
        sizePolicy5.setHeightForWidth(btnIqKi->sizePolicy().hasHeightForWidth());
        btnIqKi->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(btnIqKi, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spbIqRef = new QDoubleSpinBox(groupBox_5);
        spbIqRef->setObjectName(QStringLiteral("spbIqRef"));
        spbIqRef->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbIqRef->setDecimals(0);
        spbIqRef->setMaximum(1e+12);
        spbIqRef->setValue(0);

        verticalLayout_4->addWidget(spbIqRef);

        spbIdRef = new QDoubleSpinBox(groupBox_5);
        spbIdRef->setObjectName(QStringLiteral("spbIdRef"));
        spbIdRef->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbIdRef->setDecimals(0);
        spbIdRef->setMaximum(1e+12);
        spbIdRef->setValue(0);

        verticalLayout_4->addWidget(spbIdRef);


        gridLayout_5->addLayout(verticalLayout_4, 4, 1, 1, 1);

        btnIdKi = new QPushButton(groupBox_5);
        btnIdKi->setObjectName(QStringLiteral("btnIdKi"));
        sizePolicy5.setHeightForWidth(btnIdKi->sizePolicy().hasHeightForWidth());
        btnIdKi->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(btnIdKi, 3, 0, 1, 1);

        spbIdKi = new QSpinBox(groupBox_5);
        spbIdKi->setObjectName(QStringLiteral("spbIdKi"));
        sizePolicy5.setHeightForWidth(spbIdKi->sizePolicy().hasHeightForWidth());
        spbIdKi->setSizePolicy(sizePolicy5);
        spbIdKi->setMaximum(65535);

        gridLayout_5->addWidget(spbIdKi, 3, 1, 1, 1);

        spbIdKp = new QSpinBox(groupBox_5);
        spbIdKp->setObjectName(QStringLiteral("spbIdKp"));
        sizePolicy5.setHeightForWidth(spbIdKp->sizePolicy().hasHeightForWidth());
        spbIdKp->setSizePolicy(sizePolicy5);
        spbIdKp->setMaximum(65535);

        gridLayout_5->addWidget(spbIdKp, 2, 1, 1, 1);

        spbFlux = new QSpinBox(groupBox_5);
        spbFlux->setObjectName(QStringLiteral("spbFlux"));
        spbFlux->setEnabled(false);
        spbFlux->setFocusPolicy(Qt::NoFocus);
        spbFlux->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbFlux->setMinimum(-999999999);
        spbFlux->setMaximum(999999999);
        spbFlux->setValue(0);

        gridLayout_5->addWidget(spbFlux, 6, 0, 1, 2);

        btnIqKp = new QPushButton(groupBox_5);
        btnIqKp->setObjectName(QStringLiteral("btnIqKp"));
        sizePolicy5.setHeightForWidth(btnIqKp->sizePolicy().hasHeightForWidth());
        btnIqKp->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(btnIqKp, 0, 0, 1, 1);

        spbIqKi = new QSpinBox(groupBox_5);
        spbIqKi->setObjectName(QStringLiteral("spbIqKi"));
        sizePolicy5.setHeightForWidth(spbIqKi->sizePolicy().hasHeightForWidth());
        spbIqKi->setSizePolicy(sizePolicy5);
        spbIqKi->setMaximum(65535);

        gridLayout_5->addWidget(spbIqKi, 1, 1, 1, 1);

        spbTorque = new QSpinBox(groupBox_5);
        spbTorque->setObjectName(QStringLiteral("spbTorque"));
        spbTorque->setEnabled(false);
        spbTorque->setFocusPolicy(Qt::NoFocus);
        spbTorque->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbTorque->setMinimum(-999999999);
        spbTorque->setMaximum(999999999);
        spbTorque->setValue(0);

        gridLayout_5->addWidget(spbTorque, 5, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_5, 1, 0, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnOtherCMD = new QPushButton(centralWidget);
        btnOtherCMD->setObjectName(QStringLiteral("btnOtherCMD"));
        sizePolicy3.setHeightForWidth(btnOtherCMD->sizePolicy().hasHeightForWidth());
        btnOtherCMD->setSizePolicy(sizePolicy3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/general/general/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnOtherCMD->setIcon(icon4);

        horizontalLayout->addWidget(btnOtherCMD);

        cbbMotorNum = new QComboBox(centralWidget);
        cbbMotorNum->setObjectName(QStringLiteral("cbbMotorNum"));
        QSizePolicy sizePolicy13(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy13.setHorizontalStretch(2);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(cbbMotorNum->sizePolicy().hasHeightForWidth());
        cbbMotorNum->setSizePolicy(sizePolicy13);

        horizontalLayout->addWidget(cbbMotorNum);

        cbbFrameID = new QComboBox(centralWidget);
        cbbFrameID->setObjectName(QStringLiteral("cbbFrameID"));
        QSizePolicy sizePolicy14(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy14.setHorizontalStretch(1);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(cbbFrameID->sizePolicy().hasHeightForWidth());
        cbbFrameID->setSizePolicy(sizePolicy14);
        cbbFrameID->setMinimumSize(QSize(125, 0));
        cbbFrameID->setMaximumSize(QSize(125100, 16777215));

        horizontalLayout->addWidget(cbbFrameID);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        cbbRegAddr = new QComboBox(centralWidget);
        cbbRegAddr->setObjectName(QStringLiteral("cbbRegAddr"));
        cbbRegAddr->setEnabled(false);

        verticalLayout_2->addWidget(cbbRegAddr);

        cbbCMD = new QComboBox(centralWidget);
        cbbCMD->setObjectName(QStringLiteral("cbbCMD"));

        verticalLayout_2->addWidget(cbbCMD);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        txtOtherCMD = new QLineEdit(centralWidget);
        txtOtherCMD->setObjectName(QStringLiteral("txtOtherCMD"));

        verticalLayout_3->addWidget(txtOtherCMD);

        txtOtherRx = new QLineEdit(centralWidget);
        txtOtherRx->setObjectName(QStringLiteral("txtOtherRx"));
        txtOtherRx->setEnabled(false);

        verticalLayout_3->addWidget(txtOtherRx);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 1, 1, 4);

        lstLog = new QListWidget(centralWidget);
        lstLog->setObjectName(QStringLiteral("lstLog"));

        gridLayout_4->addWidget(lstLog, 2, 1, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(actionAbout);
        menu->addAction(menu_3->menuAction());
        menu_3->addAction(actionbalck);
        menu_3->addAction(actionorigenral);
        menu_2->addAction(actionCurve);

        retranslateUi(MainWindow);

        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionCurve->setText(QApplication::translate("MainWindow", "\346\233\262\347\272\277", Q_NULLPTR));
        actionbalck->setText(QApplication::translate("MainWindow", "Black", Q_NULLPTR));
        actionorigenral->setText(QApplication::translate("MainWindow", "Original", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Status/Fault", Q_NULLPTR));
        ckbStatus->setText(QApplication::translate("MainWindow", "Not Connected", Q_NULLPTR));
        ckbFOCD->setText(QApplication::translate("MainWindow", "FOC duration", Q_NULLPTR));
        ckbOverV->setText(QApplication::translate("MainWindow", "Over voltage", Q_NULLPTR));
        ckbUnderV->setText(QApplication::translate("MainWindow", "Under voltage", Q_NULLPTR));
        ckbOverH->setText(QApplication::translate("MainWindow", "Overheat", Q_NULLPTR));
        ckbSU->setText(QApplication::translate("MainWindow", "Start-up", Q_NULLPTR));
        ckbSFB->setText(QApplication::translate("MainWindow", "Speedfeedback", Q_NULLPTR));
        ckbOverC->setText(QApplication::translate("MainWindow", "Overcurrent", Q_NULLPTR));
        ckbSW->setText(QApplication::translate("MainWindow", "Software error", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\237\272\347\241\200\346\216\247\345\210\266", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", Q_NULLPTR));
        btnStopRamp->setText(QApplication::translate("MainWindow", "Stop Ramp", Q_NULLPTR));
        btnStartStop->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250/\345\201\234\346\255\242", Q_NULLPTR));
        btnStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        btnAlignment->setText(QApplication::translate("MainWindow", "\346\240\241\345\207\206\345\257\271\351\275\220", Q_NULLPTR));
        btnFaultAck->setText(QApplication::translate("MainWindow", "Fault Ack", Q_NULLPTR));
        btnReset->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR));
        cbbCtrlMode->clear();
        cbbCtrlMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Speed", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Torque", Q_NULLPTR)
        );
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\216\247\345\210\266", Q_NULLPTR));
        btnPosKp->setText(QApplication::translate("MainWindow", "Kp", Q_NULLPTR));
        btnPosKi->setText(QApplication::translate("MainWindow", "Ki", Q_NULLPTR));
        btnPosKd->setText(QApplication::translate("MainWindow", "Kd", Q_NULLPTR));
        btnRamp->setText(QApplication::translate("MainWindow", "Ramp", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237", Q_NULLPTR));
        spbCurrentPos->setPrefix(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256 ", Q_NULLPTR));
        spbCurrentPos->setSuffix(QApplication::translate("MainWindow", " r", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\351\200\237\345\272\246\346\216\247\345\210\266", Q_NULLPTR));
        btnSpdKp->setText(QApplication::translate("MainWindow", "Kp", Q_NULLPTR));
        btnSpdKi->setText(QApplication::translate("MainWindow", "Ki", Q_NULLPTR));
        btnSpdTarget->setText(QApplication::translate("MainWindow", "Spd", Q_NULLPTR));
        btnSpdRamp->setText(QApplication::translate("MainWindow", "Ramp", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237", Q_NULLPTR));
        spbSpeed->setSuffix(QApplication::translate("MainWindow", " RPM", Q_NULLPTR));
        spbSpeed->setPrefix(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\275\254\351\200\237\357\274\232 ", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        btnCurrentRef->setText(QApplication::translate("MainWindow", "Ref", Q_NULLPTR));
        btnIdKp->setText(QApplication::translate("MainWindow", "Id Kp", Q_NULLPTR));
        btnIqKi->setText(QApplication::translate("MainWindow", "Iq Ki", Q_NULLPTR));
        spbIqRef->setPrefix(QApplication::translate("MainWindow", "Iq\357\274\232", Q_NULLPTR));
        spbIqRef->setSuffix(QString());
        spbIdRef->setPrefix(QApplication::translate("MainWindow", "Id\357\274\232", Q_NULLPTR));
        btnIdKi->setText(QApplication::translate("MainWindow", "Id Ki", Q_NULLPTR));
        spbFlux->setSuffix(QString());
        spbFlux->setPrefix(QApplication::translate("MainWindow", "Flux(Id)\357\274\232 ", Q_NULLPTR));
        btnIqKp->setText(QApplication::translate("MainWindow", "Iq Kp", Q_NULLPTR));
        spbTorque->setSuffix(QString());
        spbTorque->setPrefix(QApplication::translate("MainWindow", "Torque(Iq)\357\274\232 ", Q_NULLPTR));
        btnOtherCMD->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        cbbMotorNum->clear();
        cbbMotorNum->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\224\265\346\234\272_\351\273\230\350\256\244", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Motor 1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Motor 2", Q_NULLPTR)
        );
        cbbFrameID->clear();
        cbbFrameID->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "FrameID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_REG", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GET_REG", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EXECUTE_CMD", Q_NULLPTR)
         << QApplication::translate("MainWindow", "STORE_TOADDR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "LOAD_FROMADDR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GET_BOARD_INFO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_SPEED_RAMP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GET_REVUP_DATA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_REVUP_DATA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_CURRENT_REF", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GET_MP_INFO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GET_FW_VERSION", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_TORQUE_RAMP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SET_POSITION_CMD", Q_NULLPTR)
        );
        cbbCMD->clear();
        cbbCMD->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "CMD", Q_NULLPTR)
         << QApplication::translate("MainWindow", "START_MOTOR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "STOP_MOTOR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "STOP_RAMP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RESET", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PING", Q_NULLPTR)
         << QApplication::translate("MainWindow", "START_STOP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FAULT_ACK", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ENCODER_ALIGN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "IQDREF_CLEAR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PFC_ENABLE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PFC_DISABLE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PFC_FAULT_ACK", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SC_START", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SC_STOP", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        txtOtherCMD->setToolTip(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200\343\200\201\346\225\260\346\215\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\243\216\346\240\274\344\270\273\351\242\230", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\233\262\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
