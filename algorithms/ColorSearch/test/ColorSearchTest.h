#ifndef COLORSEARCHTEST_H
#define COLORSEARCHTEST_H

#include <QObject>





/**
 * @brief Main testclass for ColorSearch.
 */
class ColorSearchTest : public QObject
{
    Q_OBJECT

private slots:
    void pluginTest();
    void mediumSearchTest();
    void roiSearchTest();
    void annotationSearchTest();
};

#endif
