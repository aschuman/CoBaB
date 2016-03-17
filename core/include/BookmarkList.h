#ifndef _BOOKMARKLIST_H
#define _BOOKMARKLIST_H

#include "Bookmark.h"
#include "SearchResult.h"
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDataStream>

/**
 * @brief BookmarkList contains a list of bookmarks and stores the bookmarks.
 * @author Tung
 */

class BookmarkList {
public: 
    
    BookmarkList();

    void load(const QString path);
    
    void addBookmark(const Bookmark& bookmark);
    
    bool removeBookmark(const Bookmark& bookmark);
    
    QList<const Bookmark*> sortByName();
    
    QList<const Bookmark*> sortByDate();

private: 

    QList<Bookmark> mBookmarkList;

    QList<const Bookmark*> getBookmarkList();
};

#endif //_BOOKMARKLIST_H
