/**
 * Project \
 */


#ifndef _PHOTO_H
#define _PHOTO_H

#include "Medium.h"


class Photo: public Medium {

public: 
    Photo(const QString path, const QList<QPair<int, Annotation> > annotations);
};

#endif //_PHOTO_H
