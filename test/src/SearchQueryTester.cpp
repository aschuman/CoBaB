#include "SearchQueryTester.h"
#include "SearchQuery.h"
#include <QtTest>

SearchQuery squery;

void SearchQueryTester::testType()
{

    QCOMPARE(squery.getType(), DataPacket::Type::SEARCHQUERY);

}

void SearchQueryTester::testDatasets()
{

    QList<QString> datasets;
    squery.setDatasets(datasets);
    QCOMPARE(squery.getDatasets(), datasets);
}

void SearchQueryTester::testSearchObject()
{

    SearchObject sobject;
    squery.setSearchObject(sobject);
    QCOMPARE(squery.getSearchObject().getMediumIndex(), sobject.getMediumIndex());
}

void SearchQueryTester::testStreamMethods()
{

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file);
    in << squery;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file);
    SearchQuery newSquery;
    out >> newSquery;
    file.close();

    QCOMPARE(squery.getDatasets(), newSquery.getDatasets());
    QCOMPARE(squery.getSearchObject().getMediumIndex(), newSquery.getSearchObject().getMediumIndex());
}
