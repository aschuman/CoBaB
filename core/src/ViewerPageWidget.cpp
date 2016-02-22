#include "include/ViewerPageWidget.h"
#include "ui_ViewerPageWidget.h"
#include "SearchQuery.h"
#include <QMenu>

const int ViewerPageWidget::EXIT_NEXT = 0;

ViewerPageWidget::ViewerPageWidget() :
    ui(new Ui::ViewerPageWidget), mIndex(0), mImage(nullptr), mSelectionPen(QColor(0,255,230)),
    mCurrentSelection(nullptr), mAnnotationDrawer(&mGraphicsScene), mSelectedAnnotation(nullptr)
{
    ui->setupUi(this);
    ui->mViewerListView->setResizeMode(QListView::Adjust);
    ui->mGraphicsView->setScene(&mGraphicsScene);
    ui->mViewerListView->setModel(&mModel);

    connect(ui->mViewerListView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicked(const QModelIndex&)));
    connect(ui->mNextButton, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->mBeforeButton, SIGNAL(clicked()), this, SLOT(before()));
    connect(ui->mROIButton, SIGNAL(clicked()), this, SLOT(roiClicked()));
    connect(&mAnnotationDrawer, SIGNAL(selected(Annotation*, const QPointF&)), this, SLOT(annotationSelected(Annotation*, const QPointF&)));
}

ViewerPageWidget::~ViewerPageWidget()
{
    delete ui;
}
void ViewerPageWidget::annotationSelected(Annotation* annotation, const QPointF& pos) {
    mSelectedAnnotation = annotation;
    contextMenu(pos);
}

void ViewerPageWidget::contextMenu(const QPointF &pos) {
    if(mCurrentSelection != nullptr) {
        if(mCurrentSelection->contains(pos)) {
            mROI = mCurrentSelection->rect().toRect();
            mSelectedAnnotation = nullptr;
        } else {
            mROI.setRect(0,0,0,0);
        }
    }
    QMenu contextMenu(this);
    QAction action1("algorithm 1", this);
    action1.setToolTip("description 1");
    contextMenu.addAction(&action1);
    QAction action2("algorithm 2", this);
    action2.setToolTip("description 2");
    contextMenu.addAction(&action2);
    connect(&contextMenu, SIGNAL(triggered(QAction*)), this, SLOT(nextWidget(QAction*)));
    contextMenu.exec(QCursor::pos());
}
void ViewerPageWidget::clicked(const QModelIndex& index) {
    mIndex = index.row();
    displayImage();
}
void ViewerPageWidget::next() {
    mIndex++;
    if(mIndex >= mDataset->getNumberOfMedia()) {
        mIndex = mDataset->getNumberOfMedia()-1;
    }
    displayImage();
}
void ViewerPageWidget::before() {
    mIndex--;
    if(mIndex <= -1) {
        mIndex = 0;
    }
    displayImage();
}

void ViewerPageWidget::reset()
{
    QVariant var;
    emit readFromStack(0, var);
    if(var.canConvert<int>()){
        QVariant var2;
        emit readFromStack(1, var2);
        if(var2.canConvert<std::shared_ptr<DatasetList>>()) {
            mDataset = &(var2.value<std::shared_ptr<DatasetList>>()->getDatasetList().at(var.value<int>()));
            mModel.setDataset(*mDataset);
            mIndex = 0;
            displayImage();
        }
    }
}

void ViewerPageWidget::displayImage() {
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
}

void ViewerPageWidget::nextWidget(QAction* action) {
    SearchObject searchObject;
    searchObject.setMedium(mDataset->getMediaList().at(mIndex)->getPath());
    if(!mROI.isNull()) {
        searchObject.setROI(mROI);
    } else if(mSelectedAnnotation != nullptr) {
        searchObject.setAnnotation(*mSelectedAnnotation);
    }
    searchObject.setSourceDataset(mDataset->getPath());
    delete mSelectedAnnotation;
    delete mCurrentSelection;
    delete mImage;

    SearchQuery searchQuery;
    searchQuery.setSearchObject(searchObject);

    QString algorithm = action->text();

    QVariant query;
    query.setValue(std::make_shared<SearchQuery>(searchQuery));
    pushToStack(query);
    exit(EXIT_NEXT);
}

void ViewerPageWidget::on_mGraphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint,
                                                          const QPointF &toScenePoint)
{
    Q_UNUSED(viewportRect);
    if(fromScenePoint.x() == 0 && fromScenePoint.y() == 0){
        if(mCurrentSelection != nullptr){
            mGraphicsScene.removeItem(mCurrentSelection);
            delete mCurrentSelection;
        }
        mCurrentSelection = mGraphicsScene.addRect(mCurrentRubberBand, mSelectionPen);
    } else {
        int width = mImage->boundingRect().width();
        int height = mImage->boundingRect().height();

        if(fromScenePoint.x() >= 0 && fromScenePoint.x() < width
                && toScenePoint.x() >= 0 && toScenePoint.x() < width
                && fromScenePoint.y() >= 0 && fromScenePoint.y() < height
                && toScenePoint.y() >= 0 && toScenePoint.y() < height) {
            mCurrentRubberBand.setLeft(fromScenePoint.x());
            mCurrentRubberBand.setTop(fromScenePoint.y());
            mCurrentRubberBand.setRight(toScenePoint.x());
            mCurrentRubberBand.setBottom(toScenePoint.y());
            mCurrentRubberBand = mCurrentRubberBand.normalized();
        }
    }
}

void ViewerPageWidget::roiClicked() {
    if(ui->mROIButton->text() == "select ROI") {
        ui->mGraphicsView->setDragMode(QGraphicsView::DragMode::RubberBandDrag);
        ui->mROIButton->setText("remove ROI");
    } else {
        ui->mGraphicsView->setDragMode(QGraphicsView::DragMode::NoDrag);
        ui->mROIButton->setText("select ROI");
        if(mCurrentSelection != nullptr) {
            mGraphicsScene.removeItem(mCurrentSelection);
            mCurrentSelection = nullptr;
            mCurrentRubberBand.setRect(0,0,0,0);
        }
    }
}
