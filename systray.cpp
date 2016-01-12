#include "systray.h"

SysTray::SysTray()
{
    qDebug()<<"add tray";
    this->setIcon(QIcon(":/images/clip.png"));
    this->show();
}

