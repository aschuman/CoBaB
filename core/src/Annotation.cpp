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

Annotation::Annotation() {

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
void Annotation::toStream(QDataStream& in) const {
    in << mId << mType;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Annotation::fromStream(QDataStream& out) {
    out >> mId >> mType;
}
