#ifndef SEARCHFEEDBACKTESTER_H
#define SEARCHFEEDBACKTESTER_H

#include <QObject>
#include <QTest>
#include <QtTest/QtTest>
#include "SearchFeedback.h"

typedef QPair<SearchObject, int> pair;

class SearchFeedbackTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testGetType();
    void testGetList();
    void testSaveLoad();

};

#endif // SEARCHFEEDBACKTESTER_H
