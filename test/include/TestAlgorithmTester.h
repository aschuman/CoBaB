#ifndef TESTALGORITHMTESTER_H
#define TESTALGORITHMTESTER_H

#include <QObject>
#include <QTest>
#include "TestAlgorithm.h"

class TestAlgorithmTester : public QObject
{
    Q_OBJECT
private slots:
    void initTest();
    void testGetters();
    void testSetInputs();
    void testSetParameters();
    void testRun();
};

#endif // TESTALGORITHMTESTER_H
