#include "SearchResultElementTester.h"
#include "SearchResultElement.h"

#include <QtTest>
/**
 * @brief Tests the getter and setter of the score.
 */
void SearchResultElementTester::testScore()
{
    SearchResultElement s;
    QCOMPARE(s.getScore(), 0.);
    s.setScore(5.);
    QCOMPARE(s.getScore(), 5.);
}
/**
 * @brief Tests the setter and getter of the SearchObject.
 */
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
/**
 * @brief Tests the sending and seceiving of information throught streams.
 */
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
    QDataStream out(&file);
    out << s;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    SearchResultElement newS;
    in >> newS;
    file.close();

    QCOMPARE(s.getScore(), newS.getScore());
    QCOMPARE(s.getSearchObject().getMedium(), newS.getSearchObject().getMedium());
    QCOMPARE(s.getSearchObject().getSourceDataset(), newS.getSearchObject().getSourceDataset());
    QCOMPARE(s.getSearchObject().getMediumIndex(), newS.getSearchObject().getMediumIndex());
}
