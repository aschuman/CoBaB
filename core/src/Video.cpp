/**
 * Project \
 */


#include "CoBaB.h"

/**
 * Video implementation
 */


/**
 * @param path
 */
Video::Video(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mMediumType = MediumType::VIDEO;
}
