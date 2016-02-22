#ifndef BOOKMARKTESTER_H
#define BOOKMARKTESTER_H

#include <QObject>
#include "Bookmark.h"

class BookmarkTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestcase();

};

Bookmark fBookmark, sBookmark;

#endif // BOOKMARKTESTER_H
