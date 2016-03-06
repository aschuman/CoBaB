/**
 * Project \
 */


#include "AlgorithmList.h"
#include <QDir>

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * AlgorithmList implementation
 */


/**
 * @param file
 */
AlgorithmList::AlgorithmList(const QString& file) {
    QDir pluginsDir(file);

    for(const QString& fileName : pluginsDir.entryList(QDir::Files))
    {
        QString filePath = pluginsDir.absoluteFilePath(fileName);
        mPluginLoaders.push_back(std::make_unique<QPluginLoader>(filePath));
    }
}

AlgorithmList::~AlgorithmList()
{
    for(auto& loader : mPluginLoaders){
        loader->unload();
    }
}

AlgorithmList::AlgorithmList(AlgorithmList&& a) : mPluginLoaders(std::move(a.mPluginLoaders))
{
}

AlgorithmList& AlgorithmList::operator=(AlgorithmList &&a)
{
    mPluginLoaders = std::move(a.mPluginLoaders);
    return *this;
}

/**
 * @param packet
 * @return QList<Algorithm>
 */
QList<Algorithm*> AlgorithmList::findCompatibleAlgorithms(const QList<DataPacket*>& inputDataList) {
    QList<Algorithm*> algos;
    for(auto& loader : mPluginLoaders){
        auto algo = loadAlgorithm(loader.get());
        if(algo){
            if(algo->setInputs(inputDataList))
                algos.push_back(std::move(algo));
        }
    }
    return algos;
}

/**
 * @return QList<Algorithm>
 */
QList<Algorithm*> AlgorithmList::getAlgorithmList() {
    QList<Algorithm*> algos;
    for(auto& loader : mPluginLoaders){
        auto algo = loadAlgorithm(loader.get());
        if(algo)
            algos.push_back(std::move(algo));
    }
    return algos;
}

Algorithm *AlgorithmList::loadAlgorithm(QPluginLoader* loader)
{
    Algorithm* loadedAlgorithm = nullptr;
    QObject* plugin = loader->instance();
     if(plugin){
         LOG("loading plugin ",  loader->fileName().toStdString(), " ..");
         loadedAlgorithm = qobject_cast<Algorithm*>(plugin);
         if(loadedAlgorithm){
             LOG("sucessfully loaded algorithm ", loadedAlgorithm->getName().toStdString());
         } else {
             LOG("plugin does not implement Algorithm-interface");
         }
     }
     return loadedAlgorithm;
}
