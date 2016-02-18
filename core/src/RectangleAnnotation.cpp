#include "RectangleAnnotation.h"

/**
 * @brief RectangleAnnotation::RectangleAnnotation creates a new RectangleAnnotation with ID and type
 * @param id annotation ID
 * @param type annotation type
 */
RectangleAnnotation::RectangleAnnotation(QString& id, QString& type) : Annotation(id, type) {

}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param annotation data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation){
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
    out << this->mId << this->x() << this->y() << this->width()
        << this->height() << this->mType;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void RectangleAnnotation::fromStream(QDataStream& in) {
    double x, y, width, height;
    in >> this->mId >> x >> y >> width >> height >> this->mType;

    //set coordinates and size
    this->setX((int)ceil(x));
    this->setY((int)ceil(y));
    this->setWidth((int)floor(width));
    this->setHeight((int)floor(height));
}
