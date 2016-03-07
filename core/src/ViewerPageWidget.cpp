#include "include/ViewerPageWidget.h"
#include "ui_ViewerPageWidget.h"
#include "TestAlgorithm.h"
#include <QMenu>
#include <QToolTip>
#include <QMessageBox>

const int ViewerPageWidget::EXIT_NEXT = 0;

ViewerPageWidget::ViewerPageWidget() :
    ui(new Ui::ViewerPageWidget), mIndex(0), mImage(nullptr), mSelectionPen(QColor(0,255,230)),
    mCurrentSelection(nullptr), mAnnotationDrawer(&mGraphicsScene), mSelectedAnnotation(nullptr),
    mAlgorithmList(nullptr), mDataset(nullptr), mROIIsChosen(false)
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
    connect(ui->mZoomIn, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->mZoomOut, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->mGraphicsView, SIGNAL(resize()), this, SLOT(resize()));
}

ViewerPageWidget::~ViewerPageWidget()
{
    delete ui;
}

void ViewerPageWidget::resizeEvent(QResizeEvent *event) {
    resize();
}
void ViewerPageWidget::resize() {
    ui->mGraphicsView->fitInView(mImage, Qt::KeepAspectRatio);
}

void ViewerPageWidget::zoomIn() {
    ui->mGraphicsView->scale(2,2);
}
void ViewerPageWidget::zoomOut() {
    ui->mGraphicsView->scale(0.5,0.5);
}

void ViewerPageWidget::annotationSelected(Annotation* annotation, const QPointF& pos) {
    mSelectedAnnotation = annotation->copy();
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

    SearchObject searchObject;
    searchObject.setMedium(mDataset->getMediaList().at(mIndex)->getPath());
    if(!mROI.isNull()) {
        searchObject.setROI(mROI);
    } else if(mSelectedAnnotation != nullptr) {
        searchObject.setAnnotation(mSelectedAnnotation);
    }
    searchObject.setSourceDataset(mDataset->getPath());
    mSearchQuery = std::make_shared<SearchQuery>();
    mSearchQuery->setSearchObject(searchObject);
    QList<QString> datasetList;
    datasetList.push_back(mDataset->getName());
    mSearchQuery->setDatasets(datasetList);

    QList<Algorithm*> algoList = mAlgorithmList ? mAlgorithmList->findCompatibleAlgorithms(QList<DataPacket*>({mSearchQuery.get()})) : QList<Algorithm*>();

    QMenu contextMenu(this);
    if(algoList.isEmpty()) {
        QMessageBox msgBox(QMessageBox::Information, "", "Found no fitting algorithm.", QMessageBox::Ok, this);
        msgBox.exec();
        //return;
    }
    for(Algorithm* iter: algoList) {
        mAlgorithms.insert(iter->getName(), iter);
        QAction action(iter->getName(), this);
        action.setToolTip(iter->getDescription());
        contextMenu.addAction(&action);
    }
    //for testing
    QAction action1("algorithm 1", this);
    action1.setToolTip("description 1");
    contextMenu.addAction(&action1);
    QAction action2("algorithm 2", this);
    action2.setToolTip("description 2");
    contextMenu.addAction(&action2);

    connect(&contextMenu, SIGNAL(triggered(QAction*)), this, SLOT(nextWidget(QAction*)));
    connect(&contextMenu, SIGNAL(hovered(QAction*)), this, SLOT(showToolTip(QAction*)));
    contextMenu.exec(QCursor::pos());
}
void ViewerPageWidget::showToolTip(QAction* action) {
    QToolTip::showText(QCursor::pos(), action->toolTip());
}

void ViewerPageWidget::clicked(const QModelIndex& index) {
    mIndex = index.row();
    display();
}
void ViewerPageWidget::next() {
    mIndex++;
    mIndex%=mDataset->getNumberOfMedia();
    display();
}
void ViewerPageWidget::before() {  
    if(mIndex <= 0) {
        mIndex = mDataset->getNumberOfMedia();
    }
    mIndex--;
    display();
}

