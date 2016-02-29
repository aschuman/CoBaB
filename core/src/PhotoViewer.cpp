#include "PhotoViewer.h"
#include "ui_ViewerPageWidget.h"

PhotoViewer::PhotoViewer() :
    ViewerPageWidget()
{
    ViewerPageWidget::ui->mPlayOrPauseButton->hide();
}

PhotoViewer::~PhotoViewer()
{

}

void PhotoViewer::display() {
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

    /*mImage = new ClickableGraphicsPixmapItem(QPixmap::fromImage(QImage(medium->getPath()).scaled(
        ViewerPageWidget::ui->mGraphicsView->viewport()->width(),
        ViewerPageWidget::ui->mGraphicsView->viewport()->height(), Qt::KeepAspectRatio)));*/

    mGraphicsScene.addItem(mImage);
    connect(mImage, SIGNAL(selected(const QPointF&)), this, SLOT(contextMenu(const QPointF&)));
    mGraphicsScene.setSceneRect(0,0, mImage->boundingRect().width(), mImage->boundingRect().height());
    mAnnotationDrawer.setAnnotations(medium->getAnnotationList());
}
