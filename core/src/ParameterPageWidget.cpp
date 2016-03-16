#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"
#include <stdio.h>
#include <iterator>
#include "Algorithm.h"
#include "log.h"

/**
 * @brief ParameterPageWidget::ParameterPageWidget Constructs a ParameterPageWidget.
 */
ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget), mSearchDatasetList(nullptr) {

    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);

    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
}

/**
 * @brief ParameterPageWidget::~ParameterPageWidget Destructs a ParameterPageWidget.
 */
ParameterPageWidget::~ParameterPageWidget() {
    delete ui;
}

/**
 * @brief ParameterPageWidget::reset Resets the data of the ParameterPageWidget.
 */
void ParameterPageWidget::reset() {

    //display the parameters
    QVariant var;
    emit readFromStack(-2, var);
    if (var.canConvert<std::shared_ptr<DatasetList>>()){
        mSearchDatasetList = var.value<std::shared_ptr<DatasetList>>().get();
        mModel.setDatasetList(mSearchDatasetList->getDatasetList());
    }

    //display the parameters
    QVariant chosenAlgorithm;
    emit readFromStack(0, chosenAlgorithm);
    if (chosenAlgorithm.canConvert<QPointer<Algorithm>>()){
        QPointer<Algorithm> algo = chosenAlgorithm.value<QPointer<Algorithm>>();
        QJsonObject parameterJson = algo->getDefaultParameters();

		QJsonObject parameters;
        for(QString key: parameterJson.keys()) {
            for(QString key2: parameterJson.value(key).toObject().keys()) {
				if(key2 == "default") {
                    parameters.insert(key, parameterJson.value(key).toObject().value(key2));
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
 * @brief ParameterPageWidget::nextButtonClicked Switches to the next GUI window and pushesh the needed data to stack.
 */
void ParameterPageWidget::nextButtonClicked() {

    //push the chosen datasets to stack
    QItemSelectionModel* model = ui->mSearchDatasetListView->selectionModel();
    QModelIndexList listOfDatasetIndexes = model->selectedIndexes();
    std::shared_ptr<QModelIndexList> list = std::make_shared<QModelIndexList>(listOfDatasetIndexes);
    QVariant var;
    var.setValue(list);
    emit pushToStack(var);

    //push the parameters to stack
    std::shared_ptr<QJsonObject> parameters = std::make_shared<QJsonObject>(mParameterModel->getParameters().value("root").toObject());
    QVariant var2;
    var2.setValue(parameters);
    emit pushToStack(var2);

    exit(EXIT_NEXT);
}

/**
 * @brief ParameterPageWidget::retranslateUi Translates the ParameterPageWidget in English.
 */
void ParameterPageWidget::retranslateUi() {
    ui->mNext->setText(tr("Weiter"));
    ui->mParameterLabel->setText(tr("Verfahrensparameter"));
    ui->mSearchAreaLabel->setText(tr("Auswahl des Suchraums"));
}

/**
 * @brief ParameterPageWidget::getName Gets the name of the ParameterPageWidget.
 * @return the name ot the ParameterPageWidget
 */
QString ParameterPageWidget::getName() {
    return tr("CoBaB - Parameter");
}
