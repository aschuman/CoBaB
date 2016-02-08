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
    (void) annotation;
    return out;
}

/**
 * @param in
 * @param annotation
 */
QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation) {
    (void) annotation;
    return in;
}
