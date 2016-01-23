/**
 * Project \
 */


#ifndef _CONFIGDATA_H
#define _CONFIGDATA_H

#include "Language.h"
#include <QSettings>


class ConfigData: public QSettings {
public: 
    
    static ConfigData getInstance();
    
    Language getLanguage();
    
    /**
     * @param language
     */
    void setLanguage(Language language);
    
    bool getSoundOn();
    
    /**
     * @param soundOn
     */
    void setSoundOn(bool soundOn);
    
    QString getHelp();
    
    QString getAbout();
private: 
    static ConfigData instance;
    
    ConfigData();
};

#endif //_CONFIGDATA_H
