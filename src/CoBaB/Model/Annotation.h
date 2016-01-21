/**
 * Project \
 */


#ifndef _ANNOTATION_H
#define _ANNOTATION_H

#include "QDataStream.h"
#include "Serializable.h"


class Annotation: public QDataStream, public Serializable {
public: 
    
    /**
     * @param id
     */
    void Annotation(QString id);
    
    QString getId();
    
    AnnotationType getType();
    
    /**
     * @param out
     * @param annotation
     */
    QDataStream& operator<<(QDataStream& out, Annotation& annotation);
    
    /**
     * @param in
     * @param annotation
     */
    QDataStream& operator>>(QDataStream& in, Annotation& annotation);
    
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
    QString mType = unknown;
};

#endif //_ANNOTATION_H