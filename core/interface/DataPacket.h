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

    enum Type { SEARCHRESULT, SEARCHQUERY, SEARCHFEEDBACK };

    DataPacket();

    Type getType() const;
    
    QUuid getUuid() const;
    
    void toStream(QDataStream& in) const override;
    
    void fromStream(QDataStream& out) override;

    friend QDataStream& operator >>(QDataStream& in, DataPacket& datapacket);

    friend QDataStream& operator <<(QDataStream& out, const DataPacket& datapacket);

protected: 

    Type mType;             ///< The type of the datapacket
    static QUuid mUuid;     ///< Unique identifier for the datapacket
};

#endif //_DATAPACKET_H
