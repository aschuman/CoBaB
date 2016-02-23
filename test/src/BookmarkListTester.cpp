#include "BookmarkListTester.h"

void BookmarkListTester::initTest() {
    //create new temporary directory
    QDir dir(QDir::currentPath());
    dir.mkdir("temp_dir");
    dir.cd("temp_dir");

    Bookmark bm1;
    bm1.setName("3rd bm");
    bm1.setDate(QDateTime(QDate(2015,1,1)));
    bm1.setPath(dir.path().append("/bookmark.01"));

    Bookmark bm2;
    bm2.setName("1st bm");
    bm2.setDate(QDateTime(QDate(2015,3,1)));
    bm2.setPath(dir.path().append("/bookmark.02"));

    Bookmark bm3;
    bm3.setName("2nd bm");
    bm3.setDate(QDateTime(QDate(2015,2,1)));
    bm3.setPath(dir.path().append("/bookmark.03"));

    list.addBookmark(bm1);
    list.addBookmark(bm2);
    list.addBookmark(bm3);
}

void BookmarkListTester::testAdd() {
    Bookmark bm4;
    bm4.setName("4th bm");

    QCOMPARE(list.sortByName().size(), 3);

    list.addBookmark(bm4);
    QCOMPARE(list.sortByName().size(), 4);
}

void BookmarkListTester::testRemove() {
    Bookmark bm;
    bm.setName("5th bm");

    QCOMPARE(list.sortByName().size(), 4);
    QVERIFY(!list.removeBookmark(bm));

    bm.setName("4th bm");
    QVERIFY(list.removeBookmark(bm));
    QCOMPARE(list.sortByName().size(), 3);
}

void BookmarkListTester::testSortByName() {
    QList<const Bookmark*> nList = list.sortByName();
    QCOMPARE(nList.size(), 3);

    QCOMPARE(nList.value(0)->getName(), (QString)"1st bm");
    QCOMPARE(nList.value(1)->getName(), (QString)"2nd bm");
    QCOMPARE(nList.value(2)->getName(), (QString)"3rd bm");
}

void BookmarkListTester::testSortByDate() {
    QList<const Bookmark*> nList = list.sortByDate();
    QCOMPARE(nList.size(), 3);

    QCOMPARE(nList.value(0)->getName(), (QString)"3rd bm");
    QCOMPARE(nList.value(1)->getName(), (QString)"2nd bm");
    QCOMPARE(nList.value(2)->getName(), (QString)"1st bm");
}

void BookmarkListTester::testLoad() {
    QString path = QDir::currentPath().append("/temp_dir");
    BookmarkList fList;
    fList.load(path);

    QCOMPARE(fList.sortByName().size(), 3);
}
