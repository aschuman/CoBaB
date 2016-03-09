#include "ConfigData.h"
#include <QTranslator>
#include <QApplication>


/**
 * @brief ConfigData::ConfigData Creates the ConfigData object.
 */
ConfigData::ConfigData() : QSettings("IOSB", "CoBaB"){
    Q_INIT_RESOURCE(application);
    languages.insert("German", QLocale(QLocale::German));
    languages.insert("English", QLocale(QLocale::English));
    mTranslator = new QTranslator(0);
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
    if(languages.contains(language)) {
        if(mTranslator->load(languages.value(language), QLatin1String("CoBaB"), QLatin1String("_"), QLatin1String(":/resources/translations"))) {
            qApp->installTranslator(mTranslator);
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
    return tr("Bibliothek:\nEnthält die zuletzt verwendeten Datensätze und die Datensätze aus dem Standardordner, der per Kommandozeile übergeben werden kann.\n"
    "Per Doppelklick wird der Datensatz ausgewählt, in dem sich das Bild/Video befindet, das als Grundlage für die inhaltsbasierte Suche dienen soll. \n \n"
    "Viewer:\nÜber die Buttons 'vorheriges' und 'nächstes' wird das Bild/Video ausgewählt, das als Grundlage für die inhaltsbasierte Suche dienen soll. \n"
    "Bei einem Rechtsklick auf das Bild werden die verfügbaren Suchalgorithmen aufgelistet. "
    "Fährt man mit der Maus über einen solchen Algorithmus, erscheint eine Beschreibung zu diesem. "
    "Durch Klicken auf einen Algorithmus kann mit dem Programm fortgefahren werden. \n"
    "In den Bildern werden außerdem, falls vorhanden, Annotationen angezeigt. \n"
    "Nach einem Klick auf den Button 'Bereich auswählen' kann ein eigenes Rechteck auf dem Bild gezogen werden. "
    "Mit einem Rechtsklick in die Annotation oder das gezogene Rechteck werden die dafür verfügbaren Algorithmen angezeigt. \n\n"
    "Parameter:\nNach der Auswahl eines Algorithmus kann man Parameter für den diesen festlegen. "
    "Außerdem können weitere Datensätze ausgewählt werden, in denen gesucht werden soll. \n \n"
    "Bestätigung:\nHier wird die aktuelle Auswahl angezeigt, die dem Algorithmus übergeben wird. \n \n"
    "Ergebnisse:\nDas Suchergebnis kann als Lesezeichen gespeichert werden. \n"
    "Die Bilder können als positiv (grüner Kasten, ein Klick auf das Bild), negativ (roter Kasten, zweiter Klick) oder wieder neutral (dritter Klick) bewertet werden.\n"
    "Durch einen Klick auf den Button 'Erneut suchen' wird das Feedback an den Algorithmus übermittelt und eine neue verbesserte Suche gestartet.");
}

/**
 * @brief ConfigData::getAbout Returns the about string in the chosen language.
 * @return The about string.
 */
QString ConfigData::getAbout() {
    return tr("CoBaB ermöglicht es, anhand eines ausgewählten Bildes"
    " oder Videos eine inhaltsbasierte Suche in Bild- oder Videodaten durchzuführen."
    " Als Ergebnis liefert CoBaB eine Auswahl ähnlicher Bilder oder Videos. Durch die Eingabe von Feedback kann diese Auswahl verfeinert werden.\n\n"
    "Autoren: Anja Blechinger, Marie Bommersheim, Georgi Georgiev, Tung Nguyen, Vincent Winkler, Violina Zhekova");
}
