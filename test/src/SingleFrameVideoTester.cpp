#include "include/SingleFrameVideoTester.h"
#include <QtTest>

void SingleFrameVideoTester::init()
{
    QList<QPair<int, Annotation*>> *annotations = new QList<QPair<int, Annotation*>>();
    mSingleFrameVideo = std::make_unique<SingleFrameVideo>("../../test/testdata/SingleFrameVideo/SingleFrameVideo", *annotations);
}

void SingleFrameVideoTester::testFramerate()
{
    QCOMPARE(mSingleFrameVideo->getFramerate(), 0.5);
}

void SingleFrameVideoTester::testFrameList()
{
    QList<QString> list;
    list.append("bigbangtheory_s1e1.vob_00000.png");
    list.append("bigbangtheory_s1e1.vob_00250.png");
    list.append("bigbangtheory_s1e1.vob_00500.png");
    QCOMPARE(mSingleFrameVideo->getFrameList(), list);

}
