#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"

const int ParameterPageWidget::EXIT_NEXT = 0;

ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget)
{
    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);
    ui->mParameterWidget->setModel(&mParameterModel);

 //   mParameterModel.load("/home/vzh/Documents/PSE/CoBaB/resources/PluginDepthEstimator.json");

 //   ui->mSearchDatasetListView->setSelectionMode(QAbstractItemView::MultiSelection);

    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
}

ParameterPageWidget::~ParameterPageWidget()
{
    delete ui;
}

void ParameterPageWidget::reset() {

    QVariant var;
    emit readFromStack(-2, var);
    if(var.canConvert<std::shared_ptr<DatasetList>>()){
        mSearchDatasetList = var.value<std::shared_ptr<DatasetList>>().get();
        mModel.setDatasetList(mSearchDatasetList->getDatasetList());
    }

}

void ParameterPageWidget::nextButtonClicked() {

  //  QModelIndexList listOfDatasetIndexes = *ui->mSearchDatasetListView->selectionMode().selectedIndexes();
  //  pushToStack(listOfDatasetIndexes);
    exit(EXIT_NEXT);
}

void ParameterPageWidget::on_mSearchDatasetListView_indexesMoved(const QModelIndexList &indexes)
{

}

void ParameterPageWidget::retranslateUi() {
    ui->mNext->setText(tr("Weiter"));
}
