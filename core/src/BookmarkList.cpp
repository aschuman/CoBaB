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

    QDir dir(path);
    QFileInfoList filesList = dir.entryInfoList();
    for(QFileInfo& f : filesList) {
        if (f.isFile()) {
            Bookmark bookmark(f.absoluteFilePath());
            if (Bookmark::validate(bookmark)) {
                mBookmarkList.append(bookmark);
            }
        }
    }
}

/**
 * @brief BookmarkList::addBookmark add a new bookmark to end of list
 * @param bookmark new bookmark
 */
void BookmarkList::addBookmark(const Bookmark& bookmark) {
    mBookmarkList.append(bookmark);
    bookmark.saveFile();
}

/**
 * @brief BookmarkList::removeBookmark remove a bookmark if it exists in the list
 * @param bookmark pointer to the to-be-removed bookmark
 */
bool BookmarkList::removeBookmark(const Bookmark& bookmark) {
    if (mBookmarkList.removeOne(bookmark)) {
        bookmark.deleteFile();
        return true;
    }
    else {
        return false;
    }
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
