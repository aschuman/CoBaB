#include "application.h"
#include <iostream>
#include <qdir.h>
#include <qlibraryinfo.h>
#include <qpluginloader.h>

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
        if(plugin)
                plugins.push_back(std::make_unique<QObject>(plugin));
    }
}

void Application::run()
{
    std::cout << "loading plugins..." << std::endl;
    loadPlugins();
    std::cout << "loaded " << plugins.size() << " plugins" << std::endl;

    emit finished();
}
