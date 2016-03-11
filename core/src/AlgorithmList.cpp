#include "AlgorithmList.h"
#include <QDir>

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief AlgorithmList::AlgorithmList create new AlgorithmList containing all algorithms in a folder
 * @param path algorithm folder path
 */
AlgorithmList::AlgorithmList(const QString& path) {
    QDir pluginsDir(path);

    for (const QString& fileName : pluginsDir.entryList(QDir::Files))
    {
        QString filePath = pluginsDir.absoluteFilePath(fileName);
        std::unique_ptr<QPluginLoader> loader =  std::make_unique<QPluginLoader>(filePath);
        loader->load();
        mPluginLoaders.push_back(std::move(loader));
    }
}

/**
 * @brief AlgorithmList::~AlgorithmList destructor to unload the algorithms
 */
AlgorithmList::~AlgorithmList() {
    for (auto& loader : mPluginLoaders){
        loader->unload();
    }
}

/**
 * @brief AlgorithmList::AlgorithmList
 * @param a
 */
AlgorithmList::AlgorithmList(AlgorithmList&& a) : mPluginLoaders(std::move(a.mPluginLoaders)) {
}

/**
 * @brief AlgorithmList::operator =
 * @param a
 * @return
 */
AlgorithmList& AlgorithmList::operator=(AlgorithmList &&a) {
    mPluginLoaders = std::move(a.mPluginLoaders);
    return *this;
}

/**
 * @brief AlgorithmList::findCompatibleAlgorithms find algorithms compatible mit input data
 * @param inputDataList list of input data
 * @return all algorithms compatible mit input data
 */
QList<Algorithm*> AlgorithmList::findCompatibleAlgorithms(const QList<DataPacket*>& inputDataList) {
    QList<Algorithm*> algos;
    for (auto& loader : mPluginLoaders) {
        auto algo = loadAlgorithm(loader.get());
        if (algo) {
            if (algo->setInputs(inputDataList)) {
                algos.push_back(std::move(algo));
            }
        }
    }
    return algos;
}

/**
 * @brief AlgorithmList::getAlgorithmList
 * @return all loaded algorithms
 */
QList<Algorithm*> AlgorithmList::getAlgorithmList() {
    QList<Algorithm*> algos;
    for(auto& loader : mPluginLoaders) {
        auto algo = loadAlgorithm(loader.get());
        if (algo) {
            algos.push_back(std::move(algo));
        }
    }
    return algos;
}

/**
 * @brief AlgorithmList::loadAlgorithm load an algorithm from loader
 * @param loader pointer to loader
 * @return an pointer to algorithm instance
 */
Algorithm* AlgorithmList::loadAlgorithm(QPluginLoader* loader) {
    Algorithm* loadedAlgorithm = nullptr;
    QObject* plugin = loader->instance();

    if (plugin) {
        LOG("loading plugin ",  loader->fileName().toStdString(), " ..");
        loadedAlgorithm = qobject_cast<Algorithm*>(plugin);
        if (loadedAlgorithm) {
            LOG("sucessfully loaded algorithm ", loadedAlgorithm->getName().toStdString());
        } else {
            LOG("plugin does not implement Algorithm-interface");
        }
    }
    return loadedAlgorithm;
}
