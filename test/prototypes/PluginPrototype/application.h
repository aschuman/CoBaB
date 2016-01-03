#ifndef APPLICATION_H
#define APPLICATION_H
#include <qobject.h>
#include <qlist.h>
#include <memory>
#include <vector>
#include "iprinter.h"
#include "printer.h"
#include "greeting.h"


class Application : public QObject
{
    Q_OBJECT
public:
    Application();

public slots:
    void run();

signals:
    void finished();

private:
    std::vector<std::unique_ptr<IPrinter>> plugins;
    void loadPlugins();
    void greet(const Greeting& g);
};

#endif // APPLICATION_H
