/**
 * Project \
 */


#include "Medium.h"

/**
 * Medium implementation
 */


/**
 * @param path
 * @param annotations
 */
Medium::Medium(const QString path, const QList<QPair<int, Annotation>> annotations)
    : mRelativePath(path), mAnnotationList(annotations) {
}

/**
 * @return Type
 */
Medium::Type Medium::getType() const {
    return mType;
}

/**
 * @return QList<QPair<int, Annotation>>
 */
QList<QPair<int, Annotation>> Medium::getAnnotationList() const {
    return mAnnotationList;
}

/**
 * @return QString
 */
QString Medium::getPath() const {
    return mRelativePath;
}
