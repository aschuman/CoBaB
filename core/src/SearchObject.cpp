#include "CoBaB.h"

SearchObject::SearchObject() {

}

QString SearchObject::getMedium() {
    return mMedium;
}

void SearchObject::setMedium(QString medium) {
    mMedium = medium;
}

Annotation *SearchObject::getAnnotation() {
    return mAnnotation;
}

void SearchObject::setAnnotation(Annotation *annotation) {
    mAnnotation = annotation;
}

QRect *SearchObject::getROI() {
    return mROI;
}

void SearchObject::setROI(QRect *roi) {
    mROI = roi;
}

QString SearchObject::getSourceDataset() {
    return mSourceDataset;
}

void SearchObject::setSourceDataset(QString dataset) {
    mSourceDataset = dataset;
}

int SearchObject::getMediumIndex() {
    return mMediumIndex;
}

void SearchObject::setMediumIndex(int index) {
    mMediumIndex = index;
}

void SearchObject::toStream(QDataStream in) {

    in << *this;

}

void SearchObject::fromStream(QDataStream out) {

    out >> *this;

}

QDataStream& operator >>(QDataStream &in, SearchObject &searchObject) {

    //read object from stream

    QString medium;
    int mediumIndex;
    Annotation *ann = new Annotation("", "");
    QRect *roi;
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

QDataStream& operator <<(QDataStream &out, SearchObject &searchObject) {

    //write object to stream
    out << "(" << searchObject.getMedium() << ", "
        << searchObject.getMediumIndex() << ", "
        << searchObject.getAnnotation() << ", "
        << searchObject.getROI() << ", "
        << searchObject.getSourceDataset() << ")";
    return out;
}

