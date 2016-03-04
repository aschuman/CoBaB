#include "include/LibraryPageWidget.h"
#include "ui_LibraryPageWidget.h"
#include <QVariant>

const int LibraryPageWidget::EXIT_NEXT = 0;

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
        mModel.setDatasetList(var.value<std::shared_ptr<DatasetList>>()->getDatasetList());
    }
}

void LibraryPageWidget::retranslateUi() {

}

void LibraryPageWidget::on_mLibraryListView_doubleClicked(const QModelIndex &index)
{
    pushToStack(index.row());
    exit(EXIT_NEXT);
}
