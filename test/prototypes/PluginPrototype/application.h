#ifndef APPLICATION_H
#define APPLICATION_H
#include <qobject.h>
#include <qlist.h>
#include <memory>
#include <vector>
#include "iprinter.h"


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
    std::vector<std::unique_ptr<QObject>> plugins;
    void loadPlugins();
};

#endif // APPLICATION_H
