/**
 * Project \
 */


#ifndef _SEARCHRESULT_H
#define _SEARCHRESULT_H

#include "DataPacket.h"
#include "SearchResultElement.h"


class SearchResult: public DataPacket {
public:
    
    SearchResult();

    SearchResult(QList<SearchResultElement>* list);
    
    QList<SearchResultElement>* getSearchResultList();
    
    QList<SearchResultElement>* sortByScore();

    friend QDataStream& operator<<(QDataStream& out, SearchResult& searchResult);

    friend QDataStream& operator>>(QDataStream& in, SearchResult& searchResult);

    void toStream(QDataStream in);

    void fromStream(QDataStream out);

private: 

    QList<SearchResultElement>* mSearchResultElementList;

};

#endif //_SEARCHRESULT_H
