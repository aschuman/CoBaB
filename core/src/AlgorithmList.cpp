/**
 * Project \
 */


#include "AlgorithmList.h"
#include <QDir>
#include <QPluginLoader>

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
        QPluginLoader loader(filePath);
        QObject* plugin = loader.instance();
        if(plugin){
            LOG("loading plugin ", fileName.toStdString(), " ..");
            Algorithm* algo = qobject_cast<Algorithm*>(plugin);
            if(algo){
                LOG("sucessfully loaded plugin");
                mAlgorithmList.push_back(std::unique_ptr<Algorithm>(algo));
            } else {
                LOG("plugin does not implement Algorithm-interface");
            }
        }
    }
}

AlgorithmList::AlgorithmList(AlgorithmList&& a) : mAlgorithmList(std::move(a.mAlgorithmList))
{
}

AlgorithmList& AlgorithmList::operator=(AlgorithmList &&a)
{
    mAlgorithmList = std::move(a.mAlgorithmList);
    return *this;
}

/**
 * @param packet
 * @return QList<Algorithm>
 */
QList<Algorithm*> AlgorithmList::findCompatibleAlgorithms(const DataPacket& packet) {
    return QList<Algorithm*>();
}

/**
 * @return QList<Algorithm>
 */
QList<Algorithm*> AlgorithmList::getAlgorithmList() {
    return QList<Algorithm*>();
}
