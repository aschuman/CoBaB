/**
 * Project \
 */


#include "SearchResult.h"

/**
 * @brief a constructor for the class
 * @param list of SearchResultElements
 */
SearchResult::SearchResult(const QList<SearchResultElement> list) {
    mType = Type::SEARCHRESULT;
    mSearchResultElementList = list;
}

/**
 * @brief gets the list of SearchResultElements
 * @return the list of SearchResultElements
 */
QList<SearchResultElement> SearchResult::getSearchResultList() const {
    return mSearchResultElementList;
}

/**
 * @brief sorts the SearchResultElements by score
 * @return the sorted list
 */
QList<SearchResultElement> SearchResult::sortByScore() {
    std::sort(mSearchResultElementList.begin(), mSearchResultElementList.end(), SearchResultElement::compareByScore);
    return mSearchResultElementList;
}

/**
 * @brief override << the operator
 * @param out the datastream
 * @param SearchResult whose data will be sent
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult) {


}

/**
 * @brief override >> the operator
 * @param in the datastream
 * @param SearchResult to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {


}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchResult::toStream(QDataStream& in) const  {

    in >> mSearchResultElementList;

}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchResult::fromStream(QDataStream& out) {
    out << this->getSearchResultList();
}
