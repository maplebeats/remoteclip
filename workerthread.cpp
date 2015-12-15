#include "workerthread.h"

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

void WorkerThread::run()
{
    _client = new QTcpSocket();  //不能加到初始化里，初始化的时候线程还没起来!!!
    //_client->connectToHost(QHostAddress("14.17.41.149"), 11025);
    _client->connectToHost(QHostAddress("127.0.0.1"), 9999);
    bool ret = _client->waitForConnected(1000);
    qDebug()<<"connect"<<"|"<<ret<<"|"<<this->currentThreadId();
    while(1){
        QString text = get_clip();
        qDebug() <<"recv"<<"|"<<_client->readAll();
        if(text == _data){
            sleep(1);
            continue;
        }
        _data = text;
        send_clip();
        qDebug() <<"loop"<<"|"<< _data<<"|"<<ret ;
    }
}


void WorkerThread::send_clip()
{
    const char * d = _data.toStdString().c_str();
    qint64 ret = _client->write(d,_data.size());
    _client->flush();
    qDebug() <<"send"<<"|"<<ret;
}
