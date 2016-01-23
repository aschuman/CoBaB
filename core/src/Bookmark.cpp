/**
 * Project \
 */


#include "CoBaB.h"

/**
 * Bookmark implementation
 */


/**
 * @param result
 * @param algorithm
 * @param query
 */
Bookmark::Bookmark(SearchResult result, QString algorithm, SearchQuery query) {

}

/**
 * @param out
 * @param bookmark
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, Bookmark& bookmark) {
    return null;
}

/**
 * @param in
 * @param bookmark
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, Bookmark& bookmark) {
    return null;
}

/**
 * @param in
 */
void Bookmark::toStream(QDataStream in) {

}

/**
 * @param out
 */
void Bookmark::fromStream(QDataStream out) {

}

/**
 * @param feedback
 */
void Bookmark::setFeedback(SearchFeedback feedback) {

}

/**
 * @return SearchFeedback
 */
SearchFeedback Bookmark::getFeedback() {
    return null;
}

/**
 * @param name
 */
void Bookmark::setName(QString name) {

}

/**
 * @return QString
 */
QString Bookmark::getName() {
    return null;
}

/**
 * @return QDateTime
 */
QDateTime Bookmark::getDate() {
    return null;
}

/**
 * @return QString
 */
QString Bookmark::getAlgorithm() {
    return null;
}

/**
 * @return SearchQuery
 */
SearchQuery Bookmark::getSearchQuery() {
    return null;
}

/**
 * @return SearchResult
 */
SearchResult Bookmark::getSearchResult() {
    return null;
}

/**
 * @return QJsonObject
 */
QJsonObject Bookmark::getParameter() {
    return null;
}
