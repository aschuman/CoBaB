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
    mType = SearchObject::Type::MEDIUM;

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
    mType = SearchObject::Type::ANNOTATION;
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
    mType = SearchObject::Type::ROI;
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
 * @brief gets the type of the searchobject
 * @return the type
 */
SearchObject::Type SearchObject::getType() const {
    return mType;
}
/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchObject::toStream(QDataStream& out) const {

    //write object to stream

    out << mMedium
        << mMediumIndex
        << mAnnotation
        << mROI
        << mSourceDataset;

}
/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchObject::fromStream(QDataStream& in) {

    //read object from stream
    in >> mMedium;
    in >> mMediumIndex;
    in >> mAnnotation;
    in >> mROI;
    in >> mSourceDataset;

}

//QDataStream& operator<<(QDataStream& out, const SearchObject& searchObject) {
//    searchObject.toStream(out);
//    return out;
//}

//QDataStream& operator>>(QDataStream& in, SearchObject& searchObject) {
//    searchObject.fromStream(in);
//    return in;
//}

