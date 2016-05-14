#include "workerthread.h"



WorkerThread::WorkerThread()
{
    _data= get_clip();
}
QString WorkerThread::get_clip()
{
    QClipboard *clip = QApplication::clipboard();
    const QMimeData *mimeData = clip->mimeData();
    if (mimeData->hasText()){
        return clip->text();
    }else
    {
        return NULL; //unsupport
    }
}


void WorkerThread::run()
{
    workloop();
}

void WorkerThread::workloop()
{
    while(1){
        QString text = get_clip();
        if (_data != text)
        {
            qDebug()<<__FUNCTION__ <<"|clip changed|"<<text;
            _data = text;
            emit changeClip(text);
        };
        sleep(1);
    }
}


