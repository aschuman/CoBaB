#include "ConfigData.h"
#include <QFile>
#include <QTextStream>

/**
 * @brief ConfigData::ConfigData Creates the ConfigData object.
 */
ConfigData::ConfigData() : QSettings("KIT", "CoBaB"){
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
ConfigData::Language ConfigData::getLanguage() {
    return (Language)QSettings::value("language", GERMAN).toInt();
}

/**
 * @brief ConfigData::setLanguage Stores the language and the help and about files in this language.
 * @param language The language chosen by the user.
 */
void ConfigData::setLanguage(Language language) {
    QSettings::setValue("language", language);
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
 * @brief ConfigData::getHelp Reads the help file in the chosen language.
 * @return The contents of the help file.
 */
QString ConfigData::getHelp() {
    Language language = getLanguage();
    switch(language) {
    case GERMAN:
        return readFile("../../help files/help_de.txt");
    case ENGLISH:
        return readFile("../../help files/help_en.txt");
    default:
        return "";
    }
}

/**
 * @brief ConfigData::getAbout Reads the about file in the chosen language.
 * @return The contents of the about file.
 */
QString ConfigData::getAbout() {
    Language language = getLanguage();
    switch(language) {
    case GERMAN:
        return readFile("../../help files/about_de.txt");
    case ENGLISH:
        return readFile("../../help files/about_en.txt");
    default:
        return "";
    }
}

/**
 * @brief ConfigData::readFile Reads the contents of the file with the given path.
 * @param path The path to the file.
 * @return The contents of the file.
 */
QString ConfigData::readFile(QString path) {
    QFile file(path);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "no file avaliable";
    }
    QTextStream in(&file);
    return in.readAll();
}
