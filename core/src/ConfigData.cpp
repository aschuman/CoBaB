/**
 * Project \
 */


#include "CoBaB.h"

/**
 * ConfigData implementation
 */


/**
 * @return ConfigData
 */
static ConfigData ConfigData::getInstance() {
    return null;
}

/**
 * @return Language
 */
Language ConfigData::getLanguage() {
    return null;
}

/**
 * @param language
 */
void ConfigData::setLanguage(Language language) {

}

/**
 * @return bool
 */
bool ConfigData::getSoundOn() {
    return false;
}

/**
 * @param soundOn
 */
void ConfigData::setSoundOn(bool soundOn) {

}

/**
 * @return QString
 */
QString ConfigData::getHelp() {
    return null;
}

/**
 * @return QString
 */
QString ConfigData::getAbout() {
    return null;
}

ConfigData::ConfigData() {

}
