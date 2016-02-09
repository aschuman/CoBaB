/**
 * Project \
 */


#ifndef _DATASETLIST_H
#define _DATASETLIST_H

#include "Dataset.h"


class DatasetList {

public: 
    DatasetList();
    QList<Dataset> getDatasetList() const;
    void addDataset(Dataset dataset);
    void load(const QString path);
    void store(const QString path) const;

private: 
    QList<Dataset> mDatasetList;
};

#endif //_DATASETLIST_H
