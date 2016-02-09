/**
 * Project \
 */


#include "SearchResult.h"

/**
 * SearchResult implementation
 */

SearchResult::SearchResult() {

}

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
QList<SearchResultElement> * SearchResult::sortByScore() {

    SearchResultElement element = mSearchResultElementList->first();
    QList<SearchResultElement> *sortedElements = new QList<SearchResultElement>;
    QListIterator<SearchResultElement> it(*mSearchResultElementList);

    for (int i = 0; i < mSearchResultElementList->size(); i++) {
        int j = 0;
        for (int i = 0; i < mSearchResultElementList->size() - 1; i++) {
            j = i;
            if(element.getScore() > mSearchResultElementList->takeAt(i + 1).getScore()) {
                element = mSearchResultElementList->takeAt(i + 1);
                j = i + 1;
            }
        }

        mSearchResultElementList->removeAt(j);
        sortedElements->push_back(element);
        element = mSearchResultElementList->first();
    }

    return sortedElements;
}

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
