#ifndef SYSTRAY_H
#define SYSTRAY_H
#include <QMenu>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QCloseEvent>
class SysTray : QSystemTrayIcon
{
    Q_OBJECT
public:
    SysTray();
    QAction * quitAction;
    QMenu *myMenu;
signals:

public slots:

};

#endif // SYSTRAY_H
