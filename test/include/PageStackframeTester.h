#ifndef PAGESTACKFRAMETESTER_H
#define PAGESTACKFRAMETESTER_H

#include <QObject>

class PageStackFrameTester : public QObject
{
    Q_OBJECT
private slots:
    void testConstructor_data();
    void testConstructor();
    void testSetSize();
};

#endif // PAGESTACKFRAMETESTER_H
