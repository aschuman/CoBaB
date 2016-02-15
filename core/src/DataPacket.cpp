/**
 * Project \
 */

#include <QUuid>
#include <typeinfo>

#include "DataPacket.h"

/**
 * @brief DataPacket implementation
 *
 */

DataPacket::DataPacket() {

    QString type = typeid(DataPacket).name();
    if (type == "SearchResult") {
        mType = Type::SEARCHRESULT;
    } else if (type == "SearchQuery") {
        mType = Type::SEARCHQUERY;
    } else {
        mType = Type::SEARCHFEEDBACK;
    }

    mUuid = QUuid::createUuid();
}

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
