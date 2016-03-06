#ifndef _ANNOTATION_H
#define _ANNOTATION_H

#include "Serializable.h"
#include "Annotation.h"
#include <QDataStream>

/**
 * Annotation implementation
 * @author Tung
 */

class Annotation: public Serializable {
public: 

    enum Type { FACE, PERSON, UNKNOWN };
    enum Form { NONE, RECTANGLE, UNKNOWN_FORM }; //needed for serialization to construct annotations of the right type,
                                                 //NONE is only needed to check if the annotation is a null object

    Annotation();

    Annotation(const QString& id, const QString& type);

    virtual Annotation* copy() const;

    QString getId() const;
    
    Type getType() const;

    virtual Form getForm() const;

    friend QDataStream& operator<<(QDataStream& out, const Annotation& annotation);

    friend QDataStream& operator>>(QDataStream& in, Annotation& annotation);

    virtual void toStream(QDataStream& out) const override;
    
    virtual void fromStream(QDataStream& in) override;

protected: 
    QString mId;    //Id
    QString mType;  //Type

private:
    QStringList mTypes = (QStringList() << "Face" << "Person" << "Unknown");
};

#endif //_ANNOTATION_H
