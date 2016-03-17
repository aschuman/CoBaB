#include "SingleFrameVideoViewer.h"
#include "ui_ViewerPageWidget.h"
#include "log.h"

/**
 * @brief SingleFrameVideoViewer::SingleFrameVideoViewer Constructs a SingleFrameVideoViewer.
 */
SingleFrameVideoViewer::SingleFrameVideoViewer() : ViewerPageWidget(), mIsPlaying(false),
    mSFVideo("", QList<QPair<int, Annotation*>>()), mFrameIndex(-1), mIsLooping(false)
{
    Q_INIT_RESOURCE(application);
    connect(ui->mPlayOrPauseButton, SIGNAL(clicked()), this, SLOT(playOrPause()));
    connect(ui->mStopButton, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->mLoopButton, SIGNAL(clicked()), this, SLOT(loop()));

    connect(&mTimer, SIGNAL(timeout()), this, SLOT(showFrame()));
    mVideoTime.setInterval(1000);
    connect(&mVideoTime, SIGNAL(timeout()), this, SLOT(showTime()));

    ui->mSlider->setSingleStep(1);
    connect(ui->mSlider, SIGNAL(sliderPressed()), this, SLOT(pause()));
    connect(ui->mSlider, SIGNAL(sliderMoved(int)), this, SLOT(slide(int)));
    connect(ui->mSlider, SIGNAL(sliderReleased()), this, SLOT(play()));
}

/**
 * @brief SingleFrameVideoViewer::showTime Shows the current time in the video.
 */
void SingleFrameVideoViewer::showTime() {
    ui->mTime->setText(QString::number(mFrameIndex*mTimer.interval()/1000));
    ui->mSlider->triggerAction(QAbstractSlider::SliderSingleStepAdd);
}

/**
 * @brief SingleFrameVideoViewer::display Displays the video in the QGraphicsScene.
 */
void SingleFrameVideoViewer::display() {
    ViewerPageWidget::display();
    stop();
    ui->mStopButton->setIcon(QIcon(":/stop.png"));
    ui->mLoopButton->setIcon(QIcon(":/loop.png"));
    mIsLooping = false;
    mFrameIndex = 0;

    ui->mPhotoCount->setText("Video "+QString::number(mIndex+1)+" von "+QString::number(mDataset->getNumberOfMedia()));

    mSFVideo = *(SingleFrameVideo*)mDataset->getMediaList().at(mIndex);
    mTimer.setInterval(1000/mSFVideo.getFramerate()); //time interval in milliseconds per frame
    ui->mSlider->setMaximum(mSFVideo.getFrameList().size()/mSFVideo.getFramerate());
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
    }
    mAnnotations.clear();
    for(QPair<int, Annotation*> iter: mSFVideo.getAnnotationList()) {
        mAnnotations.insert(iter.first, iter);
    }
    resize();
}

/**
 * @brief SingleFrameVideoViewer::playOrPause Plays the video if it is pausing and pauses it if it is playing.
 */
void SingleFrameVideoViewer::playOrPause() {
    if(mIsPlaying) {
        pause();
    } else {
        play();
    }
}

/**
 * @brief SingleFrameVideoViewer::stop Stops the video.
 */
void SingleFrameVideoViewer::stop() {
    pause();
    ui->mTime->setText("0");
    ui->mSlider->setSliderPosition(0);
    mAnnotationDrawer.removeAnnotations();
    if(mImage != nullptr)
        mGraphicsScene.removeItem(mImage);
        delete mImage;
    if(!mFrameList.isEmpty()) {
        mImage = new ClickableGraphicsPixmapItem(mFrameList.first());
    }
    if(mImage != nullptr) {
        mGraphicsScene.addItem(mImage);
        mFrameIndex = 0;
    }
}

/**
 * @brief SingleFrameVideoViewer::loop Loops the video if it is not looping, else don't loop it.
 */
void SingleFrameVideoViewer::loop() {
    if(mIsLooping) {
        mIsLooping = false;
        ui->mLoopButton->setIcon(QIcon(":/loop.png"));
    } else {
        mIsLooping = true;
        ui->mLoopButton->setIcon(QIcon(":/noLoop.png"));
    }
}

/**
 * @brief SingleFrameVideoViewer::contextMenu Shows a context menu to select an algorithm.
 * @param pos The position of the mouse.
 */
void SingleFrameVideoViewer::contextMenu(const QPointF &pos, const Annotation *selectedAnnotation) {
    pause();
    ViewerPageWidget::contextMenu(pos, selectedAnnotation);
}

/**
 * @brief SingleFrameVideoViewer::pause Pauses the video.
 */
void SingleFrameVideoViewer::pause() {
    mVideoTime.stop();
    mTimer.stop();
    mIsPlaying = false;
    ui->mPlayOrPauseButton->setIcon(QIcon(":/play.png"));
}

/**
 * @brief SingleFrameVideoViewer::play Plays the video.
 */
void SingleFrameVideoViewer::play() {
    mIsPlaying = true;
    ui->mPlayOrPauseButton->setIcon(QIcon(":/pause.png"));
    mVideoTime.start();
    mTimer.start();
}

/**
 * @brief SingleFrameVideoViewer::showFrame Shows one frame.
 */
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
        stop();
        if(mIsLooping) {
            play();
        }
        return;
    }

    mImage = new ClickableGraphicsPixmapItem(mFrameList.at(mFrameIndex));
    connect(mImage, SIGNAL(selected(const QPointF&)), this, SLOT(contextMenu(QPointF)));
    mGraphicsScene.addItem(mImage);
    mAnnotationDrawer.setAnnotations(mAnnotations.values(mFrameIndex));
}

/**
 * @brief SingleFrameVideoViewer::getFrameIndex Returns the frame in the video.
 * @return The frame in the Medium (to be set in the SearchObject).
 */
int SingleFrameVideoViewer::getFrameIndex() {
    return mFrameIndex;
}

/**
 * @brief SingleFrameVideoViewer::nextWidget Shows the next widget.
 * @param action The Action of the context menu that was selceted.
 */
void SingleFrameVideoViewer::nextWidget(QAction* action) {
    stop();
    ViewerPageWidget::nextWidget(action);
}

/**
 * @brief SingleFrameVideoViewer::slide Moves the slider.
 * @param sec The seconds that have passed since the video started.
 */
void SingleFrameVideoViewer::slide(int sec) {
    mFrameIndex = sec * mSFVideo.getFramerate() - 1;
    showFrame();
}

/**
 * @brief SingleFrameVideoViewer::retranslateUi Translates the GUI.
 */
void SingleFrameVideoViewer::retranslateUi() {
    ViewerPageWidget::retranslateUi();
    ui->mPhotoCount->setText(tr("Video ")+QString::number(mIndex+1)+tr(" von ")+QString::number(mDataset->getNumberOfMedia()));
}
