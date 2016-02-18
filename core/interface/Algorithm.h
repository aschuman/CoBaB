#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "DataPacket.h"
#include <QList>
#include <QJsonObject>

/**
 * Algorithm interface
 * @author Tung
 */

class Algorithm {
public: 
    
    virtual QList<DataPacket*> run();
    
    void cancel();
    
    bool setInputs(QList<DataPacket> inputDataList);
    
    bool setParameters(QJsonObject parameters);
    
    QString getId() const;
};

#endif //_ALGORITHM_H