void ViewerPageWidget::reset()
{
    QVariant var;
    emit readFromStack(0, var);
    if(var.canConvert<int>()){
        QVariant var2;
        emit readFromStack(-2, var2);
        if(var2.canConvert<std::shared_ptr<DatasetList>>()) {
            if(mDataset != nullptr) {
                delete mDataset;
            }
            mDataset = new Dataset(var2.value<std::shared_ptr<DatasetList>>()->getDatasetList().at(var.value<int>()));
            mModel.setDataset(*mDataset);
            mIndex = 0;
            if(mImage != nullptr) {
                delete mImage;
                mImage = nullptr;
            }
            if(mCurrentSelection != nullptr) {
                delete mCurrentSelection;
                mCurrentSelection = nullptr;
            }
            if(mSelectedAnnotation != nullptr) {
                delete mSelectedAnnotation;
                mSelectedAnnotation = nullptr;
            }

            display();
        }
    }

    QVariant algoListVariant;
    emit readFromStack(-1, algoListVariant);
    if(algoListVariant.canConvert<std::shared_ptr<AlgorithmList>>()){
        mAlgorithmList = algoListVariant.value<std::shared_ptr<AlgorithmList>>().get();
    } else {
        mAlgorithmList = nullptr;
    }
}

void ViewerPageWidget::nextWidget(QAction* action) {
    SearchObject searchObject;
    searchObject.setMedium(mDataset->getMediaList().at(mIndex)->getPath());
    if(!mROI.isNull()) {
        searchObject.setROI(mROI);
    } else if(mSelectedAnnotation != nullptr) {
        searchObject.setAnnotation(mSelectedAnnotation);
    }
    searchObject.setSourceDataset(mDataset->getPath());
    delete mSelectedAnnotation;
    mSelectedAnnotation = nullptr;
    delete mCurrentSelection;
    mCurrentSelection = nullptr;
    delete mImage;
    mImage = nullptr;

    /*SearchQuery searchQuery;
    searchQuery.setSearchObject(searchObject);
    QList<QString> datasetList;
    datasetList.push_back(mDataset->getName());
    searchQuery.setDatasets(datasetList);
    delete mDataset;
    mDataset = nullptr;*/

    QVariant query;
    query.setValue(mSearchQuery);
    pushToStack(query);

    // todo: push actual, user-chosen algorithm
    //std::shared_ptr<Algorithm> algo(mAlgorithms.value(action->text()));
    std::shared_ptr<Algorithm> algo = std::make_shared<TestAlgorithm>("id123");
    QVariant varAlgo;
    varAlgo.setValue(algo);
    pushToStack(varAlgo);

    exit(EXIT_NEXT);
}

void ViewerPageWidget::on_mGraphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint,
                                                          const QPointF &toScenePoint)
{
    Q_UNUSED(viewportRect);
    if(mImage == nullptr) {
        return;
    }
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
                && fromScenePoint.y() >= 0 && fromScenePoint.y() < height) {
            mCurrentRubberBand.setLeft(fromScenePoint.x());
            mCurrentRubberBand.setTop(fromScenePoint.y());
            mCurrentRubberBand.setRight(toScenePoint.x());
            mCurrentRubberBand.setBottom(toScenePoint.y());

            if(toScenePoint.x() < 0)
                mCurrentRubberBand.setRight(0);
            if(toScenePoint.x() >= width)
                mCurrentRubberBand.setRight(width-1);
            if(toScenePoint.y() < 0)
                mCurrentRubberBand.setBottom(0);
            if(toScenePoint.y() >= height)
                mCurrentRubberBand.setBottom(height-1);
            mCurrentRubberBand = mCurrentRubberBand.normalized();
        }
    }
}

void ViewerPageWidget::roiClicked() {
    if(!mROIIsChosen) {
        ui->mGraphicsView->setDragMode(QGraphicsView::DragMode::RubberBandDrag);
        ui->mROIButton->setText(tr("Bereich entfernen"));
        mROIIsChosen = true;
    } else {
        ui->mGraphicsView->setDragMode(QGraphicsView::DragMode::NoDrag);
        ui->mROIButton->setText(tr("Bereich auswählen"));
        mROIIsChosen = false;
        if(mCurrentSelection != nullptr) {
            mGraphicsScene.removeItem(mCurrentSelection);
            mCurrentSelection = nullptr;
            mCurrentRubberBand.setRect(0,0,0,0);
        }
    }
}

void ViewerPageWidget::display() {
    ui->mPhotoCount->setText("Foto "+QString::number(mIndex+1)+" von "+QString::number(mDataset->getNumberOfMedia()));
}

void ViewerPageWidget::retranslateUi() {
    ui->mBeforeButton->setText(tr("vorheriges"));
    ui->mNextButton->setText(tr("nächstes"));
    if(mROIIsChosen) {
        ui->mROIButton->setText(tr("Bereich entfernen"));
    } else {
        ui->mROIButton->setText(tr("Bereich auswählen"));
    }
}
