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
    void retranslateUi() override;

public slots:
    void playOrPause();
    void stop();
    void loop();
    void contextMenu(const QPointF &pos, const Annotation* selectedAnnotation = nullptr) override;
    void showFrame();
    void showTime();
    void nextWidget(QAction* action) override;
    void play();
    void pause();
    void slide(int sec);

protected:
    int getFrameIndex() override;

private:
    SingleFrameVideo mSFVideo; ///< The SingleFrameVideo that is currently selected.
    QTimer mTimer;             ///< The timer for interrupting when the next frame has to be shown.
    QTimer mVideoTime;         ///< The timer for updating the time display.
    QList<QPixmap> mFrameList; ///< The frame list of the video.
    int mFrameIndex;           ///< The index of the current frame in the video.
    bool mIsPlaying;           ///< Indicates whether the video is currently playing.
    QMultiHash<int, QPair<int,Annotation*>> mAnnotations; ///< Hashes a frame index to a list of annotations.
    bool mIsLooping;
};

#endif // SINGLEFRAMEVIDEOVIEWER_H
