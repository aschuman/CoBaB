/**
 * Project \
 */


#include "SearchResult.h"

/**
 * SearchResult implementation
 */

/**
 * @brief SearchResult::SearchResult
 */
SearchResult::SearchResult() {

}

/**
 * @brief SearchResult::SearchResult
 * @param list
 */
SearchResult::SearchResult(QList<SearchResultElement>* list) {
    mSearchResultElementList = list;
}

/**
 * @brief SearchResult::getSearchResultList
 * @return
 */
QList<SearchResultElement>* SearchResult::getSearchResultList() {
    return mSearchResultElementList;
}

/**
 * @brief SearchResult::sortByScore
 * @return
 */
QList<SearchResultElement>* SearchResult::sortByScore() {

    SearchResultElement element = mSearchResultElementList->first();
    QList<SearchResultElement>* sortedElements = new QList<SearchResultElement>;
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
 * @brief operator <<
 * @param out
 * @param searchResult
 * @return
 */
QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult) {
    out << *(searchResult.mSearchResultElementList);
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param searchResult
 * @return
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    in >> *(searchResult.mSearchResultElementList);
    return in;
}

/**
 * @brief SearchResult::toStream
 * @param in
 */
void SearchResult::toStream(QDataStream in) {
    in << *this;
}

/**
 * @brief SearchResult::fromStream
 * @param out
 */
void SearchResult::fromStream(QDataStream out) {
    out >> *this;
}
