#include "RectangleAnnotation.h"

/**
 * @brief RectangleAnnotation::RectangleAnnotation creates a new RectangleAnnotation with ID and type
 * @param id annotation ID
 * @param type annotation type
 */
RectangleAnnotation::RectangleAnnotation(const QString& id, const QString& type) : Annotation(id, type) {

}

Annotation* RectangleAnnotation::copy() const {
    return new RectangleAnnotation(*this);
}

Annotation::Form RectangleAnnotation::getForm() const {
    return RECTANGLE;
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
    Annotation::toStream(out);                  //write ID + type
    out << x() << y() << width() << height();   //write coordinates
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void RectangleAnnotation::fromStream(QDataStream& in) {
    Annotation::fromStream(in);                 //read ID + type
    int newX, newY, newWidth, newHeight;                    //read coordinates
    in >> newX >> newY >> newWidth >> newHeight;            //set coordinates
    setX(newX);
    setY(newY);
    setWidth(newWidth);
    setHeight(newHeight);
}
