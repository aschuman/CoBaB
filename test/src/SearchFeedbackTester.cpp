#include "SearchFeedbackTester.h"

SearchFeedbackTester::SearchFeedbackTester() : fb("Dual")
{
}

void SearchFeedbackTester::initTestCase() {
    SearchObject obj1;
    obj1.setMedium("picture");
    list.append(pair(obj1, 10));

    SearchObject obj2;
    obj2.setROI(QRect(1,2,3,4));
    list.append(pair(obj2, 20));

    fb.setFeedbackList(list);
}

void SearchFeedbackTester::testGetType() {
    QCOMPARE(fb.getType(), DataPacket::Type::SEARCHFEEDBACK);
    QCOMPARE(fb.getFeedbackType(), SearchFeedback::Type::DUAL);

    SearchFeedback f((QString)"Extended");
    QCOMPARE(f.getFeedbackType(), SearchFeedback::Type::EXTENDED);
}

void SearchFeedbackTester::testGetList() {
    QList<pair> fbList = fb.getFeedbackList();
    QCOMPARE(list.size(), fbList.size());
    QCOMPARE(list.value(0).first.getMedium(), fbList.value(0).first.getMedium());
    QCOMPARE(list.value(0).second, fbList.value(0).second);

    QCOMPARE(list.value(1).first.getROI(), fbList.value(1).first.getROI());
    QCOMPARE(list.value(1).second, fbList.value(1).second);
}

void SearchFeedbackTester::testSaveLoad() {
    QFile file("testSearchFeedback.tmp");

    //write to file
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << fb;
    file.close();

    //read from file
    file.open(QIODevice::ReadOnly);
    SearchFeedback feedback;
    stream >> feedback;
    file.close();

    QCOMPARE(fb.getType(), feedback.getType());
    QCOMPARE(fb.getFeedbackType(), feedback.getFeedbackType());

    QList<pair> fList = fb.getFeedbackList();
    QList<pair> sList = feedback.getFeedbackList();
    QCOMPARE(fList.size(), sList.size());

    QCOMPARE(fList.value(0).first.getMedium(), sList.value(0).first.getMedium());
    QCOMPARE(fList.value(0).second, sList.value(0).second);

    QCOMPARE(fList.value(1).first.getROI(), sList.value(1).first.getROI());
    QCOMPARE(fList.value(1).second, sList.value(1).second);
}
