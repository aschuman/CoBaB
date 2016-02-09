/**
 * Project \
 */


#include "Bookmark.h"

/**
 * Bookmark implementation
 */


/**
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
 * @param out
 * @param bookmark
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, Bookmark& bookmark) {
    (void)bookmark;
    return out;
}

/**
 * @param in
 * @param bookmark
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, Bookmark& bookmark) {
    (void)bookmark;
    return in;
}

/**
 * @param in
 */
void Bookmark::toStream(QDataStream in) {
	in << *this;
}

/**
 * @param out
 */
void Bookmark::fromStream(QDataStream out) {
	out >> *this;
}

/**
 * @param feedback
 */
void Bookmark::setFeedback(SearchFeedback feedback) {
	mSearchFeedback = feedback;
}

/**
 * @return SearchFeedback
 */
SearchFeedback Bookmark::getFeedback() {
    return mSearchFeedback;
}

/**
 * @param name
 */
void Bookmark::setName(QString name) {
	mName = name;
}

/**
 * @return QString
 */
QString Bookmark::getName() {
    return mName;
}

/**
 * @return QDateTime
 */
QDateTime Bookmark::getDate() {
    return mDate;
}

/**
 * @return QString
 */
QString Bookmark::getAlgorithm() {
    return mAlgorithm;
}

/**
 * @return SearchQuery
 */
SearchQuery Bookmark::getSearchQuery() {
    return mSearchQuery;
}

/**
 * @return SearchResult
 */
SearchResult Bookmark::getSearchResult() {
    return mSearchResult;
}

/**
 * @return QJsonObject
 */
QJsonObject Bookmark::getParameter() {
    return mParameter;
}
