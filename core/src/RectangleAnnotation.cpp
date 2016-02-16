/**
 * Project \
 */


#include "RectangleAnnotation.h"

/**
 * RectangleAnnotation implementation
 */


/**
 * @brief RectangleAnnotation::RectangleAnnotation creates a new RectangleAnnotation with ID and type
 * @param id annotation ID
 * @param type annotation type
 */
RectangleAnnotation::RectangleAnnotation(QString id, QString type) : Annotation(id, type) {
    mId = id;
    mType = type;
}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param annotation data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation){
    out << annotation.mId << annotation.x() << annotation.y() << annotation.width()
        << annotation.height() << annotation.mType;

    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param annotation save new annotation
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation) {

    double x, y, width, height;
    in >> annotation.mId >> x >> y >> width >> height >> annotation.mType;

    //set coordinates and size
    annotation.setX((int)ceil(x));
    annotation.setY((int)ceil(y));
    annotation.setWidth((int)floor(width));
    annotation.setHeight((int)floor(height));

    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void RectangleAnnotation::toStream(QDataStream& in) {
    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void RectangleAnnotation::fromStream(QDataStream& out) {
    out >> *this;
}
