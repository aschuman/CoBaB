#include "Photo.h"

/**
 * @brief Photo::Photo Creates a Photo with the given path and Annotation.
 * @param path The path to the Photo.
 * @param annotations The Annotations which belong to the Photo.
 */
Photo::Photo(const QString path, const QList<QPair<int, Annotation*>> annotations)
    : Medium(path, annotations) {
    mType = Medium::Type::PHOTO;
}
