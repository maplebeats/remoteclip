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

public:
    WorkerThread();

    ~WorkerThread(){
        qDebug()<<"over";
    }

    void run();
private:
    QString _data;
    QTcpSocket * _client;
    QString get_clip();
};

#endif // WORKERTHREAD_H
