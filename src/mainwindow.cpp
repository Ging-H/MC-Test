#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleFactory>
#include <QDebug>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

#define FACTOR_RAD_ROUND  6.283185f// 弧度 单位转换成转数单位

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler( QSerialPort::SerialPortError)));
    this->initComboBox_Config();
    txTim = new QTimer();
//    connect(txTim,SIGNAL(timeout()),this, SLOT(slots_timeoutTx()) );
    QApplication::setStyle(QStyleFactory::create("Fusion"));//Qt自带皮肤风格 可选 Windows,WindowsXP,WindowsVista,Fusion
    this->limitLineEdit();
    listOrder << order0;
    this->setWindowTitle("ing10-MCTest");

    multiCheckBox.push_back(ui->ckbFOCD);
    multiCheckBox.push_back(ui->ckbOverV);
    multiCheckBox.push_back(ui->ckbUnderV);
    multiCheckBox.push_back(ui->ckbOverH);
    multiCheckBox.push_back(ui->ckbSU);
    multiCheckBox.push_back(ui->ckbSFB);
    multiCheckBox.push_back(ui->ckbOverC);
    multiCheckBox.push_back(ui->ckbSW);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::initComboBox_Config 初始化combobox的下拉列表
 */
void MainWindow::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    this->listRegAddress(ui->cbbRegAddr);
    ui->cbbRegAddr->setMaxVisibleItems(20); //设置显示的行数为20
}

/**
 * @brief MainWindow::listRegAddress 在comboBox下拉列表列出寄存器地址
 * @param cbbREGAddress
 */
void MainWindow::listRegAddress(QComboBox *cbbREGAddress)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<MainWindow::MC_Protocol_REG_t>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        cbbREGAddress->addItem(mtaEnum.key(i), mtaEnum.value(i));
    }
}

/**
 * @brief MainWindow::on_btnRefresh_clicked 刷新端口号
 */
void MainWindow::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}


/**
 * @brief MainWindow::on_btnOpenPort_clicked 打开串口
 * @param checked 按钮状态
 */
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
//            txTim->start(150);    // 启动定时器
            txTim->singleShot(50,this,SLOT(slots_timeoutTx()));
             ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        txTim->stop();    // 停止定时器
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/**
 * @brief MainWindow::configPort 配置串口参数
 */
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

/**
 * @brief MainWindow::slots_errorHandler 串口错误信息警告
 * @param error 错误信息类型
 */
void MainWindow::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("请检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("请检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}
/**
  * @brief MainWindow::limitLineEdit  限制只能输入十六进制字符
 */
void MainWindow::limitLineEdit()
{
    QRegExp regExp("[a-fA-F0-9 ]*");  // 匹配十六进制字符和空格
    QRegExpValidator *reg = new QRegExpValidator (regExp,this);
    ui->txtOtherCMD->setValidator(reg);      // 设定正则表达式
}
/**
 * @brief MainWindow::on_btnReset_clicked 控制板复位
 */
void MainWindow::on_btnReset_clicked()
{
    if(currentPort->isOpen())
        listOrder << order10;
}
/**
 * @brief MainWindow::on_btnStart_clicked 启动电机转动
 */
void MainWindow::on_btnStart_clicked()
{
    if(currentPort->isOpen())
        listOrder << order2;
}
/**
 * @brief MainWindow::on_btnStop_clicked  停止电机转动
 */
void MainWindow::on_btnStop_clicked()
{
    if(currentPort->isOpen())
        listOrder << order3;
}

/**
 * @brief MainWindow::on_btnStartStop_clicked 启动/停止电机转动
 */
void MainWindow::on_btnStartStop_clicked()
{
    if(currentPort->isOpen())
        listOrder << order4;
}
/**
 * @brief MainWindow::on_btnAlignment_clicked 编码器模式校准对齐
 */
void MainWindow::on_btnAlignment_clicked()
{
    if(currentPort->isOpen())
        listOrder << order5;
}

/**
 * @brief MainWindow::on_btnPosKp_clicked  设置位置环的Kp
 */
void MainWindow::on_btnPosKp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order6;
}
/**
 * @brief MainWindow::on_btnPosKi_clicked  设置位置环Ki
 */
void MainWindow::on_btnPosKi_clicked()
{
    if(currentPort->isOpen())
        listOrder << order7;
}

