/**
 * Project \
 */


#ifndef _SINGLEFRAMEVIDEO_H
#define _SINGLEFRAMEVIDEO_H

#include "..\..\include\Medium.h"


class SingleFrameVideo: public Medium {
public: 
    
    /**
     * @param path
     */
    SingleFrameVideo(QString path, QList<QPair<int, Annotation> > annotations);
    
    int getFramerate();
    
    QList<QString> getFrameList();
private: 
    int mFramerate;
    QList<QString> mFrameList;
};

#endif //_SINGLEFRAMEVIDEO_H
