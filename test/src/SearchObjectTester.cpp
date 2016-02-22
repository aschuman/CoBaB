#include "SearchObjectTester.h"
#include "SearchObject.h"
#include <QtTest>

SearchObject sobject;

void SearchObjectTester::testMedium()
{

  QString medium = "../../test/testdata/Fotos/000_45.bmp";
  sobject.setMedium(medium);
  QCOMPARE(sobject.getMedium(), medium);

}

void SearchObjectTester::testAnnotation()
{

   Annotation annotation;
   sobject.setAnnotation(annotation);
   QCOMPARE(sobject.getAnnotation().getId(), annotation.getId());
   QCOMPARE(sobject.getAnnotation().getType(), annotation.getType());
}

void SearchObjectTester::testROI()
{

    QRect roi;
    sobject.setROI(roi);
    QCOMPARE(sobject.getROI(), roi);

}

void SearchObjectTester::testSourceDataset()
{

    QString sourceDataset = "../../test/testdata/Fotos/";
    sobject.setSourceDataset(sourceDataset);
    QCOMPARE(sobject.getSourceDataset(), sourceDataset);
}

void SearchObjectTester::testMediumIndex()
{

    int mediumindex = 0;
    sobject.setMediumIndex(mediumindex);
    QCOMPARE(sobject.getMediumIndex(), mediumindex);
}

void SearchObjectTester::testStreamMethods()
{

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file);
    in << sobject;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream out(&file);
    SearchObject newSobject;
    out >> newSobject;
    file.close();

    QCOMPARE(sobject.getMedium(), newSobject.getMedium());
    QCOMPARE(sobject.getAnnotation().getId(), newSobject.getAnnotation().getId());
    QCOMPARE(sobject.getAnnotation().getType(), newSobject.getAnnotation().getType());
    QCOMPARE(sobject.getROI(), newSobject.getROI());
    QCOMPARE(sobject.getSourceDataset(), newSobject.getSourceDataset());
    QCOMPARE(sobject.getMediumIndex(), newSobject.getMediumIndex());


}
