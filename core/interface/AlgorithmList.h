#ifndef _ALGORITHMLIST_H
#define _ALGORITHMLIST_H

#include "DataPacket.h"
#include "Algorithm.h"
#include <vector>
#include <QList>
#include <QPluginLoader>

/**
 * @brief The AlgorithmList class load and return list of compatible algorithms dynamically
 * @author Vincent
 */

class AlgorithmList {
public:

    explicit AlgorithmList(const QString& path);

    ~AlgorithmList();

    AlgorithmList(AlgorithmList&& a);

    AlgorithmList& operator=(AlgorithmList&& a);
    
    QList<Algorithm*> findCompatibleAlgorithms(const QList<DataPacket *> &inputDataList);
    
    QList<Algorithm*> getAlgorithmList();

private:
    Algorithm* loadAlgorithm(QPluginLoader* loader);

    std::vector<std::unique_ptr<QPluginLoader>> mPluginLoaders;
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<AlgorithmList>)

#endif //_ALGORITHMLIST_H
