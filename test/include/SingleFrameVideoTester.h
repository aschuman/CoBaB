#ifndef SINGLEFRAMEVIDEOTESTER_H
#define SINGLEFRAMEVIDEOTESTER_H

#include <memory>
#include <QObject>
#include "SingleFrameVideo.h"

/**
 * @brief The SingleFrameVideoTester class Tests the SingleFrameVideo class.
 */
class SingleFrameVideoTester : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void testFramerate();
    void testFrameList();

private:
    std::unique_ptr<SingleFrameVideo> mSingleFrameVideo;        //< The single frame video to test.
};

#endif // SINGLEFRAMEVIDEOTESTER_H
