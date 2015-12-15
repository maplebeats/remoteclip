#include "workerthread.h"

#define TEST 1

WorkerThread::WorkerThread()
{
    _data="";
}
QString WorkerThread::get_clip()
{
    QClipboard *clip = QApplication::clipboard();
    QString text = clip->text();
    return text;
}
qint16 WorkerThread::createTcp(QTcpSocket *socket)
{
    if(TEST)
        socket->connectToHost(QHostAddress("127.0.0.1"), 9999);
    else
        socket->connectToHost(QHostAddress("14.17.41.149"), 11025);
    if(!socket->waitForConnected(1000))
    {
        qDebug()<<"connect"<<"|"<<"fail"<<"|"<<this->currentThreadId();
        return -1;
    }
    return 0;
}


void WorkerThread::run()
{
    _client = new QTcpSocket();  //不能加到初始化里，初始化的时候线程还没起来!!!
    createTcp(_client);
    while(1){

        QString text = get_clip();
        if(text == _data){
            sleep(1);
            continue;
        }
        _data = text;
        if(_client->state() != QAbstractSocket::ConnectedState)
            createTcp(_client);
        send_clip();
        while (_client->state() == QAbstractSocket::ConnectedState) {
            if (_client->waitForReadyRead( 100 )) {
                if(_client->bytesAvailable()) {
                    qDebug()<<"recv"<<"|"<<_client->readAll();
                    break;
                }
            }
            else {
                sleep(1);
            }
        }
    }
}


void WorkerThread::send_clip()
{
    QString dataSize = QString("%1").arg(_data.size(),4,10,QChar('0'));
    QString sendData = dataSize + _data;
    qint64 ret = _client->write(sendData.toStdString().c_str(), sendData.size());
    _client->flush();
    qDebug() <<"send"<<"|"<<ret<<"|"<<sendData;
}
