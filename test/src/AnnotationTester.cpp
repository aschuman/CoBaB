#include "AnnotationTester.h"

void AnnotationTester::initTestCase() {

	
}

void AnnotationTester::testGetters() {
    Annotation a("new annotation", "Face");
    QCOMPARE(a.getId(), (QString)"Face");
    QCOMPARE(a.getType(), Annotation::Type::FACE);

    Annotation b("", "something weird");
    QCOMPARE(b.getType(), Annotation::Type::UNKNOWN);
}

void AnnotationTester::testSaveLoad() {


}
