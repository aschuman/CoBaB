#include "SearchResultTester.h"
#include "SearchResult.h"

#include <QtTest>

void SearchResultTester::testType()
{
    QList<SearchResultElement> list;
    SearchResult s(list);
    QVERIFY(s.getType() == DataPacket::Type::SEARCHRESULT);
}
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

    QCOMPARE(sortedList.takeAt(0).getScore(), element2.getScore());
    QCOMPARE(sortedList.takeAt(1).getScore(), element5.getScore());
    QCOMPARE(sortedList.takeAt(2).getScore(), element4.getScore());
    QCOMPARE(sortedList.takeAt(3).getScore(), element1.getScore());
    QCOMPARE(sortedList.takeAt(4).getScore(), element3.getScore());

}
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
    QDataStream in(&file); //serialize the data into the file
    in << s; //serialize the datapacket

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file); //read the data serialized from the file
    SearchResult newS(list);
    out >> newS; //extract the datapacket

    QCOMPARE(s.getSearchResultList().takeFirst().getScore(), newS.getSearchResultList().takeFirst().getScore());
    QCOMPARE(s.getSearchResultList().takeLast().getScore(), newS.getSearchResultList().takeLast().getScore());
}
