#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"
#include <stdio.h>
#include <iterator>
#include "Algorithm.h"
#include "log.h"

/**
 * @brief ParameterPageWidget::ParameterPageWidget
 */
ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget), mSearchDatasetList(nullptr) {

    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);

    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
}

/**
 * @brief ParameterPageWidget::~ParameterPageWidget
 */
ParameterPageWidget::~ParameterPageWidget() {
    delete ui;
}

/**
 * @brief ParameterPageWidget::reset
 */
void ParameterPageWidget::reset() {

    QVariant var;
    emit readFromStack(-2, var);
    if (var.canConvert<std::shared_ptr<DatasetList>>()){
        mSearchDatasetList = var.value<std::shared_ptr<DatasetList>>().get();
        mModel.setDatasetList(mSearchDatasetList->getDatasetList());
    }

    QVariant chosenAlgorithm;
    emit readFromStack(0, chosenAlgorithm);
    if (chosenAlgorithm.canConvert<QPointer<Algorithm>>()){
        QPointer<Algorithm> algo = chosenAlgorithm.value<QPointer<Algorithm>>();
        QJsonObject parameterJson = algo->getParameters();

		QJsonObject parameters;
		QJsonObject jsonObject = parameterJson["Properties"].toObject();
		for(QString key: jsonObject.keys()) {
			for(QString key2: jsonObject.value(key).toObject().keys()) {
				if(key2 == "default") {
					parameters.insert(key, jsonObject.value(key).toObject().value(key2));
				}
			}
		}

		QVector<QJsonObject> list;
		list.append(parameters);
		mParameterModel = new QJsonModel(ui->mParameterWidget, list);

		ui->mParameterWidget->setModel(mParameterModel);
		ui->mParameterWidget->setColumnWidth(0,250);

    } else {
        LOG_ERR("no algorithm");
    }

}

/**
 * @brief ParameterPageWidget::nextButtonClicked
 */
void ParameterPageWidget::nextButtonClicked() {

    QItemSelectionModel* model = ui->mSearchDatasetListView->selectionModel();
    QModelIndexList listOfDatasetIndexes = model->selectedIndexes();
    std::shared_ptr<QModelIndexList> list = std::make_shared<QModelIndexList>(listOfDatasetIndexes);
    QVariant var;
    var.setValue(list);
    emit pushToStack(var);

    std::shared_ptr<QJsonObject> parameters = std::make_shared<QJsonObject>(mParameterModel->getParameters());
    QVariant var2;
    var2.setValue(parameters);
    emit pushToStack(var2);

    exit(EXIT_NEXT);
}

/*void ParameterPageWidget::on_mSearchDatasetListView_indexesMoved(const QModelIndexList &indexes)
{

    //save chosen datasets to the stack
    QModelIndexList listOfDatasetIndexes = indexes;
    for (int i = 0; i <listOfDatasetIndexes.size(); i++) {
        pushToStack(listOfDatasetIndexes.at(i));
    }
}*/

/**
 * @brief ParameterPageWidget::retranslateUi
 */
void ParameterPageWidget::retranslateUi() {
    ui->mNext->setText(tr("Weiter"));
    ui->mParameterLabel->setText(tr("Verfahrensparameter"));
    ui->mSearchAreaLabel->setText(tr("Auswahl des Suchraums"));
}

/**
 * @brief ParameterPageWidget::getName
 * @return
 */
QString ParameterPageWidget::getName() {
    return tr("CoBaB - Parameter");
}
