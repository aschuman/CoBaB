#include "SearchObject.h"

/**
 * @brief SearchObject::SearchObject
 */
SearchObject::SearchObject() : mAnnotation(nullptr) {

    mMedium = "";

    mSourceDataset = "";

    mMediumIndex = 0;
    mFrameIndex = 0;
}

/**
 * @brief SearchObject::SearchObject
 * @param other
 */
SearchObject::SearchObject(const SearchObject& other) {
    mMedium = other.getMedium();
    mROI = other.getROI();
    mSourceDataset = other.getSourceDataset();
    mMediumIndex = other.getMediumIndex();
    mFrameIndex = other.getFrameIndex();
    mType = other.getType();
    setAnnotation(other.getAnnotation());
}

/**
 * @brief SearchObject::SearchObject
 * @param other
 */
SearchObject::SearchObject(SearchObject &&other)
    : mMedium(std::move(other.mMedium)),
      mROI(std::move(other.mROI)),
      mSourceDataset(std::move(other.mSourceDataset)),
      mMediumIndex(std::move(other.mMediumIndex)),
      mFrameIndex(std::move(other.mFrameIndex)),
      mType(std::move(other.mType)),
      mAnnotation(std::move(other.mAnnotation)) {

    other.mAnnotation = nullptr;
}

/**
 * @brief SearchObject::operator =
 * @param other
 * @return
 */
SearchObject& SearchObject::operator=(const SearchObject &other) {
    mMedium = other.mMedium;
    mROI = other.mROI;
    mSourceDataset = other.mSourceDataset;
    mMediumIndex = other.mMediumIndex;
    mFrameIndex = other.mFrameIndex;
    mType = other.mType;
    setAnnotation(other.mAnnotation);
    return *this;
}

/**
 * @brief SearchObject::operator =
 * @param other
 * @return
 */
SearchObject& SearchObject::operator=(SearchObject &&other) {
    mMedium = std::move(other.mMedium);
    mROI = std::move(other.mROI);
    mSourceDataset = std::move(other.mSourceDataset);
    mMediumIndex = std::move(other.mMediumIndex);
    mFrameIndex = std::move(other.mFrameIndex);
    mType = std::move(other.mType);
    mAnnotation = std::move(other.mAnnotation);
    other.mAnnotation = nullptr;
    return *this;
}

/**
 * @brief SearchObject::~SearchObject
 */
SearchObject::~SearchObject() {
    delete mAnnotation;
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
Annotation* SearchObject::getAnnotation() const {
    return mAnnotation;
}
/**
 * @brief sets the annotation
 * @param annotation to be set
 */
void SearchObject::setAnnotation(const Annotation* annotation) {
    if(annotation == nullptr) {
        mAnnotation = nullptr;
    } else {
        mAnnotation = annotation->copy();
        mType = SearchObject::Type::ANNOTATION;
    }
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
 * @brief gets the frame in the medium
 * @return the index
 */
int SearchObject::getFrameIndex() const {
    return mFrameIndex;
}
/**
 * @brief sets the frame in the medium
 * @param index to be set
 */
void SearchObject::setFrameIndex(const int index) {
    mFrameIndex = index;
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
 * @brief SearchObject::setType sets the type of the searchobject to type
 * @param type
 */
void SearchObject::setType(const Type type) {
    mType = type;
}
/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchObject::toStream(QDataStream& out) const {

    //write object to stream

    out << mMedium
        << mMediumIndex
        << mFrameIndex;
    if(mAnnotation != nullptr) {
        out << mAnnotation->getForm()
            << *mAnnotation;
    } else {
        out << Annotation::Form::NONE;
    }
    out << mROI
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
    in >> mFrameIndex;
    Annotation::Form form;
    in >> (quint32&)form;
    switch(form) {
        case Annotation::Form::UNKNOWN_FORM:
            {
                Annotation temp;
                in >> temp;
                mAnnotation = temp.copy();
            }
            break;
        case Annotation::Form::RECTANGLE:
            {
                RectangleAnnotation temp("","");
                in >> temp;
                mAnnotation = temp.copy();
            }
            break;
        case Annotation::Form::NONE:
        default:
            mAnnotation = nullptr;
            break;
    }
    in >> mROI;
    in >> mSourceDataset;
}

/**
 * @brief operator <<
 * @param out
 * @param searchObject
 * @return
 */
QDataStream& operator<<(QDataStream& out, const SearchObject& searchObject) {
    searchObject.toStream(out);
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param searchObject
 * @return
 */
QDataStream& operator>>(QDataStream& in, SearchObject& searchObject) {
    searchObject.fromStream(in);
    return in;
}

