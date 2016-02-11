/**
 * Project \
 */


#include "SearchFeedback.h"

/**
 * SearchFeedback implementation
 */

/**
 * @brief SearchFeedback::SearchFeedback
 */
SearchFeedback::SearchFeedback() {

}

/**
 * @brief SearchFeedback::SearchFeedback
 * @param type
 */
SearchFeedback::SearchFeedback(FeedbackType type) {
    mType = type;
}

/**
 * @brief SearchFeedback::getFeedbackList
 * @return
 */
QList<QPair<SearchObject, int>> SearchFeedback::getFeedbackList() {
    return mFeedbackList;
}

/**
 * @brief SearchFeedback::setFeedbackList
 * @param feedbackList
 */
void SearchFeedback::setFeedbackList(QList<QPair<SearchObject, int>> feedbackList) {
    mFeedbackList = feedbackList;
}

/**
 * @brief SearchFeedback::getFeedbackType
 * @return
 */
FeedbackType SearchFeedback::getFeedbackType() {
    return mType;
}

/**
 * @brief operator <<
 * @param out
 * @param feedback
 * @return
 */
QDataStream& operator<<(QDataStream& out, SearchFeedback& feedback) {
    (void)feedback;
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param feedback
 * @return
 */
QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback) {
    (void)feedback;
    return in;
}

/**
 * @brief SearchFeedback::toStream
 * @param in
 */
void SearchFeedback::toStream(QDataStream in) {
    in << *this;
}

/**
 * @brief SearchFeedback::fromStream
 * @param out
 */
void SearchFeedback::fromStream(QDataStream out) {
    out >> *this;
}
