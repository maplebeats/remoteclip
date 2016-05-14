#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H


#include <QApplication> //widgets
#include <QClipboard>   //gui

#include <QtNetwork>

#include <QThread>
#include <QQueue>

#include <QMessageLogger>
#include <QDebug>

#include <QObject>

#include "network.h"

class WorkerThread:public QThread
{
    Q_OBJECT

signals:
    void changeClip(QString);

public:
    WorkerThread();
    void run();

    QString get_clip();
private:
    void workloop();
    QString _data;
    QString _guid;
    QQueue<QString> _queue;
};

#endif // WORKERTHREAD_H
