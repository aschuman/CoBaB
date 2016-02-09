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
Video::Video(QString path, QList<QPair<int, Annotation>> annotations)
    : Medium(path, annotations) {
    mType = Type::VIDEO;
}
