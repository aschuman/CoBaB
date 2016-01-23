/**
 * Project \
 */


#include "CoBaB.h"

/**
 * SearchResult implementation
 */


/**
 * @param list
 */
SearchResult::SearchResult(QList<SearchResultElement> list) {

}

/**
 * @return QList<SearchResultElement>
 */
QList<SearchResultElement> SearchResult::getSearchResultList() {
    return null;
}

/**
 * @return QList<SearchResultElement>
 */
QList<SearchResultElement> SearchResult::sortByScore() {
    return null;
}

/**
 * @param out
 * @param searchResult
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchResult& searchResult) {
    return null;
}

/**
 * @param in
 * @param searchResult
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    return null;
}

/**
 * @param in
 */
void SearchResult::toStream(QDataStream in) {

}

/**
 * @param out
 */
void SearchResult::fromStream(QDataStream out) {

}
