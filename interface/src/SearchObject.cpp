#include "SearchObject.h"

/**
 * @brief SearchObject::SearchObject Constructs a default searchobject.
 */
SearchObject::SearchObject() : mAnnotation(nullptr) {

    mMedium = "";

    mSourceDataset = "";

    mMediumIndex = 0;
    mFrameIndex = 0;
}

/**
 * @brief SearchObject::SearchObject Copies a searchobject.
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
 * @brief SearchObject::SearchObject Copies a searchobject.
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
 * @brief SearchObject::operator = Overrides the operator =.
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
 * @brief SearchObject::operator = Overrides the operator =.
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
 * @brief SearchObject::~SearchObject Destructs a searchobject.
 */
SearchObject::~SearchObject() {
    delete mAnnotation;
}

/**
 * @brief SearchObject::getMedium Gets the medium.
 * @return the medium
 */
QString SearchObject::getMedium() const {
    return mMedium;
}

/**
 * @brief SearchObject::setMedium Sets the medium.
 * @param medium to be set
 */
void SearchObject::setMedium(const QString medium) {
    mMedium = medium;
    mType = SearchObject::Type::MEDIUM;

}

/**
 * @brief SearchObject::getAnnotation Gets the annotation.
 * @return the annotation
 */
Annotation* SearchObject::getAnnotation() const {
    return mAnnotation;
}

/**
 * @brief SearchObject::setAnnotation Sets the annotation.
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
 * @brief SearchObject::getROI Gets the region of interest.
 * @return the region of interest
 */
QRect SearchObject::getROI() const {
    return mROI;
}

/**
 * @brief SearchObject::setROI Sets the region of interest.
 * @param roi the region of interest
 */
void SearchObject::setROI(const QRect roi) {
    mROI = roi;
    mType = SearchObject::Type::ROI;
}

/**
 * @brief SearchObject::getSourceDataset Gets the source dataset.
 * @return the source dataset
 */
QString SearchObject::getSourceDataset() const {
    return mSourceDataset;
}

/**
 * @brief SearchObject::setSourceDataset Sets the souce dataset.
 * @param dataset to be set as source
 */
void SearchObject::setSourceDataset(const QString dataset) {
    mSourceDataset = dataset;
}

/**
 * @brief SearchObject::getFrameIndex Gets the frame in the medium.
 * @return the index
 */
int SearchObject::getFrameIndex() const {
    return mFrameIndex;
}

/**
 * @brief SearchObject::setFrameIndex Sets the frame in the medium.
 * @param index the frame
 */
void SearchObject::setFrameIndex(const int index) {
    mFrameIndex = index;
}

/**
 * @brief SearchObject::getMediumIndex Gets the index of the medium.
 * @return the index
 */
int SearchObject::getMediumIndex() const {
    return mMediumIndex;
}

/**
 * @brief SearchObject::setMediumIndex Sets the index of the medium.
 * @param index to be set
 */
void SearchObject::setMediumIndex(const int index) {
    mMediumIndex = index;
}

/**
 * @brief SearchObject::getType Gets the type of the searchobject.
 * @return the type
 */
SearchObject::Type SearchObject::getType() const {
    return mType;
}

/**
 * @brief SearchObject::setType Sets the type of the searchobject to type.
 * @param type
 */
void SearchObject::setType(const Type type) {
    mType = type;
}

/**
 * @brief SearchObject::toStream Calls the << operator and writes the searchobject to stream..
 * @param out the datastream
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
 * @brief SearchObject::fromStream Calls the >> operator and calls the searchobject from stream.
 * @param in the datastream
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
 * @brief operator << Overrides the operator <<.
 * @param out the datastream
 * @param searchObject to be written
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchObject& searchObject) {
    searchObject.toStream(out);
    return out;
}

/**
 * @brief operator >> Overrides the operator >>.
 * @param in the datastream
 * @param searchObject to be read
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchObject& searchObject) {
    searchObject.fromStream(in);
    return in;
}

