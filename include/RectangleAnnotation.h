/**
 * Project \
 */


#ifndef _RECTANGLEANNOTATION_H
#define _RECTANGLEANNOTATION_H

#include "..\..\include\Annotation.h"
#include <QRect.h>


class RectangleAnnotation: public Annotation, public QRect {
public: 
    
    /**
     * @param id
     */
    RectangleAnnotation(QString id);

    /**
     * @param out
     * @param annotation
     */
    friend QDataStream& operator<<(QDataStream& out, RectangleAnnotation& annotation);

    /**
     * @param in
     * @param annotation
     */
    friend QDataStream& operator>>(QDataStream& in, RectangleAnnotation& annotation);
};

#endif //_RECTANGLEANNOTATION_H
