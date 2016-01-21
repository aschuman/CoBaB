/**
 * Project \
 */


#ifndef _PERSONANNOTATION_H
#define _PERSONANNOTATION_H

#include "RectangleAnnotation.h"


class PersonAnnotation: public RectangleAnnotation {
public: 
    
    AnnotationType getType();
};

#endif //_PERSONANNOTATION_H