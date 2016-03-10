#ifndef _SINGLEFRAMEVIDEO_H
#define _SINGLEFRAMEVIDEO_H

#include "Medium.h"
#include "Configuration.h"

/**
 * @brief The SingleFrameVideo is a video which consists of single pictures.
 * @author Anja
 */
class SingleFrameVideo: public Medium {

public: 
    SingleFrameVideo(const QString path, const QList<QPair<int, Annotation*>> annotations);
    SingleFrameVideo(const SingleFrameVideo& other);
    double getFramerate() const;
    QList<QString> getFrameList() const;
    Medium* copy() override;

private: 
    double mFramerate;                                      ///< The framerate of the SingleFrameVideo.
    QList<QString> mFrameList;                              ///< The list of frames of the SingleFrameVideo.

    double readFramerateFromJson(const QString path); 
};

#endif //_SINGLEFRAMEVIDEO_H
