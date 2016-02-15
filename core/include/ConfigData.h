#ifndef _CONFIGDATA_H
#define _CONFIGDATA_H

#include <QSettings>

/**
 * @brief The ConfigData class stores the user settings language and notitification sound.
 * The help and about files are read.
 * @author Marie
 */
class ConfigData : public QSettings{

public: 
    static ConfigData* getInstance();
    enum Language { GERMAN, ENGLISH };
    Language getLanguage();
    void setLanguage(Language language);
    bool getSoundOn();
    void setSoundOn(bool soundOn);
    QString getHelp();
    QString getAbout();

private: 
    static ConfigData* instance;
    ConfigData();
    QString readFile(QString path);
    ConfigData(const ConfigData&);
    ConfigData& operator=(const ConfigData&);

};

#endif //_CONFIGDATA_H
