/**
 * Project \
 */


#include "CoBaB.h"

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
    return "";
}

/**
 * @return AnnotationType
 */
AnnotationType Annotation::getType() {
    return AnnotationType::FACE;
}

/**
 * @param out
 * @param annotation
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, Annotation& annotation) {
    return out;
}

/**
 * @param in
 * @param annotation
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    return in;
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
