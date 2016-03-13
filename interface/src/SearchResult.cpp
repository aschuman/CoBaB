#include "SearchResult.h"

/**
 * @brief SearchResult::SearchResult Costructs a default SearchResult.
 */
SearchResult::SearchResult() {
    mType = DataPacket::Type::SEARCHRESULT;
}

/**
 * @brief SearchResult::SearchResult Constructs a SearchResult.
 * @param list of SearchResultElements
 */
SearchResult::SearchResult(QList<SearchResultElement> list) {
    mType = Type::SEARCHRESULT;
    mSearchResultElementList = std::move(list);
}

/**
 * @brief SearchResult::addResultElement Adds a result element.
 * @param newElement to be added
 */
void SearchResult::addResultElement(const SearchResultElement &newElement) {
   mSearchResultElementList.append(newElement);
}

/**
 * @brief SearchResult::getSearchResultList Gets the list of SearchResultElements.
 * @return the list of SearchResultElements
 */
QList<SearchResultElement> SearchResult::getSearchResultList() const {
    return mSearchResultElementList;
}

/**
 * @brief SearchResult::sortByScore Sorts the SearchResultElements by score.
 * @return the sorted list
 */
QList<SearchResultElement> SearchResult::sortByScore() {
    std::sort(mSearchResultElementList.begin(), mSearchResultElementList.end(), SearchResultElement::compareByScore);
    return mSearchResultElementList;
}

/**
 * @brief operator << Overrides the operator <<.
 * @param out the datastream
 * @param searchResult to be written
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult) {
    searchResult.toStream(out);
    return out;

}

/**
 * @brief operator >> Overrides the operator >>.
 * @param in the datastream
 * @param searchResult to be read
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchResult& searchResult) {
    searchResult.fromStream(in);
    return in;

}

/**
 * @brief SearchResult::toStream Calls the << operator and writes the searchresult to stream.
 * @param out the datastream
 */
void SearchResult::toStream(QDataStream& out) const  {
    DataPacket::toStream(out);
    out << mSearchResultElementList;

}

/**
* @brief SearchResult::fromStream Calls the >> operator and calls the searchresult from stream.
* @param in the datastream
*/
void SearchResult::fromStream(QDataStream& in) {
    DataPacket::fromStream(in);
    in >> mSearchResultElementList;
}
