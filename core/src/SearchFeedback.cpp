/**
 * Project \
 */


#include "SearchFeedback.h"

/**
 * SearchFeedback implementation
 */

SearchFeedback::SearchFeedback() {

}

/**
 * @param type
 */
SearchFeedback::SearchFeedback(FeedbackType type) {
    mType = type;
}

/**
 * @return QList<QPair<SearchObject; int>>
 */
QList<QPair<SearchObject, int>> SearchFeedback::getFeedbackList() {
    return mFeedbackList;
}

/**
 * @param feedbackList
 */
void SearchFeedback::setFeedbackList(QList<QPair<SearchObject, int>> feedbackList) {
    mFeedbackList = feedbackList;
}

/**
 * @return FeedbackType
 */
FeedbackType SearchFeedback::getFeedbackType() {
    return mType;
}

/**
 * @param out
 * @param feedback
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchFeedback& feedback) {
    (void)feedback;
    return out;
}

/**
 * @param in
 * @param feedback
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchFeedback& feedback) {
    (void)feedback;
    return in;
}

/**
 * @param in
 */
void SearchFeedback::toStream(QDataStream in) {
    in << *this;
}

/**
 * @param out
 */
void SearchFeedback::fromStream(QDataStream out) {
    out >> *this;
}
