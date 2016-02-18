#include "DatasetTester.h"
#include "Dataset.h"
#include <QtTest>

Q_DECLARE_METATYPE(Dataset::Type)

void DatasetTester::testType_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<Dataset::Type>("type");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << Dataset::Type::SINGLE_FRAME_VIDEO;
    QTest::newRow("video dataset") << "../test/testdata/Video" << Dataset::Type::VIDEO;
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << Dataset::Type::PHOTO;

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

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << "SingleFrameVideo";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "Video";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "Fotos";

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

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo"
                                                << "../test/testdata/SingleFrameVideo/SingleFrameVideo/bigbangtheory_s1e1.vob_00000.png";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "../test/testdata/videoIcon.png";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "../test/testdata/Fotos/preview.png";

}

void DatasetTester::testPreviewImage()
{
    QFETCH(QString, path);
    QFETCH(QString, image);

    Dataset dataset(path);
    QImage preview(image);
    QVERIFY(!preview.isNull());
    QCOMPARE(dataset.getPreviewPhoto(), preview.scaled(100, 100, Qt::KeepAspectRatio));

}

void DatasetTester::testMediaList_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QList<QString>>("list");

    QList<QString> list;
    list.append("test/testdata/SingleFrameVideo");
    QTest::newRow("single frame video dataset") << "SingleFrameVideo" << list;

    list.clear();
    list.append("test/testdata/Video/Titanic in 10 Sekunden.mp4");
    QTest::newRow("video dataset") << "Video" << list;

    list.clear();
    list.append("test/testdata/Fotos/000_45.bmp");
    list.append("test/testdata/Fotos/001_45.bmp");
    list.append("test/testdata/Fotos/002_45.bmp");
    QTest::newRow("photo dataset") << "Fotos" << list;

}

void DatasetTester::testMediaList()
{
    QFETCH(QString, path);
    QFETCH(QList<QString>, list);

    Dataset dataset(path);
    for(int i= 0; i < dataset.getMediaList().size(); i++) {
        QVERIFY(dataset.getMediaList().at(i)->getPath().endsWith(list.at(i)));
    }
}


void DatasetTester::testPath_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("resultPath");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << "test/testdata/SingleFrameVideo";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "test/testdata/Video";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "test/testdata/Fotos";

}

void DatasetTester::testPath()
{
    QFETCH(QString, path);
    QFETCH(QString, resultPath);

    Dataset dataset(path);
    QVERIFY(dataset.getPath().endsWith(resultPath));
}


void DatasetTester::testAnnotationsSFVideo()
{
    QString path = "../test/testdata/SingleFrameVideo";

    Dataset dataset(path);
    if(dataset.getMediaList().isEmpty()) {
        QFAIL("Media list is empty.");
    }
    QList<QPair<int, Annotation*>> list = dataset.getMediaList().first()->getAnnotationList();
    QCOMPARE(list.size(), 4);

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

void DatasetTester::testAnnotationsVideo()
{
    QString path = "../test/testdata/Video";

    Dataset dataset(path);
    if(dataset.getMediaList().isEmpty()) {
        QFAIL("Media list is empty.");
    }
    QList<QPair<int, Annotation*>> list = dataset.getMediaList().first()->getAnnotationList();
    QVERIFY(list.isEmpty());
}

void DatasetTester::testAnnotationsPhoto()
{
    QString path = "../test/testdata/Fotos";

    Dataset dataset(path);
    if(dataset.getMediaList().isEmpty()) {
        QFAIL("Media list is empty.");
    }
    QList<QPair<int, Annotation*>> list = dataset.getMediaList().at(0)->getAnnotationList();
    QCOMPARE(list.size(), 1);
    QCOMPARE(list.at(0).first, 0);
    QRect rect(0, 0, 48, 128);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(0).second))->normalized(), rect);

    list = dataset.getMediaList().at(1)->getAnnotationList();
    QCOMPARE(list.size(), 1);
    QCOMPARE(list.at(0).first, 0);
    rect.setRect(0, 0, 48, 128);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(0).second))->normalized(), rect);

    list = dataset.getMediaList().at(2)->getAnnotationList();
    QCOMPARE(list.size(), 1);
    QCOMPARE(list.at(0).first, 0);
    rect.setRect(0, 0, 48, 128);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(0).second))->normalized(), rect);

}
