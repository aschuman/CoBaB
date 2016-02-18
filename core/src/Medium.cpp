#include "Medium.h"

/**
 * @brief Medium::Medium Creates a new Medium which has the given path and Annotation list.
 * @param path The path to the Medium.
 * @param annotations The list of Annotation which belong to this Medium.
 */
Medium::Medium(const QString path, const QList<QPair<int, Annotation*>> annotations)
    : mPath(path), mAnnotationList(annotations) {
    mType = Medium::Type::PHOTO;
}

/**
 * @brief Medium::~Medium Deletes the Medium.
 */
Medium::~Medium() {
    for(QPair<int, Annotation*> iter: mAnnotationList) {
        delete iter.second;
    }
}

/**
 * @brief Medium::getType Returns the Type of the Medium.
 * @return The Type of the Medium.
 */
Medium::Type Medium::getType() const {
    return mType;
}

/**
 * @brief Medium::getAnnotationList Returns the list of Annotation which belong to the Medium.
 * @return The list of Annotation.
 */
QList<QPair<int, Annotation*>> Medium::getAnnotationList() const {
    return mAnnotationList;
}

/**
 * @brief Medium::getPath Returns the path to the Medium.
 * @return The path to the Medium.
 */
QString Medium::getPath() const {
    return mPath;
}
