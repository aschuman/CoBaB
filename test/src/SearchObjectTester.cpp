#include "SearchObjectTester.h"
#include "SearchObject.h"
#include <QtTest>
#include "RectangleAnnotation.h"

SearchObject sobject;

void SearchObjectTester::testMedium()
{

  QString medium = "../../test/testdata/Fotos/000_45.bmp";
  sobject.setMedium(medium);
  QCOMPARE(sobject.getMedium(), medium);

}

void SearchObjectTester::testAnnotation()
{
   RectangleAnnotation* annotation = new RectangleAnnotation("","Unknown");
   annotation->setRect(10,20,30,40);
   sobject.setAnnotation(annotation);
   QCOMPARE(sobject.getAnnotation()->getId(), annotation->getId());
   QCOMPARE(sobject.getAnnotation()->getType(), annotation->getType());
   QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->x(), annotation->x());
   QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->y(), annotation->y());
   QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->width(), annotation->width());
   QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->height(), annotation->height());
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

void SearchObjectTester::testType()
{

    QString medium = "../../test/testdata/Fotos/000_45.bmp";
    sobject.setMedium(medium);
    QCOMPARE(sobject.getType(), SearchObject::Type::MEDIUM);

    Annotation* annotation = new Annotation();
    sobject.setAnnotation(annotation);
    QCOMPARE(sobject.getType(), SearchObject::Type::ANNOTATION);

    QRect roi;
    sobject.setROI(roi);
    QCOMPARE(sobject.getType(), SearchObject::Type::ROI);

}

void SearchObjectTester::testStreamMethods()
{
    RectangleAnnotation* annotation = new RectangleAnnotation("test", "Unknown");
    annotation->setRect(10,20,30,40);
    sobject.setAnnotation(annotation);
    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << sobject;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    SearchObject newSobject;
    in >> newSobject;
    file.close();

    QCOMPARE(sobject.getMedium(), newSobject.getMedium());
    QCOMPARE(sobject.getAnnotation()->getId(), newSobject.getAnnotation()->getId());
    QCOMPARE(sobject.getAnnotation()->getType(), newSobject.getAnnotation()->getType());
    QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->x(), ((RectangleAnnotation*)newSobject.getAnnotation())->x());
    QCOMPARE(((RectangleAnnotation*)sobject.getAnnotation())->y(), ((RectangleAnnotation*)newSobject.getAnnotation())->y());
    QCOMPARE(sobject.getROI(), newSobject.getROI());
    QCOMPARE(sobject.getSourceDataset(), newSobject.getSourceDataset());
    QCOMPARE(sobject.getMediumIndex(), newSobject.getMediumIndex());

}

