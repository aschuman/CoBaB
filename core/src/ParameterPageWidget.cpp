#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"
#include <stdio.h>
#include <iterator>
#include "Algorithm.h"
#include "log.h"

const int ParameterPageWidget::EXIT_NEXT = 0;

ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget), mSearchDatasetList(nullptr)
{

    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);

    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
    connect(ui->mParameterWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(on_mParameterWidget_clicked(QModelIndex)));
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

    QVariant chosenAlgorithm;
    emit readFromStack(0, chosenAlgorithm);
    if(chosenAlgorithm.canConvert<QPointer<Algorithm>>()){
        QPointer<Algorithm> algo = chosenAlgorithm.value<QPointer<Algorithm>>();
        QJsonObject json = algo->getParameterJson();
        QJsonObject jsonObject = json["Properties"].toObject();
        QVector<QJsonObject> list;
        list.append(jsonObject);
        mParameterModel = new QJsonModel(ui->mParameterWidget, list);

        ui->mParameterWidget->setModel(mParameterModel);

    } else {
        LOG_ERR("no algorithm");
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

QString ParameterPageWidget::getName() {
    return tr("CoBaB - Parameter");
}

void ParameterPageWidget::on_mParameterWidget_clicked(const QModelIndex &index)
{
    QModelIndex indexNew = index;
    mParameterModel->flags(indexNew);
}
