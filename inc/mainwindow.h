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

/** @name Fault source error codes */
/** @{ */
#define  MC_NO_ERROR     (uint16_t)(0x0000u)    /**< @brief No error.*/
#define  MC_NO_FAULTS    (uint16_t)(0x0000u)    /**< @brief No error.*/
#define  MC_FOC_DURATION (uint16_t)(0x0001u)    /**< @brief Error: FOC rate to high.*/
#define  MC_OVER_VOLT    (uint16_t)(0x0002u)    /**< @brief Error: Software over voltage.*/
#define  MC_UNDER_VOLT   (uint16_t)(0x0004u)    /**< @brief Error: Software under voltage.*/
#define  MC_OVER_TEMP    (uint16_t)(0x0008u)    /**< @brief Error: Software over temperature.*/
#define  MC_START_UP     (uint16_t)(0x0010u)    /**< @brief Error: Startup failed.*/
#define  MC_SPEED_FDBK   (uint16_t)(0x0020u)    /**< @brief Error: Speed feedback.*/
#define  MC_BREAK_IN     (uint16_t)(0x0040u)    /**< @brief Error: Emergency input (Over current).*/
#define  MC_SW_ERROR     (uint16_t)(0x0080u)    /**< @brief Software Error.*/
/** @} */

#define INTERVALTIME  50
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


    enum SendOrder{
        order0,  // 读取速度
        order1,  // 读取位置
        order2,
        order3,
        order4,
        order5,
        order6,
        order7,
        order8,
        order9,
        order10,
        order11,
        order12,
        order13,
        order14,
        order15,
        order16,
        order17,
        order18,
        order19,
        order20,
        order21,
        order22,
        order23,
        order24,
        order25,
        order26,
    };
    Q_ENUM(SendOrder);

    enum State_t
    {
        IDLE = 0,             /*!< Persistent state, following state can be IDLE_START
                               if a start motor command has been given or
                               IDLE_ALIGNMENT if a start alignment command has been
                               given */
        IDLE_ALIGNMENT = 1,   /*!< "Pass-through" state containg the code to be executed
                               only once after encoder alignment command.
                               Next states can be ALIGN_CHARGE_BOOT_CAP or
                               ALIGN_OFFSET_CALIB according the configuration. It
                               can also be ANY_STOP if a stop motor command has been
                               given. */

        ALIGNMENT = 2,        /*!< Persistent state in which the encoder are properly
                               aligned to set mechanical angle, following state can
                               only be ANY_STOP */
        IDLE_START = 3,       /*!< "Pass-through" state containg the code to be executed
                               only once after start motor command.
                               Next states can be CHARGE_BOOT_CAP or OFFSET_CALIB
                               according the configuration. It can also be ANY_STOP
                               if a stop motor command has been given. */

        START = 4,            /*!< Persistent state where the motor start-up is intended
                               to be executed. The following state is normally
                               SWITCH_OVER or RUN as soon as first validated speed is
                               detected. Another possible following state is
                               ANY_STOP if a stop motor command has been executed */

        START_RUN = 5,        /*!< "Pass-through" state, the code to be executed only
                               once between START and RUN states itâ€™s intended to be
                               here executed. Following state is normally  RUN but
                               it can also be ANY_STOP  if a stop motor command has
                               been given */
        RUN = 6,              /*!< Persistent state with running motor. The following
                               state is normally ANY_STOP when a stop motor command
                               has been executed */
        ANY_STOP = 7,         /*!< "Pass-through" state, the code to be executed only
                               once between any state and STOP itâ€™s intended to be
                               here executed. Following state is normally STOP */
        STOP = 8,             /*!< Persistent state. Following state is normally
                               STOP_IDLE as soon as conditions for moving state
                               machine are detected */
        STOP_IDLE = 9,        /*!< "Pass-through" state, the code to be executed only
                               once between STOP and IDLE itâ€™s intended to be here
                               executed. Following state is normally IDLE */
        FAULT_NOW = 10,       /*!< Persistent state, the state machine can be moved from
                               any condition directly to this state by
                               STM_FaultProcessing method. This method also manage
                               the passage to the only allowed following state that
                               is FAULT_OVER */
        FAULT_OVER = 11,       /*!< Persistent state where the application is intended to
                              stay when the fault conditions disappeared. Following
                              state is normally STOP_IDLE, state machine is moved as
                              soon as the user has acknowledged the fault condition.
                          */
        ICLWAIT = 12,         /*!< Persistent state, the system is waiting for ICL
                                 deactivation. Is not possible to run the motor if
                                 ICL is active. Until the ICL is active the state is
                                 forced to ICLWAIT, when ICL become inactive the state
                                 is moved to IDLE */
        ALIGN_CHARGE_BOOT_CAP = 13,/*!< Persistent state where the gate driver boot
                               capacitors will be charged. Next states will be
                               ALIGN_OFFSET_CALIB. It can also be ANY_STOP if a stop
                               motor command has been given. */
        ALIGN_OFFSET_CALIB = 14,/*!< Persistent state where the offset of motor currents
                               measurements will be calibrated. Next state will be
                               ALIGN_CLEAR. It can also be ANY_STOP if a stop motor
                               command has been given. */
        ALIGN_CLEAR = 15,     /*!< "Pass-through" state in which object is cleared and
                               set for the startup.
                               Next state will be ALIGNMENT. It can also be ANY_STOP
                               if a stop motor command has been given. */
        CHARGE_BOOT_CAP = 16, /*!< Persistent state where the gate driver boot
                               capacitors will be charged. Next states will be
                               OFFSET_CALIB. It can also be ANY_STOP if a stop motor
                               command has been given. */
        OFFSET_CALIB = 17,    /*!< Persistent state where the offset of motor currents
                               measurements will be calibrated. Next state will be
                               CLEAR. It can also be ANY_STOP if a stop motor
                               command has been given. */
        CLEAR = 18,           /*!< "Pass-through" state in which object is cleared and
                               set for the startup.
                               Next state will be START. It can also be ANY_STOP if
                               a stop motor command has been given. */
        SWITCH_OVER = 19,     /**< TBD */
        WAIT_STOP_MOTOR = 20

    };
    Q_ENUM(State_t);

    QList<SendOrder> listOrder;
    quint8 style = 0;

    quint8 loadStyle();

    void initComboBox_Config();
    void configPort();
    void limitLineEdit();
    void listRegAddress(QComboBox *cbbREGAddress);

    bool  checkCRC(QByteArray &buffer);
    void appendCRC(QByteArray &buffer);

    qint32 readSpd(QByteArray &buffer);
    float readPos(QByteArray &buffer);

    void delayMSec(int msec);
    void insertLog(QString &msg);
    QByteArray sendCMD(QString cmd, QString log, bool isLog = true);
    void readProtocalFrame(QByteArray &rxBuf);
    quint32 readFaultFlag(QByteArray &buffer);
    qint16 readCurent(QByteArray &buffer);

signals:
    void signals_updateSpeedGraph(qint32 spd);
    void signals_updatePositionGraph(float pos);

public slots:
    void slots_errorHandler(QSerialPort::SerialPortError error);
//    void slots_serialRxCallback();
    void slots_timeoutTx();

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

    void on_actionAbout_triggered();

    void on_btnFaultAck_clicked();

    void on_btnSpdKp_clicked();

    void on_btnSpdKi_clicked();

    void on_btnSpdRamp_clicked();

    void on_btnStopRamp_clicked();

    void on_btnSpdTarget_clicked();

    void on_btnCurrentRef_clicked();

    void on_btnIqKp_clicked();

    void on_btnIqKi_clicked();

    void on_btnIdKp_clicked();

    void on_btnIdKi_clicked();

    void on_cbbCtrlMode_currentIndexChanged(int index);

    void on_actionCurve_triggered();

    void on_actionbalck_triggered();

    void on_actionorigenral_triggered();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    BaseSerialComm *currentPort;   // 端口号
    QTimer *txTim;
    QVector<QCheckBox*> multiCheckBox;
};

#endif // MAINWINDOW_H
