#ifndef _RECTANGLEANNOTATION_H
#define _RECTANGLEANNOTATION_H

#include "Annotation.h"
#include <QRect>

/**
 * RectangleAnnotation implementation
 * @author Tung
 */

class RectangleAnnotation: public Annotation, public QRect {
public: 

    RectangleAnnotation(const QString& id, const QString& type);

    Annotation* copy();

    friend QDataStream& operator<<(QDataStream& out, const RectangleAnnotation& annotation);

    friend QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation);

    void toStream(QDataStream& out) const override;

    void fromStream(QDataStream& in) override;
};

#endif //_RECTANGLEANNOTATION_H
