/**
 * Project \
 */


#include "Annotation.h"

/**
 * Annotation implementation
 */


/**
 * @brief Annotation::Annotation
 * @param id
 * @param type
 */
Annotation::Annotation(QString id, QString type) {
    mId = id;
    mType = type;
}

/**
 * @brief Annotation::getId
 * @return
 */
QString Annotation::getId() {
    return mId;
}

/**
 * @brief Annotation::getType
 * @return
 */
Annotation::Type Annotation::getType() {
    switch (mTypes.indexOf(mType)) {
        case 0:     return FACE;
        case 1:     return PERSON;
        default:    return UNKNOWN;
    }
}

/**
 * @brief operator <<
 * @param out
 * @param annotation
 * @return
 */
QDataStream& operator<<(QDataStream& out, Annotation& annotation) {
    out << annotation.mId << annotation.mType;
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param annotation
 * @return
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    in >> annotation.mId >> annotation.mType;
    return in;
}

/**
 * @brief Annotation::toStream
 * @param in
 */
void Annotation::toStream(QDataStream in) {
    in << *this;
}

/**
 * @brief Annotation::fromStream
 * @param out
 */
void Annotation::fromStream(QDataStream out) {
    out >> *this;
}
