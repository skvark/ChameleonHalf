#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QtQml>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QCoreApplication>
#include <controller.h>
#include <QDebug>


int main(int argc, char *argv[])
{
    Controller controller;
    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view->rootContext()->setContextProperty("controller", &controller);
    view->setSource(SailfishApp::pathTo("qml/harbour-chameleon.qml"));
    view->showFullScreen();
    app->exec();
}

