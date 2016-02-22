#include "SearchResultElementTester.h"
#include "SearchResultElement.h"

#include <QtTest>

void SearchResultElementTester::testScore()
{
    SearchResultElement s;
    QCOMPARE(s.getScore(), 0);
    s.setScore(5);
    QCOMPARE(s.getScore(), 5);
}
void SearchResultElementTester::testSearchObject()
{
    SearchResultElement s;
    SearchObject object;
    object.setMedium("the medium");
    object.setSourceDataset("the dataset");
    object.setMediumIndex(1);
    s.setSearchObject(object);
    QCOMPARE(s.getSearchObject().getMedium(), object.getMedium());
    QCOMPARE(s.getSearchObject().getSourceDataset(), object.getSourceDataset());
    QCOMPARE(s.getSearchObject().getMediumIndex(), 1);
}
void SearchResultElementTester::testStreamMethods()
{
    SearchResultElement s;
    SearchObject object;
    object.setMedium("the medium");
    object.setSourceDataset("the dataset");
    object.setMediumIndex(1);
    s.setScore(3);

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file); //serialize the data into the file
    in << s; //serialize the datapacket
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file); //read the data serialized from the file
    SearchResultElement newS;
    out >> newS; //extract the datapacket
    file.close();

    QCOMPARE(s.getScore(), newS.getScore());
    QCOMPARE(s.getSearchObject().getMedium(), newS.getSearchObject().getMedium());
    QCOMPARE(s.getSearchObject().getSourceDataset(), newS.getSearchObject().getSourceDataset());
    QCOMPARE(s.getSearchObject().getMediumIndex(), newS.getSearchObject().getMediumIndex());
}
