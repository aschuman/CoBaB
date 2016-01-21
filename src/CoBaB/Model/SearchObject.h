/**
 * Project \
 */


#ifndef _SEARCHOBJECT_H
#define _SEARCHOBJECT_H

#include "Serializable.h"


class SearchObject: public Serializable {
public: 
    
    void SearchObject();
    
    QString getMedium();
    
    /**
     * @param medium
     */
    void setMedium(QString medium);
    
    Annotation getAnnotation();
    
    /**
     * @param annotation
     */
    void setAnnotation(Annotation annotation);
    
    QRect getROI();
    
    /**
     * @param ROI
     */
    void setROI(QRect ROI);
    
    Dataset getSourceDataset();
    
    /**
     * @param dataset
     */
    void setSourceDataset(Dataset dataset);
    
    int getMediumIndex();
    
    /**
     * @param index
     */
    void setMediumIndex(int index);
    
    /**
     * @param out
     * @param searchObject
     */
    QDataStream& operator<<(QDataStream& out, SearchObject& searchObject);
    
    /**
     * @param in
     * @param searchObject
     */
    QDataStream& operator>>(QDataStream& in, SearchObject& searchObject);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
private: 
    QString mMedium;
    Annotation mAnnotation;
    QRect mROI;
    QString mSourceDataset;
    int mMediumIndex;
};

#endif //_SEARCHOBJECT_H