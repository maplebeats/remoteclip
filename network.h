#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork>

#include <QThread>
#include <QQueue>

class Network:public QThread
{
    Q_OBJECT

public slots:
    qint16 sendClip(QString);

signals:
    void recvClip(QString);

public:
    Network();
    qint16 connect(QTcpSocket *socket);
    QString recv(QTcpSocket *socket);
    qint16 send(QTcpSocket *socket);
    void mainloop();
    QTcpSocket *Sock;

protected:
    void run();
    QQueue<QString> _queue;
    QString encode(QString);
};

#endif // NETWORK_H
