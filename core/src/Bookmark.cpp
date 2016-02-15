/**
 * Project \
 */


#include "Bookmark.h"

/**
 * Bookmark implementation
 */

/**
 * @brief Bookmark::Bookmark default constructor
 */

Bookmark::Bookmark() {

}

/**
 * @brief Bookmark::Bookmark construct new bookmark
 * @param result search result
 * @param algorithm used algorithm
 * @param query search query
 */
Bookmark::Bookmark(SearchResult result, QString algorithm, SearchQuery query) {
    mSearchResult = result;
    mAlgorithm = algorithm;
    mSearchQuery = query;
}

/**
 * @brief Bookmark::setFeedback set new feedback
 * @param feedback new value
 */
void Bookmark::setFeedback(SearchFeedback feedback) {
	mSearchFeedback = feedback;
}

/**
 * @brief Bookmark::getFeedback get feedback
 * @return feedback
 */
SearchFeedback Bookmark::getFeedback() {
    return mSearchFeedback;
}

/**
 * @brief Bookmark::setName set bookmark name
 * @param name new name
 */
void Bookmark::setName(QString name) {
	mName = name;
}

/**
 * @brief Bookmark::getName get bookmark name
 * @return name
 */
QString Bookmark::getName() {
    return mName;
}

/**
 * @brief Bookmark::getDate get bookmark date
 * @return date
 */
QDateTime Bookmark::getDate() {
    return mDate;
}

/**
 * @brief Bookmark::getAlgorithm get used algorithm
 * @return search algorithm
 */
QString Bookmark::getAlgorithm() {
    return mAlgorithm;
}

/**
 * @brief Bookmark::getSearchQuery get search query
 * @return search query
 */
SearchQuery Bookmark::getSearchQuery() {
    return mSearchQuery;
}

/**
 * @brief Bookmark::getSearchResult get search result
 * @return search result
 */
SearchResult Bookmark::getSearchResult() {
    return mSearchResult;
}

/**
 * @brief Bookmark::getParameter get search parameters (QJsonObject)
 * @return parameters
 */
QJsonObject Bookmark::getParameter() {
    return mParameter;
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
 * @brief calls the << operator
 * @param in - the data stream
 */
void Bookmark::toStream(QDataStream& in) {
    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Bookmark::fromStream(QDataStream& out) {
    out >> *this;
}