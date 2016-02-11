/**
 * Project \
 */


#include "RectangleAnnotation.h"

/**
 * RectangleAnnotation implementation
 */


/**
 * @brief RectangleAnnotation::RectangleAnnotation
 * @param id
 * @param type
 */
RectangleAnnotation::RectangleAnnotation(QString id, QString type) : Annotation(id, type) {
    mId = id;
    mType = type;
}

/**
 * @brief operator <<
 * @param out
 * @param annotation
 * @return
 */
QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation){
    out << annotation.mId << annotation.x() << annotation.y() << annotation.width()
        << annotation.height() << annotation.mType;

    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param annotation
 * @return
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
