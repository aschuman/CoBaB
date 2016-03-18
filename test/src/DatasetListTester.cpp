#include "DatasetListTester.h"
#include <QTest>

/**
 * @brief DatasetListTester::initTestCase Generates a Photo, Video, and SingleFrameVideo dataset
 * and appends them to the list.
 */
void DatasetListTester::initTestCase() {
    Dataset photos("../test/testdata/Fotos");
    Dataset videos("../test/testdata/Video");
    Dataset singleFrameVideos("../test/testdata/SingleFrameVideo");
    mList.addDataset(photos);
    mList.addDataset(videos);
    mList.addDataset(singleFrameVideos);
}

/**
 * @brief DatasetListTester::testList Tests whether the datasets are correctly appended to the list.
 */
void DatasetListTester::testList() {
    QList<Dataset> list = mList.getDatasetList();
    QCOMPARE(list.size(), 3);
    QCOMPARE(list.at(0).getName(), (QString)"Fotos");
    QCOMPARE(list.at(1).getName(), (QString)"Video");
    QCOMPARE(list.at(2).getName(), (QString)"SingleFrameVideo");
}

/**
 * @brief DatasetListTester::testLoadStore Stores the dataset list and loads it again
 * and compares whether they contain the same datasets.
 */
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
