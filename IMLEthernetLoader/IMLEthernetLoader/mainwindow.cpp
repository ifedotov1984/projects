#include "mainwindow.h"
#include "ui_mainwindow.h"

int finished_flag = -10;
int send_data_bytes = 0;

QHostAddress IMLtftpServer;
int IMLserverPort = 0;
int IMLFile_Size = 0;
QString IMLFilePath = "";
short IMLwrq_block_no = 0;
int IMLputTimerCnt = 0;

QString FileDIR = QDir::homePath();
int BINFile_Size = 0;

int SendTotalTime=0;

QTextCodec* defaultTextCodec;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Init udpSocketClient
    udpSocketClient = new QUdpSocket();
    udpSocketClient->bind(QHostAddress::Any, 7755);

    //set the slot function()
    connect(udpSocketClient, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    memset(recvData, 0, sizeof(recvData));

    messageTimer = new QTimer(this);
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(messageTimerTimeout()));

    putTimer = new QTimer(this);
    connect(putTimer, SIGNAL(timeout()), this, SLOT(putTimerTimeout()));

    webTimer = new QTimer(this);
    connect(webTimer, SIGNAL(timeout()), this, SLOT(webTimerTimeout()));

    sFile = NULL;
    networkManager = NULL;

    ui->IpAddressIMLEdit->setText("192.168.200.200");
    ui->IpAddressBINEdit->setText("192.168.200.200");

    defaultTextCodec = QTextCodec::codecForName("Windows-1251");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::messageTimerTimeout()
{
    SendTotalTime+=100;
    if(finished_flag == 0)
        return;

    messageTimer->stop();

    switch(finished_flag){
        default: return;
        case 1:
            {
                QMessageBox::information(this, tr("Put Finished"),
                                       tr("File Put Successfully Done"));
                break;
            }
        case 2:
        {
            QMessageBox::information(this, tr("File Upload Finished"),
                                   tr("File Upload Successfully Done"));
            break;
        }
        case -1:
        case -2:
            {
                QMessageBox::critical(this, tr("Error"),
                               tr("Selected File Opening Error"));
                break;
            }
        case -3:
        case -4:
            {
                QMessageBox::critical(this, tr("Error"),
                           tr("Device answer with ERROR TFTP OPCODE"));
                break;
            }
        case -5:
        case -6:
            {
                QMessageBox::critical(this, tr("Error"),
                           tr("Device connection error"));
                break;
            }
            case -7:
            {
                QMessageBox::critical(this, tr("Error"),
                           tr("File Upload error"));
                break;
            }
        }
}


void MainWindow::putTimerTimeout()
{
    putTimer->stop();
    if(finished_flag != 0)
    {
        return;
    }
    if(IMLputTimerCnt++<5)
    {
        StartTFTPPut();
    }
    else
    {
        finished_flag = -5;
        ui->labelInfo->setText(tr("--- Device connection error ---"));
        ui->progressBar->setValue(0);
    }
}

bool MainWindow::CheckFormBusy( )
{
    if(finished_flag == 0) // передача в процессе
    {
        QMessageBox::information(this, tr("Operation not finished"),
                               tr("Last action in progress. Try again later"));
        return true;
    }
    return false;
}


void MainWindow::on_IMLOpenButton_clicked()
{
    QString FilePath = QFileDialog::getOpenFileName(this, tr("Open File"), FileDIR, tr("IML Files (*.iml);;All files(*.*)"));
    if(FilePath.length()>0){
       int indx = FilePath.lastIndexOf("\\");
       if(indx==-1)
           indx = FilePath.lastIndexOf("/");
       if(indx>=0)
            FileDIR = FilePath.left(indx);
       ui->IMLFileEdit->setText(FilePath);
       ui->labelInfo->setText(tr("--- .iml File ready to Put ---"));
    }
}



void MainWindow::on_IMLWriteButton_clicked()
{
    if(ui->IMLFileEdit->text().size() >0 )
    {
        if(CheckFormBusy())
            return;

        if(sFile!=NULL)
        {
            if(sFile->isOpen()==true)
                sFile->close();
            sFile->~QFile();
            sFile=NULL;
        }
        IMLputTimerCnt = 0;
        IMLFilePath = ui->IMLFileEdit->text();

        QString imlIP =  ui->IpAddressIMLEdit->text().replace("http:\\\\", "");
        imlIP = imlIP.replace("https:\\\\", "");
        imlIP = imlIP.replace("http://", "");
        imlIP = imlIP.replace("https://", "");
        while(imlIP.endsWith(' ' ) || imlIP.endsWith( '\n' ) || imlIP.endsWith( '/' )) imlIP.chop(1);
        IMLtftpServer.setAddress(imlIP);
        IMLserverPort = TFTP_PORT;

        StartTFTPPut();
     }
}

void MainWindow::StartTFTPPut()
{
    putTimer->start(5000);

    IMLwrq_block_no = 0;
    send_data_bytes = 0;

    ui->labelInfo->setText(tr("--- Connecting to Device ---"));
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(100);

    messageTimer->start(100);
    SendTotalTime=0;

    sendWriteReqMsg(IMLFilePath);
}


