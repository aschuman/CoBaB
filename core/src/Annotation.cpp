/**
 * Project \
 */


#include "Annotation.h"

/**
 * Annotation implementation
 */


/**
 * @param id
 */
Annotation::Annotation(QString id, QString type) {
    mId = id;
    mType = type;
}

/**
 * @return QString
 */
QString Annotation::getId() {
    return mId;
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
    (void) annotation;
    return out;
}

/**
 * @param in
 * @param annotation
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    (void) annotation;
    return in;
}

/**
 * @param in
 */
void Annotation::toStream(QDataStream in) {
    in << *this;
}

/**
 * @param out
 */
void Annotation::fromStream(QDataStream out) {
    out >> *this;
}
