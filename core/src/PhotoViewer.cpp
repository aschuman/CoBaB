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
    mAnnotationDrawer.removeAnnotations();
    if(mImage != nullptr) {
        mGraphicsScene.removeItem(mImage);
        delete mImage;
        mImage = nullptr;
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
 * @brief PhotoViewer::retranslateUi Translates the GUI.
 */
void PhotoViewer::retranslateUi() {
    ViewerPageWidget::retranslateUi();
    ui->mPhotoCount->setText(tr("Foto ")+QString::number(mIndex+1)+tr(" von ")+QString::number(mDataset->getNumberOfMedia()));
}
