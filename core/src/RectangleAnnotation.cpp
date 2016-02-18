#include "RectangleAnnotation.h"

/**
 * @brief RectangleAnnotation::RectangleAnnotation creates a new RectangleAnnotation with ID and type
 * @param id annotation ID
 * @param type annotation type
 */
RectangleAnnotation::RectangleAnnotation(const QString& id, const QString& type) : Annotation(id, type) {

}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param annotation data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, const RectangleAnnotation& annotation){
    annotation.toStream(out);
    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param annotation save new annotation
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation) {
    annotation.fromStream(in);
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void RectangleAnnotation::toStream(QDataStream& out) const {
    out << *(Annotation*)this;      //write ID + type
    out << *(QRect*)this;            //write coordinates
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void RectangleAnnotation::fromStream(QDataStream& in) {
    in >> *(Annotation*)this;
    in >> *(QRect*)this;
}
