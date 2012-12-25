#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "MainModel.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    MainModel d;
    viewer.rootContext()->setContextProperty("mainModel", &d);

    viewer.setMainQmlFile(QStringLiteral("qml/quick2test/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
