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

    void load(const QString path);

    void save(const QString path) const;
    
    void addBookmark(const Bookmark& bookmark);
    
    void removeBookmark(const Bookmark& bookmark);
    
    QList<const Bookmark*> sortByName();
    
    QList<const Bookmark*> sortByDate();

private: 

    QList<Bookmark> mBookmarkList;

    QList<const Bookmark*> getBookmarkList();
};

#endif //_BOOKMARKLIST_H