void MainWindow::sendWriteReqMsg(QString pFilepath)
{
    finished_flag = 0;
    //open localfile and send them to server
    {
        sFile = new QFile(pFilepath);
        if(!sFile->open(QIODevice::ReadOnly) || sFile->size() <= 0)
        {
            if(sFile->isOpen()==true)
                sFile->close();
            sFile->~QFile();
            sFile=NULL;
            finished_flag = -2;
            ui->labelInfo->setText(tr("--- Selected file open error ---"));
            ui->progressBar->setValue(0);
            return;
        }
        IMLFile_Size = sFile->size();
    }
    {
        struct TFTPHeader header;
        header.opcode = qToBigEndian<short>(OPCODE_WRQ);
        QFileInfo fi(pFilepath);
        QString filename(fi.fileName());
        QByteArray pFilename = defaultTextCodec->fromUnicode(filename);
        int filenamelen = pFilename.length() + 1;
        int packetsize = sizeof(header) + filenamelen + 5 + 1;

        char *wrq_packet = (char *)malloc(packetsize);
        if(NULL == wrq_packet)
        {
            finished_flag = -1;
            ui->labelInfo->setText(tr("--- Memory allocate error ---"));
            ui->progressBar->setValue(0);
            return;
        }
        const char *mode = "ascii";
        memcpy(wrq_packet, &header, sizeof(header));
        memcpy(wrq_packet + sizeof(header), pFilename.data(), filenamelen);
        memcpy(wrq_packet + sizeof(header) + filenamelen, mode, strlen(mode) + 1);

        udpSocketClient->writeDatagram(wrq_packet,packetsize,IMLtftpServer,IMLserverPort);

        if(NULL != wrq_packet)
        {
            free(wrq_packet);
        }
     }
}

void MainWindow::sendDataMsg(short blockno, QHostAddress sender, quint16 senderPort)
{
    char *temp_buff = (char *)malloc(BLOCKSIZE);
    int data_size = sFile->read(temp_buff, BLOCKSIZE);
    int data_packet_size = 0;

    struct TFTPData send_data;
    send_data.header.opcode = qToBigEndian<short>(OPCODE_DATA);
    send_data.block = qFromBigEndian<short>(blockno);

    if(data_size >= 0)
    {
        data_packet_size = DATA_PACKET_HEADER_LEN + data_size;
        send_data_bytes += data_size;
    }
    char *data_packet_buff = (char *)malloc(data_packet_size);

    memcpy(data_packet_buff, &send_data, DATA_PACKET_HEADER_LEN);
    memcpy(data_packet_buff + DATA_PACKET_HEADER_LEN, temp_buff, data_size);

    if(data_size >= 0 && data_size < BLOCKSIZE)
    {
        sFile->close();
        finished_flag = 1;
    }

    udpSocketClient->writeDatagram(data_packet_buff,data_packet_size,sender,senderPort);

    if(NULL != temp_buff)
    {
        free(temp_buff);
    }

    if(NULL != data_packet_buff)
    {
        free(data_packet_buff);
    }

}



void MainWindow::readPendingDatagrams()
{
    if(udpSocketClient->hasPendingDatagrams())
    {
        QHostAddress sender;
        quint16 senderPort;

        udpSocketClient->readDatagram(recvData, sizeof(recvData), &sender, &senderPort);
        IMLtftpServer = sender;
        IMLserverPort = senderPort;
        struct TFTPHeader *header = (struct TFTPHeader*) recvData;
        struct TFTPACK *ack = (struct TFTPACK*) recvData;

        switch(qFromBigEndian<short>(header->opcode))
        {
            case OPCODE_ACK:
            if(0 == finished_flag)
            {
                IMLwrq_block_no = qFromBigEndian<short>(ack->block) + 1;
                sendDataMsg(IMLwrq_block_no, sender, senderPort);
                ui->labelInfo->setText(tr("--- Put --- Block: %1, Bytes Sent: %2 ---").arg( IMLwrq_block_no).arg( send_data_bytes));
                ui->progressBar->setValue(((float)send_data_bytes/(float)IMLFile_Size)*100);
                putTimer->start(5000);
            }
            else if(1 == finished_flag)
            {
                ui->labelInfo->setText(tr("--- Put Finished --- Total Bytes: %1, Total Time: %2 s ---").arg(IMLFile_Size).arg((SendTotalTime+500)/1000));
                sFile->close();
                sFile->deleteLater();
                sFile = NULL;
            }
            break;

        case OPCODE_ERR:
         {
            finished_flag = -3;
            ui->labelInfo->setText(tr("--- Put Error --- Device answer \"OPCODE ERROR\" ---"));
            break;
        }
        default:
            finished_flag = -4;
            ui->labelInfo->setText(tr("--- Put Error --- Device answer UNKNOWN OPCODE ---"));
            break;
        }
    }
    memset(recvData, 0, sizeof(recvData));
}







