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
    void Photo(QString path, QList<QPair<int, QList<Annotation>>> annotations);
};

#endif //_PHOTO_H
