#ifndef SEARCHQUERYTESTER_H
#define SEARCHQUERYTESTER_H

#include <QObject>
/**
 * @brief The SearchQueryTester class
 * @author Georgi
 */
class SearchQueryTester : public QObject
{
    Q_OBJECT

private slots:

    void testType();
    void testDatasets();
    void testSearchObject();
    void testStreamMethods();


};


#endif // SEARCHQUERYTESTER_H
