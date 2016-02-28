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
    virtual ~Algorithm() = default;
    
    virtual QList<DataPacket*> run() = 0;
    
    virtual void cancel() = 0;
    
    virtual bool setInputs(const QList<DataPacket*>& inputDataList) = 0;
    
    virtual bool setParameters(const QJsonObject& parameters) = 0;

    virtual QString getId() const = 0;

    virtual QString getName() const = 0;

    virtual QString getDescription() const = 0;
};

#define Algorithm_iid "org.CoBaC.Algorithm"
Q_DECLARE_INTERFACE(Algorithm, Algorithm_iid)

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<Algorithm>)


#endif //_ALGORITHM_H
