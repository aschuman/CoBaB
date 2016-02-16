#ifndef ANNOTATIONTESTER_H
#define ANNOTATIONTESTER_H

#include <QObject>
#include "Annotation.h"

class AnnotationTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    

private:
    int x;

};

#endif // ANNOTATIONTESTER_H
