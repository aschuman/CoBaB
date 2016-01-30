/**
 * Project \
 */


#ifndef _MEDIUM_H
#define _MEDIUM_H

#include "Annotation.h"
#include "MediumType.h"

class Medium {
public: 
    
    /**
     * @param path
     * @param annotations
     */
    Medium(QString path, QList<QPair<int, Annotation>> annotations);
    
    MediumType getType();
    
    QList<QPair<int, Annotation>> getAnnotationList();

    QString getPath();

protected: 
    QString mRelativePath;
    MediumType mMediumType;
    QList<QPair<int, Annotation>> mAnnotationList;
};

#endif //_MEDIUM_H
