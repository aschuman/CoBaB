#ifndef SINGLEFRAMEVIDEOVIEWER_H
#define SINGLEFRAMEVIDEOVIEWER_H

#include "ViewerPageWidget.h"
#include <QTimer>
#include <QMultiHash>

/**
 * @brief The SingleFrameVideoViewer class
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
private:
    SingleFrameVideo mSFVideo;
    QTimer mTimer;
    QList<QPixmap> mFrameList;
    int mFrameIndex;
    bool mIsPlaying;
    QMultiHash<int, QPair<int,Annotation*>> mAnnotations;
    void pause();
    void play();
    void videoEnd();
};

#endif // SINGLEFRAMEVIDEOVIEWER_H
