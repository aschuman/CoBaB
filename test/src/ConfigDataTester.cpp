#include "ConfigDataTester.h"
#include <QTest>
#include <QTextStream>

Q_DECLARE_METATYPE(ConfigData::Language)

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
    QTest::addColumn<ConfigData::Language>("setLanguage");
    QTest::addColumn<ConfigData::Language>("resultLanguage");

    QTest::newRow("English") << ConfigData::ENGLISH << ConfigData::ENGLISH;
    QTest::newRow("German") << ConfigData::GERMAN << ConfigData::GERMAN;
}

void ConfigDataTester::testLanguage() {
    QFETCH(ConfigData::Language, setLanguage);
    QFETCH(ConfigData::Language, resultLanguage);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(setLanguage);
    QCOMPARE(setLanguage, resultLanguage);

}

void ConfigDataTester::testHelp_data() {
    QTest::addColumn<ConfigData::Language>("language");
    QTest::addColumn<QString>("help");

    QTest::newRow("English") << ConfigData::ENGLISH << "Help";
    QTest::newRow("German") << ConfigData::GERMAN << "Hilfe";
}

void ConfigDataTester::testHelp() {
    QFETCH(ConfigData::Language, language);
    QFETCH(QString, help);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QCOMPARE(data->getHelp(), help);
}

void ConfigDataTester::testAbout_data() {
    QTest::addColumn<ConfigData::Language>("language");
    QTest::addColumn<QString>("about");

    QTest::newRow("English") << ConfigData::ENGLISH << "About CoBaB";
    QTest::newRow("German") << ConfigData::GERMAN << "Über CoBaB";
}

void ConfigDataTester::testAbout() {
    QFETCH(ConfigData::Language, language);
    QFETCH(QString, about);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QCOMPARE(data->getAbout(), about);
}
