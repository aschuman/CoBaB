#include "CoBaB.h"
#include <iostream>
#include <fstream>

SearchObject::SearchObject() {

}

QString SearchObject::getMedium() {
    return mMedium;
}

void SearchObject::setMedium(QString medium) {
    mMedium = medium;
}

Annotation SearchObject::getAnnotation() {
    return mAnnotation;
}

void SearchObject::setAnnotation(Annotation annotation) {
    mAnnotation = annotation;
}

QRect SearchObject::getROI() {
    return mROI;
}

void SearchObject::setROI(QRect roi) {
    mROI = roi;
}

Dataset SearchObject::getSourceDataset() {
    return mSourceDataset;
}

void SearchObject::setSourceDataset(Dataset dataset) {
    mSourceDataset = dataset;
}

int SearchObject::getMediumIndex() {
    return mMediumIndex;
}

void SearchObject::setMediumIndex(int index) {
    mMediumIndex = index;
}

void SearchObject::toStream(QDataStream in) {

}

void SearchObject::fromStream(QDataStream out) {

}

friend QDataStream& operator >>(QDataStream &in, SearchObject &searchObject) {

    //read object from stream

    Medium medium;
    int mediumIndex;
    Annotation ann;
    QRect roi;
    Dataset source;

    //skip opening bracket
    in.ignore(1);

    in >> medium;
    searchObject.setMedium(medium);

    //skip coma
    in.ignore(2);

    in >> mediumIndex;
    searchObject.setMediumIndex(mediumIndex);

    in.ignore(2);

    in >> ann;
    searchObject.setAnnotation(ann);

    in.ignore(2);

    in >> roi;
    searchObject.setROI(roi);

    in.ignore(2);

    in >> source;
    searchObject.setSourceDataset(source);

    in.ignore(1);

    return in;
}

friend QDataStream& operator <<(QDataStream &out, const SearchObject &searchObject) {

    //write object to stream
    out << "(" << searchObject.getMedium() << ", "
        << searchObject.getMediumIndex() << ", "
        << searchObject.getAnnotation() << ", "
        << searchObject.getROI() << ", "
        << searchObject.getSourceDataset() << ")";
    return out;
}
