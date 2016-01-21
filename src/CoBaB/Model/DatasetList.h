/**
 * Project \
 */


#ifndef _DATASETLIST_H
#define _DATASETLIST_H

#include "DataSetInterface.h"


class DatasetList: public DataSetInterface {
public: 
    
    void DatasetList();
    
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