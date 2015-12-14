#ifndef NETCLIP_H
#define NETCLIP_H

#include <QApplication> //widgets
#include <QClipboard>   //gui
#include <QObject>

class NetClip : public QClipboard
{
public:
    NetClip();

};

#endif // NETCLIP_H
