/**
 * Project \
 */


#ifndef _VIDEO_H
#define _VIDEO_H

#include "Medium.h"


class Video: public Medium {

public: 
    Video(QString path, QList<QPair<int, Annotation> > annotations);
};

#endif //_VIDEO_H
