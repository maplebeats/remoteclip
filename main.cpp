#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QMessageLogger>
#include <QDebug>

#include "workerthread.h"
#include "netclip.h"
#include "systray.h"

#include <QObject>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/net.ico"));

    /*
    QSystemTrayIcon tray;
    tray.setIcon(QIcon(":/images/clip.png"));
    tray.show();
    */
    SysTray Tray;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    NetClip clip;
    clip.start();

    return app.exec();
}
