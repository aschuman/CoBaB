/**
 * Project \
 */


#ifndef _RECTANGLEANNOTATION_H
#define _RECTANGLEANNOTATION_H

#include "Annotation.h"
#include <QRect>


class RectangleAnnotation: public Annotation, public QRect {
public: 

    RectangleAnnotation(QString id, QString type);

    friend QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation);

    friend QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation);

    void toStream(QDataStream& in) const override;

    void fromStream(QDataStream& out) override;
};

#endif //_RECTANGLEANNOTATION_H
