#ifndef NETCLIP_H
#define NETCLIP_H
#include "workerthread.h"

class NetClip:public QObject
{
    Q_OBJECT

public:
    NetClip();

public slots:
    void setClip(QString);

};

#endif // NETCLIP_H
