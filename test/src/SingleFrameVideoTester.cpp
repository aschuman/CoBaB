#include "include/SingleFrameVideoTester.h"
#include <QtTest>


void SingleFrameVideoTester::init()
{
    QList<QPair<int, Annotation>> *annotations = new QList<QPair<int, Annotation>>();
    SingleFrameVideo video("testdata/SingleFrameVideo", *annotations);
    mSingleFrameVideo = video;
}

void SingleFrameVideoTester::testFramerate()
{
    QCOMPARE(mSingleFrameVideo.getFramerate(), 0.5);
}

void SingleFrameVideoTester::testFrameList()
{
    QList<QImage> *list = new QList<QImage>();
    QImage image("testdata/SingleFrameVideo/bigbangtheory_s1e1.vob_00000.png");
    list->append(image);
    image.load("testdata/SingleFrameVideo/bigbangtheory_s1e1.vob_00250.png");
    list->append(image);
    image.load("testdata/SingleFrameVideo/bigbangtheory_s1e1.vob_00500.png");
    list->append(image);
    QCOMPARE(mSingleFrameVideo.getFrameList(), list);
}
