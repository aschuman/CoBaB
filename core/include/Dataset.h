/**
 * Project \
 */


#ifndef _DATASET_H
#define _DATASET_H

#include "Medium.h"
#include "DatasetType.h"
#include <QDir>
#include <QDataStream>
#include <QImage>

class Dataset {
public: 
    
    /**
     * @param path
     */
    Dataset(QString path);
    
    QString getName();
    
    int getNumberOfMedia();
    
    QImage getPreviewPhoto();
    
    QList<Medium> getMediaList();
    
    QString getPath();
    
    DatasetType getType();
protected: 
    QString mName;
    QImage mPreviewPhoto;
    QList<Medium> mMediaList;
    QString mPath;
    DatasetType mDatasetType;
private: 
    
    void createPreviewPhoto();
};

#endif //_DATASET_H