//#include "netclip.h"
#include "moc_netclip.cpp"


NetClip::NetClip()
{
    WorkerThread *work = new WorkerThread();
    connect(work, SIGNAL(set_clip(QString)), this, SLOT(setClip(QString)), Qt::QueuedConnection);
    work->start();
}


void NetClip::setClip(QString data)
{
    qDebug()<<"set"<<"|"<<data<<"|"<<QThread::currentThreadId();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(data);
}
