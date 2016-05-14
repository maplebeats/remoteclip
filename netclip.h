#ifndef NETCLIP_H
#define NETCLIP_H
#include "workerthread.h"

class NetClip:public QObject
{
    Q_OBJECT

public slots:
    void setClip(QString);

public:
    NetClip();
    void start();

    WorkerThread *work;
    Network *net;


};

#endif // NETCLIP_H
