#include "SearchResult.h"

/**
 * @brief SearchResult::SearchResult default constructor
 */
SearchResult::SearchResult() {
    mType = DataPacket::Type::SEARCHRESULT;
}

/**
 * @brief a constructor for the class
 * @param list of SearchResultElements
 */
SearchResult::SearchResult(QList<SearchResultElement> list) {
    mType = Type::SEARCHRESULT;
    mSearchResultElementList = std::move(list);
}

/**
 * @brief SearchResult::addResultElement
 * @param newElement
 */
void SearchResult::addResultElement(const SearchResultElement &newElement) {
   mSearchResultElementList.append(newElement);
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
    searchResult.toStream(out);
    return out;

}

/**
 * @brief override >> the operator
 * @param in the datastream
 * @param SearchResult to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    searchResult.fromStream(in);
    return in;

}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchResult::toStream(QDataStream& out) const  {
    DataPacket::toStream(out);
    out << mSearchResultElementList;

}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchResult::fromStream(QDataStream& in) {
    DataPacket::fromStream(in);
    in >> mSearchResultElementList;
}
