#include "SearchObject.h"

SearchObject::SearchObject() {

    mMedium = "";

    mSourceDataset = "";

    mMediumIndex = 0;

}
/**
 * @brief gets the medium
 * @return the medium
 */
QString SearchObject::getMedium() const {
    return mMedium;
}
/**
 * @brief sets the medium
 * @param medium to be set
 */
void SearchObject::setMedium(const QString medium) {
    mMedium = medium;
}
/**
 * @brief gets the annotation
 * @return the annotation
 */
Annotation SearchObject::getAnnotation() const {
    return mAnnotation;
}
/**
 * @brief sets the annotation
 * @param annotation to be set
 */
void SearchObject::setAnnotation(const Annotation annotation) {
    mAnnotation = annotation;
}
/**
 * @brief gets the region of interest
 * @return the region of interest
 */
QRect SearchObject::getROI() const {
    return mROI;
}
/**
 * @brief sets the region of interest
 * @param roi - the region of interest
 */
void SearchObject::setROI(const QRect roi) {
    mROI = roi;
}
/**
 * @brief gets the source dataset
 * @return the source dataset
 */
QString SearchObject::getSourceDataset() const {
    return mSourceDataset;
}
/**
 * @brief sets the souce dataset
 * @param dataset to be set as source
 */
void SearchObject::setSourceDataset(const QString dataset) {
    mSourceDataset = dataset;
}
/**
 * @brief gets the index of the medium
 * @return the index
 */
int SearchObject::getMediumIndex() const {
    return mMediumIndex;
}
/**
 * @brief sets the index of the medium
 * @param index to be set
 */
void SearchObject::setMediumIndex(const int index) {
    mMediumIndex = index;
}
/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchObject::toStream(QDataStream& in) const {

    //write object to stream

    in  << mMedium
        << mMediumIndex
        << mAnnotation
        << mROI
        << mSourceDataset;

   // in << *this;

}
/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchObject::fromStream(QDataStream& out) {

    //read object from stream
    out >> mMedium;
    out >> mMediumIndex;
    out >> mAnnotation;
    out >> mROI;
    out >> mSourceDataset;

}

QDataStream& operator<<(QDataStream& in, const SearchObject& searchObject) {
    searchObject.toStream(in);
    return in;
}

QDataStream& operator>>(QDataStream& out, SearchObject& searchObject) {
    searchObject.fromStream(out);
    return out;
}

