/**
 * Project \
 */


#include "..\..\include\CoBaB.h"

/**
 * Annotation implementation
 */


/**
 * @param id
 */
Annotation::Annotation(QString id) {

}

/**
 * @return QString
 */
QString Annotation::getId() {
    return null;
}

/**
 * @return AnnotationType
 */
AnnotationType Annotation::getType() {
    return null;
}

/**
 * @param out
 * @param annotation
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, Annotation& annotation) {
    return null;
}

/**
 * @param in
 * @param annotation
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    return null;
}

/**
 * @param in
 */
void Annotation::toStream(QDataStream in) {

}

/**
 * @param out
 */
void Annotation::fromStream(QDataStream out) {

}
