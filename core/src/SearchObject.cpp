#include "SearchObject.h"
/**
 * @brief SearchObject::SearchObject
 */
SearchObject::SearchObject() {

}
/**
 * @brief SearchObject::getMedium
 * @return
 */
QString SearchObject::getMedium() {
    return mMedium;
}
/**
 * @brief SearchObject::setMedium
 * @param medium
 */
void SearchObject::setMedium(QString medium) {
    mMedium = medium;
}
/**
 * @brief SearchObject::getAnnotation
 * @return
 */
Annotation* SearchObject::getAnnotation() {
    return mAnnotation;
}
/**
 * @brief SearchObject::setAnnotation
 * @param annotation
 */
void SearchObject::setAnnotation(Annotation* annotation) {
    mAnnotation = annotation;
}
/**
 * @brief SearchObject::getROI
 * @return
 */
QRect* SearchObject::getROI() {
    return mROI;
}

void SearchObject::setROI(QRect* roi) {
    mROI = roi;
}
/**
 * @brief SearchObject::getSourceDataset
 * @return
 */
QString SearchObject::getSourceDataset() {
    return mSourceDataset;
}
/**
 * @brief SearchObject::setSourceDataset
 * @param dataset
 */
void SearchObject::setSourceDataset(QString dataset) {
    mSourceDataset = dataset;
}
/**
 * @brief SearchObject::getMediumIndex
 * @return
 */
int SearchObject::getMediumIndex() {
    return mMediumIndex;
}
/**
 * @brief SearchObject::setMediumIndex
 * @param index
 */
void SearchObject::setMediumIndex(int index) {
    mMediumIndex = index;
}
/**
 * @brief SearchObject::toStream
 * @param in
 */
void SearchObject::toStream(QDataStream in) {

    in << *this;

}
/**
 * @brief SearchObject::fromStream
 * @param out
 */
void SearchObject::fromStream(QDataStream out) {

    out >> *this;

}
/**
 * @brief operator >>
 * @param in
 * @param searchObject
 * @return
 */
QDataStream& operator >>(QDataStream& in, SearchObject& searchObject) {

    //read object from stream

    QString medium;
    int mediumIndex;
    Annotation* ann = new Annotation("", "");
    QRect* roi = new QRect();
    QString source;

    //skip opening bracket
    in.skipRawData(1);

    in >> medium;
    searchObject.setMedium(medium);

    //skip coma
    in.skipRawData(2);

    in >> mediumIndex;
    searchObject.setMediumIndex(mediumIndex);

    in.skipRawData(2);

    in >> *ann;
    searchObject.setAnnotation(ann);

    in.skipRawData(2);

    in >> *roi;
    searchObject.setROI(roi);

    in.skipRawData(2);

    in >> source;
    searchObject.setSourceDataset(source);

    in.skipRawData(1);

    return in;
}
/**
 * @brief operator <<
 * @param out
 * @param searchObject
 * @return
 */
QDataStream& operator <<(QDataStream& out, const SearchObject& searchObject) {

    //write object to stream
    out << "(" << searchObject.mMedium << ", "
        << searchObject.mMediumIndex << ", "
        << searchObject.mAnnotation << ", "
        << searchObject.mROI << ", "
        << searchObject.mSourceDataset << ")";
    return out;
}

