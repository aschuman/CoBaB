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
SearchResult::SearchResult(QList<SearchResultElement> *list) {
    mSearchResultElementList = list;
}

/**
 * @return QList<SearchResultElement>
 */
QList<SearchResultElement> * SearchResult::getSearchResultList() {
    return mSearchResultElementList;
}

/**
 * @return QList<SearchResultElement>
 */
/*QList<SearchResultElement> SearchResult::sortByScore() {
    return ;
}*/

/**
 * @param out
 * @param searchResult
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchResult& searchResult) {
    return out;
}

/**
 * @param in
 * @param searchResult
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    return in;
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
