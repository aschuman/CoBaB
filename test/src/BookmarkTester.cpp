#include "BookmarkTester.h"

void BookmarkTester::initTest() {
    fPath = QDir::currentPath().append("/bookmark.tmp");

    //init query
    SearchQuery query;
    QList<QString> datasets;
    datasets.append("dataset1");
    datasets.append("dataset2");
    query.setDatasets(datasets);

    //init result
    SearchResult result;
    SearchResultElement res;
    res.setScore(100);
    result.addResultElement(res);

    //init parameters
    QJsonObject parameters;
    parameters.insert("random value", 123);

    //init feedback
    SearchFeedback feedback("Extended");

    fB = Bookmark(result, "test algo", query);
    fB.setName("1st bookmark");
    fB.setDate(QDateTime(QDate(1,1,2000)));
    fB.setPath(fPath);
    fB.setParameter(parameters);
    fB.setFeedback(feedback);

    sB.setName("2nd bookmark");
    sB.setDate(QDateTime(QDate(31,12,1999)));
}

void BookmarkTester::testGetters() {
    QCOMPARE(fB.getName(), (QString)"1st bookmark");
    QCOMPARE(fB.getDate(), QDateTime(QDate(1,1,2000)));
    QCOMPARE(fB.getParameter().value("random value"), (QJsonValue)123);
}

void BookmarkTester::testSearchQuery() {
    QList<QString> datasets = fB.getSearchQuery().getDatasets();
    QCOMPARE(datasets.length(), 2);
    QCOMPARE(datasets.value(0), (QString)"dataset1");
    QCOMPARE(datasets.value(1), (QString)"dataset2");
}

void BookmarkTester::testSearchResult() {
    QList<SearchResultElement> resultList = fB.getSearchResult().getSearchResultList();
    QCOMPARE(resultList.length(), 1);
    QCOMPARE(resultList.value(0).getScore(), 100);
}

void BookmarkTester::testSearchFeedback() {
    QCOMPARE(fB.getFeedback().getFeedbackType(), SearchFeedback::Type::EXTENDED);
}

void BookmarkTester::testSaveLoad() {   //stream methods included
    fB.saveFile();
    sB = Bookmark((QString)fPath);
    QCOMPARE(fB.getName(), sB.getName());
    QCOMPARE(fB.getDate(), sB.getDate());
    QCOMPARE(fB.getParameter().value("random value"), sB.getParameter().value("random value"));
    QFile file(fPath);
    QVERIFY(file.exists());
}

void BookmarkTester::testDelete() {
    fB.saveFile();
    QFile file(fPath);
    QVERIFY(file.exists());

    fB.deleteFile();
    QVERIFY(!file.exists());
}

