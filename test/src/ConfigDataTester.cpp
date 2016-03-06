#include "ConfigDataTester.h"
#include <QTest>

void ConfigDataTester::initTestCase() {
    ConfigData* first = ConfigData::getInstance();
    ConfigData* second = ConfigData::getInstance();
    QCOMPARE(first, second);
}

void ConfigDataTester::testSoundOn() {
    ConfigData* data = ConfigData::getInstance();
    QVERIFY(!data->getSoundOn());

    data->setSoundOn(true);
    QVERIFY(data->getSoundOn());

    data->setSoundOn(false);
    QVERIFY(!data->getSoundOn());
}

void ConfigDataTester::testLanguage_data() {
    QTest::addColumn<QString>("setLanguage");
    QTest::addColumn<QString>("resultLanguage");

    QTest::newRow("English") << "English" << "English";
    QTest::newRow("German") << "German" << "German";
}

void ConfigDataTester::testLanguage() {
    QFETCH(QString, setLanguage);
    QFETCH(QString, resultLanguage);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(setLanguage);
    QCOMPARE(data->getLanguage(), resultLanguage);

}

void ConfigDataTester::testHelp_data() {
    QTest::addColumn<QString>("language");
    QTest::addColumn<QString>("help");

    QTest::newRow("English") << "English" << "Library";
    QTest::newRow("German") << "German" << "Bibliothek";
}

void ConfigDataTester::testHelp() {
    QFETCH(QString, language);
    QFETCH(QString, help);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QVERIFY(data->getHelp().contains(help));
}

void ConfigDataTester::testAbout_data() {
    QTest::addColumn<QString>("language");
    QTest::addColumn<QString>("about");

    QTest::newRow("English") << "English" << "content based search";
    QTest::newRow("German") << "German" << "inhaltsbasierte Suche";
}

void ConfigDataTester::testAbout() {
    QFETCH(QString, language);
    QFETCH(QString, about);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QVERIFY(data->getAbout().contains(about));
}
