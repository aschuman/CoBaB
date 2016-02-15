/**
 * Project \
 */


#include "Annotation.h"

/**
 * Annotation implementation
 * @author Tung
 */


/**
 * @brief Annotation::Annotation create new Annotation
 * @param id
 * @param type
 */
Annotation::Annotation(QString id, QString type) {
    mId = id;
    mType = type;
}

/**
 * @brief Annotation::getId gets Id
 * @return annotation Id
 */
QString Annotation::getId() {
    return mId;
}

/**
 * @brief Annotation::getType gets type
 * @return annotation type
 */
Annotation::Type Annotation::getType() {
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
QDataStream& operator<<(QDataStream& out, Annotation& annotation) {
    out << annotation.mId << annotation.mType;
    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param annotation save new annotation
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    in >> annotation.mId >> annotation.mType;
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void Annotation::toStream(QDataStream& in) {
    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Annotation::fromStream(QDataStream& out) {
    out >> *this;
}
