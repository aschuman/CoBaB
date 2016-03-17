#include "ConfigDataTester.h"
#include <QTest>

/**
 * @brief ConfigDataTester::initTestCase Loads two ConfigData instances and ensures that they are the same.
 */
void ConfigDataTester::initTestCase() {
    ConfigData* first = ConfigData::getInstance();
    ConfigData* second = ConfigData::getInstance();
    QCOMPARE(first, second);
}

/**
 * @brief ConfigDataTester::testSoundOn Tests whether the sound is correcty stored.
 */
void ConfigDataTester::testSoundOn() {
    ConfigData* data = ConfigData::getInstance();

    data->setSoundOn(true);
    QVERIFY(data->getSoundOn());

    data->setSoundOn(false);
    QVERIFY(!data->getSoundOn());
}

/**
 * @brief ConfigDataTester::testLanguage_data The languages to test are German and English.
 */
void ConfigDataTester::testLanguage_data() {
    QTest::addColumn<QString>("setLanguage");
    QTest::addColumn<QString>("resultLanguage");

    QTest::newRow("English") << "English" << "English";
    QTest::newRow("German") << "German" << "German";
}

/**
 * @brief ConfigDataTester::testLanguage_data Changes the language and tests whether is correcty stored.
 */
void ConfigDataTester::testLanguage() {
    QFETCH(QString, setLanguage);
    QFETCH(QString, resultLanguage);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(setLanguage);
    QCOMPARE(data->getLanguage(), resultLanguage);

}

/**
 * @brief ConfigDataTester::testHelp_data The help test needs to be executed in both languages.
 */
void ConfigDataTester::testHelp_data() {
    QTest::addColumn<QString>("language");
    QTest::addColumn<QString>("help");

    QTest::newRow("English") << "English" << "Library";
    QTest::newRow("German") << "German" << "Bibliothek";
}

/**
 * @brief ConfigDataTester::testHelp Tests whether the help text contains information about the library.
 */
void ConfigDataTester::testHelp() {
    QFETCH(QString, language);
    QFETCH(QString, help);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QVERIFY(data->getHelp().contains(help));
}

/**
 * @brief ConfigDataTester::testAbout_data The about test needs to be executed in both languages.
 */
void ConfigDataTester::testAbout_data() {
    QTest::addColumn<QString>("language");
    QTest::addColumn<QString>("about");

    QTest::newRow("English") << "English" << "content based search";
    QTest::newRow("German") << "German" << "inhaltsbasierte Suche";
}

/**
 * @brief ConfigDataTester::testAbout Tests whether the about test contains information about content based search.
 */
void ConfigDataTester::testAbout() {
    QFETCH(QString, language);
    QFETCH(QString, about);

    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(language);
    QVERIFY(data->getAbout().contains(about));
}
