/**
 * Project \
 */


#ifndef _SEARCHRESULT_H
#define _SEARCHRESULT_H

#include "DataPacket.h"
#include "QDataStream.h"


class SearchResult: public DataPacket, public QDataStream {
public: 
    
    /**
     * @param list
     */
    void SearchResult(QList<SearchResultElement> list);
    
    QList<SearchResultElement> getSearchResultList();
    
    QList<SearchResultElement> sortByScore();
    
    /**
     * @param out
     * @param searchResult
     */
    QDataStream& operator<<(QDataStream& out, SearchResult& searchResult);
    
    /**
     * @param in
     * @param searchResult
     */
    QDataStream& operator>>(QDataStream& in, SearchResult& searchResult);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
private: 
    QList<SearchResultElement> mSearchResultElementList;
};

#endif //_SEARCHRESULT_H