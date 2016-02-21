/**
 * Project \
 */


#ifndef _SEARCHRESULT_H
#define _SEARCHRESULT_H

#include "DataPacket.h"
#include "SearchResultElement.h"

/**
 * @brief SearchResult class
 * @author Violina
 */
class SearchResult: public DataPacket {
public:
    
    SearchResult();

    SearchResult(const QList<SearchResultElement> list);

    void addResultElement(const SearchResultElement& newElement);
    
    QList<SearchResultElement> getSearchResultList() const;
    
    QList<SearchResultElement> sortByScore();

    friend QDataStream& operator<<(QDataStream& out, const SearchResult& searchResult);

    friend QDataStream& operator>>(QDataStream& in, SearchResult& searchResult);

    void toStream(QDataStream& in) const override;

    void fromStream(QDataStream& out) override;

private: 

    QList<SearchResultElement> mSearchResultElementList;        ///< The list of searchresults

};

#endif //_SEARCHRESULT_H
