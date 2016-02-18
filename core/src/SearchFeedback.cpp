#include "SearchFeedback.h"

/**
 * @brief SearchFeedback::SearchFeedback default constructor
 */
SearchFeedback::SearchFeedback() {

}

/**
 * @brief SearchFeedback::SearchFeedback create new feedback with given type
 * @param type feedback type
 */
SearchFeedback::SearchFeedback(QString type) {
    mType = type;
}

/**
 * @brief SearchFeedback::getFeedbackList get the list of feedbacks
 * @return feedback list
 */
QList<QPair<SearchObject, int>> SearchFeedback::getFeedbackList() const {
    return mFeedbackList;
}

/**
 * @brief SearchFeedback::setFeedbackList set the list of feedbaks
 * @param feedbackList new list
 */
void SearchFeedback::setFeedbackList(QList<QPair<SearchObject, int>> feedbackList) {
    mFeedbackList = feedbackList;
}

/**
 * @brief SearchFeedback::getFeedbackType gets type of all feedbacks in this list
 * @return feedback type
 */
SearchFeedback::Type SearchFeedback::getType() const {
    return (mType == "Dual") ? DUAL : EXTENDED;
}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param feedback data to write
 * @return out - the data stream after write
 */
QDataStream& operator<<(QDataStream& out, const SearchFeedback& feedback) {
    feedback.toStream(out);
    return out;
}

/**
 * @brief override the operator >>
 * @param out - the datastream
 * @param feedback save new feedback here
 * @return out - the data stream after read
 */
QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback) {
    feedback.fromStream(in);
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void SearchFeedback::toStream(QDataStream& out) const {
    DataPacket::toStream(out);
    out << mType << mFeedbackList;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void SearchFeedback::fromStream(QDataStream& in) {
    DataPacket::fromStream(in);
    in >> mType >> mFeedbackList;
}
