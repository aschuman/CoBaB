#include "PhotoViewer.h"
#include "ui_ViewerPageWidget.h"

PhotoViewer::PhotoViewer() :
    ViewerPageWidget()
{
    ViewerPageWidget::ui->mPlayOrPauseButton->hide();
    ViewerPageWidget::ui->mTime->hide();
}

PhotoViewer::~PhotoViewer()
{

}

void PhotoViewer::display() {
    ViewerPageWidget::display();
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
