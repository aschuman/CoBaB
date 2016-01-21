/**
 * Project \
 */


#include "SearchFeedback.h"

/**
 * SearchFeedback implementation
 */


/**
 * @param type
 */
void SearchFeedback::SearchFeedback(FeedbackType type) {

}

/**
 * @return QList<QPair<SearchObject; int>>
 */
QList<QPair<SearchObject; int>> SearchFeedback::getFeedbackList() {
    return null;
}

/**
 * @param feedbackList
 */
void SearchFeedback::setFeedbackList(QList<QPair<SearchObject; int>> feedbackList) {

}

/**
 * @return FeedbackType
 */
FeedbackType SearchFeedback::getFeedbackType() {
    return null;
}

/**
 * @param out
 * @param feedback
 * @return QDataStream&
 */
QDataStream& SearchFeedback::operator<<(QDataStream& out, Feedback& feedback) {
    return null;
}

/**
 * @param in
 * @param feedback
 * @return QDataStream&
 */
QDataStream& SearchFeedback::operator>>(QDataStream& in, Feedback& feedback) {
    return null;
}

/**
 * @param in
 */
void SearchFeedback::toStream(QDataStream in) {

}

/**
 * @param out
 */
void SearchFeedback::fromStream(QDataStream out) {

}