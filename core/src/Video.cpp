#include "Video.h"

/**
 * @brief Video::Video Creates a Video with the given path and Annotations.
 * @param path The path to the Video.
 * @param annotations The Annotations which belong to this Video.
 */
Video::Video(QString path, QList<QPair<int, Annotation*>> annotations)
    : Medium(path, annotations) {
    mType = Type::VIDEO;
}
