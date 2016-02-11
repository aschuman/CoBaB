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

    void load(QString path);

    void save(QString path);
    
    void addBookmark(Bookmark bookmark);
    
    void removeBookmark(const Bookmark* bookmark);
    
    QList<Bookmark*> sortByName();
    
    QList<Bookmark*> sortByDate();

private: 

    QList<Bookmark> mBookmarkList;

    void validateResult(SearchResult searchResult);
};

#endif //_BOOKMARKLIST_H
