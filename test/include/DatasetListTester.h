#ifndef DATASETLISTTESTER_H
#define DATASETLISTTESTER_H

#include <QObject>
#include "DatasetList.h"

class DatasetListTester : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testList();
    void testLoadStore();

private:
    DatasetList mList;

};

#endif // DATASETLISTTESTER_H
