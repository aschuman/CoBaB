#include "ConfirmationPageWidget.h"
#include "ui_ConfirmationPageWidget.h"
#include "DatasetList.h"
#include "SearchQuery.h"
#include "Algorithm.h"
#include "log.h"
#include <QJsonDocument>

ConfirmationPageWidget::ConfirmationPageWidget() :
    ui(new Ui::ConfirmationPageWidget)
{
    ui->setupUi(this);
    ui->mSearchButton->setText(tr("start search"));


    ui->mParameters->setRowCount(1);
    ui->mParameters->setColumnCount(3);

    ui->mParameters->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("datasets")));
    ui->mParameters->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("algorithm")));
    ui->mParameters->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("parameters")));

    QTableWidgetItem* datasetNames = new QTableWidgetItem("no dataset chosen");
    datasetNames->setFlags(datasetNames->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* algorithmName = new QTableWidgetItem("no algo chosen");
    algorithmName->setFlags(algorithmName->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* parameters = new QTableWidgetItem("no parameters set");
    parameters->setFlags(parameters->flags() ^ Qt::ItemIsEditable);

    ui->mParameters->setItem(0, 0, datasetNames);
    ui->mParameters->setItem(0, 1, algorithmName);
    ui->mParameters->setItem(0, 2, parameters);

}

ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

void ConfirmationPageWidget::reset()
{
    std::shared_ptr<DatasetList> list = nullptr;
    int indexOfChosenDataset = -1;
    const Dataset* chosenDataset = nullptr;

    //read datasets
    QVariant varDatasets;
    emit readFromStack(2, varDatasets);
    if(varDatasets.canConvert<std::shared_ptr<DatasetList>>()){
        list = varDatasets.value<std::shared_ptr<DatasetList>>();
    } else {
        LOG_ERR("no datasets");
    }

    //read number of chosen dataset
    QVariant varChosenDataset;
    emit readFromStack(1, varChosenDataset);
    if(varChosenDataset.canConvert<int>()) {
        indexOfChosenDataset = varChosenDataset.value<int>();

        if((list != nullptr) && (indexOfChosenDataset < list->getDatasetList().size())) {
            chosenDataset = &(list->getDatasetList().at(indexOfChosenDataset));
            ui->mParameters->item(0, 0)->setText(chosenDataset->getName());
        }
    } 
    if(chosenDataset == nullptr) {
        LOG_ERR("no chosen dataset");
        return;
    }

    //read searchobject
    QVariant varSearchQuery;
    emit readFromStack(0, varSearchQuery);
    if(varSearchQuery.canConvert<std::shared_ptr<SearchQuery>>()) {
        std::shared_ptr<SearchQuery> searchQuery = varSearchQuery.value<std::shared_ptr<SearchQuery>>();
        QImage chosenImage(searchQuery->getSearchObject().getMedium());
        QPixmap pixmap;
        pixmap.convertFromImage(chosenImage);

        if(!(searchQuery->getSearchObject().getROI().isNull())) {
            pixmap = pixmap.copy(searchQuery->getSearchObject().getROI());
        } /*else if(searchQuery->getSearchObject().getAnnotation() != nullptr) {
            Annotation* annotation = &(searchQuery->getSearchObject().getAnnotation());
            if(annotation->getType() == Annotation::FACE || annotation->getType() == Annotation::PERSON) {
                RectangleAnnotation* rectAnnotation = static_cast<RectangleAnnotation*> (annotation);
                QRect rect = static_cast<QRect> (*rectAnnotation);
                pixmap = pixmap.copy(rect);
            }
        }*/
        ui->mImageToSearchLabel->setPixmap(pixmap);

    } else {
        LOG_ERR("no searchQuery");
    }

    // add names of chosen datasets
    QVariant varDatasetIndices;
    emit readFromStack(0, varDatasetIndices);
    if(varDatasetIndices.canConvert<QList<int>>()) {
        QList<int> indices = varDatasetIndices.value<QList<int>>();
        for(int i = 0; i < indices.size(); i++) {
            QString name = list->getDatasetList().at(i).getName();
            if(name != chosenDataset->getName()) {
                ui->mParameters->insertRow(i);
                ui->mParameters->setItem(i, 0, new QTableWidgetItem(name));
            }
        }
    }

    //read name of algorithm
    QVariant chosenAlgorithm;
    emit readFromStack(0, chosenAlgorithm);
    if(chosenAlgorithm.canConvert<std::shared_ptr<Algorithm>>()){
        std::shared_ptr<Algorithm> algo = chosenAlgorithm.value<std::shared_ptr<Algorithm>>();
        ui->mParameters->item(0, 1)->setText(algo->getName());
    } else {
        LOG_ERR("no algorithm");
    }

    //read parameters and their values
    QVariant parameterFile;
    emit readFromStack(0, parameterFile);
    if (parameterFile.canConvert<QString>()) {
        QString fileName = parameterFile.value<QString>();
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly)) {
            LOG_ERR("cannot open parameter file");
        }
        QJsonObject object = QJsonDocument::fromJson(file.readAll()).object();
        QStringList keys = object.keys();
        ui->mParameters->setRowCount(std::max(keys.size(), ui->mParameters->rowCount()));
        for (int i = 0; i < keys.size(); i++) {
            QString value = object.value(keys.at(i)).toString();
            ui->mParameters->setItem(i, 2, new QTableWidgetItem(keys.at(i) + " = " + value));
        }
    } else {
        LOG_ERR("no parameter file");
    }
}

void ConfirmationPageWidget::on_mSearchButton_clicked()
{
    exit(EXIT_NEXT);
}

const int ConfirmationPageWidget::EXIT_NEXT = 0;
