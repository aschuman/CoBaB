#ifndef SEARCHOBJECTTESTER_H
#define SEARCHOBJECTTESTER_H

#include <QObject>

class SearchObjectTester : public QObject
{
    Q_OBJECT
private slots:

    void testMedium();
    void testAnnotation();
    void testROI();
    void testSourceDataset();
    void testMediumIndex();
    void testStreamMethods();

};

#endif // SEARCHOBJECTTESTER_H
