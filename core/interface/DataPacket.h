/**
 * Project \
 */


#ifndef _DATAPACKET_H
#define _DATAPACKET_H

#include "Serializable.h"
#include <QUuid>


class DataPacket: public Serializable {
public: 
    enum Type { SEARCHRESULT, SEARCHQUERY, FEEDBACK };
    Type getType();
    
    QUuid getUuid();
    
    virtual void toStream(QDataStream in) = 0;
    
    virtual void fromStream(QDataStream out) = 0;
protected: 
    Type mType;
    QUuid mUuid;
};

#endif //_DATAPACKET_H
