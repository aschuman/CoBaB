#include "include/LibraryPageWidget.h"
#include "ui_LibraryPageWidget.h"
#include <QVariant>

LibraryPageWidget::LibraryPageWidget() :
    ui(new Ui::LibraryPageWidget)
{
    ui->setupUi(this);
    ui->mLibraryListView->setModel(&mModel);
}

LibraryPageWidget::~LibraryPageWidget()
{
    delete ui;
}

void LibraryPageWidget::reset()
{
    QVariant var;
    emit readFromStack(0, var);
    if(var.canConvert<std::shared_ptr<DatasetList>>()){
        mModel.setDatasetList(var.value<std::shared_ptr<DatasetList>>()->getDatasetList());
    }

    /*mDatasetList = new DatasetList();
    mDatasetList->addDataset(Dataset("oiajsd"));
    mDatasetList->addDataset(Dataset("rest"));*/

    //mModel.setDatasetList(mDatasetList->getDatasetList());

}

void LibraryPageWidget::on_pushButton_clicked()
{
    emit exit(EXIT_NEXT);
}

const int LibraryPageWidget::EXIT_NEXT = 0;
