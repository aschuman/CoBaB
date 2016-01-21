/**
 * Project \
 */


#ifndef _CONFIGDATA_H
#define _CONFIGDATA_H

#include "QSettings.h"


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
    
    void ConfigData();
};

#endif //_CONFIGDATA_H