#include "SearchObjectTester.h"
#include "SearchObject.h"
#include <QtTest>
#include "RectangleAnnotation.h"

SearchObject sobject; ///< Instance of SearchObject for testing.
/**
 * @brief Tests the funktion of the setter and getter for Medium.
 */
void SearchObjectTester::testMedium()
{

  QString medium = "../../test/testdata/Fotos/000_45.bmp";
  sobject.setMedium(medium);
  QCOMPARE(sobject.getMedium(), medium);

}
/**
 * @brief Tests the id and the type of an Annotation aswell as its koordinates, width and height.
 */
void SearchObjectTester::testRectangleAnnotation()
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

   delete annotation;
}
/**
 * @brief Tests any anotation for id and type , not just rectangle Annotation like RectangleAnnotationTester.
 */
void SearchObjectTester::testAnnotation()
{
   Annotation* annotation = new Annotation("","Unknown");
   sobject.setAnnotation(annotation);
   QCOMPARE(sobject.getAnnotation()->getId(), annotation->getId());
   QCOMPARE(sobject.getAnnotation()->getType(), annotation->getType());
   delete annotation;
}
/**
 * @brief Tests the getter and setter of the region of interest  selected by the user.
 */
void SearchObjectTester::testROI()
{

    QRect roi;
    sobject.setROI(roi);
    QCOMPARE(sobject.getROI(), roi);

}
/**
 * @brief Tests the getter and setter of the sourcedataset.
 */
void SearchObjectTester::testSourceDataset()
{

    QString sourceDataset = "../../test/testdata/Fotos/";
    sobject.setSourceDataset(sourceDataset);
    QCOMPARE(sobject.getSourceDataset(), sourceDataset);
}
/**
 * @brief Tests the getter and setter of the MediumIndex.
 */
void SearchObjectTester::testMediumIndex()
{

    int mediumindex = 0;
    sobject.setMediumIndex(mediumindex);
    QCOMPARE(sobject.getMediumIndex(), mediumindex);
}
/**
 * @brief Tests the type of the SearchObject.
 */
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

    delete annotation;
}
/**
 * @brief Tests the sending and receiving of information through stream.
 */
void SearchObjectTester::testStreamMethods()
{
    Annotation* annotation = new Annotation("test", "Unknown");
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
    QCOMPARE(sobject.getROI(), newSobject.getROI());
    QCOMPARE(sobject.getSourceDataset(), newSobject.getSourceDataset());
    QCOMPARE(sobject.getMediumIndex(), newSobject.getMediumIndex());

    delete annotation;
}
/**
 * @brief Tests the sending and receiving of information through stream for a RectangleAnnotation.
 */
void SearchObjectTester::testStreamMethodsRectangle()
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

    delete annotation;
}

