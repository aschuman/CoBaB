#ifndef SEARCHOBJECTTESTER_H
#define SEARCHOBJECTTESTER_H

#include <QObject>

class SearchObjectTester : public QObject
{
    Q_OBJECT
private slots:
    void testMedium_data();
    void testMedium();

//    void testAnnotation_data();
//    void testAnnotation();

//    void testROI_data();
//    void testROI();

//    void testSourceDataset_data();
//    void testSourceDataset();

//    void testMediumIndex_data();
//    void testMediumIndex();

//    void testToStream();
//    void testFromStream();

#endif // SEARCHOBJECTTESTER_H
