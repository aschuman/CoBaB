#ifndef RECTANGLEANNOTATIONTESTER_H
#define RECTANGLEANNOTATIONTESTER_H

#include <QObject>
#include <QTest>
#include <QtTest/QtTest>
#include "RectangleAnnotation.h"

class RectangleAnnotationTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testGetters();
    void testSaveLoad();
};

#endif // RECTANGLEANNOTATIONTESTER_H
