#include "include/pagestackframetester.h"
#include <QtTest>
#include "PageStackFrame.h"

void PageStackFrameTester::testConstructor_data(){
    QTest::addColumn<PageType>("inType");
    QTest::addColumn<PageType>("outType");

    QTest::newRow("confirmation") << PageType::CONFIRMATION << PageType::CONFIRMATION;
    QTest::newRow("library") << PageType::LIBRARY << PageType::LIBRARY;
    QTest::newRow("none") << PageType::NONE << PageType::NONE;
    QTest::newRow("parameter") << PageType::PARAMETER << PageType::PARAMETER;
    QTest::newRow("results") << PageType::RESULTS << PageType::RESULTS;
    QTest::newRow("viewer") << PageType::VIEWER << PageType::VIEWER;
}

void PageStackFrameTester::testConstructor()
{
    QFETCH(PageType, inType);
    QFETCH(PageType, outType);
    PageStackFrame frame(inType);
    QCOMPARE(frame.getType(), outType);
    QCOMPARE(frame.getSize(), (size_t)0);
}

void PageStackFrameTester::testSetSize()
{
    const size_t SIZE = 123;
    PageStackFrame frame(PageType::NONE);
    frame.setSize(SIZE);
    QCOMPARE(frame.getSize(), SIZE);
}
