/**
 * Project \
 */

#ifndef _DATAPACKET_H
#define _DATAPACKET_H

#include "Serializable.h"
#include <QUuid>

/**
 * @brief The class represents an abstraction for the three datapacket types: SearchResult, SearchFeedback and SearchResult
 * @author Violina, Georgi
 */
class DataPacket: public Serializable {

public: 

    /**
     * @brief The Type enum The type of a DataPacket can be searchresult, searchquery, searchfeedback,
     * or unknown (intialization)
     */
    enum Type { SEARCHRESULT, SEARCHQUERY, SEARCHFEEDBACK, UNKNOWN };

    DataPacket();

    Type getType() const;
    
    QUuid getUuid() const;
    
    void toStream(QDataStream& out) const override;
    
    void fromStream(QDataStream& in) override;

    friend QDataStream& operator >>(QDataStream& in, DataPacket& datapacket);

    friend QDataStream& operator <<(QDataStream& out, const DataPacket& datapacket);

    friend QDataStream& operator >>(QDataStream& in, DataPacket::Type& type);

protected: 

    Type mType;             ///< The type of the datapacket
    QUuid mUuid;            ///< Unique identifier for the datapacket
};

#endif //_DATAPACKET_H
