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
void Photo::Photo(QString path, QList<QPair<int, QList<Annotation>>> annotations)
    : Medium(path, annotations) {
    mMediumType = PHOTO;
}
