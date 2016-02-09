/**
 * Project \
 */


#include "DataPacket.h"

/**
 * DataPacket implementation
 */


/**
 * @return Type
 */
DataPacket::Type DataPacket::getType() {
    return mType;
}

/**
 * @return QUuid
 */
QUuid DataPacket::getUuid() {
    return mUuid;
}
