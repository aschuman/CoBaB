/**
 * Project \
 */


#include "CoBaB.h"

/**
 * RectangleAnnotation implementation
 */


/**
 * @param id
 */
RectangleAnnotation::RectangleAnnotation(QString id, QString type) {

}

/**
 * @param out
 * @param annotation
 */
QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation){
    return null;
}

/**
 * @param in
 * @param annotation
 */
QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation) {
    return null;
}
