/**
 * Project \
 */


#ifndef _ALGORITHMLIST_H
#define _ALGORITHMLIST_H

#include "DataPacket.h"
#include "Algorithm.h"
#include <vector>
#include <QList>

class AlgorithmList {
public: 
    
    /**
     * @param file
     */
    explicit AlgorithmList(const QString& file);
    AlgorithmList(AlgorithmList&& a);
    AlgorithmList& operator=(AlgorithmList&& a);
    
    /**
     * @param packet
     */
    QList<Algorithm*> findCompatibleAlgorithms(const DataPacket& packet);
    
    QList<Algorithm*> getAlgorithmList();
private:
    std::vector<std::unique_ptr<Algorithm>> mAlgorithmList;
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<AlgorithmList>)

#endif //_ALGORITHMLIST_H
