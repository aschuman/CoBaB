#include "SearchObjectTester.h"
#include "SearchObject.h"
#include <QtTest>

void SearchObjectTester::testMedium()
{
  SearchObject sobject;
  QString medium = "../../test/testdata/Fotos/000_45.bmp";
  sobject.setMedium(medium);
  QCOMPARE(sobject.getMedium(), medium);

}

void SearchObjectTester::testAnnotation()
{
   SearchObject sobject;
   Annotation annotation;
   sobject.setAnnotation(annotation);
   QCOMPARE(sobject.getAnnotation().getId(), annotation.getId());
   QCOMPARE(sobject.getAnnotation().getType(), annotation.getType());
}

void SearchObjectTester::testROI()
{
    SearchObject sobject;
    QRect roi;
    sobject.setROI(roi);
    QCOMPARE(sobject.getROI(), roi);

}

void SearchObjectTester::testSourceDataset()
{
    SearchObject sobject;
    QString sourceDataset = "../../test/testdata/Fotos/";
    sobject.setSourceDataset(sourceDataset);
    QCOMPARE(sobject.getSourceDataset(), sourceDataset);
}

void SearchObjectTester::testMediumIndex()
{
    SearchObject sobject;
    int mediumindex;
    sobject.setMediumIndex(mediumindex);
    QCOMPARE(sobject.getMediumIndex(), mediumindex);
}

void SearchObjectTester::testStreamMethods()
{
    SearchObject sobject;

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file); //serialize the data into the file
    in << sobject; //serialize the datapacket
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file); //read the data serialized from the file
    SearchObject newSobject;
    out >> newSobject; //extract the datapacket
    file.close();

    QCOMPARE(sobject.getMedium(), newSobject.getMedium());
    QCOMPARE(sobject.getAnnotation().getId(), newSobject.getAnnotation().getId());
    QCOMPARE(sobject.getAnnotation().getType(), newSobject.getAnnotation().getType());
    QCOMPARE(sobject.getROI(), newSobject.getROI());
    QCOMPARE(sobject.getSourceDataset(), newSobject.getSourceDataset());
    QCOMPARE(sobject.getMediumIndex(), newSobject.getMediumIndex());


}
