/**
 * Project \
 */


#ifndef _DATAPACKET_H
#define _DATAPACKET_H

#include "Serializable.h"
#include "DataPacketType.h"
#include <QUuid>


class DataPacket: public Serializable {
public: 
    
    DataPacketType getType();
    
    QUuid getUuid();
    
    /**
     * @param in
     */
    virtual void toStream(QDataStream in) = 0;
    
    /**
     * @param out
     */
    virtual void fromStream(QDataStream out) = 0;
protected: 
    DataPacketType mType;
    QUuid mUuid;
};

#endif //_DATAPACKET_H
