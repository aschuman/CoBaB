#ifndef SEARCHRESULTTESTER_H
#define SEARCHRESULTTESTER_H

#include <QObject>
#include "SearchResult.h"
#include "SearchResultElement.h"
/**
 * @brief The SearchResultTester class
 * @author Violina
 */
class SearchResultTester : public QObject
{
    Q_OBJECT
private slots:
    void testType();
    void testList();
    void testSort();
    void testStreamMethods();

};

#endif // SEARCHRESULTTESTER_H
