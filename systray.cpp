#include "systray.h"

SysTray::SysTray()
{
    qDebug()<<"add tray";
    this->setIcon(QIcon(":/images/clip.png"));

    quitAction = new QAction("退出(&Q)",this);
    this->show();
}

