#include "application.h"
#include <iostream>
#include <qdir.h>
#include <qlibraryinfo.h>
#include <qpluginloader.h>
#include "printer.h"

Application::Application()
{

}

void Application::loadPlugins()
{
    QDir pluginsDir(QDir::currentPath());

#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS")
    {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");

    for(const QString& fileName : pluginsDir.entryList(QDir::Files))
    {
        QString filePath = pluginsDir.absoluteFilePath(fileName);
        QPluginLoader loader(filePath);
        QObject* plugin = loader.instance();
        IPrinter* printer = dynamic_cast<IPrinter*>(plugin);
        if(printer)
                plugins.push_back(std::unique_ptr<IPrinter>(printer));
    }
}

void Application::greet(const Greeting& greeting)
{
    for(auto& printer : plugins){
        Printer<Greeting>* greetingsPrinter = dynamic_cast<Printer<Greeting>*>(printer.get());
        if(greetingsPrinter)
            greetingsPrinter->print(greeting);
    }
}

void Application::run()
{
    std::cout << "loading plugins..." << std::endl;
    loadPlugins();
    std::cout << "loaded " << plugins.size() << " plugins" << std::endl;
    greet(Greeting("WoRlD"));

    emit finished();
}
