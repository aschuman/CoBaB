#include "DatasetListTester.h"
#include <QTest>

void DatasetListTester::initTestCase() {
    Dataset photos("../../test/testdata/Fotos");
    Dataset videos("../../test/testdata/Video");
    Dataset singleFrameVideos("../../test/testdata/SingleFrameVideo");
    mList.addDataset(photos);
    mList.addDataset(videos);
    mList.addDataset(singleFrameVideos);
}

void DatasetListTester::testList() {
    QList<Dataset> list = mList.getDatasetList();
    QCOMPARE(list.size(), 3);
    QCOMPARE(list.at(0).getName(), (QString)"Fotos");
    QCOMPARE(list.at(1).getName(), (QString)"Video");
    QCOMPARE(list.at(2).getName(), (QString)"SingleFrameVideo");
}

void DatasetListTester::testLoadStore() {
    QString path("datasets.txt");
    mList.store(path);
    mList.load(path);
    QList<Dataset> list = mList.getDatasetList();
    QCOMPARE(list.size(), 3);
    QCOMPARE(list.at(0).getName(), (QString)"Fotos");
    QCOMPARE(list.at(1).getName(), (QString)"Video");
    QCOMPARE(list.at(2).getName(), (QString)"SingleFrameVideo");
}
