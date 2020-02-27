#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include "QMessageBox"
#include "QDebug"
#include "QTimer"
#include "QShortcut"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QByteArray rxBuf;
    void initComboBox_Config();
    void configPort();
    bool  checkCRC(QByteArray &buffer);
    qint32 readSpd(QByteArray &buffer);
    void appendCRC(QByteArray &buffer);




public slots:
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_serialRxCallback();
    void slots_timeoutGetSpeed();

private slots:
    void on_btnRefresh_clicked();
    void on_btnOpenPort_clicked(bool checked);


    void on_btnStartStop_clicked();

    void on_btnReset_clicked();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnPosKp_clicked();

    void on_btnAlignment_clicked();

    void on_btnPosKi_clicked();

    void on_btnPosKd_clicked();

    void on_btnRamp_clicked();

private:
    Ui::MainWindow *ui;
    BaseSerialComm *currentPort;   // 端口号
    QTimer *tim;


};

#endif // MAINWINDOW_H
