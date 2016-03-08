#ifndef SINGLEFRAMEVIDEOVIEWER_H
#define SINGLEFRAMEVIDEOVIEWER_H

#include "ViewerPageWidget.h"
#include <QTimer>
#include <QMultiHash>

/**
 * @brief The SingleFrameVideoViewer class is a ViewerPageWidget which can only show SingleFrameVideos.
 * @author Anja
 */
class SingleFrameVideoViewer : public ViewerPageWidget
{
    Q_OBJECT

public:
    SingleFrameVideoViewer();
    void display() override;

public slots:
    void playOrPause();
    void contextMenu(const QPointF &pos);
    void showFrame();
    void showTime();

protected:
    QString getSearchMedium() override;

private:
    SingleFrameVideo mSFVideo; ///< The SingleFrameVideo that is currently selected.
    QTimer mTimer;             ///< The timer for interrupting when the next frame has to be shown.
    QTimer mVideoTime;         ///< The timer for updating the time display.
    QList<QPixmap> mFrameList; ///< The frame list of the video.
    int mFrameIndex;           ///< The index of the current frame in the video.
    bool mIsPlaying;           ///< Indicates whether the video is currently playing.
    QMultiHash<int, QPair<int,Annotation*>> mAnnotations; ///< Hashes a frame index to a list of annotations.
    void pause();
    void play();
    void videoEnd();
};

#endif // SINGLEFRAMEVIDEOVIEWER_H
