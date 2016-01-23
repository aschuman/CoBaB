/**
 * Project \
 */


#ifndef _PHOTO_H
#define _PHOTO_H

#include "Medium.h"


class Photo: public Medium {
public: 
    
    /**
     * @param path
     */
    Photo(QString path, QList<QPair<int, Annotation> > annotations);
};

#endif //_PHOTO_H
