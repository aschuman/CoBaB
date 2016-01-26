#include <QtCore>
#include <QApplication>
#include <maincontrol.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainControl mc;
    QObject::connect(&mc, &MainControl::finished, &a, &QApplication::quit);
    QTimer::singleShot(0, &mc, &MainControl::run);

    return a.exec();
}
