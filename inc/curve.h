#ifndef CURVE_H
#define CURVE_H

#include <QMainWindow>
#include <QFileDialog>
namespace Ui {
class Curve;
}

class Curve : public QMainWindow
{
    Q_OBJECT

public:
    explicit Curve(QWidget *parent = 0);
    ~Curve();

    quint32 spdCoorX = 0;
    quint32 posCoorX = 0;
    quint32 indexOfSpd = 0;
    quint32 indexOfPos = 0;

    void initCurve();
    void addSpeedGraph();
    void addPosGraph();
    void resetSpdAxisRange(quint32 xValue, qint32 yValue);
    void resetPosAxisRange(float yValue);
    QFileDialog *initSaveFileDialog();



private slots:
    void slots_updateSpeedGraph(qint32 spd);

    void slots_updatePositionGraph(float pos);

    void on_actionClear_triggered();

    void on_actionZoom_triggered(bool checked);

    void on_actionSaveImg_triggered();

private:
    Ui::Curve *ui;
};

#endif // CURVE_H