/**
 * @brief MainWindow::on_btnPosKd_clicked  设置位置环Kd
 */
void MainWindow::on_btnPosKd_clicked()
{
    if(currentPort->isOpen())
        listOrder << order8;
}

/**
 * @brief MainWindow::on_btnRamp_clicked  Ramp指令
 */
void MainWindow::on_btnRamp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order9;
}

/**
 * @brief MainWindow::on_btnFaultAck_clicked 应答错误
 */
void MainWindow::on_btnFaultAck_clicked()
{
    if(currentPort->isOpen())
        listOrder << order12;
}

/**
 * @brief MainWindow::on_btnSpdKp_clicked 发送速度环的Kp
 */
void MainWindow::on_btnSpdKp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order14;
}
/**
 * @brief MainWindow::on_btnSpdKi_clicked 发送速度环的Ki
 */
void MainWindow::on_btnSpdKi_clicked()
{
    if(currentPort->isOpen())
        listOrder << order15;
}
/**
 * @brief MainWindow::on_btnSpdRamp_clicked  执行速度Ramp
 */
void MainWindow::on_btnSpdRamp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order16;
}
/**
 * @brief MainWindow::on_btnStopRamp_clicked 停止Ramp
 */
void MainWindow::on_btnStopRamp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order17;
}
/**
 * @brief MainWindow::on_btnSpdTarget_clicked 发送速度目标值
 */
void MainWindow::on_btnSpdTarget_clicked()
{
    if(currentPort->isOpen())
        listOrder << order18;
}

/**
 * @brief MainWindow::on_btnCurrentRef_clicked  发送电流目标值，Iq，Id
 */
void MainWindow::on_btnCurrentRef_clicked()
{
    if(currentPort->isOpen())
        listOrder << order19;
}
/**
 * @brief MainWindow::on_btnIqKp_clicked 设置Iq Kp
 */
void MainWindow::on_btnIqKp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order20;
}

/**
 * @brief MainWindow::on_btnIqKi_clicked Iq Ki
 */
void MainWindow::on_btnIqKi_clicked()
{
    if(currentPort->isOpen())
        listOrder << order21;
}
/**
 * @brief MainWindow::on_btnIdKp_clicked Id Kp
 */
void MainWindow::on_btnIdKp_clicked()
{
    if(currentPort->isOpen())
        listOrder << order22;
}
/**
 * @brief MainWindow::on_btnIdKi_clicked  Id Ki
 */
void MainWindow::on_btnIdKi_clicked()
{
    if(currentPort->isOpen())
        listOrder << order23;
}
/**
 * @brief MainWindow::on_cbbCtrlMode_currentIndexChanged 改变控制模式
 * @param index 控制模式
 */
void MainWindow::on_cbbCtrlMode_currentIndexChanged(int index)
{
    index = index;
    if(currentPort->isOpen())
        listOrder << order26;
}

/**
 * @brief MainWindow::slots_timeoutTx 超时读取速度值
 */
