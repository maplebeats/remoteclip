#include "workerthread.h"

#define TEST 0

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

/*
void WorkerThread::set_clip(QString data)
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(data);
}
*/

QString WorkerThread::readTcp(QTcpSocket *socket)
{
    if (socket->waitForReadyRead( 1000 )) {
        if(socket->bytesAvailable()) {
            QString clipdata = socket->readAll();
            qDebug()<<"recv"<<"|"<<clipdata<<"|"<<QThread::currentThreadId();
            _data = clipdata;
            emit set_clip(clipdata);
            return clipdata;
        }
        return "";
    }
    return "";
}

void WorkerThread::run()
{
    _client = new QTcpSocket();  //不能加到初始化里，初始化的时候线程还没起来!!!
    if(_client->state() != QAbstractSocket::ConnectedState)
        createTcp(_client);
    while(1){

        sleep(1); //休息一秒，不然主线程来不及更新剪切板导致死循环。
        QString text = get_clip();
        if(text == _data){
            readTcp(_client);
            continue;
        }
        _data = text;
        if(_client->state() != QAbstractSocket::ConnectedState)
            createTcp(_client);
        send_clip();
    }
}


void WorkerThread::send_clip()
{
    QString dataSize = QString("%1").arg(_data.toStdString().length(),4,10,QChar('0'));
    QString sendData = dataSize + _data;
    _queue.enqueue(sendData);
    while(!_queue.empty()){
        QString data = _queue.dequeue();
        qint64 ret = _client->write(data.toStdString().c_str(), sendData.size());
        _client->flush();
        qDebug() <<"send"<<"|"<<ret<<"|"<<data;
    }
}
