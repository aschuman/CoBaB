/**
 * Project \
 */


#include "SearchResult.h"

/**
 * SearchResult implementation
 */

/**
 * @brief SearchResult::SearchResult
 * @author Violina
 */
SearchResult::SearchResult() {

    mType = Type::SEARCHRESULT;
}

/**
 * @brief a constructor for the class
 * @param list of SearchResultElements
 */
SearchResult::SearchResult(QList<SearchResultElement>* list) {
    mSearchResultElementList = list;
}

/**
 * @brief gets the list of SearchResultElements
 * @return the list of SearchResultElements
 */
QList<SearchResultElement>* SearchResult::getSearchResultList() {
    return mSearchResultElementList;
}

/**
 * @brief sorts the SearchResultElements by score
 * @return the sorted list
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
 * @brief override << the operator
 * @param out - the datastream
 * @param SearchResult whose data will be sent
 * @return out - the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult) {
    out << *(searchResult.mSearchResultElementList);
    return out;
}

/**
 * @brief override >> the operator
 * @param in - the datastream
 * @param SearchResult to be changed
 * @return in - the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    in >> *(searchResult.mSearchResultElementList);
    return in;
}

/**
 * @brief calls the << operator
 * @param in - the datastream
 */
void SearchResult::toStream(QDataStream& in) {
    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the datastream
 */
void SearchResult::fromStream(QDataStream& out) {
    out >> *this;
}
