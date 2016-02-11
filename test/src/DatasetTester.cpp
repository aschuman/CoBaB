#include "DatasetTester.h"
#include "Dataset.h"
#include <QtTest>

Q_DECLARE_METATYPE(Dataset::Type)

void DatasetTester::testType_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<Dataset::Type>("type");

    QTest::newRow("single frame video dataset") << "testdata/SingleFrameVideo" << Dataset::Type::SINGLE_FRAME_VIDEO;
    QTest::newRow("video dataset")     << "testdata/Video" << Dataset::Type::VIDEO;
    QTest::newRow("photo dataset") << "testdata/Fotos" << Dataset::Type::PHOTO;

}

void DatasetTester::testType()
{
    QFETCH(QString, path);
    QFETCH(Dataset::Type, type);

    Dataset dataset(path);
    QCOMPARE(dataset.getType(), type);

}

void DatasetTester::testName_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("name");

    QTest::newRow("single frame video dataset") << "testdata/SingleFrameVideo" << "SingleFrameVideo";
    QTest::newRow("video dataset") << "testdata/Video" << "Video";
    QTest::newRow("photo dataset") << "testdata/Fotos" << "Fotos";

}

void DatasetTester::testName()
{
    QFETCH(QString, path);
    QFETCH(QString, name);

    Dataset dataset(path);
    QCOMPARE(dataset.getName(), name);

}


void DatasetTester::testPreviewImage_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("image");

    QTest::newRow("single frame video dataset") << "testdata/SingleFrameVideo" << "testdata/SingleFrameVideo/bigbangtheory_s1e1.vob_00000.png";
    QTest::newRow("photo dataset") << "testdata/Fotos" << "testdata/Fotos/preview.png";

}

void DatasetTester::testPreviewImage()
{
    QFETCH(QString, path);
    QFETCH(QString, image);

    Dataset dataset(path);
    QImage preview(image);
    QCOMPARE(dataset.getPreviewPhoto(), preview);

}


void DatasetTester::testMediaList_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QList<QString>>("list");

    QList<QString> list;
    list.append("testdata/SingleFrameVideo");
    QTest::newRow("single frame video dataset") << "testdata/SingleFrameVideo" << list;

    list.clear();
    list.append("testdata/Video/Titanic in 10 Sekunden.mp4");
    QTest::newRow("video dataset") << "testdata/Video" << list;

    list.clear();
    list.append("testdata/Fotos/000_45.bmp");
    list.append("testdata/Fotos/001_45.bmp");
    list.append("testdata/Fotos/002_45.bmp");
    QTest::newRow("photo dataset") << "testdata/Fotos" << list;

}

void DatasetTester::testMediaList()
{
    QFETCH(QString, path);
    QFETCH(QList<QString>, list);

    Dataset dataset(path);
    QList<QString> mediaList;
    for(int i= 0; i < dataset.getMediaList().size(); i++) {
        mediaList.append(dataset.getMediaList().at(i)->getPath());
    }
    QCOMPARE(mediaList, list);

}


void DatasetTester::testPath_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("resultPath");

    QTest::newRow("single frame video dataset") << "testdata/SingleFrameVideo" << "testdata/SingleFrameVideo";
    QTest::newRow("video dataset") << "testdata/Video" << "testdata/Video";
    QTest::newRow("photo dataset") << "testdata/Fotos" << "testdata/Fotos";

}

void DatasetTester::testPath()
{
    QFETCH(QString, path);
    QFETCH(QString, resultPath);

    Dataset dataset(path);

    QCOMPARE(dataset.getPath(), resultPath);
}


void DatasetTester::testAnnotations()
{
    QString path = "testdata/SingleFrameVideo";

    Dataset dataset(path);
    QList<QPair<int, Annotation*>> list = dataset.getMediaList().first()->getAnnotationList();

    QCOMPARE(list.at(0).first, 1);
    QRect rect(315, 53, 169, 570);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(0).second))->normalized(), rect);

    QCOMPARE(list.at(1).first, 1);
    rect.setRect(535, 120, 186, 606);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(1).second))->normalized(), rect);

    QCOMPARE(list.at(2).first, 2);
    rect.setRect(295, 75, 90, 337);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(2).second))->normalized(), rect);

    QCOMPARE(list.at(3).first, 2);
    rect.setRect(431, 98, 107, 351);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(3).second))->normalized(), rect);



}
