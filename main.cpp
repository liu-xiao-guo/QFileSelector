#include <QDebug>
#include <QFileSelector>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore/private/qfileselector_p.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Create and display a file selector, just for interest.
    QFileSelector sel;
    QStringList s;
    s.append("good");
    sel.setExtraSelectors(s);
    qDebug() << sel.allSelectors();
    QFileSelectorPrivate::addStatics(QStringList() << "good");


    // Load and execute the main QML file.
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
