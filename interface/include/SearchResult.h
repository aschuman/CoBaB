/**
 * Project \
 */


#ifndef _SEARCHRESULT_H
#define _SEARCHRESULT_H

#include "DataPacket.h"
#include "SearchResultElement.h"

/**
 * @brief The SearchResult class builds a search result with a list of search result elements.
 * The search result elements can be sorted by score given by the algorithm.
 * @author Violina
 */
class SearchResult: public DataPacket {
public:
    
    SearchResult();

    explicit SearchResult(QList<SearchResultElement> list);

    void addResultElement(const SearchResultElement& newElement);
    
    QList<SearchResultElement> getSearchResultList() const;
    
    QList<SearchResultElement> sortByScore();

    friend QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult);

    friend QDataStream& operator>>(QDataStream& in, SearchResult& searchResult);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;

private: 

    QList<SearchResultElement> mSearchResultElementList;        ///< The list of searchresults

};

#endif //_SEARCHRESULT_H
