#include <QtCore>
#include <QApplication>
#include <MainControl.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainControl mc;
    QObject::connect(&mc, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, &mc, SIGNAL(run()));

    return a.exec();
}
