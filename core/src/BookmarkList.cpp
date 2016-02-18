#include "BookmarkList.h"

/**
 * @brief BookmarkList::BookmarkList default constructor : create empty list
 */
BookmarkList::BookmarkList() {

}

/**
 * @brief BookmarkList::load load bookmark list from binary file
 * @param path absolute file path
 */
void BookmarkList::load(const QString path) {
    QFile file(path);
    QDataStream in(&file);
    in >> mBookmarkList;
    file.close();
}

/**
 * @brief BookmarkList::save save bookmark list to binary file
 * @param path file path
 */
void BookmarkList::save(const QString path) const {
    QFile file(path);
    QDataStream out(&file);
    out << mBookmarkList;
    file.close();
}

/**
 * @brief BookmarkList::addBookmark add a new bookmark to end of list
 * @param bookmark new bookmark
 */
void BookmarkList::addBookmark(const Bookmark& bookmark) {
    mBookmarkList.append(bookmark);
}

/**
 * @brief BookmarkList::removeBookmark remove a bookmark if it exists in the list
 * @param bookmark pointer to the to-be-removed bookmark
 */
void BookmarkList::removeBookmark(const Bookmark& bookmark) {
    mBookmarkList.removeOne(bookmark);
}

/**
 * @brief getBookmarkPointerList return the pointers to bookmarks
 * @return list of bookmark pointers
 */
QList<const Bookmark*> BookmarkList::getBookmarkList() {
    QList<const Bookmark*> list;
    int length = mBookmarkList.size();
    for (int i = 0; i < length; i++) {
        const Bookmark* bookmark = &mBookmarkList.at(i);
        list.append(bookmark);
    }
    return list;
}

/**
 * @brief BookmarkList::sortByName sort all bookmarks by name
 * @return a list of sorted-bookmarks-pointers
 */
QList<const Bookmark*> BookmarkList::sortByName() {
    std::sort(mBookmarkList.begin(), mBookmarkList.end(), Bookmark::smallerByName);
    return getBookmarkList();
}

/**
 * @brief BookmarkList::sortByDate sort all bookmarks by date
 * @return a list of sorted-bookmarks-pointers
 */
QList<const Bookmark*> BookmarkList::sortByDate() {
    std::sort(mBookmarkList.begin(), mBookmarkList.end(), Bookmark::smallerByDate);
    return getBookmarkList();
}
