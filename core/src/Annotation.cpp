/**
 * Project \
 */


#include "Annotation.h"

/**
 * Annotation implementation
 */


/**
 * @brief Annotation::Annotation
 * @param id
 * @param type
 */
Annotation::Annotation(QString id, QString type) {
    mId = id;
    mType = type;
}

/**
 * @brief Annotation::getId
 * @return
 */
QString Annotation::getId() {
    return mId;
}

/**
 * @brief Annotation::getType
 * @return
 */
AnnotationType Annotation::getType() {
    QStringList types;
    types << "Face" << "Person";
    switch (types.indexOf(mId)) {
        case 0  : return AnnotationType::PERSON;
        case 1  : return AnnotationType::FACE;
        default : return AnnotationType::FACE;
    }
}

/**
 * @brief operator <<
 * @param out
 * @param annotation
 * @return
 */
QDataStream& operator<<(QDataStream& out, Annotation& annotation) {
    Q_UNUSED(annotation);
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param annotation
 * @return
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    Q_UNUSED(annotation);
    return in;
}

/**
 * @brief Annotation::toStream
 * @param in
 */
void Annotation::toStream(QDataStream in) {
    in << *this;
}

/**
 * @brief Annotation::fromStream
 * @param out
 */
void Annotation::fromStream(QDataStream out) {
    out >> *this;
}
