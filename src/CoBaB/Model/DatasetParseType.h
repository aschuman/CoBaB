/**
 * Project \
 */


#ifndef _DATASETPARSETYPE_H
#define _DATASETPARSETYPE_H

class DatasetParseType {
public: 
    
    void DatasetParser();
private: 
    QDirIterator mIterator;
    
    /**
     * @param path
     */
    MediumType parseType(QString path);
};

#endif //_DATASETPARSETYPE_H