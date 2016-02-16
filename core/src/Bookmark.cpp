/**
 * Project \
 */


#include "Bookmark.h"

/**
 * Bookmark implementation
 * @author Tung
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
QString Bookmark::getName() const {
    return mName;
}

/**
 * @brief Bookmark::getDate get bookmark date
 * @return date
 */
QDateTime Bookmark::getDate() const {
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
 * @brief returns true if 2 bookmarks are same (same name)
 * @param A first bookmark
 * @param B second bookmark
 */
bool operator==(const Bookmark& A, const Bookmark& B) {
    return (A.getName().compare(B.getName()) == 0);
}

/**
 * @brief compareByName compares 2 bookmarks by name
 * @param A first bookmark
 * @param B second bookmark
 * @return true if first bookmark is lexicographically smaller than b
 */

bool compareByName(Bookmark A, Bookmark B) {
    return (A.getName().compare(B.getName()) < 0);
}

/**
 * @brief compareByDate compares 2 bookmarks by creation date
 * @param A first bookmark
 * @param B second bookmark
 * @return true if A is created before B
 */
bool compareByDate(Bookmark A, Bookmark B) {
    return (A.getDate() < B.getDate());
}

/**
 * @brief override the operator <<
 * @param out - the datastream
 * @param bookmark data to write
 * @return out - the data stream after write
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
 * @brief override the operator >>
 * @param out - the datastream
 * @param bookmark save new bookmark here
 * @return out - the data stream after read
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
