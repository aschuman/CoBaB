#include "SearchResultTester.h"
#include "SearchResult.h"

#include <QtTest>
/**
 * @brief Tests the type of the SearchResult.
 */
void SearchResultTester::testType()
{
    QList<SearchResultElement> list;
    SearchResult s(list);
    QVERIFY(s.getType() == DataPacket::Type::SEARCHRESULT);
}
/**
 * @brief Tests setter and getter of the list of SearchResultElements.
 */
void SearchResultTester::testList()
{
    QList<SearchResultElement> list;
    SearchResult s(list);
    SearchResultElement element1;
    element1.setScore(2);
    SearchResultElement element2;
    element2.setScore(4);
    s.addResultElement(element1);
    s.addResultElement(element2);
    QCOMPARE(s.getSearchResultList().takeFirst().getScore(), element1.getScore());
    QCOMPARE(s.getSearchResultList().takeLast().getScore(), element2.getScore());

}
/**
 * @brief Tests the sorting method for SearchResultElements.
 */
void SearchResultTester::testSort()
{
    QList<SearchResultElement> list;
    SearchResult s(list);
    SearchResultElement element1;
    element1.setScore(4);
    SearchResultElement element2;
    element2.setScore(1);
    SearchResultElement element3;
    element3.setScore(7);
    SearchResultElement element4;
    element4.setScore(3);
    SearchResultElement element5;
    element5.setScore(2);
    s.addResultElement(element1);
    s.addResultElement(element2);
    s.addResultElement(element3);
    s.addResultElement(element4);
    s.addResultElement(element5);

    QList<SearchResultElement> sortedList = s.sortByScore();

    QCOMPARE(sortedList.at(0).getScore(), element2.getScore());
    QCOMPARE(sortedList.at(1).getScore(), element5.getScore());
    QCOMPARE(sortedList.at(2).getScore(), element4.getScore());
    QCOMPARE(sortedList.at(3).getScore(), element1.getScore());
    QCOMPARE(sortedList.at(4).getScore(), element3.getScore());

}
/**
 * @brief Tests the sending and receiving of information through streams.
 */
void SearchResultTester::testStreamMethods()
{

    QList<SearchResultElement> list;
    SearchResult s(list);
    SearchResultElement element1;
    element1.setScore(2);
    SearchResultElement element2;
    element2.setScore(4);
    s.addResultElement(element1);
    s.addResultElement(element2);

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << s;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    SearchResult newS(list);
    in >> newS;
    file.close();

    QCOMPARE(s.getSearchResultList().takeFirst().getScore(), newS.getSearchResultList().takeFirst().getScore());
    QCOMPARE(s.getSearchResultList().takeLast().getScore(), newS.getSearchResultList().takeLast().getScore());
}
