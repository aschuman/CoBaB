#ifndef _PHOTO_H
#define _PHOTO_H

#include "Medium.h"

/**
 * @brief A Photo is a picture which may contain Annotations.
 */
class Photo: public Medium {

public: 
    Photo(const QString path, const QList<QPair<int, Annotation*> > annotations);
};

#endif //_PHOTO_H
