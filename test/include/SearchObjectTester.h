#ifndef SEARCHOBJECTTESTER_H
#define SEARCHOBJECTTESTER_H

#include <QObject>
/**
 * @brief The SearchObjectTester class
 * @author Georgi
 */
class SearchObjectTester : public QObject
{
    Q_OBJECT
private slots:

    void testMedium();
    void testRectangleAnnotation();
    void testAnnotation();
    void testROI();
    void testSourceDataset();
    void testMediumIndex();
    void testType();
    void testStreamMethods();
    void testStreamMethodsRectangle();

};

#endif // SEARCHOBJECTTESTER_H
