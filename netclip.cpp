#include "netclip.h"


NetClip::NetClip()
{
    work = new WorkerThread();
    connect(work, SIGNAL(set_clip(QString)), this, SLOT(setClip(QString)), Qt::QueuedConnection);
}

void NetClip::start()
{
    work->start();
}

void NetClip::setClip(QString data)
{
    qDebug()<<"set"<<"|"<<data<<"|"<<QThread::currentThreadId();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(data);
}
