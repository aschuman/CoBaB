/**
 * Project \
 */


#include "Photo.h"

/**
 * Photo implementation
 */


/**
 * @param path
 */
Photo::Photo(const QString path, const QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mType = Medium::Type::PHOTO;
}
