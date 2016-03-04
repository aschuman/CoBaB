#include "include/LibraryPageWidget.h"
#include "ui_LibraryPageWidget.h"
#include <QVariant>

const int LibraryPageWidget::EXIT_PHOTO = 0;
const int LibraryPageWidget::EXIT_SINGLE_FRAME_VIDEO = 1;
const int LibraryPageWidget::EXIT_VIDEO = 2;

/**
 * @brief Constructs a LibraryPageWidget.
 */
LibraryPageWidget::LibraryPageWidget() :
    ui(new Ui::LibraryPageWidget)
{
    ui->setupUi(this);
    ui->mLibraryListView->setModel(&mModel);
}

/**
 * @brief Destructs a LibraryPageWidget.
 */
LibraryPageWidget::~LibraryPageWidget()
{
    delete ui;
}

void LibraryPageWidget::reset()
{
    QVariant var;
    emit readFromStack(-2, var);
    if(var.canConvert<std::shared_ptr<DatasetList>>()){
        mDatasetList = var.value<std::shared_ptr<DatasetList>>().get();
        mModel.setDatasetList(mDatasetList->getDatasetList());
    }
}

void LibraryPageWidget::retranslateUi() {

}

void LibraryPageWidget::on_mLibraryListView_doubleClicked(const QModelIndex &index)
{
    int i = index.row();
    int e = -1;
    switch(mDatasetList->getDatasetList().at(i).getType()){
    case Dataset::PHOTO:
        e = EXIT_PHOTO;
    break;
    case Dataset::SINGLE_FRAME_VIDEO:
        e = EXIT_SINGLE_FRAME_VIDEO;
        break;
    case Dataset::VIDEO:
        e = EXIT_VIDEO;
        break;
    }

    emit pushToStack(i);
    emit exit(e);
}
