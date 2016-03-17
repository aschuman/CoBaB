#include "SearchQueryTester.h"
#include "SearchQuery.h"
#include <QtTest>

SearchQuery squery; ///< Instance of SearchQuery for testing.
/**
 * @brief Tests the type of the SearchQuery.
 */
void SearchQueryTester::testType()
{

    QCOMPARE(squery.getType(), DataPacket::Type::SEARCHQUERY);

}
/**
 * @brief Tests the setter and getter of the list of Datasets of the SearchQuery
 */
void SearchQueryTester::testDatasets()
{

    QList<QString> datasets;
    squery.setDatasets(datasets);
    QCOMPARE(squery.getDatasets(), datasets);
}
/**
 * @brief Tests the setter and getter of the SearchObject of the SearchQuery.
 */
void SearchQueryTester::testSearchObject()
{

    SearchObject sobject;
    squery.setSearchObject(sobject);
    QCOMPARE(squery.getSearchObject().getMediumIndex(), sobject.getMediumIndex());
}
/**
 * @brief Tests the sending and receiving of information through streams.
 */
void SearchQueryTester::testStreamMethods()
{

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << squery;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    SearchQuery newSquery;
    in >> newSquery;
    file.close();

    QCOMPARE(squery.getDatasets(), newSquery.getDatasets());
    QCOMPARE(squery.getSearchObject().getMediumIndex(), newSquery.getSearchObject().getMediumIndex());
}
