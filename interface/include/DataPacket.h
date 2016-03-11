/**
 * Project \
 */

#ifndef _DATAPACKET_H
#define _DATAPACKET_H

#include "Serializable.h"
#include <QUuid>

/**
 * @brief DataPacket implementation
 * @author Violina, Georgi
 */
class DataPacket: public Serializable {

public: 

    enum Type { SEARCHRESULT, SEARCHQUERY, SEARCHFEEDBACK, UNKNOWN };

    DataPacket();

    Type getType() const;
    
    QUuid getUuid() const;
    
    void toStream(QDataStream& out) const override;
    
    void fromStream(QDataStream& in) override;

    friend QDataStream& operator >>(QDataStream& in, DataPacket& datapacket);

    friend QDataStream& operator <<(QDataStream& out, const DataPacket& datapacket);

    friend QDataStream& operator >>(QDataStream& in, DataPacket::Type& e);

protected: 

    Type mType;             ///< The type of the datapacket
    QUuid mUuid;            ///< Unique identifier for the datapacket
};

#endif //_DATAPACKET_H