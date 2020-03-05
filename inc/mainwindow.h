#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include "QMessageBox"
#include "QDebug"
#include "QTimer"
#include "QShortcut"
#include "QMetaEnum"
#include "QTime"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    enum MC_Protocol_REG_t
    {
        REG_TARGET_MOTOR,          /* 0   */
        REG_FLAGS,                 /* 1   */
        REG_STATUS,                /* 2   */
        REG_CONTROL_MODE,          /* 3   */
        REG_SPEED_REF,             /* 4   */
        REG_SPEED_KP,              /* 5   */
        REG_SPEED_KI,              /* 6   */
        REG_SPEED_KD,              /* 7   */
        REG_TORQUE_REF,            /* 8   */
        REG_TORQUE_KP,             /* 9   */
        REG_TORQUE_KI,             /* 10  */
        REG_TORQUE_KD,             /* 11  */
        REG_FLUX_REF,              /* 12  */
        REG_FLUX_KP,               /* 13  */
        REG_FLUX_KI,               /* 14  */
        REG_FLUX_KD,               /* 15  */
        REG_OBSERVER_C1,           /* 16  */
        REG_OBSERVER_C2,           /* 17  */
        REG_OBSERVER_CR_C1,        /* 18  */
        REG_OBSERVER_CR_C2,        /* 19  */
        REG_PLL_KI,                /* 20  */
        REG_PLL_KP,                /* 21  */
        REG_FLUXWK_KP,             /* 22  */
        REG_FLUXWK_KI,             /* 23  */
        REG_FLUXWK_BUS,            /* 24  */
        REG_BUS_VOLTAGE,           /* 25  */
        REG_HEATS_TEMP,            /* 26  */
        REG_MOTOR_POWER,           /* 27  */
        REG_DAC_OUT1,              /* 28  */
        REG_DAC_OUT2,              /* 29  */
        REG_SPEED_MEAS,            /* 30  */
        REG_TORQUE_MEAS,           /* 31  */
        REG_FLUX_MEAS,             /* 32  */
        REG_FLUXWK_BUS_MEAS,       /* 33  */
        REG_RUC_STAGE_NBR,         /* 34  */
        REG_I_A,                   /* 35  */
        REG_I_B,                   /* 36  */
        REG_I_ALPHA,               /* 37  */
        REG_I_BETA,                /* 38  */
        REG_I_Q,                   /* 39  */
        REG_I_D,                   /* 40  */
        REG_I_Q_REF,               /* 41  */
        REG_I_D_REF,               /* 42  */
        REG_V_Q,                   /* 43  */
        REG_V_D,                   /* 44  */
        REG_V_ALPHA,               /* 45  */
        REG_V_BETA,                /* 46  */
        REG_MEAS_EL_ANGLE,         /* 47  */
        REG_MEAS_ROT_SPEED,        /* 48  */
        REG_OBS_EL_ANGLE,          /* 49  */
        REG_OBS_ROT_SPEED,         /* 50  */
        REG_OBS_I_ALPHA,           /* 51  */
        REG_OBS_I_BETA,            /* 52  */
        REG_OBS_BEMF_ALPHA,        /* 53  */
        REG_OBS_BEMF_BETA,         /* 54  */
        REG_OBS_CR_EL_ANGLE,       /* 55  */
        REG_OBS_CR_ROT_SPEED,      /* 56  */
        REG_OBS_CR_I_ALPHA,        /* 57  */
        REG_OBS_CR_I_BETA,         /* 58  */
        REG_OBS_CR_BEMF_ALPHA,     /* 59  */
        REG_OBS_CR_BEMF_BETA,      /* 60  */
        REG_DAC_USER1,             /* 61  */
        REG_DAC_USER2,             /* 62  */
        REG_MAX_APP_SPEED,         /* 63  */
        REG_MIN_APP_SPEED,         /* 64  */
        REG_IQ_SPEEDMODE,          /* 65  */
        REG_EST_BEMF_LEVEL,        /* 66  */
        REG_OBS_BEMF_LEVEL,        /* 67  */
        REG_EST_CR_BEMF_LEVEL,     /* 68  */
        REG_OBS_CR_BEMF_LEVEL,     /* 69  */
        REG_FF_1Q,                 /* 70  */
        REG_FF_1D,                 /* 71  */
        REG_FF_2,                  /* 72  */
        REG_FF_VQ,                 /* 73  */
        REG_FF_VD,                 /* 74  */
        REG_FF_VQ_PIOUT,           /* 75  */
        REG_FF_VD_PIOUT,           /* 76  */
        REG_PFC_STATUS,            /* 77  */
        REG_PFC_FAULTS,            /* 78  */
        REG_PFC_DCBUS_REF,         /* 79  */
        REG_PFC_DCBUS_MEAS,        /* 80  */
        REG_PFC_ACBUS_FREQ,        /* 81  */
        REG_PFC_ACBUS_RMS,         /* 82  */
        REG_PFC_I_KP,              /* 83  */
        REG_PFC_I_KI,              /* 84  */
        REG_PFC_I_KD,              /* 85  */
        REG_PFC_V_KP,              /* 86  */
        REG_PFC_V_KI,              /* 87  */
        REG_PFC_V_KD,              /* 88  */
        REG_PFC_STARTUP_DURATION,  /* 89  */
        REG_PFC_ENABLED,           /* 90  */
        REG_RAMP_FINAL_SPEED,      /* 91  */
        REG_RAMP_DURATION,         /* 92  */
        REG_HFI_EL_ANGLE,          /* 93  */
        REG_HFI_ROT_SPEED,         /* 94  */
        REG_HFI_CURRENT,           /* 95  */
        REG_HFI_INIT_ANG_PLL,      /* 96  */
        REG_HFI_INIT_ANG_SAT_DIFF, /* 97  */
        REG_HFI_PI_PLL_KP,         /* 98  */
        REG_HFI_PI_PLL_KI,         /* 99  */
        REG_HFI_PI_TRACK_KP,       /* 100 */
        REG_HFI_PI_TRACK_KI,       /* 101 */
        REG_SC_CHECK,              /* 102 */
        REG_SC_STATE,              /* 103 */
        REG_SC_RS,                 /* 104 */
        REG_SC_LS,                 /* 105 */
        REG_SC_KE,                 /* 106 */
        REG_SC_VBUS,               /* 107 */
        REG_SC_MEAS_NOMINALSPEED,  /* 108 */
        REG_SC_STEPS,              /* 109 */
        REG_SPEED_KP_DIV,          /* 110 */
        REG_SPEED_KI_DIV,          /* 111 */
        REG_UID,                   /* 112 */
        REG_HWTYPE,                /* 113 */
        REG_CTRBDID,               /* 114 */
        REG_PWBDID,                /* 115 */
        REG_SC_PP,                 /* 116 */
        REG_SC_CURRENT,            /* 117 */
        REG_SC_SPDBANDWIDTH,       /* 118 */
        REG_SC_LDLQRATIO,          /* 119 */
        REG_SC_NOMINAL_SPEED,      /* 120 */
        REG_SC_CURRBANDWIDTH,      /* 121 */
        REG_SC_J,                  /* 122 */
        REG_SC_F,                  /* 123 */
        REG_SC_MAX_CURRENT,        /* 124 */
        REG_SC_STARTUP_SPEED,      /* 125 */
        REG_SC_STARTUP_ACC,        /* 126 */
        REG_SC_PWM_FREQUENCY,      /* 127 */
        REG_SC_FOC_REP_RATE,       /* 128 */
        REG_PWBDID2,               /* 129 */
        REG_SC_COMPLETED,          /* 130 */
        REG_CURRENT_POSITION,      /* 131 */
        REG_TARGET_POSITION,       /* 132 */
        REG_MOVE_DURATION,         /* 133 */
        REG_POSITION_KP,           /* 134 */
        REG_POSITION_KI,           /* 135 */
        REG_POSITION_KD,           /* 136 */
        REG_UNDEFINED
    };

    Q_ENUM(MC_Protocol_REG_t);


    void initComboBox_Config();
    void configPort();
    bool  checkCRC(QByteArray &buffer);
    qint32 readSpd(QByteArray &buffer);
    void appendCRC(QByteArray &buffer);
    void listRegAddress(QComboBox *cbbREGAddress);
    float readPos(QByteArray &buffer);
    void motorProtocolTx(QByteArray &buffer);
    void delayMSec(int msec);
    void insertLog(QString &msg);
    void sendCMD(QString &cmd, QString log);
    void limitLineEdit();


public slots:
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_serialRxCallback();
    void slots_timeoutTx();
    void slots_timeoutRx();

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

    void on_btnOtherCMD_clicked();

    void on_cbbFrameID_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    BaseSerialComm *currentPort;   // 端口号
    QTimer *txTim;
    QTimer *rxTim;
};

#endif // MAINWINDOW_H
