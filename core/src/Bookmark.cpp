/**
 * Project \
 */


#include "Bookmark.h"

/**
 * Bookmark implementation
 */


/**
 * @brief Bookmark::Bookmark
 * @param result
 * @param algorithm
 * @param query
 */
Bookmark::Bookmark(SearchResult result, QString algorithm, SearchQuery query) {
    mSearchResult = result;
    mAlgorithm = algorithm;
    mSearchQuery = query;
}

/**
 * @brief operator <<
 * @param out
 * @param bookmark
 * @return
 */
QDataStream& operator<<(QDataStream& out, Bookmark& bookmark) {
    (void)bookmark;
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param bookmark
 * @return
 */
QDataStream& operator>>(QDataStream& in, Bookmark& bookmark) {
    (void)bookmark;
    return in;
}

/**
 * @brief Bookmark::toStream
 * @param in
 */
void Bookmark::toStream(QDataStream in) {
	in << *this;
}

/**
 * @brief Bookmark::fromStream
 * @param out
 */
void Bookmark::fromStream(QDataStream out) {
	out >> *this;
}

/**
 * @brief Bookmark::setFeedback
 * @param feedback
 */
void Bookmark::setFeedback(SearchFeedback feedback) {
	mSearchFeedback = feedback;
}

/**
 * @brief Bookmark::getFeedback
 * @return
 */
SearchFeedback Bookmark::getFeedback() {
    return mSearchFeedback;
}

/**
 * @brief Bookmark::setName
 * @param name
 */
void Bookmark::setName(QString name) {
	mName = name;
}

/**
 * @brief Bookmark::getName
 * @return
 */
QString Bookmark::getName() {
    return mName;
}

/**
 * @brief Bookmark::getDate
 * @return
 */
QDateTime Bookmark::getDate() {
    return mDate;
}

/**
 * @brief Bookmark::getAlgorithm
 * @return
 */
QString Bookmark::getAlgorithm() {
    return mAlgorithm;
}

/**
 * @brief Bookmark::getSearchQuery
 * @return
 */
SearchQuery Bookmark::getSearchQuery() {
    return mSearchQuery;
}

/**
 * @brief Bookmark::getSearchResult
 * @return
 */
SearchResult Bookmark::getSearchResult() {
    return mSearchResult;
}

/**
 * @brief Bookmark::getParameter
 * @return
 */
QJsonObject Bookmark::getParameter() {
    return mParameter;
}
