#ifndef SINGLEFRAMEVIDEOTESTER_H
#define SINGLEFRAMEVIDEOTESTER_H

#include <memory>
#include <QObject>
#include "SingleFrameVideo.h"

class SingleFrameVideoTester : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void testFramerate();
    void testFrameList();

private:
    std::unique_ptr<SingleFrameVideo> mSingleFrameVideo;
};

#endif // SINGLEFRAMEVIDEOTESTER_H
