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
    return null;
}

/**
 * @return QUuid
 */
QUuid DataPacket::getUuid() {
    return null;
}

/**
 * @param in
 */
virtual void DataPacket::toStream(QDataStream in) {

}

/**
 * @param out
 */
virtual void DataPacket::fromStream(QDataStream out) {

}