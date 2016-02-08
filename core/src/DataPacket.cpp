/**
 * Project \
 */


#include "DataPacket.h"

/**
 * DataPacket implementation
 */


/**
 * @return DataPacketType
 */
DataPacketType DataPacket::getType() {
    return mType;
}

/**
 * @return QUuid
 */
QUuid DataPacket::getUuid() {
    return mUuid;
}
