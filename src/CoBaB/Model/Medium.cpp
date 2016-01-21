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
void Medium::Medium(QString path, QList<QPair<int, Annotation>> annotations) {
    mAnnotationList = annotation;
    mRelativePath = path;
}

/**
 * @return MediumType
 */
MediumType Medium::getType() {
    return mMediumType;
}

/**
 * @return QList<QPair<int, Annotation>>
 */
QList<QPair<int, Annotation>> Medium::getAnnotationList() {
    return mAnnotationList;
}
