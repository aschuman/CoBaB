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
        LOG("loading plugin '",  fileName.toStdString(), "' ..");
        QObject* plugin = loader->instance();
        if(plugin){
            Algorithm* loadedAlgorithm = qobject_cast<Algorithm*>(plugin);
            if (loadedAlgorithm) {
                if(loadedAlgorithm->initialize(loader.get())){
                    mPluginLoaders.push_back(std::move(loader));
                    LOG("sucessfully loaded algorithm '", loadedAlgorithm->getName().toStdString(), "'");
                } else {
                    LOG("plugin could not be initialized");
                }
            } else {
                LOG("plugin does not implement Algorithm-interface");
            }
        } else {
            LOG("could not load plugin");
        }
    }
}

/**
 * @brief AlgorithmList::~AlgorithmList destructor to unload the algorithms
 */
AlgorithmList::~AlgorithmList() {
    for (auto& loader : mPluginLoaders) {
        loader->unload();
    }
}

/**
 * @brief AlgorithmList::AlgorithmList Move-constructs an AlgorithmList instance,
 * making it point at the same object that a was pointing to.
 * @param a the AlgorithmList to be move-constructed
 */
AlgorithmList::AlgorithmList(AlgorithmList&& a) : mPluginLoaders(std::move(a.mPluginLoaders)) {

}

/**
 * @brief AlgorithmList::operator = Move-assigns a to this AlgorithmList instance.
 * @param a the AlgorithmList to be move-assigned to this AlgorithmList
 * @return reference to this list
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
        auto algo = instanceAlgorithm(loader.get());
        if (algo) {
            if (algo->setInputs(inputDataList)) {
                algos.push_back(std::move(algo));
            }
        }
    }
    return algos;
}

/**
 * @brief AlgorithmList::getAlgorithmList Returns all loaded algorithms
 * @return all loaded algorithms
 */
QList<Algorithm*> AlgorithmList::getAlgorithmList() {
    QList<Algorithm*> algos;
    for(auto& loader : mPluginLoaders) {
        auto algo = instanceAlgorithm(loader.get());
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
Algorithm* AlgorithmList::instanceAlgorithm(QPluginLoader* loader) {
    Algorithm* loadedAlgorithm = nullptr;
    QObject* plugin = loader->instance();

    if (plugin)
        loadedAlgorithm = qobject_cast<Algorithm*>(plugin);

    return loadedAlgorithm;
}
