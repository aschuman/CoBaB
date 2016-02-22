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
    
    virtual void cancel();
    
    virtual bool setInputs(const QList<DataPacket*>& inputDataList);
    
    virtual bool setParameters(const QJsonObject& parameters);

    virtual QString getName() const;

    virtual QString getDescription() const;
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<Algorithm>)

#endif //_ALGORITHM_H
