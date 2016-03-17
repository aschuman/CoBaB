#include "include/ViewerPageWidget.h"
#include "ui_ViewerPageWidget.h"
#include <QMenu>
#include <QToolTip>
#include <QMessageBox>
#include <QPointer>

/**
 * @brief ViewerPageWidget::ViewerPageWidget Constructs a ViewerPageWidget.
 */
ViewerPageWidget::ViewerPageWidget() :
    ui(new Ui::ViewerPageWidget), mIndex(0), mImage(nullptr), mSelectionPen(QColor(0,255,230)),
    mCurrentSelection(nullptr), mAnnotationDrawer(&mGraphicsScene),
    mAlgorithmList(nullptr), mDataset(nullptr), mROIIsChosen(false)
{
    ui->setupUi(this);
    ui->mViewerListView->setResizeMode(QListView::Adjust);
    ui->mGraphicsView->setScene(&mGraphicsScene);
    ui->mViewerListView->setModel(&mModel);

    connect(ui->mViewerListView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this,
        SLOT(selectionChanged(const QModelIndex&, const QModelIndex&)));
    connect(ui->mNextButton, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->mBeforeButton, SIGNAL(clicked()), this, SLOT(before()));
    connect(ui->mROIButton, SIGNAL(clicked()), this, SLOT(roiClicked()));
    connect(&mAnnotationDrawer, SIGNAL(selected(Annotation*, const QPointF&)), this, SLOT(annotationSelected(Annotation*, const QPointF&)));
    connect(ui->mZoomIn, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->mZoomOut, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->mGraphicsView, SIGNAL(zoomed(double)), this, SLOT(zoomed(double)));
    connect(ui->mGraphicsView, SIGNAL(resize()), this, SLOT(resize()));

    Q_INIT_RESOURCE(application);
    ui->mBeforeButton->setIcon(QIcon(":/before.png"));
    ui->mNextButton->setIcon(QIcon(":/next.png"));
}

/**
 * @brief ViewerPageWidget::~ViewerPageWidget Deletes the ViewerPageWidget.
 */
ViewerPageWidget::~ViewerPageWidget()
{
    delete ui;
}

/**
 * @brief ViewerPageWidget::resizeEvent Resizes the widget.
 * @param event The QResizeEvent.
 */
void ViewerPageWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    resize();
}

/**
 * @brief ViewerPageWidget::resize Resizes the displayed Medium.
 */
void ViewerPageWidget::resize() {
    ui->mGraphicsView->fitInView(mImage, Qt::KeepAspectRatio);
    ui->mGraphicsView->resetZoom();
    ui->mZoom->setText("100 %");
}

/**
 * @brief ViewerPageWidget::zoomIn Zooms in the Medium.
 */
void ViewerPageWidget::zoomIn() {
    ui->mGraphicsView->zoom(2);
}

/**
 * @brief ViewerPageWidget::zoomOut Zooms the Medium out.
 */
void ViewerPageWidget::zoomOut() {
    ui->mGraphicsView->zoom(0.5);
}

/**
 * @brief ViewerPageWidget::zoomed The view was zoomed, so the zooming level and display are updated.
 * @param factor The zooming factor.
 */
void ViewerPageWidget::zoomed(double zoomLevel) {
    ui->mZoom->setText(QString::number(zoomLevel*100) + " %");
}

/**
 * @brief ViewerPageWidget::annotationSelected Sets the selected annotation and shows a context menu to select an Algorithm.
 * @param annotation The selected Annotation.
 * @param pos The mouse position.
 */
void ViewerPageWidget::annotationSelected(Annotation* annotation, const QPointF& pos) {
    contextMenu(pos, annotation);
}

/**
 * @brief ViewerPageWidget::contextMenu Shows a context menu to select an Algorithm.
 * @param pos The mouse position.
 */
