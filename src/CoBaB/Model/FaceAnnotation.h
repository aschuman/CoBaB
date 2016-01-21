/**
 * Project \
 */


#ifndef _FACEANNOTATION_H
#define _FACEANNOTATION_H

#include "RectangleAnnotation.h"


class FaceAnnotation: public RectangleAnnotation {
public: 
    
    AnnotationType getType();
};

#endif //_FACEANNOTATION_H