/********************************************************************************
** Form generated from reading UI file 'curve.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVE_H
#define UI_CURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Curve
{
public:
    QAction *actionPause;
    QAction *actionZoom;
    QAction *actionClear;
    QAction *actionSaveImg;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Curve)
    {
        if (Curve->objectName().isEmpty())
            Curve->setObjectName(QStringLiteral("Curve"));
        Curve->resize(650, 478);
        QIcon icon;
        icon.addFile(QStringLiteral(":/general/general/Curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        Curve->setWindowIcon(icon);
        actionPause = new QAction(Curve);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionPause->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/general/general/Paused.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/general/general/play_1.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPause->setIcon(icon1);
        actionZoom = new QAction(Curve);
        actionZoom->setObjectName(QStringLiteral("actionZoom"));
        actionZoom->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/general/general/selection_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/general/general/pointer.png"), QSize(), QIcon::Normal, QIcon::On);
        actionZoom->setIcon(icon2);
        actionClear = new QAction(Curve);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/general/general/view-refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionSaveImg = new QAction(Curve);
        actionSaveImg->setObjectName(QStringLiteral("actionSaveImg"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/general/general/Save_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveImg->setIcon(icon4);
        centralwidget = new QWidget(Curve);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QStringLiteral("plot"));

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        Curve->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Curve);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Curve->setStatusBar(statusbar);
        toolBar = new QToolBar(Curve);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(25, 25));
        Curve->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSaveImg);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionClear);
        toolBar->addAction(actionZoom);

        retranslateUi(Curve);

        QMetaObject::connectSlotsByName(Curve);
    } // setupUi

    void retranslateUi(QMainWindow *Curve)
    {
        Curve->setWindowTitle(QApplication::translate("Curve", "MainWindow", Q_NULLPTR));
        actionPause->setText(QApplication::translate("Curve", "\346\232\202\345\201\234", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("Curve", "\346\232\202\345\201\234\347\273\230\345\233\276/\347\273\247\347\273\255\347\273\230\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionZoom->setText(QApplication::translate("Curve", "\351\200\211\346\213\251\346\224\276\345\244\247", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionZoom->setToolTip(QApplication::translate("Curve", "\351\200\211\346\241\206\346\224\276\345\244\247/\351\274\240\346\240\207\346\213\226\345\212\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("Curve", "\346\270\205\347\251\272\346\225\260\346\215\256", Q_NULLPTR));
        actionSaveImg->setText(QApplication::translate("Curve", "\344\277\235\345\255\230\346\233\262\347\272\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveImg->setToolTip(QApplication::translate("Curve", "\344\277\235\345\255\230\346\233\262\347\272\277\345\233\276\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("Curve", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Curve: public Ui_Curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVE_H
