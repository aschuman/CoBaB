#include "include/LibraryPageWidget.h"
#include "ui_LibraryPageWidget.h"
#include <QVariant>
#include <QFileDialog>
#include <QMessageBox>
#include "Configuration.h"

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

QString LibraryPageWidget::getName() {
    return tr("CoBaB - Bibliothek");
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

void LibraryPageWidget::showFileDialog() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Datenordner öffnen"), "/home");
    Dataset dataset(dir);
    if(dataset.isValid()) {
        mDatasetList->addDataset(dataset);
        mDatasetList->store(DATASET_HISTORY_FILE);
        int e = -1;
        switch(dataset.getType()){
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
        emit pushToStack(mDatasetList->getDatasetList().indexOf(dataset));
        emit exit(e);
    } else {
        QMessageBox msgBox(QMessageBox::Information, "", tr("Kein gültiger Datenordner gewählt"), QMessageBox::Ok, this);
        msgBox.exec();
    }
}
