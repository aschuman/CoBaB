#ifndef DATASETLISTTESTER_H
#define DATASETLISTTESTER_H

#include <QObject>
#include "DatasetList.h"

/**
 * @brief The DatasetListTester class Tests the DatasetList class.
 */
class DatasetListTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testList();
    void testLoadStore();

private:
    DatasetList mList;      //< The dataset list to test.

};

#endif // DATASETLISTTESTER_H
