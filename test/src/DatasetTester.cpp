#include "DatasetTester.h"
#include "Dataset.h"
#include <QtTest>

Q_DECLARE_METATYPE(Dataset::Type)

void DatasetTester::testValid_data() {
    QTest::addColumn<QString>("path");
    QTest::addColumn<bool>("valid");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << true;
    QTest::newRow("video dataset") << "../test/testdata/Video" << false; //because there is no video player
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << true;
    QTest::newRow("invalid, non existing directory") << "sdkkjhgnj" << false;
    QTest::newRow("invalid, existing directory") << "../core" << false;
}

void DatasetTester::testValid() {
    QFETCH(QString, path);
    QFETCH(bool, valid);

    Dataset dataset(path);
    QCOMPARE(dataset.isValid(), valid);
}

/**
 * @brief DatasetTester::testType_data The Dataset type needs to be tested with the available types
 * SingleFrameVideo, Video, and Photo
 */
void DatasetTester::testType_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<Dataset::Type>("type");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << Dataset::Type::SINGLE_FRAME_VIDEO;
    QTest::newRow("video dataset") << "../test/testdata/Video" << Dataset::Type::VIDEO;
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << Dataset::Type::PHOTO;

}

/**
 * @brief DatasetTester::testType Tests whether the Dataset type is correctly set.
 */
void DatasetTester::testType()
{
    QFETCH(QString, path);
    QFETCH(Dataset::Type, type);

    Dataset dataset(path);
    QCOMPARE(dataset.getType(), type);

}

/**
 * @brief DatasetTester::testName_data The name test needs to be executed for all types.
 */
void DatasetTester::testName_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("name");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << "SingleFrameVideo";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "Video";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "Fotos";
    QTest::newRow("invalid dataset") << "lsflnlkdfa" << "";
}

/**
 * @brief DatasetTester::testName Tests whether the name of the datasets is correcty set.
 */
void DatasetTester::testName()
{
    QFETCH(QString, path);
    QFETCH(QString, name);

    Dataset dataset(path);
    QCOMPARE(dataset.getName(), name);

}

/**
 * @brief DatasetTester::testPreviewImage_data The preview image needs to be tested for all types and an invalid dataset.
 */
void DatasetTester::testPreviewImage_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("image");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo"
                                                << "../test/testdata/SingleFrameVideo/SingleFrameVideo/bigbangtheory_s1e1.vob_00000.png";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "../test/testdata/videoIcon.png";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "../test/testdata/Fotos/preview.png";
    QTest::newRow("invalid dataset") << "bjkkb" << "";

}

/**
 * @brief DatasetTester::testPreviewImage Tests whether the preview image is correctly set.
 */
void DatasetTester::testPreviewImage()
{
    QFETCH(QString, path);
    QFETCH(QString, image);

    Dataset dataset(path);
    QImage preview(image);
    if(image != "") {
        QVERIFY(!preview.isNull());
        QCOMPARE(dataset.getPreviewPhoto(), preview.scaledToHeight(100));
    } else {
        QCOMPARE(dataset.getPreviewPhoto(), preview);
    }

}

/**
 * @brief DatasetTester::testMediaList_data The media list test needs to be executed for all types.
 */
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

    list.clear();
    QTest::newRow("invalid dataset") << "kjbuzv" << list;

}

/**
 * @brief DatasetTester::testMediaList Tests whether the correct media list is correctly set.
 */
void DatasetTester::testMediaList()
{
    QFETCH(QString, path);
    QFETCH(QList<QString>, list);

    Dataset dataset(path);
    for(int i = 0; i < dataset.getMediaList().size(); i++) {
        QVERIFY(dataset.getMediaList().at(i)->getPath().endsWith(list.at(i)));
    }
}

/**
 * @brief DatasetTester::testPath_data The path test needs to be executed for all types.
 */
void DatasetTester::testPath_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("resultPath");

    QTest::newRow("single frame video dataset") << "../test/testdata/SingleFrameVideo" << "test/testdata/SingleFrameVideo";
    QTest::newRow("video dataset") << "../test/testdata/Video" << "test/testdata/Video";
    QTest::newRow("photo dataset") << "../test/testdata/Fotos" << "test/testdata/Fotos";
    QTest::newRow("invalid dataset") << "ksdgsn" << "";

}

/**
 * @brief DatasetTester::testPath Tests whether the path of the dataset is correctly set.
 */
void DatasetTester::testPath()
{
    QFETCH(QString, path);
    QFETCH(QString, resultPath);

    Dataset dataset(path);
    if(resultPath == "") {
        QCOMPARE(dataset.getPath(), resultPath);
    } else {
        QVERIFY(dataset.getPath().endsWith(resultPath));
    }
}

/**
 * @brief DatasetTester::testAnnotationsSFVideo Tests the annotations in a SingleFrameVideo.
 */
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

/**
 * @brief DatasetTester::testAnnotationsVideo Ensures that the video does not contain annotations.
 */
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

/**
 * @brief DatasetTester::testAnnotationsPhoto Tests whether the annotations in the photo dataset are correctly set.
 */
void DatasetTester::testAnnotationsPhoto()
{
    QString path = "../test/testdata/Fotos";

    Dataset dataset(path);
    if(dataset.getMediaList().isEmpty()) {
        QFAIL("Media list is empty.");
    }
    QList<QPair<int, Annotation*>> list = dataset.getMediaList().at(0)->getAnnotationList();
    QCOMPARE(list.size(), 2);
    QCOMPARE(list.at(0).first, 0);
    QRect rect(0, 0, 48, 128);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(0).second))->normalized(), rect);
    QCOMPARE(list.at(1).first, 0);
    rect.setRect(17, 0, 16, 17);
    QCOMPARE((static_cast<RectangleAnnotation*>(list.at(1).second))->normalized(), rect);

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
