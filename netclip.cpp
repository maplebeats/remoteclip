#include "netclip.h"
#include "network.h"


NetClip::NetClip()
{
    work = new WorkerThread();
    net  = new Network();
    net->setParent(0)
            ;
    connect(net, SIGNAL(recvClip(QString)), this, SLOT(setClip(QString)), Qt::QueuedConnection );
    connect(work, SIGNAL(changeClip(QString)), net, SLOT(sendClip(QString)), Qt::QueuedConnection );
}

void NetClip::start()
{
    net->start();
    work->start();
}

void NetClip::setClip(QString data)
{
    qDebug()<<__FUNCTION__
           <<"|"<<"set"
          <<"|"<<data
         <<"|"<<QThread::currentThreadId();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(data, QClipboard::Clipboard);
}
