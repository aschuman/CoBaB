#include "SingleFrameVideoViewer.h"
#include "ui_ViewerPageWidget.h"
#include "log.h"

SingleFrameVideoViewer::SingleFrameVideoViewer() : ViewerPageWidget(), mIsPlaying(false), mSFVideo("", QList<QPair<int, Annotation*>>()), mFrameIndex(-1)
{
    connect(ViewerPageWidget::ui->mPlayOrPauseButton, SIGNAL(clicked()), this, SLOT(playOrPause()));
    connect(&mTimer, SIGNAL(timeout()), this, SLOT(showFrame()));
}

void SingleFrameVideoViewer::display() {
    mSFVideo = *(SingleFrameVideo*)mDataset->getMediaList().at(mIndex);
    mTimer.setInterval(1000/mSFVideo.getFramerate()); //time interval in milliseconds per frame
    mFrameList.clear();
    for(QString iter : mSFVideo.getFrameList()) {
        mFrameList.append(QPixmap(mSFVideo.getPath()+"/"+iter));
    }
    if(mFrameList.isEmpty()) {
        LOG_ERR("empty video");
        return;
    }
    mImage = new ClickableGraphicsPixmapItem(mFrameList.first());
    if(mImage != nullptr) {
        mGraphicsScene.addItem(mImage);
        connect(mImage, SIGNAL(selected(const QPointF&)), this, SLOT(contextMenu(QPointF)));
        mGraphicsScene.setSceneRect(0,0, mImage->boundingRect().width(), mImage->boundingRect().height());
        mFrameIndex = 0;
    }
    for(QPair<int, Annotation*> iter: mSFVideo.getAnnotationList()) {
        mAnnotations.insert(iter.first, iter);
    }
    ViewerPageWidget::ui->mPlayOrPauseButton->setEnabled(true);
}

void SingleFrameVideoViewer::playOrPause() {
    if(mIsPlaying) {
        pause();
    } else {
        play();
    }
}
void SingleFrameVideoViewer::videoEnd() {
    pause();
    ViewerPageWidget::ui->mPlayOrPauseButton->setEnabled(false);
}
void SingleFrameVideoViewer::contextMenu(const QPointF &pos) {
    pause();
    ViewerPageWidget::contextMenu(pos);
}

void SingleFrameVideoViewer::pause() {
    mTimer.stop();
    mIsPlaying = false;
    ViewerPageWidget::ui->mPlayOrPauseButton->setText("play");
}
void SingleFrameVideoViewer::play() {
    mIsPlaying = true;
    ViewerPageWidget::ui->mPlayOrPauseButton->setText("pause");
    mTimer.start();
}

void SingleFrameVideoViewer::showFrame() {
    if(mImage != nullptr) {
        mGraphicsScene.removeItem(mImage);
        delete mImage;
        mAnnotationDrawer.removeAnnotations();
    }
    if(mCurrentSelection != nullptr){
        mGraphicsScene.removeItem(mCurrentSelection);
        delete mCurrentSelection;
        mCurrentSelection = nullptr;
    }
    mFrameIndex++;
    if(mFrameIndex >= mFrameList.size()) {
        mTimer.stop();
        mImage = nullptr;
        videoEnd();
        return;
    }

    mImage = new ClickableGraphicsPixmapItem(mFrameList.at(mFrameIndex));
    connect(mImage, SIGNAL(selected(const QPointF&)), this, SLOT(contextMenu(QPointF)));
    mGraphicsScene.addItem(mImage);
    mAnnotationDrawer.setAnnotations(mAnnotations.values(mFrameIndex));
}
