#include "PhotoViewer.h"
#include "ui_ViewerPageWidget.h"

/**
 * @brief PhotoViewer::PhotoViewer Constructs a PhotoViewer.
 */
PhotoViewer::PhotoViewer() :
    ViewerPageWidget()
{
    ui->mPlayOrPauseButton->hide();
    ui->mStopButton->hide();
    ui->mLoopButton->hide();
    ui->mTime->hide();
    ui->mSlider->hide();
}

/**
 * @brief PhotoViewer::display Displays a photo in the QGraphicsScene.
 */
void PhotoViewer::display() {
    ViewerPageWidget::display();
    ui->mPhotoCount->setText("Foto "+QString::number(mIndex+1)+" von "+QString::number(mDataset->getNumberOfMedia()));
    if(mImage != nullptr) {
        mGraphicsScene.removeItem(mImage);
        delete mImage;
        mImage = nullptr;
        mAnnotationDrawer.removeAnnotations();

    }
    if(mCurrentSelection != nullptr){
        mGraphicsScene.removeItem(mCurrentSelection);
        delete mCurrentSelection;
        mCurrentSelection = nullptr;
    }
    Medium* medium = mDataset->getMediaList().at(mIndex);
    mImage = new ClickableGraphicsPixmapItem(QPixmap::fromImage(QImage(medium->getPath())));

    mGraphicsScene.addItem(mImage);
    connect(mImage, SIGNAL(selected(const QPointF&)), this, SLOT(contextMenu(const QPointF&)));
    mGraphicsScene.setSceneRect(0,0, mImage->boundingRect().width(), mImage->boundingRect().height());
    mAnnotationDrawer.setAnnotations(medium->getAnnotationList());
    resize();
}

/**
 * @brief PhotoViewer::getSearchMedium Returns the path to the Medium that is searched for.
 * @return The path of the Medium (to be set in the SearchObject).
 */
QString PhotoViewer::getSearchMedium() {
    return mDataset->getMediaList().at(mIndex)->getPath();
}
