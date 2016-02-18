#ifndef _BOOKMARKLIST_H
#define _BOOKMARKLIST_H

#include "Bookmark.h"
#include "SearchResult.h"
#include <QFile>
#include <QDataStream>

/**
 * BookmarkList implementation
 * @author Tung
 */

class BookmarkList {
public: 
    
    BookmarkList();

    void load(QString path);

    void save(QString path);
    
    void addBookmark(Bookmark bookmark);
    
    void removeBookmark(const Bookmark* bookmark);
    
    QList<Bookmark*> sortByName();
    
    QList<Bookmark*> sortByDate();

    QList<Bookmark*> getBookmarkPointerList();

private: 

    QList<Bookmark> mBookmarkList;

    bool validateResult(SearchResult searchResult);


};

#endif //_BOOKMARKLIST_H
