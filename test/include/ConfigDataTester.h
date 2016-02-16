#ifndef CONFIGDATATESTER_H
#define CONFIGDATATESTER_H

#include <QObject>
#include "ConfigData.h"

class ConfigDataTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testSoundOn();
    void testLanguage_data();
    void testLanguage();
    void testHelp_data();
    void testHelp();
    void testAbout_data();
    void testAbout();

};

#endif // CONFIGDATATESTER_H
