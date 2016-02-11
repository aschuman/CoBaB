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

    Annotation(QString id, QString type);
    
    QString getId();
    
    AnnotationType getType();

    friend QDataStream& operator<<(QDataStream& out, Annotation& annotation);

    friend QDataStream& operator>>(QDataStream& in, Annotation& annotation);
    
    void toStream(QDataStream in);
    
    void fromStream(QDataStream out);

protected: 
    QString mId;
    QString mType = "unknown";
};

#endif //_ANNOTATION_H
