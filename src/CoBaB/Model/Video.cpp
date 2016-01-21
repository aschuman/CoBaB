/**
 * Project \
 */


#include "Video.h"

/**
 * Video implementation
 */


/**
 * @param path
 */
void Video::Video(QString path, QList<QPair<int, QList<Annotation>>> annotations)
    : Medium(path, annotations) {
    mMediumType = VIDEO;
}
