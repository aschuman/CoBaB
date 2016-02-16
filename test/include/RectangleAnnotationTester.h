#ifndef RECTANGLEANNOTATIONTESTER_H
#define RECTANGLEANNOTATIONTESTER_H

#include <QObject>
#include "RectangleAnnotation.h"

class RectangleAnnotationTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    

private:
    int x;

};

#endif // RECTANGLEANNOTATIONTESTER_H
