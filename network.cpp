#include "network.h"
#define TEST 0

Network::Network()
{

}

qint16 Network::connect(QTcpSocket *socket)
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
    socket->write("0000"); //首次注册
    socket->waitForBytesWritten();
    return 0;
}

QString Network::recv(QTcpSocket *socket)
{
    qDebug()<<__FUNCTION__<<"|recv"<<"|"<<socket->bytesAvailable();
    if(socket->waitForReadyRead(1000))
    {
        if(socket->bytesAvailable()) {
            QString clipdata = socket->readAll();
            return clipdata;
        }
    }
    if(!socket->waitForConnected(1000)){
        qDebug()<<__FUNCTION__ <<"|reconnect...";
        connect(Sock);
    }
    return "";
}

void Network::netRecv()
{
    QString recv_clip;
    recv_clip  = recv(Sock);
    if(!recv_clip.isEmpty())
    {
        qDebug()<<__FUNCTION__ <<"|recv clip"<<"|"<<recv_clip;
        emit recvClip(recv_clip);
    }
}

qint16 Network::send(QTcpSocket *socket)
{
    if(!socket->waitForConnected(1000)){
        qDebug()<<__FUNCTION__ <<"|reconnect...";
        connect(Sock);
    }
    while(!_queue.empty()){
        QString data = _queue.dequeue();
        socket->write(data.toStdString().c_str(), data.toStdString().length());
        socket->waitForBytesWritten();
    }
    return 0;
}

void Network::mainloop()
{
    while(1)
    {
        if(!_queue.empty())
            send(Sock);
        sleep(1);
    }
}

QString Network::encode(QString data)
{
    QString dataSize = QString("%1").arg(data.toStdString().length(),4,10,QChar('0'));
    QString sendData = dataSize + data;
    return sendData;
}

qint16 Network::sendClip(QString data){
    qDebug()<<__FUNCTION__ <<"|send clip"<<"|"<<data;
    _queue.enqueue(encode(data));
    return 0;
}

void Network::run()
{
    Sock = new QTcpSocket();
    if(Sock->state() != QAbstractSocket::ConnectedState)
        connect(Sock);
    QObject::connect( Sock, SIGNAL(readyRead()), this, SLOT(netRecv()) );
    mainloop();
}

