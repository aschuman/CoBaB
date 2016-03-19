#ifndef _ANNOTATION_H
#define _ANNOTATION_H

#include "Serializable.h"
#include "Annotation.h"
#include <QDataStream>

/**
 * @brief An Annotation represents an area in photos/videos, its type can be face or person.
 * @author Tung
 */

class Annotation: public Serializable {
public: 

    /**
     * @brief The Type of the Annotation can be face, person or unknown.
     */
    enum Type { FACE, PERSON, UNKNOWN };
    /**
     * @brief The Form enum is needed for serialization to construct annotations of the right type,
     * NONE is only needed to check if the annotation is a null object
     */
    enum Form { NONE, RECTANGLE, UNKNOWN_FORM };


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
    QString mId;    ///<Id
    QString mType;  ///<Type
    Form mForm;     ///<Form

private:
    QStringList mTypes = (QStringList() << "Face" << "Person" << "Unknown");
};

#endif //_ANNOTATION_H
