/**
 * Project \
 */


#include "..\..\include\CoBaB.h"

/**
 * SearchObject implementation
 */


SearchObject::SearchObject() {

}

/**
 * @return QString
 */
QString SearchObject::getMedium() {
    return null;
}

/**
 * @param medium
 */
void SearchObject::setMedium(QString medium) {

}

/**
 * @return Annotation
 */
Annotation SearchObject::getAnnotation() {
    return null;
}

/**
 * @param annotation
 */
void SearchObject::setAnnotation(Annotation annotation) {

}

/**
 * @return QRect
 */
QRect SearchObject::getROI() {
    return null;
}

/**
 * @param ROI
 */
void SearchObject::setROI(QRect ROI) {

}

/**
 * @return Dataset
 */
Dataset SearchObject::getSourceDataset() {
    return null;
}

/**
 * @param dataset
 */
void SearchObject::setSourceDataset(Dataset dataset) {

}

/**
 * @return int
 */
int SearchObject::getMediumIndex() {
    return 0;
}

/**
 * @param index
 */
void SearchObject::setMediumIndex(int index) {

}

/**
 * @param out
 * @param searchObject
 * @return QDataStream&
 */
QDataStream& SearchObject::operator<<(QDataStream& out, SearchObject& searchObject) {
    return null;
}

/**
 * @param in
 * @param searchObject
 * @return QDataStream&
 */
QDataStream& SearchObject::operator>>(QDataStream& in, SearchObject& searchObject) {
    return null;
}

/**
 * @param in
 */
void SearchObject::toStream(QDataStream in) {

}

/**
 * @param out
 */
void SearchObject::fromStream(QDataStream out) {

}
