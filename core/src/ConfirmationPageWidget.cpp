#include "ConfirmationPageWidget.h"
#include "ui_ConfirmationPageWidget.h"
#include "DatasetList.h"

ConfirmationPageWidget::ConfirmationPageWidget() :
    ui(new Ui::ConfirmationPageWidget)
{
    ui->setupUi(this);
    ui->mSearchButton->setText(tr("start search"));


    ui->mParameters->setRowCount(2);
    ui->mParameters->setColumnCount(3);
    QTableWidgetItem* datasets = new QTableWidgetItem(tr("datasets"));
    datasets->setFlags(datasets->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* datasetNames = new QTableWidgetItem("no dataset chosen");
    datasetNames->setFlags(datasetNames->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* algorithm = new QTableWidgetItem(tr("algorithm"));
    algorithm->setFlags(algorithm->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* algorithmName = new QTableWidgetItem("no algo chosen");
    algorithmName->setFlags(algorithmName->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* parameters = new QTableWidgetItem(tr("parameters"));
    parameters->setFlags(parameters->flags() ^ Qt::ItemIsEditable);
    ui->mParameters->setItem(0, 0, datasets);
    ui->mParameters->setItem(0, 1, algorithm);
    ui->mParameters->setItem(0, 2, parameters);
    ui->mParameters->setItem(1, 0, datasetNames);
    ui->mParameters->setItem(1, 1, algorithmName);

}

ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

void ConfirmationPageWidget::reset()
{
    std::shared_ptr<DatasetList> list = nullptr;
    int indexOfChosenDataset;
    const Dataset* chosenDataset;
    int indexOfChosenMedium;
    const Medium* chosenMedium;

    //read names of datasets
    QVariant varDatasets;
    emit readFromStack(1, varDatasets);
    if(varDatasets.canConvert<std::shared_ptr<DatasetList>>()){
        list = varDatasets.value<std::shared_ptr<DatasetList>>();
    }

    //read number of chosen dataset
    QVariant varChosenDataset;
    emit readFromStack(0, varChosenDataset);
    if(varChosenDataset.canConvert<int>()) {
        indexOfChosenDataset = varChosenDataset.value<int>();
    }

    if((list != nullptr) && (indexOfChosenDataset < list->getDatasetList().size())) {
        chosenDataset = &(list->getDatasetList().at(indexOfChosenDataset));
    }

    //read number of chosen medium

    pushToStack(0);

    QVariant varChosenMedium;
    emit readFromStack(0, varChosenMedium);
    if(varChosenMedium.canConvert<int>()) {
        indexOfChosenMedium = varChosenMedium.value<int>();
    }

    if(indexOfChosenMedium < chosenDataset->getMediaList().size()) {
        chosenMedium = chosenDataset->getMediaList().at(indexOfChosenMedium);
    }


    //ToDo display correct search object (annotation/roi/medium)
    QImage chosenImage(chosenMedium->getPath());
    QPixmap pixmap;
    pixmap.convertFromImage(chosenImage);
    ui->mImageToSearchLabel->setPixmap(pixmap);


    //ToDo add names of other chosen datasets
    ui->mParameters->item(1, 0)->setText(chosenDataset->getName());

    //read name of algorithm
    pushToStack("Testalgorithm");

    QVariant chosenAlgorithm;
    emit readFromStack(0, chosenAlgorithm);
    if(chosenAlgorithm.canConvert<QString>()){
        QString algo = chosenAlgorithm.value<QString>();
        ui->mParameters->item(1, 1)->setText(algo);
    }

    //ToDo read parameters and their values
}

void ConfirmationPageWidget::on_mSearchButton_clicked()
{
    exit(EXIT_NEXT);
}

const int ConfirmationPageWidget::EXIT_NEXT = 0;
