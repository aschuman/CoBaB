#ifndef _CONFIGDATA_H
#define _CONFIGDATA_H

#include <QSettings>
#include <QLocale>
#include <QHash>
#include <QTranslator>

/**
 * @brief The ConfigData class stores the user settings language and notitification sound.
 * The help and about files are read.
 * @author Marie
 */
class ConfigData : public QSettings{
    Q_OBJECT

public: 
    static ConfigData* getInstance();
    QString getLanguage();
    void setLanguage(QString language);
    bool getSoundOn();
    void setSoundOn(bool soundOn);
    QString getHelp();
    QString getAbout();
    QString translate(const char *className, const char *text);

private:
    QHash<QString, QLocale> languages;    ///< A map which contains the avaliable languages and corresponding QLocales for the translator.
    static ConfigData* instance;
    ConfigData();
    ConfigData(const ConfigData&);
    ConfigData& operator=(const ConfigData&);
    QTranslator mTranslator;

};

#endif //_CONFIGDATA_H
