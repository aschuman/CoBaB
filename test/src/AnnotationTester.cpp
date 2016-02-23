#include "AnnotationTester.h"

void AnnotationTester::initTestCase() {	
}

void AnnotationTester::testGetters() {
    Annotation a("new annotation", "Face");
    QCOMPARE(a.getId(), (QString)"new annotation");
    QCOMPARE(a.getType(), Annotation::Type::FACE);

    Annotation b("", "something weird");
    QCOMPARE(b.getType(), Annotation::Type::UNKNOWN);
}

void AnnotationTester::testSaveLoad() {
    Annotation a("new annotation", "Person");
    QFile file("testAnnotation.tmp");

    //write to file
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << a;
    file.close();

    //read from file
    file.open(QIODevice::ReadOnly);
    Annotation b("", "");
    stream >> b;
    file.close();

    QCOMPARE(a.getId(), b.getId());
    QCOMPARE(a.getType(), b.getType());
}
