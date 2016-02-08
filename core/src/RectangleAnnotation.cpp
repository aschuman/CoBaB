/**
 * Project \
 */


#include "RectangleAnnotation.h"

/**
 * RectangleAnnotation implementation
 */


/**
 * @param id
 */
RectangleAnnotation::RectangleAnnotation(QString id, QString type) : Annotation(id, type) {

}

/**
 * @param out
 * @param annotation
 */
QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation){
    //convert QString to char array for output
    const char *id = annotation.getId().toStdString().c_str();
    const char *type = annotation.mType.toStdString().c_str();

    out << id << " " << annotation.x() << " " << annotation.y() << " "
        << annotation.width() << " " << annotation.height() << " " << type << " ";

    return out;
}

/**
 * @param in
 * @param annotation
 */
QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation) {

    char *id, *type;
    int x, y, width, height;
    in >> id >> x >> y >> width >> height >> type;
    annotation = RectangleAnnotation(QString(id), QString(type));

    //set coordinates and size
    annotation.setX(x);
    annotation.setY(y);
    annotation.setWidth(width);
    annotation.setHeight(height);

    return in;
}
