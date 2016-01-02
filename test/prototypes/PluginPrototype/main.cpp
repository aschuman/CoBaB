#include <QtCore>
#include "application.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Application myApp;

    QObject::connect(&myApp, &Application::finished, &a, &QCoreApplication::quit);
    QTimer::singleShot(0, &myApp, &Application::run);
    return a.exec();
}

