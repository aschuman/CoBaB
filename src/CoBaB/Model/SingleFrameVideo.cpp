/**
 * Project \
 */


#include "SingleFrameVideo.h"

/**
 * SingleFrameVideo implementation
 */


/**
 * @param path
 */
void SingleFrameVideo::SingleFrameVideo(QString path, QList<QPair<int, QList<Annotation>>> annotations)
    : Medium(path, annotations) {
    mMediumType = SINGLE_FRAME_VIDEO;

    QDir dir(mRelativePath);
    dir.setFilter(QDir::Files);
    mMediaList = dir.entryList();
}

/**
 * @return int
 */
int SingleFrameVideo::getFramerate() {
    return mFramerate;
}

/**
 * @return QList<QString>
 */
QList<QString> SingleFrameVideo::getFrameList() {
    return mFrameList;
}
