/**
 * Project \
 */


#ifndef _ALGORITHMLIST_H
#define _ALGORITHMLIST_H

#include "..\..\include\DataPacket.h"
#include "..\..\include\Algorithm.h"
#include <QList>

class AlgorithmList {
public: 
    
    /**
     * @param file
     */
    AlgorithmList(QString file);
    
    /**
     * @param packet
     */
    QList<Algorithm> findCompatibleAlgorithms(DataPacket packet);
    
    QList<Algorithm> getAlgorithmList();
private: 
    QList<Algorithm> mAlgorithmList;
};

#endif //_ALGORITHMLIST_H
