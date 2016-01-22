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
};

#endif //_RECTANGLEANNOTATION_H
