#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QMessageLogger>
#include <QDebug>

#include <workerthread.h>

#include <QObject>




int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    WorkerThread *work = new WorkerThread();
    work->start();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

