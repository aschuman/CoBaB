/**
 * Project \
 */

#include <QUuid>
#include <typeinfo>

#include "DataPacket.h"


/**
 * @brief DataPacket::DataPacket Creates a Datapacket with a unique number.
 */
DataPacket::DataPacket() {

    mUuid = QUuid::createUuid();
    mType = DataPacket::Type::UNKNOWN;
}

/**
 * @brief DataPacket::getType Gets the type of the datapacket.
 * @return Type The type of the datapacket
 */
DataPacket::Type DataPacket::getType() const {
    return mType;
}

/**
 * Gets the uuid of the datapacket
 * @return QUuid The unique identification number
 */
QUuid DataPacket::getUuid() const {
    return mUuid;
}

/**
 * @brief
 * @param out the stream
 */
/**
 * @brief DataPacket::toStream Writes the datapacket to stream.
 * @param out the stream
 */
void DataPacket::toStream(QDataStream& out) const {
    out << mType
       << mUuid;

}

/**
 * @brief DataPacket::fromStream Calls the datapacket from stream.
 * @param in the stream
 */
void DataPacket::fromStream(QDataStream& in) {
    DataPacket::Type type;
    QUuid uuid;

    in >> type;
    mType = type;

    in >> uuid;
    mUuid = uuid;
}

/**
 * @brief operator >> Overrides the operator >>.
 * @param in the stream, where the datapacket is written
 * @param datapacket which is written in the stream
 * @return the datastream
 */
QDataStream& operator >>(QDataStream& in, DataPacket& datapacket) {

    datapacket.fromStream(in);

    return in;
}

/**
 * @brief operator << Overrides the operator <<.
 * @param out the stream from which the datapacket is called
 * @param datapacket which is called
 * @return the datastream
 */
QDataStream& operator <<(QDataStream& out, const DataPacket& datapacket) {

    datapacket.toStream(out);

    return out;
}

/**
 * @brief operator >> Overrides the operator >> for the type of the datapacket.
 * @param in the stream, where the datapacket's type is written
 * @param type the type of the datapacket
 * @return the datastream
 */
QDataStream& operator >>(QDataStream& in, DataPacket::Type& type)
{
    in >> (quint32&)type;
    return in;
}
