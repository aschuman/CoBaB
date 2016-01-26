/**
 * Project \
 */


#ifndef _SINGLEFRAMEVIDEO_H
#define _SINGLEFRAMEVIDEO_H

#include "Medium.h"


class SingleFrameVideo: public Medium {
public: 
    
    /**
     * @param path
     */
    SingleFrameVideo(QString path, QList<QPair<int, Annotation> > annotations);
    
    double getFramerate();
    
    QList<QString> getFrameList();
private: 
    double mFramerate;
    QList<QString> mFrameList;
    double readFramerateFromJson(QString path);
};

#endif //_SINGLEFRAMEVIDEO_H
