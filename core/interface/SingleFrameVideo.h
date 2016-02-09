/**
 * Project \
 */


#ifndef _SINGLEFRAMEVIDEO_H
#define _SINGLEFRAMEVIDEO_H

#include "Medium.h"
#include "Configuration.h"


class SingleFrameVideo: public Medium {

public: 
    SingleFrameVideo(const QString path, const QList<QPair<int, Annotation> > annotations);
    double getFramerate() const;
    QList<QString> getFrameList() const;

private: 
    double mFramerate;
    QList<QString> mFrameList;
    double readFramerateFromJson(const QString path);
};

#endif //_SINGLEFRAMEVIDEO_H
