#include "ColorSearchTest.h"

#include "ColorSearch.h"

#include <QtTest/QtTest>

#include <iostream>

using namespace std;





/**
 * @brief Test loading of ColorSearch as a plugin.
 */
void ColorSearchTest::pluginTest()
{
    QDir plugindir("../../../plugins/");

    ColorSearch* alg = nullptr;
    for (const QString& fname : plugindir.entryList(QDir::Files))
    {
        QPluginLoader loader(plugindir.absoluteFilePath(fname));
        QObject* plugin = loader.instance();
        alg = qobject_cast<ColorSearch*>(plugin);
        if (alg)
        {
            QVERIFY(alg->initialize(&loader));
            break;
        }
    }
    QVERIFY(alg);
}



/**
 * @brief MEDIUM search testcase.
 */
void ColorSearchTest::mediumSearchTest()
{
    SearchQuery query;
    query.setDatasets({"../../../test/testdata/Fotos"});
    SearchObject obj;
    obj.setSourceDataset("../../../test/testdata/Fotos");
    obj.setMedium(QDir("../../../test/testdata/Fotos/000_45.bmp").absolutePath());
    obj.setMediumIndex(0);
    obj.setType(SearchObject::MEDIUM);
    query.setSearchObject(obj);

    ColorSearch search;

    QList<DataPacket*> in;
    in.append(&query);
    bool ok = search.setInputs(in);
    QVERIFY(ok);

    QList<DataPacket*> out = search.run();
    QVERIFY(out.size() == 1);
}



/**
 * @brief ROI search testcase.
 */
void ColorSearchTest::roiSearchTest()
{
    SearchQuery query;
    query.setDatasets({"../../../test/testdata/Fotos"});
    SearchObject obj;
    obj.setSourceDataset("../../../test/testdata/Fotos");
    obj.setMedium(QDir("../../../test/testdata/Fotos/001_45.bmp").absolutePath());
    obj.setMediumIndex(0);
    obj.setROI(QRect(13,24,25,37));
    obj.setType(SearchObject::ROI);
    query.setSearchObject(obj);

    ColorSearch search;

    QList<DataPacket*> in;
    in.append(&query);
    bool ok = search.setInputs(in);
    QVERIFY(ok);

    QList<DataPacket*> out = search.run();
    QVERIFY(out.size() == 1);
}



/**
 * @brief ANNOTATION search testcase.
 */
void ColorSearchTest::annotationSearchTest()
{
    SearchQuery query;
    query.setDatasets({"../../../test/testdata/SingleFrameVideo"});
    SearchObject obj;
    obj.setSourceDataset("../../../test/testdata/SingleFrameVideo");
    obj.setMedium(QDir("../../../test/testdata/SingleFrameVideo/SingleFrameVideo/").absolutePath());
    obj.setMediumIndex(1);
    RectangleAnnotation* ann = new RectangleAnnotation("11", "Person");
    ann->setX(315);
    ann->setY(53);
    ann->setWidth(169);
    ann->setHeight(570);
    obj.setAnnotation(ann);
    obj.setType(SearchObject::ANNOTATION);
    query.setSearchObject(obj);

    ColorSearch search;

    QList<DataPacket*> in;
    in.append(&query);
    bool ok = search.setInputs(in);
    QVERIFY(ok);

    QList<DataPacket*> out = search.run();
    QVERIFY(out.size() == 1);
}

QTEST_MAIN(ColorSearchTest)
