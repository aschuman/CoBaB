/**
 * Project \
 */


#ifndef _DATAPACKET_H
#define _DATAPACKET_H

#include "Serializable.h"
#include <QUuid>


class DataPacket: public Serializable {

public: 

    enum Type { SEARCHRESULT, SEARCHQUERY, SEARCHFEEDBACK };

    DataPacket();

    Type getType();
    
    QUuid getUuid();
    
    virtual void toStream(QDataStream in) override = 0;
    
    virtual void fromStream(QDataStream out) override = 0;

protected: 

    Type mType;
    static QUuid mUuid;
};

#endif //_DATAPACKET_H
