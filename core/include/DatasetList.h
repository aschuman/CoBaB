#ifndef _DATASETLIST_H
#define _DATASETLIST_H

#include "Dataset.h"

/**
 * @brief The DatasetList keeps a list of Dataset and stores it.
 * @author Marie
 */
class DatasetList {

public:
    const QList<Dataset>& getDatasetList() const;
    void addDataset(const Dataset& dataset);
    void load(const QString& path);
    void store(const QString path) const;

private:
    QList<Dataset> mDatasetList;            ///< The list of Dataset.
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<DatasetList>)

#endif //_DATASETLIST_H
