/**
 * Project \
 */


#include "..\..\include\CoBaB.h"

/**
 * Photo implementation
 */


/**
 * @param path
 */
Photo::Photo(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mMediumType = PHOTO;
}
