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

    virtual void toStream(QDataStream& in) const override;
    
    virtual void fromStream(QDataStream& out) override;

protected: 
    QString mId;    //Id
    QString mType;  //Type

private:
    QStringList mTypes = (QStringList() << "Face" << "Person");
};

#endif //_ANNOTATION_H
