/**
 * Project \
 */


#ifndef _RECTANGLEANNOTATION_H
#define _RECTANGLEANNOTATION_H

#include "Annotation.h"
#include "QRect.h"


class RectangleAnnotation: public Annotation, public QRect {
public: 
    
    /**
     * @param id
     */
    void RectangleAnnotation(QString id);
};

#endif //_RECTANGLEANNOTATION_H