/**
 * Project \
 */


#include "BookmarkList.h"

/**
 * BookmarkList implementation
 */

/**
 * @brief BookmarkList::BookmarkList
 */
BookmarkList::BookmarkList() {

}

/**
 * @brief BookmarkList::load
 * @param path
 */
void BookmarkList::load(QString path) {
    QFile file(path);
    QDataStream in(&file);
    in >> mBookmarkList;
    file.close();
}

/**
 * @brief BookmarkList::save
 * @param path
 */
void BookmarkList::save(QString path) {
    QFile file(path);
    QDataStream out(&file);
    out << mBookmarkList;
    file.close();
}

/**
 * @brief BookmarkList::addBookmark
 * @param bookmark
 */
void BookmarkList::addBookmark(Bookmark bookmark) {
    Q_UNUSED(bookmark);
}

/**
 * @brief BookmarkList::removeBookmark
 * @param bookmark
 */
void BookmarkList::removeBookmark(const Bookmark* bookmark) {
    Q_UNUSED(bookmark);
}

/**
 * @brief BookmarkList::sortByName
 * @return
 */
QList<Bookmark*> BookmarkList::sortByName() {
    QList<Bookmark*> list;

    return list;
}

/**
 * @brief BookmarkList::sortByDate
 * @return
 */
QList<Bookmark*> BookmarkList::sortByDate() {
    QList<Bookmark*> list;

    return list;
}

/**
 * @brief BookmarkList::validateResult
 * @param searchResult
 */
void BookmarkList::validateResult(SearchResult searchResult) {
    Q_UNUSED(searchResult);
}
