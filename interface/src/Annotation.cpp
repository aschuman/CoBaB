#include "Annotation.h"

/**
 * @brief Annotation::Annotation default constructor
 */
Annotation::Annotation() {
    mId = "";
    mType = "Unknown";
    mForm = Annotation::Form::UNKNOWN_FORM;
}

/**
 * @brief Annotation::Annotation create new Annotation
 * @param id
 * @param type
 */
Annotation::Annotation(const QString& id, const QString& type) {
    mId = id;
    mType = type;
    mForm = Annotation::Form::UNKNOWN_FORM;
}

/**
 * @brief Annotation::copy Copies the Annotation.
 * @return A copy of this Annotation.
 */
Annotation* Annotation::copy() const {
    return new Annotation(*this);
}

/**
 * @brief Annotation::getId gets Id
 * @return annotation Id
 */
QString Annotation::getId() const {
    return mId;
}

/**
 * @brief Annotation::getType gets type
 * @return annotation type
 */
Annotation::Type Annotation::getType() const {
    switch (mTypes.indexOf(mType)) {
        case 0:     return FACE;
        case 1:     return PERSON;
        default:    return UNKNOWN;
    }
}

/**
 * @brief Annotation::getForm Returns the form of the Annotation. RECTANGLE, if it is a RectangleAnnotation and
 *        UNKNOWN for a normal Annotation
 * @return the annotation form
 */
Annotation::Form Annotation::getForm() const {
    return mForm;
}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param annotation data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, const Annotation& annotation) {
    annotation.toStream(out);
    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param annotation save new annotation
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, Annotation& annotation) {
    annotation.fromStream(in);
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void Annotation::toStream(QDataStream& out) const {
    out << mId << mType;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Annotation::fromStream(QDataStream& in) {
    in >> mId >> mType;
}
