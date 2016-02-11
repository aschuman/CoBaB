#ifndef _VIDEO_H
#define _VIDEO_H

#include "Medium.h"

/**
 * @brief A Video from a Video file.
 */
class Video: public Medium {

public:
    Video(QString path, QList<QPair<int, Annotation*>> annotations);
};

#endif //_VIDEO_H
