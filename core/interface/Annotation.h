/**
 * Project \
 */


#ifndef _ANNOTATION_H
#define _ANNOTATION_H

#include "Serializable.h"
#include "Annotation.h"
#include <QDataStream>


class Annotation: public Serializable {
public: 

    enum Type { FACE, PERSON, UNKNOWN };

    Annotation(QString id, QString type);
    
    QString getId();
    
    Type getType();

    friend QDataStream& operator<<(QDataStream& out, Annotation& annotation);

    friend QDataStream& operator>>(QDataStream& in, Annotation& annotation);
    
    void toStream(QDataStream in) override;
    
    void fromStream(QDataStream out) override;

protected: 
    QString mId;
    QString mType;

private:
    QStringList mTypes = (QStringList() << "Face" << "Person");
};

#endif //_ANNOTATION_H
