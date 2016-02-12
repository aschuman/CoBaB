#include "SearchObject.h"
/**
 * @brief SearchObject::SearchObject
 * @author Georgi
 */
SearchObject::SearchObject() {

}
/**
 * @brief gets the medium
 * @return the medium
 */
QString SearchObject::getMedium() {
    return mMedium;
}
/**
 * @brief sets the medium
 * @param medium to be set
 */
void SearchObject::setMedium(QString medium) {
    mMedium = medium;
}
/**
 * @brief gets the annotation
 * @return the annotation
 */
Annotation* SearchObject::getAnnotation() {
    return mAnnotation;
}
/**
 * @brief sets the annotation
 * @param annotation to be set
 */
void SearchObject::setAnnotation(Annotation* annotation) {
    mAnnotation = annotation;
}
/**
 * @brief gets the region of interest
 * @return the region of interest
 */
QRect* SearchObject::getROI() {
    return mROI;
}
/**
 * @brief sets the region of interest
 * @param roi - the region of interest
 */
void SearchObject::setROI(QRect* roi) {
    mROI = roi;
}
/**
 * @brief gets the source dataset
 * @return the source dataset
 */
QString SearchObject::getSourceDataset() {
    return mSourceDataset;
}
/**
 * @brief sets the souce dataset
 * @param dataset to be set as source
 */
void SearchObject::setSourceDataset(QString dataset) {
    mSourceDataset = dataset;
}
/**
 * @brief gets the index of the medium
 * @return the index
 */
int SearchObject::getMediumIndex() {
    return mMediumIndex;
}
/**
 * @brief sets the index of the medium
 * @param index to be set
 */
void SearchObject::setMediumIndex(int index) {
    mMediumIndex = index;
}
/**
 * @brief calls the << operator
 * @param in - the datastream
 */
void SearchObject::toStream(QDataStream in) {

    in << *this;

}
/**
 * @brief calls the >> operator
 * @param out - the datastream
 */
void SearchObject::fromStream(QDataStream out) {

    out >> *this;

}
/**
 * @brief override >> the operator
 * @param in - the datastream
 * @param searchObject to be changed
 * @return in - the datastream
 */
QDataStream& operator >>(QDataStream& in, SearchObject& searchObject) {

    //read object from stream

    QString medium;
    int mediumIndex;
    Annotation* ann = new Annotation("", "");
    QRect* roi = new QRect();
    QString source;


    in >> medium;
    searchObject.setMedium(medium);


    in >> mediumIndex;
    searchObject.setMediumIndex(mediumIndex);


    in >> *ann;
    searchObject.setAnnotation(ann);


    in >> *roi;
    searchObject.setROI(roi);


    in >> source;
    searchObject.setSourceDataset(source);


    return in;
}
/**
 * @brief override << the operator
 * @param out - the datastream
 * @param searchObject whose data will be sent
 * @return out - the datastream
 */
QDataStream& operator <<(QDataStream& out, const SearchObject& searchObject) {

    //write object to stream
    out << searchObject.mMedium
        << searchObject.mMediumIndex
        << searchObject.mAnnotation
        << searchObject.mROI
        << searchObject.mSourceDataset;
    return out;
}

