#ifndef ANNOTATIONTESTER_H
#define ANNOTATIONTESTER_H

#include <QObject>
#include <QTest>
#include <QtTest/QtTest>
#include "Annotation.h"

class AnnotationTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testGetters();
    void testSaveLoad();

};

#endif // ANNOTATIONTESTER_H
