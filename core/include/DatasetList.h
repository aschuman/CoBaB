#ifndef _DATASETLIST_H
#define _DATASETLIST_H

#include "Dataset.h"

/**
 * @brief The DatasetList keeps a list of Dataset and stores it.
 */
class DatasetList {

public:
    QList<Dataset> getDatasetList() const;
    void addDataset(Dataset dataset);
    void load(const QString path);
    void store(const QString path) const;

private:
    QList<Dataset> mDatasetList;            ///< The list of Dataset.
};

#endif //_DATASETLIST_H
