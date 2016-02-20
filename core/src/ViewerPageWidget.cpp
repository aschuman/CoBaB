#include "include/ViewerPageWidget.h"
#include "ui_ViewerPageWidget.h"
#include "SearchQuery.h"
#include <QMenu>

const int ViewerPageWidget::EXIT_NEXT = 0;

ViewerPageWidget::ViewerPageWidget() :
    ui(new Ui::ViewerPageWidget), mIndex(0), mGraphicsItem(nullptr)
{
    ui->setupUi(this);
    ui->mViewerListView->setResizeMode(QListView::Adjust);
    ui->mGraphicsView->setScene(&mGraphicsScene);
    ui->mViewerListView->setModel(&mModel);
    connect(ui->mViewerListView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicked(const QModelIndex&)));
    connect(ui->mNextButton, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->mBeforeButton, SIGNAL(clicked()), this, SLOT(before()));

    connect(ui->mGraphicsView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(contextMenu(const QPoint&)));
}

void ViewerPageWidget::contextMenu(const QPoint &pos) {
    Q_UNUSED(pos);
    QMenu contextMenu(this);
    QAction action1("algorithm 1", this);
    contextMenu.addAction(&action1);
    QAction action2("algorithm 2", this);
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

ViewerPageWidget::~ViewerPageWidget()
{
    delete ui;
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
    if(mGraphicsItem != nullptr) {
        mGraphicsScene.removeItem(mGraphicsItem);
        delete mGraphicsItem;
    }
    mGraphicsItem = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(mDataset->getMediaList().at(mIndex)->getPath())));
    mGraphicsScene.addItem(mGraphicsItem);
}

void ViewerPageWidget::nextWidget(QAction* action) {
    delete mGraphicsItem;
    SearchObject searchObject;
    searchObject.setMedium(mDataset->getMediaList().at(mIndex)->getPath());
    searchObject.setSourceDataset(mDataset->getPath());

    SearchQuery searchQuery;
    searchQuery.setSearchObject(searchObject);

    QString algorithm = action->text();

    QVariant query;
    query.setValue(std::make_shared<SearchQuery>(searchQuery));
    pushToStack(query);
    exit(EXIT_NEXT);
}


