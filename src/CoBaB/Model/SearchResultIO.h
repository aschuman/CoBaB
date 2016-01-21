/**
 * Project \
 */


#ifndef _SEARCHRESULTIO_H
#define _SEARCHRESULTIO_H

#include "QDataStream.h"


class SearchResultIO: public QDataStream {
public: 
    
    /**
     * @param name
     */
    virtual SearchResult loadSearchResult(QString name) = 0;
    
    /**
     * @param searchResult
     */
    virtual void storeSearchResult(SearchResult searchResult) = 0;
    
    void sortByName();
    
    void sortByDate();
    
    QList<SearchResult> getSearchResultList();
protected: 
    QList<SearchResult> mSearchResultList;
    
    /**
     * @param searchResult
     */
    void operator<<(SearchResult searchResult);
    
    SearchResult operator>>();
private: 
    
    /**
     * @param searchResult
     */
    void validateResult(SearchResult searchResult);
};

#endif //_SEARCHRESULTIO_H