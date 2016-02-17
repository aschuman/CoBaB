/**
 * Project \
 */

#include <QUuid>
#include <typeinfo>

#include "DataPacket.h"


/**
 * Creates a Datapacket with a unique number.
 * @brief DataPacket::DataPacket
 */
DataPacket::DataPacket() {

    mUuid = QUuid::createUuid();
}

/**
 * @return Type The type of the datapacket
 */
DataPacket::Type DataPacket::getType() const {
    return mType;
}

/**
 * @return QUuid The unique identification number
 */
QUuid DataPacket::getUuid() const {
    return mUuid;
}

/**
 * @brief writes the datapacket to stream
 * @param in the stream
 */
void DataPacket::toStream(QDataStream& in) const {
    in << this->mType
       << this->mUuid;

}

/**
 * @brief calls the datapacket from stream
 * @param out the stream
 */
void DataPacket::fromStream(QDataStream& out) {
    DataPacket::Type type;
    QUuid uuid;

    out >> type;
    this->mType = type;

    out >> uuid;
    this->mUuid = uuid;
}

/**
 * @brief overrides the operator >>
 * @param in the stream, where the datapcket is written
 * @param datapacket which is written in the stream
 * @return
 */
QDataStream& operator >>(QDataStream& in, DataPacket& datapacket) {

    datapacket.fromStream(in);

    return in;
}

/**
 * @brief overrides the operator <<
 * @param out the stream from which the datapacket is called
 * @param datapacket which is called
 * @return
 */
QDataStream& operator <<(QDataStream& out, const DataPacket& datapacket) {

    datapacket.toStream(out);

    return out;
}
