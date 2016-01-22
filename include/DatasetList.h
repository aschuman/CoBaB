/**
 * Project \
 */


#ifndef _DATASETLIST_H
#define _DATASETLIST_H

#include "..\..\include\Dataset.h"


class DatasetList {
public: 
    
    DatasetList();
    
    QList<Dataset> getDatasetList();
    
    /**
     * @param dataset
     */
    void addDataset(Dataset dataset);
    
    /**
     * @param path
     */
    void load(QString path);
    
    /**
     * @param path
     */
    void store(QString path);
private: 
    QList<Dataset> mDatasetList;
};

#endif //_DATASETLIST_H
