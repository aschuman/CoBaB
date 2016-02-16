/**
 * Project \
 */

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "DataPacket.h"
#include <QList>
#include <QJsonObject>

class Algorithm {
public: 
    
    virtual QList<DataPacket> run();
    
    void cancel();
    
    bool setInputs(QList<DataPacket> inputDataList);
    
    bool setParameters(QJsonObject parameters);
    
    QString getId();
};

#endif //_ALGORITHM_H
