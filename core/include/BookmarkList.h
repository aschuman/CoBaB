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

    void save(QString path) const;
    
    void addBookmark(Bookmark& bookmark);
    
    void removeBookmark(const Bookmark& bookmark);
    
    QList<Bookmark*> sortByName();
    
    QList<Bookmark*> sortByDate();

private: 

    QList<Bookmark> mBookmarkList;

    QList<Bookmark*> getBookmarkList();
};

#endif //_BOOKMARKLIST_H
