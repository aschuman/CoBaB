#include "Bookmark.h"

/**
 * @brief Bookmark::Bookmark default constructor
 */

Bookmark::Bookmark() {
    mName = "new bookmark";
}

/**
 * @brief Bookmark::Bookmark load bookmark from a file
 * @param path absolute file path
 */
Bookmark::Bookmark(const QString& path) {
    mPath = path;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> *this;
    file.close();
}

/**
 * @brief Bookmark::Bookmark construct new bookmark
 * @param result search result
 * @param algorithm used algorithm
 * @param query search query
 */
Bookmark::Bookmark(const SearchResult& result, const QString& algorithm, const SearchQuery& query) {
    mSearchResult = result;
    mAlgorithm = algorithm;
    mSearchQuery = query;
}

/**
 * @brief Bookmark::setName set bookmark name
 * @param name new name
 */
void Bookmark::setName(const QString& name) {
    mName = name;
}

/**
 * @brief Bookmark::setDate set bookmark date
 * @param date new date
 */
void Bookmark::setDate(const QDateTime& date) {
    mDate = date;
}

/**
 * @brief Bookmark::setFeedback set new feedback
 * @param feedback new value
 */
void Bookmark::setFeedback(const SearchFeedback& feedback) {
	mSearchFeedback = feedback;
}

/**
 * @brief setParameter set the parameters
 * @param parameter new parameters
 */

void Bookmark::setParameter(const QJsonObject& parameter) {
    mParameter = parameter;
}

/**
 * @brief Bookmark::setPath set the absolute path
 * @param path new absolute path
 */
void Bookmark::setPath(const QString &path) {
    mPath = path;
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
QString Bookmark::getAlgorithm() const {
    return mAlgorithm;
}

/**
 * @brief Bookmark::getSearchQuery get search query
 * @return search query
 */
const SearchQuery& Bookmark::getSearchQuery() const {
    return mSearchQuery;
}

/**
 * @brief Bookmark::getParameter get search parameters (QJsonObject)
 * @return parameters
 */
QJsonObject Bookmark::getParameter() const {
    return mParameter;
}

/**
 * @brief Bookmark::getSearchResult get search result
 * @return search result
 */
const SearchResult& Bookmark::getSearchResult() const {
    return mSearchResult;
}

/**
 * @brief Bookmark::getFeedback get feedback
 * @return feedback
 */
const SearchFeedback& Bookmark::getFeedback() const {
    return mSearchFeedback;
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

bool Bookmark::smallerByName(const Bookmark& A, const Bookmark& B) {
    return (A.getName().compare(B.getName()) < 0);
}

/**
 * @brief compareByDate compares 2 bookmarks by creation date
 * @param A first bookmark
 * @param B second bookmark
 * @return true if A is created before B
 */
bool Bookmark::smallerByDate(const Bookmark& A, const Bookmark& B) {
    return (A.getDate() < B.getDate());
}

/**
 * @brief Bookmark::validate check if a bookmark is valid, i.e all the datasets are available
 * @param bookmark to be checked
 * @return {@code true} if bookmark is valid, {@code false} otherwise
 */
bool Bookmark::validate(const Bookmark& bookmark) {
    QList<QString> datasetPaths = bookmark.getSearchQuery().getDatasets();
    QDir dir;
    for (QString& path : datasetPaths) {
        dir.setPath(path);
        if (!dir.exists()) {    //dataset not exist
            return false;
        }
    }
    return true;
}

/**
 * @brief save save bookmark to file
 * @param path absolute file path
 */
void Bookmark::saveFile() const {
    QFile file(mPath);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << *this;
    file.close();
}

/**
 * @brief Bookmark::deleteFile
 */
void Bookmark::deleteFile() const {
    QFile file(mPath);
    file.remove();
}

///**
// * @brief override the operator <<
// * @param out - the datastream
// * @param bookmark data to write
// * @return out - the data stream after write
// */
//QDataStream& operator<<(QDataStream& out, const Bookmark& bookmark) {
//    bookmark.toStream(out);
//    return out;
//}

///**
// * @brief override the operator >>
// * @param out - the datastream
// * @param bookmark save new bookmark here
// * @return out - the data stream after read
// */
//QDataStream& operator>>(QDataStream& in, Bookmark& bookmark) {
//    bookmark.fromStream(in);
//    return in;
//}

/**
 * @brief calls the << operator
 * @param in - the data stream
 */
void Bookmark::toStream(QDataStream& out) const {
    //convert mParameter to QString
    QJsonDocument doc(mParameter);
    QString parameters(doc.toJson(QJsonDocument::Compact));

    //write to stream
    out << mName << mDate << mAlgorithm
        << mSearchQuery << parameters
        << mSearchResult << mSearchFeedback;

}

/**
 * @brief calls the >> operator
 * @param out - the data stream
 */
void Bookmark::fromStream(QDataStream& in) {
    QString parameters;
    in >> mName >> mDate >> mAlgorithm
       >> mSearchQuery >> parameters
       >> mSearchResult >> mSearchFeedback;

    //create mParameter from parameters-Strings
    QJsonDocument doc = QJsonDocument::fromJson(parameters.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        mParameter = doc.object();
    }
    else {
        mParameter = QJsonObject();
    }
}
