#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QMessageLogger>
#include <QDebug>

#include <workerthread.h>
#include <netclip.h>

#include <QObject>

#include <QSystemTrayIcon>
#include <QAction>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/net.ico"));
    NetClip clip;
    clip.start();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QSystemTrayIcon tray;
    tray.setIcon(QIcon(":/images/clip.png"));
    tray.show();


    return app.exec();
}

