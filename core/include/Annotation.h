/**
 * Project \
 */


#ifndef _ANNOTATION_H
#define _ANNOTATION_H

#include "Serializable.h"
#include "Annotation.h"
#include "AnnotationType.h"
#include <QDataStream>


class Annotation: public Serializable {
public: 
    
    /**
     * @param id
     */
    Annotation(QString id);
    
    QString getId();
    
    AnnotationType getType();
    
    /**
     * @param out
     * @param annotation
     */
    friend QDataStream& operator<<(QDataStream& out, Annotation& annotation);
    
    /**
     * @param in
     * @param annotation
     */
    friend QDataStream& operator>>(QDataStream& in, Annotation& annotation);
    
    /**
     * @param in
     */
    void toStream(QDataStream in);
    
    /**
     * @param out
     */
    void fromStream(QDataStream out);
protected: 
    QString mId;
    QString mType = "unknown";
};

#endif //_ANNOTATION_H
