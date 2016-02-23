#ifndef BOOKMARKTESTER_H
#define BOOKMARKTESTER_H

#include <QObject>
#include <QTest>
#include "Bookmark.h"

class BookmarkTester : public QObject
{
    Q_OBJECT
private slots:
    void initTest();
    void testGetters();
    void testSearchQuery();
    void testSearchResult();
    void testSearchFeedback();
    void testSaveLoad();
    void testDelete();

private:
    Bookmark fB, sB;
    QString fPath;
};

#endif // BOOKMARKTESTER_H
