#ifndef _SINGLEFRAMEVIDEO_H
#define _SINGLEFRAMEVIDEO_H

#include "Medium.h"
#include "Configuration.h"

/**
 * @brief The SingleFrameVideo is a video which consists of single pictures.
 */
class SingleFrameVideo: public Medium {

public: 
    SingleFrameVideo(const QString path, const QList<QPair<int, Annotation*>> annotations);
    double getFramerate() const;
    QList<QString> getFrameList() const;

private: 
    double mFramerate;                                      ///< The framerate of the SingleFrameVideo.
    QList<QString> mFrameList;                              ///< The list of frames of the SingleFrameVideo.
    double readFramerateFromJson(const QString path);
};

#endif //_SINGLEFRAMEVIDEO_H
