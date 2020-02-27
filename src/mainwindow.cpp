#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler( QSerialPort::SerialPortError)));
    this->initComboBox_Config();
    tim = new QTimer();
    connect(tim,SIGNAL(timeout()),this, SLOT(slots_timeoutGetSpeed()) );
    tim->start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*   初始化了串口设置当中的下拉列表(ComboBox) */
void MainWindow::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/* 刷新按钮点击 槽函数 */
void MainWindow::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* 打开串口 槽函数*/
void MainWindow::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
            this->configPort();

            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 有数据就直接接收显示
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void MainWindow::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}

/* 串口错误信息处理 */
void MainWindow::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}
void MainWindow::slots_serialRxCallback()
{
    rxBuf.append(currentPort->readAll());
}
/**
 * @brief MainWindow::on_btnReset_clicked 控制板复位
 */
void MainWindow::on_btnReset_clicked()
{
    QString tmp = "23 01 04";
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->appendCRC(txBuf);
    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForBytesWritten();
//    tim->setInterval(3000);
    ui->spbSpeed->setValue(0);
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}
/**
 * @brief MainWindow::on_btnStart_clicked 启动电机转动
 */
void MainWindow::on_btnStart_clicked()
{
    QString tmp = "23 01 01";
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->appendCRC(txBuf);
    currentPort->write(txBuf,txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}
/**
 * @brief MainWindow::on_btnStop_clicked  停止电机转动
 */
void MainWindow::on_btnStop_clicked()
{
    QString tmp = "23 01 02";
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->appendCRC(txBuf);
    currentPort->write(txBuf,txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}

/**
 * @brief MainWindow::on_btnStartStop_clicked 启动/停止电机转动
 */
void MainWindow::on_btnStartStop_clicked()
{
    QString tmp = "23 01 06";
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->appendCRC(txBuf);
    currentPort->write(txBuf,txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}
/**
 * @brief MainWindow::on_btnAlignment_clicked 编码器模式校准对齐
 */
void MainWindow::on_btnAlignment_clicked()
{
    QString tmp = "23 01 08";
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    this->appendCRC(txBuf);
    currentPort->write(txBuf,txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}

/**
 * @brief MainWindow::on_btnPosKp_clicked  设置位置环的Kp
 */
void MainWindow::on_btnPosKp_clicked()
{
    QString tmp = "21 03 86"; // 写寄存器 ，位置环Kp
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    quint16 positionPID = ui->spbPosKp->value();

    txBuf.append( (quint8)(positionPID & 0x00FF) );
    txBuf.append( (quint8)(positionPID >>8 ) );

    this->appendCRC(txBuf);

    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}
/**
 * @brief MainWindow::on_btnPosKi_clicked  设置位置环Ki
 */
void MainWindow::on_btnPosKi_clicked()
{
    QString tmp = "21 03 87"; // 写寄存器 ，位置环Ki
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    quint16 positionPID = ui->spbPosKi->value();

    txBuf.append( (quint8)(positionPID & 0x00FF) );
    txBuf.append( (quint8)(positionPID >>8 ) );

    this->appendCRC(txBuf);

    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}

/**
 * @brief MainWindow::on_btnPosKd_clicked  设置位置环Kd
 */
void MainWindow::on_btnPosKd_clicked()
{
    QString tmp = "21 03 88"; // 写寄存器 ，位置环Kd
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    quint16 positionPID = ui->spbPosKd->value();

    txBuf.append( (quint8)(positionPID & 0x00FF) );
    txBuf.append( (quint8)(positionPID >>8 ) );

    this->appendCRC(txBuf);

    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());
}

/**
 * @brief MainWindow::on_btnRamp_clicked  Ramp指令
 */
void MainWindow::on_btnRamp_clicked()
{
    union FloatToU32{
        quint8 U8[4];
        float   Float;
    }data;

    QString tmp = "32 08 "; // 写寄存器 ，位置环Kd
    QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
    quint32 posTarget = ui->spbPosTarget->value();
    quint32 posTime = ui->spbPosTime->value();

    data.Float= (float)posTarget;
    txBuf.append( (const char *)&data.U8, 4 );

    data.Float= (float)posTime;
    txBuf.append( (const char *)&data.U8, 4 );

    this->appendCRC(txBuf);
    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForBytesWritten();
    ui->statusBar->showMessage(txBuf.toHex(' ').toUpper());

}


/**
 * @brief MainWindow::slots_timeoutGetSpeed 超时读取速度值
 */
void MainWindow::slots_timeoutGetSpeed()
{
    if(ui->btnOpenPort->isChecked()){
        QString tmp = "22 01 1E 21";
        QByteArray txBuf = QByteArray::fromHex(tmp.toLocal8Bit());
        rxBuf.clear();
        currentPort->write(txBuf, txBuf.size());
        if(currentPort->waitForBytesWritten(100)){
            currentPort->waitForReadyRead(100);
            rxBuf.append(currentPort->readAll());
            if(checkCRC(rxBuf)){
                qint32 spd = readSpd(rxBuf);
                ui->spbSpeed->setValue(spd);
            }
            rxBuf.clear();
        }else
            qDebug()<< "read Speed Timeout";
    }
}

/**
 * @brief MainWindow::checkCRC 计算验证CRC码
 * @param buffer 接收缓存
 * @return 正确与否
 */
bool MainWindow::checkCRC(QByteArray &buffer)
{
    if( buffer.size() != 7) return false ;
    qint32 size = buffer.size()-1;
    quint16 sum = 0;
    qint32 i = 0;
    quint16 crc = 0x00FF & buffer.at(size);
    while(size--){
        sum += (quint8)buffer.at(i++);
    }
    sum = ((sum & 0xFF00)>>8) + (sum & 0x00FF);
    if( crc == sum ){
        return true;
    }
    else return false;
}
/**
 * @brief MainWindow::readSpd 读取速度值
 * @param buffer 结束数据缓存
 * @return qint32 速度值
 */
qint32 MainWindow::readSpd(QByteArray &buffer)
{
    union tmp{
        quint8 tmpChar[4];
        qint32 tmpInt;
    }aa;
    if( buffer.size() != 7) return 0;
    aa.tmpChar[0] = buffer.at(2);
    aa.tmpChar[1] = buffer.at(3);
    aa.tmpChar[2] = buffer.at(4);
    aa.tmpChar[3] = buffer.at(5);
    qint32 spd = aa.tmpInt;
    return spd;
}
/**
 * @brief MainWindow::calcCRC  计算校验码
 * @param buffer 待校验数据
 * @return 校验码
 */
void MainWindow::appendCRC(QByteArray &buffer)
{
    qint32 size = buffer.size();
    quint16 sum = 0;
    qint32 i = 0;
    while(size--){
        sum += (quint8)buffer.at(i++);
    }
    sum = ((sum & 0xFF00)>>8) + (sum & 0x00FF);
    quint8 crc = (quint8)sum;
    buffer.append(crc);
}


