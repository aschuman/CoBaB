/**
 * Project \
 */


#ifndef _VIDEO_H
#define _VIDEO_H

#include "Medium.h"


class Video: public Medium {
public: 
    
    /**
     * @param path
     */
    Video(QString path, QList<QPair<int, QList<Annotation>>> annotations);
};

#endif //_VIDEO_H
