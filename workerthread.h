#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H


#include <QApplication> //widgets
#include <QClipboard>   //gui

#include <QtNetwork>

#include <QThread>

#include <QMessageLogger>
#include <QDebug>

#include <QObject>

class WorkerThread:public QThread
{
    Q_OBJECT

public slots:
    void send_clip();

signals:
    void set_clip(QString);

public:
    WorkerThread();
    void run();

    qint16 createTcp(QTcpSocket *socket);
    QString readTcp(QTcpSocket *socket);
    QString get_clip();
private:
    QString _data;
    QTcpSocket * _client;
    QString _guid;
};

#endif // WORKERTHREAD_H