void ViewerPageWidget::contextMenu(const QPointF &pos, const Annotation* selectedAnnotation) {
    SearchObject searchObject;
    searchObject.setMedium(mDataset->getMediaList().at(mIndex)->getPath());
    searchObject.setFrameIndex(getFrameIndex());
    if(mDataset->getType() == Dataset::Type::PHOTO) {
        searchObject.setMediumIndex(0);
    } else if (mDataset->getType() == Dataset::Type::SINGLE_FRAME_VIDEO) {
        searchObject.setMediumIndex(1);
    } else {
        searchObject.setMediumIndex(-1);
    }
    if(mCurrentSelection != nullptr && mCurrentSelection->contains(pos)) {
        mROI = mCurrentSelection->rect().toRect();
        searchObject.setROI(mROI);
        searchObject.setType(SearchObject::Type::ROI);
    } else if(selectedAnnotation != nullptr) {
        searchObject.setAnnotation(selectedAnnotation);
        searchObject.setType(SearchObject::Type::ANNOTATION);
    } else {
        searchObject.setType(SearchObject::Type::MEDIUM);
    }
    searchObject.setSourceDataset(mDataset->getPath());
    mSearchQuery = std::make_shared<SearchQuery>();
    mSearchQuery->setSearchObject(searchObject);
    QList<QString> datasetList;
    datasetList.push_back(mDataset->getPath());
    mSearchQuery->setDatasets(datasetList);

    QList<Algorithm*> algoList = mAlgorithmList ? mAlgorithmList->findCompatibleAlgorithms(QList<DataPacket*>({mSearchQuery.get()})) : QList<Algorithm*>();

    QMenu contextMenu(this);
    if(algoList.isEmpty()) {
        QMessageBox msgBox(QMessageBox::Information, "", "Found no fitting algorithm.", QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }
    switch(searchObject.getType()) {
        case SearchObject::Type::ROI:
            contextMenu.setTitle("ROI");
            break;
        case SearchObject::Type::ANNOTATION:
            contextMenu.setTitle("Annotation");
            break;
        case  SearchObject::Type::MEDIUM:
        default:
            contextMenu.setTitle("Medium");
    }
    for(Algorithm* iter: algoList) {
        mAlgorithms.insert(iter->getName(), iter);
        QAction* action = new QAction(iter->getName(), this);
        action->setToolTip(iter->getDescription());
        contextMenu.addAction(action);
    }
    connect(&contextMenu, SIGNAL(triggered(QAction*)), this, SLOT(nextWidget(QAction*)));
    connect(&contextMenu, SIGNAL(hovered(QAction*)), this, SLOT(showToolTip(QAction*)));
    contextMenu.exec(QCursor::pos());
}

/**
 * @brief ViewerPageWidget::showToolTip Shows tooltips for the algorithms.
 * @param action The QAction of the algorithm in the context menu.
 */
void ViewerPageWidget::showToolTip(QAction* action) {
    QToolTip::showText(QCursor::pos(), action->toolTip());
}

/**
 * @brief ViewerPageWidget::selectionChanged Updates the displayed Medium when the selection changed.
 * @param index The new QModelIndex.
 * @param previousIndex The previous QModelIndex.
 */
void ViewerPageWidget::selectionChanged(const QModelIndex &index, const QModelIndex &previousIndex) {
    Q_UNUSED(previousIndex);
    mIndex = index.row();
    display();
}

/**
 * @brief ViewerPageWidget::next Shows the next Medium in the ListView.
 */
void ViewerPageWidget::next() {
    mIndex++;
    mIndex%=mDataset->getNumberOfMedia();
    ui->mViewerListView->selectionModel()->setCurrentIndex(mModel.index(mIndex), QItemSelectionModel::ClearAndSelect);
    display();
}

/**
 * @brief ViewerPageWidget::before Shows the Medium before in the ListView.
 */
void ViewerPageWidget::before() {  
    if(mIndex <= 0) {
        mIndex = mDataset->getNumberOfMedia();
    }
    mIndex--;
    ui->mViewerListView->selectionModel()->setCurrentIndex(mModel.index(mIndex), QItemSelectionModel::ClearAndSelect);
    display();
}

/**
 * @brief ViewerPageWidget::display Displays a Medium.
 */
void ViewerPageWidget::display() {
    ui->mGraphicsView->resetZoom();
    ui->mZoom->setText("100 %");
}

/**
 * @brief ViewerPageWidget::reset Resets the ViewerPageWidget.
 */
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

/**
 * @brief ViewerPageWidget::nextWidget Switches to the next widget.
 * @param action The QAction of the selected Algorithm.
 */
void ViewerPageWidget::nextWidget(QAction* action) {
    delete mDataset;
    mDataset = nullptr;
    delete mCurrentSelection;
    mCurrentSelection = nullptr;
    delete mImage;
    mImage = nullptr;

    QVariant query;
    query.setValue(mSearchQuery);
    pushToStack(query);

    QPointer<Algorithm> algo(mAlgorithms.value(action->text()));
    QVariant varAlgo;
    varAlgo.setValue(algo);
    pushToStack(varAlgo);

    exit(EXIT_NEXT);
}

/**
 * @brief ViewerPageWidget::on_mGraphicsView_rubberBandChanged Selects a ROI.
 * @param viewportRect unused
 * @param fromScenePoint The starting point of the selection.
 * @param toScenePoint The ending point of the selection.
 */
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

/**
 * @brief ViewerPageWidget::roiClicked En-/Disables the selection mode of a ROI, when the ROI button was clicked.
 */
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

/**
 * @brief ViewerPageWidget::retranslateUi Translates the GUI.
 */
void ViewerPageWidget::retranslateUi() {
    if(mROIIsChosen) {
        ui->mROIButton->setText(tr("Bereich entfernen"));
    } else {
        ui->mROIButton->setText(tr("Bereich auswählen"));
    }
}

/**
 * @brief ViewerPageWidget::getName Returns the name of the widget.
 * @return The name.
 */
QString ViewerPageWidget::getName() {
    return tr("CoBaB - Viewer");
}

/**
 * @brief ViewerPageWidget::getFrameIndex Returns the frameIndex for the SearchObject, 0 if it is a photo.
 * @return The frameIndex.
 */
int ViewerPageWidget::getFrameIndex() {
    return 0;
}

