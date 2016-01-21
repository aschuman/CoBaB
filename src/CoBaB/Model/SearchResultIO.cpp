/**
 * Project \
 */


#include "SearchResultIO.h"

/**
 * SearchResultIO implementation
 */


/**
 * @param name
 * @return SearchResult
 */
virtual SearchResult SearchResultIO::loadSearchResult(QString name) {
    return null;
}

/**
 * @param searchResult
 */
virtual void SearchResultIO::storeSearchResult(SearchResult searchResult) {

}

void SearchResultIO::sortByName() {

}

void SearchResultIO::sortByDate() {

}

/**
 * @return QList<SearchResult>
 */
QList<SearchResult> SearchResultIO::getSearchResultList() {
    return null;
}

/**
 * @param searchResult
 */
void SearchResultIO::operator<<(SearchResult searchResult) {

}

/**
 * @return SearchResult
 */
SearchResult SearchResultIO::operator>>() {
    return null;
}

/**
 * @param searchResult
 */
void SearchResultIO::validateResult(SearchResult searchResult) {

}