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
