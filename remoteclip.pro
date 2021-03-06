TEMPLATE = app

QT += qml quick \
    gui \
    widgets

CONFIG += c++11

SOURCES += main.cpp \
    workerthread.cpp \
    netclip.cpp \
    systray.cpp \
    network.cpp

RESOURCES += qml.qrc icon.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    netclip.h \
    workerthread.h \
    systray.h \
    network.h

DISTFILES += \
    app.rc

ICON = app.icns