void MainWindow::slots_timeoutTx()
{
    SendOrder currentOrder = listOrder.at(0);
    QString cmd ;
    QString log ;
    QByteArray rxBuf;

    if(currentPort->isOpen()){
        switch(currentOrder){
        case order0:{/* 读取当前速度 */
            cmd = "22 01 1E";
            log = "速度值" ;

            /* 读取当前速度 */
            rxBuf = this->sendCMD(cmd, log, false);
            if( !rxBuf.isEmpty()){
                qint32 spd = readSpd(rxBuf);
                ui->spbSpeed->setValue(spd);
            }
            listOrder<<order1;
            break;}

        case order1:{/* 读取当前位置 */
            cmd = "22 01 83";
            log = " 读取位置值 " ;
            rxBuf = this->sendCMD(cmd, log, false);

            if( !rxBuf.isEmpty()){
                float pos = readPos(rxBuf);
                ui->spbCurrentPos->setValue( pos/FACTOR_RAD_ROUND );
            }
            listOrder<<order11;
            break;}
        case order24:{/* 读取扭矩 Iq */
            cmd = "22 01 1F";
            log = " 读取Turque Iq " ;
            rxBuf = this->sendCMD(cmd, log, false);

            if( !rxBuf.isEmpty()){
                qint16 torque = readCurent(rxBuf);
                ui->spbTorque->setValue( torque );
            }
            listOrder<<order25;
            break;}
        case order25:{/* 读取Flux Id */
            cmd = "22 01 20";
            log = " 读取Flux Id " ;
            rxBuf = this->sendCMD(cmd, log, false);

            if( !rxBuf.isEmpty()){
                qint16 flux = readCurent(rxBuf);
                ui->spbFlux->setValue( flux );
            }
            listOrder<<order0;
            break;}
        case order2:{
            cmd = "23 01 01";
            log = "启动电机转动";
            this->sendCMD(cmd, log);
            break;}
        case order3:{
            cmd = "23 01 02";
            log = "停止电机转动";
            this->sendCMD(cmd, log);
            break;}
        case order4:{
            cmd = "23 01 06";
            log = "启动/停止电机转动";
            this->sendCMD(cmd, log);
            break;}
        case order5:{
            cmd = "23 01 08";
            log = "编码器模式校准对齐";
            this->sendCMD(cmd, log);
            break;}
        case order6:{
            // 写寄存器 ，位置环Kp
            cmd = "21 03 86 ";
            log = "设置位置环PID-Kp";
            quint16 positionPID = ui->spbPosKp->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(positionPID & 0x00FF));
            tmpByteArray.append((quint8)(positionPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order7:{// 写寄存器 ，位置环Ki
            cmd = "21 03 87 ";
            log = "设置位置环PID-Ki";
            quint16 positionPID = ui->spbPosKi->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(positionPID & 0x00FF));
            tmpByteArray.append((quint8)(positionPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order8:{
            // 写寄存器 ，位置环Kd
            cmd = "21 03 88 ";
            log = "设置位置环PID-Kd";
            quint16 positionPID = ui->spbPosKd->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(positionPID & 0x00FF));
            tmpByteArray.append((quint8)(positionPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order9:{
            union FloatToU32{
                quint8 U8[4];
                float   Float;
            }data;

            cmd = "32 08 "; // 写寄存器 ，位置环Kd
            QByteArray txBuf ;

            /* 目标转数  */
            data.Float = (float)ui->spbPosTarget->value() * FACTOR_RAD_ROUND;// 转数*6.28 -> 弧度
            txBuf.append( (const char *)&data.U8, 4 );

            /* 运动周期 单位是 s */
            float posDuration = ui->spbPosDuration->value();
            data.Float= (float)posDuration;
            txBuf.append( (const char *)&data.U8, 4 );

            QString log = "位置控制";
            if( posDuration < 0.01f){
                log = "Position following";
            }else{
                log = "Position movement";
            }
            cmd.append(txBuf.toHex(' ').toUpper());
            this->sendCMD(cmd, log);
            break;}
        case order10:{
            ui->spbSpeed->setValue(0); // reset Speed value
            cmd = "23 01 04";
            log = "目标控制板复位";
            this->sendCMD(cmd, log);
            break;}

        case order11:{ // 读错误状态
            cmd = "22 01 01";
            log = "错误状态" ;

            /* 读取Fault */
            rxBuf = this->sendCMD(cmd, log, false);
            if( !rxBuf.isEmpty()){
                quint16 faultNow;
                quint16 faultOver;
                quint32 fault = this->readFaultFlag(rxBuf);

                faultNow = fault>>16;
                faultOver = (quint16)fault;

                if(faultNow){
                    ui->ckbStatus->setCheckState(Qt::Checked);
                }else if(faultOver){
                    ui->ckbStatus->setCheckState(Qt::PartiallyChecked);
                }else ui->ckbStatus->setCheckState(Qt::Unchecked);

                foreach(QCheckBox* ckbFault,  multiCheckBox){
                    if( faultNow & 0x0001){ //
                        ckbFault->setCheckState(Qt::Checked);
                    }else if(faultOver & 0x0001) {
                        ckbFault->setCheckState(Qt::PartiallyChecked);
                    }else{
                        ckbFault->setCheckState(Qt::Unchecked);
                    }
                    faultNow  >>= 1;
                    faultOver >>= 1;
                }
            }
            listOrder<<order13;
            break;}
        case order12:{// 错误应答
            cmd = "23 01 07";
            log = "错误应答";
            this->sendCMD(cmd, log);
            break;}
        case order13:{// 读运行状态
            cmd = "22 01 02";
            log = "读取运行状态";

            /* 读取State */
            rxBuf = this->sendCMD(cmd, log, false);
            if( !rxBuf.isEmpty()){
                State_t state = (State_t)rxBuf.at(2);
                QMetaEnum mtaEnum = QMetaEnum::fromType<MainWindow::State_t>();
                ui->ckbStatus->setText(mtaEnum.key(state));
            }
            listOrder<<order24;
            break;}

        case order14:{
            // 写寄存器 ，位置环Kp
            cmd = "21 03 05 ";
            log = "设置速度环PID-Kp";
            quint16 speedPID = ui->spbSpdKp->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(speedPID & 0x00FF));
            tmpByteArray.append((quint8)(speedPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order15:{// 写寄存器 ，位置环Ki
            cmd = "21 03 06 ";
            log = "设置速度环PID-Ki";
            quint16 speedPID = ui->spbSpdKi->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(speedPID & 0x00FF));
            tmpByteArray.append((quint8)(speedPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order16:{// 速度Ramp
            cmd = "27 06 ";
            log = "速度Ramp";
            QByteArray txBuf ;

            /* 目标转数  */
            qint32 spd = (qint32)ui->spbSpdRampTarget->value();// 目标速度值
            txBuf.append( spd & 0xFF);
            txBuf.append((spd>>8)  & 0xFF);
            txBuf.append((spd>>16) & 0xFF);
            txBuf.append((spd>>24) & 0xFF);

            /* 运动周期 单位是 ms */
            qint16 spdDuration = (qint16)ui->spbSpdDuration->value();
            txBuf.append( spdDuration & 0xFF);
            txBuf.append( (spdDuration>>8) & 0xFF);

            cmd.append(txBuf.toHex(' ').toUpper());
            this->sendCMD(cmd, log);
            break;}

        case order17:{
            cmd = "23 01 03";
            log = "停止Ramp";
            this->sendCMD(cmd, log);
            break;}
        case order18:{
            // 速度目标值
            cmd = "21 05 5B ";
            log = "设置速度目标值";
            quint32 speedTarget = (quint32) ui->spbSpdTarget->value();

            QByteArray txBuf ;

            txBuf.append( speedTarget & 0xFF);
            txBuf.append((speedTarget>>8)  & 0xFF);
            txBuf.append((speedTarget>>16) & 0xFF);
            txBuf.append((speedTarget>>24) & 0xFF);

            cmd.append(txBuf.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order19:{
            // 电流目标值
            cmd = "2A 04 ";
            log = "设置电流目标值";

            QByteArray txBuf ;

            quint16 torqueIq = (quint32) ui->spbIqRef->value();
            txBuf.append( torqueIq & 0xFF);
            txBuf.append((torqueIq>>8)  & 0xFF);

            quint16 fluxId = (quint32) ui->spbIdRef->value();
            txBuf.append( fluxId & 0xFF);
            txBuf.append((fluxId>>8) & 0xFF);

            cmd.append(txBuf.toHex(' ').toUpper());
            this->sendCMD(cmd, log);
            break;}
        case order20:{
            cmd = "21 03 09 ";
            log = "设置扭矩 Iq Kp";
            quint16 IqPID = ui->spbIqKp->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(IqPID & 0x00FF));
            tmpByteArray.append((quint8)(IqPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order21:{
            cmd = "21 03 0A ";
            log = "设置扭矩 Iq Ki";
            quint16 IqPID = ui->spbIqKi->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(IqPID & 0x00FF));
            tmpByteArray.append((quint8)(IqPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order22:{
            cmd = "21 03 0D ";
            log = "设置Flux Id Kp";
            quint16 IdPID = ui->spbIdKp->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(IdPID & 0x00FF));
            tmpByteArray.append((quint8)(IdPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order23:{
            cmd = "21 03 0E ";
            log = "设置Flux Id Ki";
            quint16 IdPID = ui->spbIdKi->value();

            QByteArray tmpByteArray ;
            tmpByteArray.append((quint8)(IdPID & 0x00FF));
            tmpByteArray.append((quint8)(IdPID >>8 ));
            cmd.append(tmpByteArray.toHex(' ').toUpper());

            this->sendCMD(cmd, log);
            break;}
        case order26:
            if( ui->cbbCtrlMode->currentIndex() == 0){
                cmd = "21 02 03 01";
                log = "设置为速度模式";
            }
            else {
                cmd = "21 02 03 00";
                log = "设置为Torque模式";
            }
            this->sendCMD(cmd, log);
            break;

        default:break;
        }

        listOrder.removeFirst();
        if(listOrder.isEmpty()){
            listOrder << order0;
        }
        txTim->singleShot(150,this,SLOT(slots_timeoutTx()));
    }
}

void MainWindow::delayMSec(int msec)
{
  QTime dieTime = QTime::currentTime().addMSecs(msec);
  while( QTime::currentTime() < dieTime );
    QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
}
/**
 * @brief MainWindow::checkCRC 计算验证CRC码
 * @param buffer 接收缓存
 * @return 正确与否
 */
bool MainWindow::checkCRC(QByteArray &buffer)
{
    if(buffer.size()<3 )// 数据帧长度最小为3
        return false ;
    qint32 size = buffer.size()-1;
    quint16 sum = 0;
    quint16 crc = 0x00FF & buffer.at(size);
    foreach (quint8 cc, buffer){
        sum += cc;
    }
    sum -= crc;
    sum = ((sum & 0xFF00)>>8) + (sum & 0x00FF);
    if( crc == sum ){
        return true;
    }else return false;
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
 * @brief MainWindow::readSpd 读取当前位置值
 * @param buffer 接收数据缓存
 * @return float 位置值
 */
float MainWindow::readPos(QByteArray &buffer)
{
    union tmp{
        quint8 tmpChar[4];
        float tmpFloat;
    }aa;
    if( buffer.size() != 7) return 0;
    aa.tmpChar[0] = buffer.at(2);
    aa.tmpChar[1] = buffer.at(3);
    aa.tmpChar[2] = buffer.at(4);
    aa.tmpChar[3] = buffer.at(5);
    float pos = aa.tmpFloat;
    return pos;
}

/**
 * @brief MainWindow::readCurent 读取电流值
 * @param buffer  接收数据缓存
 * @return  电流值
 */
qint16 MainWindow::readCurent(QByteArray &buffer)
{
    qint16 current = 0;
    if( buffer.size() != 5) return 0;
    current = buffer.at(2) + (buffer.at(3)<<8);
    return current;
}
/**
 * @brief MainWindow::readSpd 读取当前位置值
 * @param buffer 接收数据缓存
 * @return float 错误状态
 */
quint32 MainWindow::readFaultFlag(QByteArray &buffer)
{
    if( buffer.size() != 7) return 0 ;
    quint32 fault = 0;
    fault = (quint8)buffer.at(2) + ((quint8)buffer.at(3)<<8) + ((quint8)buffer.at(4)<<16) + ((quint8)buffer.at(5)<<24);
    return fault;
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


/**
 * @brief MainWindow::on_btnOtherCMD_clicked 发送通用的指令
 */

void MainWindow::on_btnOtherCMD_clicked()
{
    quint8 motorNum = ui->cbbMotorNum->currentIndex();
    quint8 frameID  = ui->cbbFrameID->currentIndex();
    if(frameID == 0){
        ui->statusBar->showMessage("请选择明确的FrameID");
        return;
    }
    quint8 regAddress = ui->cbbRegAddr->currentIndex();
    quint8 cmd = ui->cbbCMD->currentIndex();

    /* 验证指令是否有效 */
    if(frameID <= 2){
        if(regAddress == 0) {
            ui->statusBar->showMessage("请选择明确的寄存器");
            return;
        }
    }else if(frameID == 3){
        if(cmd == 0) {
            ui->statusBar->showMessage("请选择明确的指令");
            return;
        }
    }

    QByteArray rxBuf;
    QString hex = ui->txtOtherCMD->text();
    hex.remove(QRegExp("\\s"));

    QByteArray txBuf = QByteArray::fromHex(hex.toLocal8Bit());

    switch( frameID ){
    /* 读写寄存器 */
    case 0x01:
    case 0x02:
        txBuf.prepend( regAddress );
        break;
    /* 发送指令 */
    case 0x03:
        txBuf.clear();
        txBuf.prepend( cmd );
        break;

    default:break;
    }
    txBuf.prepend( txBuf.size() ); // payload length
    txBuf.prepend( (motorNum<<5) | frameID );// start
    this->appendCRC(txBuf); // crc

    if(!currentPort->isOpen())return ; // 在发送之前再检查一次是否已经打开串口
    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForReadyRead(30);
//        rxBuf.append(currentPort->readAll());
    this->readProtocalFrame(rxBuf);
    ui->txtOtherRx->setText( rxBuf.toHex(' ').toUpper() );
    rxBuf.clear();
    ui->statusBar->showMessage(" Tx: " + txBuf.toHex(' ').toUpper() + " Rx:" + ui->txtOtherRx->text(),5000);
}
/**
 * @brief MainWindow::on_cbbFrameID_currentIndexChanged  FrameID
 * @param index  选择的项
 */
void MainWindow::on_cbbFrameID_currentIndexChanged(int index)
{
    switch(index){
    case 0x01:
    case 0x02:
        ui->cbbRegAddr->setEnabled(true);
        ui->cbbCMD->setEnabled(false);
        break;
    case 0x03:
        ui->cbbCMD->setEnabled(true);
        ui->cbbRegAddr->setEnabled(false);
        break;
    default:
        ui->cbbRegAddr->setEnabled(false);
        ui->cbbCMD->setEnabled(false);
        break;
    }
}
/**
 * @brief MainWindow::sendCMD 发送指令
 * @param cmd 指令字符串
 * @param log 成功响应之后显示的文本
 */
QByteArray MainWindow::sendCMD(QString cmd, QString log, bool isLog)
{
    QString tmp;
    QByteArray txBuf;
    QByteArray rxBuf;

    bool isCRCOk = false;

    txBuf = QByteArray::fromHex(cmd.toLocal8Bit());
    this->appendCRC(txBuf);
    if(!currentPort->isOpen())return rxBuf; // 在发送之前再检查一次是否已经打开串口
    currentPort->write(txBuf, txBuf.size());
    currentPort->waitForReadyRead(30);
//    delayMSec(30);
//    if(!currentPort->isOpen())return rxBuf; // 在发送之前再检查一次是否已经打开串口
//    rxBuf = currentPort->readAll(); // read all bytes form contorl board;
    this->readProtocalFrame(rxBuf);

    isCRCOk = this->checkCRC(rxBuf);
    QByteArray retArray = rxBuf;
    if(!isCRCOk){
        retArray.clear();
        log = "从机无响应或校验码错误";
    }
    if(isLog){
        tmp = "\t\tTx: ";
        log += txBuf.toHex(' ').toUpper().prepend( tmp.toLocal8Bit() );
        log += rxBuf.toHex(' ').toUpper().prepend("\tRx: ");
        this->insertLog( log );
    }
    rxBuf.clear();
    return retArray ;
}
/**
 * @brief MainWindow::insertLog 插入Log信息
 * @param msg 文本
 */
void MainWindow::insertLog(QString &msg)
{
    QTime current_time = QTime::currentTime();
    ui->lstLog->addItem(current_time.toString("[hh:mm:ss.zzz] -> ") + msg);
    ui->lstLog->setCurrentRow(ui->lstLog->count() - 1);
}

void MainWindow::on_actionAbout_triggered()
{
    QString path = QDir::currentPath();
    path += "/helpFile.pdf"; // 当前路径下的.pdf文档
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
/**
 * @brief MainWindow::readProtocalFrame 读取一帧数据
 * @return 数据缓存
 */
void MainWindow::readProtocalFrame(QByteArray &rxBuf)
{
    int  bufferSize = 0;
    int  payloadLength = 0;

    QTime dieTime = QTime::currentTime().addMSecs(50); // 50ms
    while(1){
        rxBuf.append(currentPort->readAll());
        bufferSize = rxBuf.size();
        if( bufferSize >= 2 ){
            payloadLength = rxBuf.at(1)+3;
        }
        if(bufferSize != 0){
            if(bufferSize >= payloadLength){

                break;
            }
        }else{// 50ms 内缓存长度为0，就直接返回
            if(QTime::currentTime() > dieTime){
                break;
            }
        }
    }
}

