#ifndef SEARCHRESULTELEMENTTESTER_H
#define SEARCHRESULTELEMENTTESTER_H

#include <QObject>
#include "SearchResultElement.h"
#include "SearchObject.h"
/**
 * @brief The SearchResultElementTester class
 * @author Violina
 */
class SearchResultElementTester : public QObject
{
    Q_OBJECT
private slots:

    void testScore();
    void testSearchObject();
    void testStreamMethods();

};

#endif // SEARCHRESULTELEMENTTESTER_H
