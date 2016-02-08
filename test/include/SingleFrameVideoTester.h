#ifndef SINGLEFRAMEVIDEOTESTER_H
#define SINGLEFRAMEVIDEOTESTER_H

#include <QObject>
#include "../interface/SingleFrameVideo.h"

class SingleFrameVideoTester : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void testFramerate();
    void testFrameList();

private:
    SingleFrameVideo *mSingleFrameVideo;
};

#endif // SINGLEFRAMEVIDEOTESTER_H
