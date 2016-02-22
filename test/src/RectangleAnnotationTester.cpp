#include "RectangleAnnotationTester.h"

void RectangleAnnotationTester::initTestCase() {

	
}

void RectangleAnnotationTester::testGetters() {
    RectangleAnnotation a("new annotation", "Face");
    QCOMPARE(a.getId(), (QString)"new annotation");
    QCOMPARE(a.getType(), Annotation::Type::FACE);
    a.setLeft(10);

    RectangleAnnotation b("", "something weird");
    QCOMPARE(b.getType(), Annotation::Type::UNKNOWN);
    b.setLeft(10);

    QCOMPARE(a.left(), b.left());
}

void RectangleAnnotationTester::testSaveLoad() {
    RectangleAnnotation a("new annotation", "Person");
    a.setX(10);
    a.setY(20);
    QFile file("testRectAnnotation.tmp");

    //write to file
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << a;
    file.close();

    //read from file
    file.open(QIODevice::ReadOnly);
    RectangleAnnotation b("", "");
    stream >> b;
    file.close();

    //QCOMPARE(a,b);
    QCOMPARE(a.getId(), b.getId());
    QCOMPARE(a.getType(), b.getType());
    QCOMPARE(b.x(), 10);
    QCOMPARE(b.y(), 20);
}
