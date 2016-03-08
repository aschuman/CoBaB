#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"
#include <stdio.h>
#include <iterator>

const int ParameterPageWidget::EXIT_NEXT = 0;

ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget)
{

    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);

    QString fileName = "../resources/PluginDepthEstimator.json";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QJsonObject object = QJsonDocument::fromJson(file.readAll()).object();
    mParameterModel.loadQJson(object);

//        QVector<QJsonObject> list;
//        list.append(object);
//        mParameterModel(ui->mParameterWidget, list);

    ui->mParameterWidget->setModel(&mParameterModel);

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

    QItemSelectionModel* model = ui->mSearchDatasetListView->selectionModel();
    QModelIndexList listOfDatasetIndexes = model->selectedIndexes();
    std::shared_ptr<QModelIndexList> list = std::make_shared<QModelIndexList>(listOfDatasetIndexes);
    QVariant var;
    var.setValue(list);
    emit pushToStack(var);
    exit(EXIT_NEXT);
}

void ParameterPageWidget::on_mSearchDatasetListView_indexesMoved(const QModelIndexList &indexes)
{

    //save chosen datasets to the stack
    QModelIndexList listOfDatasetIndexes = indexes;
    for (int i = 0; i <listOfDatasetIndexes.size(); i++) {
        pushToStack(listOfDatasetIndexes.at(i));
    }

}

void ParameterPageWidget::retranslateUi() {
    ui->mNext->setText(tr("Weiter"));
}
