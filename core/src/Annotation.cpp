#include "Annotation.h"

/**
 * @brief Annotation::Annotation default constructor
 */

Annotation::Annotation() {
    mId = "";
    mType = "Unknown";
}

/**
 * @brief Annotation::Annotation create new Annotation
 * @param id
 * @param type
 */
Annotation::Annotation(const QString& id, const QString& type) {
    mId = id;
    mType = type;
}

/**
 * @brief Annotation::getId gets Id
 * @return annotation Id
 */
QString Annotation::getId() const {
    return mId;
}

/**
 * @brief Annotation::getType gets type
 * @return annotation type
 */
Annotation::Type Annotation::getType() const {
    switch (mTypes.indexOf(mType)) {
        case 0:     return FACE;
        case 1:     return PERSON;
        default:    return UNKNOWN;
    }
}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param annotation data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, const Annotation& annotation) {
    annotation.toStream(out);
    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param annotation save new annotation
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    annotation.fromStream(in);
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void Annotation::toStream(QDataStream& out) const {
    out << mId << mType;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Annotation::fromStream(QDataStream& in) {
    in >> mId >> mType;
}
