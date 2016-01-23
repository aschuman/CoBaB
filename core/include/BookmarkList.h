/**
 * Project \
 */


#ifndef _BOOKMARKLIST_H
#define _BOOKMARKLIST_H

#include "Bookmark.h"
#include "SearchResult.h"

class BookmarkList {
public: 
    
    BookmarkList();
    
    /**
     * @param path
     */
    void load(QString path);
    
    /**
     * @param path
     */
    void save(QString path);
    
    /**
     * @param bookmark
     */
    void addBookmark(Bookmark bookmark);
    
    /**
     * @param bookmark
     */
    void removeBookmark(const Bookmark* bookmark);
    
    QList<Bookmark*> sortByName();
    
    QList<Bookmark*> sortByDate();
private: 
    QList<Bookmark> mBookmarkList;
    
    /**
     * @param searchResult
     */
    void validateResult(SearchResult searchResult);
};

#endif //_BOOKMARKLIST_H