void MainWindow::on_BINOpenButton_clicked()
{
    QString BINFilePath = QFileDialog::getOpenFileName(this, tr("Open File"), FileDIR, tr("BIN Files (*.bin);;All files(*.*)"));
    if(BINFilePath.length()>0){
       int indx = BINFilePath.lastIndexOf("\\");
       if(indx==-1)
           indx = BINFilePath.lastIndexOf("/");
       if(indx>=0)
            FileDIR = BINFilePath.left(indx);
       ui->BINFileEdit->setText(BINFilePath);
       ui->labelInfo->setText(tr("--- .bin File ready to Upload ---"));
    }
}

void MainWindow::on_BINWriteButton_clicked()
{
    if(ui->BINFileEdit->text().size() >0 )
    {
        if(CheckFormBusy())
            return;

        StartHTTPPut();
     }
}

void MainWindow::StartHTTPPut()
{
    finished_flag = 0;
    send_data_bytes = 0;

    ui->labelInfo->setText(tr("--- File Upload --- Connecting... ---"));
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(100);

    messageTimer->start(100);
    webTimer->start(20000);
    SendTotalTime=0;

    QString binFilePath = ui->BINFileEdit->text();

    QFile binFile(binFilePath);

    if(!binFile.open(QIODevice::ReadOnly) || binFile.size() <= 0)
    {
        if(binFile.isOpen()==true)
            binFile.close();
        finished_flag = -2;
        ui->labelInfo->setText(tr("--- Selected file open error ---"));
        ui->progressBar->setValue(0);
        return;
    }
    BINFile_Size = binFile.size();
    QByteArray binFileArray = binFile.readAll();
    QFileInfo fileInfo(binFile.fileName());
    QString BinFileName = fileInfo.fileName();
    binFile.close();

    if(networkManager == NULL)
        networkManager = new QNetworkAccessManager(this);

    QString binIP =  ui->IpAddressBINEdit->text().replace("http:\\\\", "");
    binIP = binIP.replace("https:\\\\", "");
    binIP = binIP.replace("http://", "");
    binIP = binIP.replace("https://", "");
    while(binIP.endsWith(' ' ) || binIP.endsWith( '\n' ) || binIP.endsWith( '/' )) binIP.chop(1);
    QUrl binUrl("http://" + binIP + "/mpfsupload");

    QString auth = ui->BINUserEdit->text()+":"+ui->BINPasswordEdit->text();
    auth = defaultTextCodec->fromUnicode(auth).toBase64();
    auth="Basic "+auth;

    QNetworkRequest request(binUrl);
    request.setRawHeader("Authorization", auth.toLatin1());

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart dataPart;
    dataPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"i\"; filename=\""+BinFileName+"\""));
    dataPart.setBody(binFileArray);
    multiPart->append(dataPart);

    httpreply = networkManager->post(request, multiPart);
    multiPart->setParent(httpreply); // delete the multiPart with the reply
    connect(httpreply, SIGNAL(finished()), this, SLOT(onGetReplyHTTPUpload()));
    connect(httpreply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onGetErrorHTTPUpload(QNetworkReply::NetworkError)));
    connect(httpreply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(onUploadProgressHTTPUpload(qint64,qint64)));
}

void MainWindow::onGetReplyHTTPUpload()
{

    if(finished_flag==0)
    {

        QByteArray answer = httpreply->readAll();
        QString answ = "Данные успешно загружены";
        QByteArray answ1251 = defaultTextCodec->fromUnicode(answ);
        if(answer.indexOf("Update Successful")==-1 && answer.indexOf(answ.toUtf8()) == -1 && answer.indexOf(answ1251) == -1)
        {
            finished_flag = -7;
            ui->labelInfo->setText(tr("--- File Upload Error ---"));
        }
        else
        {
            finished_flag = 2;
            ui->progressBar->setValue(100);
            ui->labelInfo->setText(tr("--- Upload Finished --- Total Bytes: %1, Total Time: %2 s ---").arg(BINFile_Size).arg((SendTotalTime+500)/1000));
        }
    }
    httpreply->~QNetworkReply();
    httpreply = NULL;
    webTimer->stop();
}

void MainWindow::onGetErrorHTTPUpload(QNetworkReply::NetworkError code)
{
    if(finished_flag == -6)
        return;
    finished_flag = -5;
    ui->labelInfo->setText(tr("--- Upload Error ---"));

}

void MainWindow::onUploadProgressHTTPUpload(qint64 bytesWrite, qint64 bytesTotal)
{
    if(finished_flag == -5 || finished_flag == -6)
        return;
    ui->labelInfo->setText(tr("--- File Upload ---  Bytes Sent: %1; Bytes Total: %2 ---").arg( bytesWrite).arg( bytesTotal));
    ui->progressBar->setValue(((float)bytesWrite/(float)bytesTotal)*75);
    webTimer->start(20000);
}


void MainWindow::webTimerTimeout()
{
    webTimer->stop();
    finished_flag = -6;
    ui->labelInfo->setText(tr("--- Device connection error --- Timeout ---"));
    httpreply->abort();
}
