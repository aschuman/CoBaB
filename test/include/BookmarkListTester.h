#ifndef BOOKMARKLISTTESTER_H
#define BOOKMARKLISTTESTER_H

#include <QObject>
#include <QTest>
#include "Bookmark.h"
#include "BookmarkList.h"

class BookmarkListTester : public QObject
{
    Q_OBJECT
private slots:
    void initTest();
    void testAdd();
    void testRemove();
    void testSortByName();
    void testSortByDate();
    void testLoad();

private:
    BookmarkList list;
};

#endif // BOOKMARKLISTTESTER_H
