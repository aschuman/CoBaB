/**
 * Project \
 */


#include "Bookmark.h"

/**
 * Bookmark implementation
 */

/**
 * @brief Bookmark::Bookmark
 */

Bookmark::Bookmark() {

}

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
QDataStream& operator<<(QDataStream& out, const Bookmark& bookmark) {
    //convert mParameter to QString
    QJsonDocument doc(bookmark.mParameter);
    QString parameters(doc.toJson(QJsonDocument::Compact));

    //write to stream
    out << bookmark.mName << bookmark.mDate << bookmark.mAlgorithm
        << bookmark.mSearchQuery << parameters
        << bookmark.mSearchResult << bookmark.mSearchFeedback;

    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param bookmark
 * @return
 */
QDataStream& operator>>(QDataStream& in, Bookmark& bookmark) {
    QString parameters;
    in >> bookmark.mName >> bookmark.mDate >> bookmark.mAlgorithm
       >> bookmark.mSearchQuery >> parameters
       >> bookmark.mSearchResult >> bookmark.mSearchFeedback;

    //create mParameter from parameters-Strings
    QJsonDocument doc = QJsonDocument::fromJson(parameters.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        bookmark.mParameter = doc.object();
    }
    else {
        bookmark.mParameter = QJsonObject();
    }
    return in;
}

/**
 * @brief Bookmark::toStream
 * @param in
 */
void Bookmark::toStream(QDataStream& in) {
	in << *this;
}

/**
 * @brief Bookmark::fromStream
 * @param out
 */
void Bookmark::fromStream(QDataStream& out) {
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
