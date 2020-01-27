#ifndef COMTHREAD_H
#define COMTHREAD_H


#include <QSerialPort>
#include <QSerialPortInfo>
#include <QQueue>
#include <QString>
#include <QByteArray>
#include <QThread>
#include <QSemaphore>
#include <QMutex>
#include <QQueue>


#define Function_Read                 (0x10)
#define Function_Write                (0x20)


#define TrmtStatus_SendWithRxTimeout  (2)
#define TrmtStatus_Send               (1)
#define TrmtStatus_Unknown            (0)
#define TrmtStatus_Exit               (-1)
#define TrmtStatus_ExitSilent         (-2)
#define TrmtStatus_SetRxTimeout       (-3)

#define TrmtStatus_EventRxTimeout     (-4)
#define TrmtStatus_EventAnswerError   (-5)
#define TrmtStatus_EventSuccess       (3)



#define ComStatus_Opened              (0)
#define ComStatus_Closed              (-1)
#define ComStatus_Error               (-2)



#define COMPORT_BAUDRATE               (57600)


QT_BEGIN_NAMESPACE

struct portFrame
{
    uint8_t ComAddress;
    uint8_t Function;
    uint8_t length;
    QByteArray data;
    int TransmitStatus;
    int rx_timeout;
};

class QueueThread
{

private:
    QMutex mutex;
    QQueue<portFrame> QueueTx;
    QQueue<portFrame> QueueRx;
    QQueue<portFrame> QueueCfg;

public:
    void ClerQueueTxFrame();
    void ClerQueueRxFrame();
    void ClerQueueCfgFrame();
    void EnqueueTxFrame(portFrame frame);
    portFrame DequeueTxFrame();
    void EnqueueRxFrame(portFrame frame);
    portFrame DequeueRxFrame();
    void EnqueueCfgFrame(portFrame frame);
    portFrame DequeueCfgFrame();
    QSemaphore semDataTx;

};

class ComPortTransmit : public QObject
{
    Q_OBJECT

public:
    ComPortTransmit();
    ~ComPortTransmit();

    void PortChangeRxTimeoutRequest(int tm);
    void PortTransmitOpen(QString port);
    void PortCloseRequest(bool silent);
    bool ComPortIsOpened;
    QueueThread queue;

private:
    QThread* thread;
    void PortOpen(QString port);


private slots:
    void deleteThread();
    void on_ComPortStatusChanged(int);

};

class ComPortWorker : public QObject
{
    Q_OBJECT
public:
    ComPortWorker(QString port,  QueueThread *pqueue);
    ~ComPortWorker();
    //int PrepearMessageToSend(SpFrame *frame, QByteArray data);



private:
    QSerialPort *sp;
    QueueThread *queue;
    uint8_t CRC8Count(QByteArray sdata, int length);
 //   bool GetResponse(SpFrame *resp);
    int RxTimeoutValue;
    int _preRxTimeoutValue;
    QString ComPortName;

private slots:
    void process();

signals:
    void finished();
    void status(int);
    void threadDel();

};


QT_END_NAMESPACE




#endif // COMTHREAD_H
