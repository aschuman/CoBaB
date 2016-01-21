/**
 * Project \
 */


#ifndef _BOOKMARKIO_H
#define _BOOKMARKIO_H

#include "SearchResultIO.h"


class BookmarkIO: public SearchResultIO {
public: 
    
    void BookmarkIO();
    
    /**
     * @param name
     */
    SearchResult loadSearchResult(QString name);
    
    /**
     * @param searchResult
     */
    void storeSearchResult(SearchResult searchResult);
};

#endif //_BOOKMARKIO_H