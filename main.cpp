#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QMessageLogger>
#include <QDebug>

#include <workerthread.h>
#include <netclip.h>

#include <QObject>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    new NetClip();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

