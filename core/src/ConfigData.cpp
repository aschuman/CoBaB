#include "ConfigData.h"
#include <QTranslator>
#include <QApplication>

/**
 * @brief ConfigData::ConfigData Creates the ConfigData object.
 */
ConfigData::ConfigData() : QSettings("IOSB", "CoBaB"){
    languages.insert("German", QLocale(QLocale::German));
    languages.insert("English", QLocale(QLocale::English));
}

/**
 * @brief ConfigData::instance The instance of ConfigData.
 */
ConfigData* ConfigData::instance = nullptr;

/**
 * @brief ConfigData::getInstance This method ensures that there is only one instance of ConfigData.
 * @return The only instance of ConfigData.
 */
ConfigData* ConfigData::getInstance() {
    if(instance == nullptr) {
        instance = new ConfigData();
    }
    return instance;
}

/**
 * @brief ConfigData::getLanguage Loads the language chosen by the user.
 * @return The language chosen by the user.
 */
QString ConfigData::getLanguage() {
    return QSettings::value("language", "German").toString();
}

/**
 * @brief ConfigData::setLanguage Stores the language and sets the translator.
 * @param language The language chosen by the user.
 */
void ConfigData::setLanguage(QString language) {
    QSettings::setValue("language", language);

    QTranslator translator;
    if(languages.contains(language)) {
        if(translator.load(languages.value(language), QLatin1String("CoBaB"), QLatin1String("_"), QLatin1String(":/resources/translations"))) {
            QApplication::installTranslator(&translator);
        }
    }
}

/**
 * @brief ConfigData::getSoundOn Loads the sound setting chosen by the user.
 * @return True if the user wants to hear a notification sound when the search is finished.
 */
bool ConfigData::getSoundOn() {
    return QSettings::value("soundOn", false).toBool();
}

/**
 * @brief ConfigData::setSoundOn Stores the sound setting chosen by the user.
 * @param soundOn True if the user wants to hear a notification sound when the search is finished.
 */
void ConfigData::setSoundOn(bool soundOn) {
    QSettings::setValue("soundOn", soundOn);
}

/**
 * @brief ConfigData::getHelp Returns the help string in the chosen language.
 * @return The help string.
 */
QString ConfigData::getHelp() {
    QString help = tr("Help");
    return help;
}

/**
 * @brief ConfigData::getAbout Returns the about string in the chosen language.
 * @return The about string.
 */
QString ConfigData::getAbout() {
    QString about = tr("About CoBaB");
    return about;
}

