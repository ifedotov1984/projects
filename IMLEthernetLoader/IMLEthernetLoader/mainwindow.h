#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QIODevice>
#include <QtEndian>
#include <QString>
#include <QTimer>
#include <QProgressBar>
#include <QStyleFactory>
#include "tftp.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QHttpMultiPart>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QTextCodec>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QUdpSocket *udpSocketClient;
    QTimer  *messageTimer;
    QTimer  *putTimer;
    QFile *sFile;
    QString IMLFileName;
    QNetworkReply* httpreply;
    QNetworkAccessManager *networkManager;
    QTimer  *webTimer;

    void sendDataAckMsg(struct TFTPData *pData, QHostAddress sender, quint16 senderPort);
    void sendWriteReqMsg(QString pFilename);
    void sendDataMsg(short blockno, QHostAddress sender, quint16 senderPort);
    void StartTFTPPut();
    void StartHTTPPut();
    bool CheckFormBusy();
    char recvData[RECV_BUFFER_SIZE];


private slots:
    void readPendingDatagrams();
    void on_IMLOpenButton_clicked();
    void on_IMLWriteButton_clicked();
    void on_BINOpenButton_clicked();
    void on_BINWriteButton_clicked();
    void messageTimerTimeout();
    void putTimerTimeout();
    void onGetReplyHTTPUpload();
    void onGetErrorHTTPUpload(QNetworkReply::NetworkError code);
    void onUploadProgressHTTPUpload(qint64 bytesWrite, qint64 bytesTotal);
    void webTimerTimeout();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
