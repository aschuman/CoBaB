/**
 * Project \
 */


#ifndef _ALGORITHMLIST_H
#define _ALGORITHMLIST_H

#include "DataPacket.h"
#include "Algorithm.h"
#include <vector>
#include <QList>
#include <QPluginLoader>

class AlgorithmList {
public: 
    
    /**
     * @param file
     */
    explicit AlgorithmList(const QString& file);
    ~AlgorithmList();
    AlgorithmList(AlgorithmList&& a);
    AlgorithmList& operator=(AlgorithmList&& a);
    
    /**
     * @param packet
     */
    QList<Algorithm*> findCompatibleAlgorithms(const QList<DataPacket *> &inputDataList);
    
    QList<Algorithm*> getAlgorithmList();
private:
    Algorithm* loadAlgorithm(QPluginLoader* loader);

    std::vector<std::unique_ptr<QPluginLoader>> mPluginLoaders;
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<AlgorithmList>)

#endif //_ALGORITHMLIST_H
