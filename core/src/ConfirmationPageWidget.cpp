#include "ConfirmationPageWidget.h"
#include "ui_ConfirmationPageWidget.h"
#include "DatasetList.h"
#include "SearchQuery.h"
#include "Algorithm.h"
#include "ParameterPageWidget.h"
#include "log.h"
#include <QJsonDocument>
#include <QDebug>
#include <QResizeEvent>
#include <QPointer>

ConfirmationPageWidget::ConfirmationPageWidget() :
    ui(new Ui::ConfirmationPageWidget)
{
    ui->setupUi(this);
    ui->mSearchButton->setText(tr("Suche starten"));


    ui->mParameters->setRowCount(1);
    ui->mParameters->setColumnCount(3);

    ui->mParameters->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Datenordner")));
    ui->mParameters->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Algorithmus")));
    ui->mParameters->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Parameter")));

    QTableWidgetItem* datasetNames = new QTableWidgetItem("no dataset chosen");
    datasetNames->setFlags(datasetNames->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* algorithmName = new QTableWidgetItem("no algo chosen");
    algorithmName->setFlags(algorithmName->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* parameters = new QTableWidgetItem("no parameters set");
    parameters->setFlags(parameters->flags() ^ Qt::ItemIsEditable);

    ui->mParameters->setItem(0, 0, datasetNames);
    ui->mParameters->setItem(0, 1, algorithmName);
    ui->mParameters->setItem(0, 2, parameters);
    ui->mParameters->item(0, 2)->setTextAlignment(Qt::AlignCenter);

    ui->mParameters->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void ConfirmationPageWidget::retranslateUi() {
    ui->mSearchButton->setText(tr("Suche starten"));
    ui->mParameters->horizontalHeaderItem(0)->setText(tr("Datenordner"));
    ui->mParameters->horizontalHeaderItem(1)->setText(tr("Algorithmus"));
    ui->mParameters->horizontalHeaderItem(2)->setText(tr("Parameter"));
}

ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

void ConfirmationPageWidget::reset()
{
    clearTable();
    std::shared_ptr<DatasetList> list = nullptr;
    int indexOfChosenDataset = -1;
    const Dataset* chosenDataset = nullptr;

    //read datasets
    QVariant varDatasets;
    emit readFromStack(-2, varDatasets);
    if(varDatasets.canConvert<std::shared_ptr<DatasetList>>()){
        list = varDatasets.value<std::shared_ptr<DatasetList>>();
    } else {
        LOG_ERR("no datasets");
    }

    //read number of chosen dataset
    QVariant varChosenDataset;
    emit readFromStack(3, varChosenDataset);
    if(varChosenDataset.canConvert<int>()) {
        indexOfChosenDataset = varChosenDataset.value<int>();

        if((list != nullptr) && (indexOfChosenDataset < list->getDatasetList().size())) {
            chosenDataset = &(list->getDatasetList().at(indexOfChosenDataset));
            ui->mParameters->insertRow(0);
            ui->mParameters->setItem(0, 0, new QTableWidgetItem(chosenDataset->getName()));
            ui->mParameters->item(0, 0)->setTextAlignment(Qt::AlignCenter);
        }
    }
    if(chosenDataset == nullptr) {
        LOG_ERR("no chosen dataset");
        return;
    }

    //read searchobject
    QVariant varSearchQuery;
    emit readFromStack(2, varSearchQuery);
    if(varSearchQuery.canConvert<std::shared_ptr<SearchQuery>>()) {
        std::shared_ptr<SearchQuery> searchQuery = varSearchQuery.value<std::shared_ptr<SearchQuery>>();
        SearchObject searchObject = searchQuery->getSearchObject();
        QImage chosenImage(searchObject.getMedium());
        pixmap.convertFromImage(chosenImage);

        if(searchObject.getType() == SearchObject::ROI) {
            pixmap = pixmap.copy(searchObject.getROI());
        } else if(searchObject.getType() == SearchObject::ANNOTATION) {
            if (searchObject.getAnnotation()->getForm() == Annotation::RECTANGLE) {
                RectangleAnnotation* rectAnnotation = (RectangleAnnotation*)searchObject.getAnnotation();
                if(rectAnnotation != nullptr) {
                    QRect rect = static_cast<QRect> (*rectAnnotation);
                    pixmap = pixmap.copy(rect);
                }
            }
        }
        ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
    } else {
        LOG_ERR("no searchQuery");
    }

    // add names of chosen datasets
    QVariant varDatasetIndices;
    emit readFromStack(0, varDatasetIndices);
    if(varDatasetIndices.canConvert<std::shared_ptr<QModelIndexList>>()) {
        std::shared_ptr<QModelIndexList> indices = varDatasetIndices.value<std::shared_ptr<QModelIndexList>>();
        for(int i = 0; i < indices.get()->size(); i++) {
            int index = indices.get()->at(i).row();
            if((list != nullptr) && (index < list->getDatasetList().size())) {
                QString name = list->getDatasetList().at(index).getName();
                if(name != chosenDataset->getName()) {
                    ui->mParameters->insertRow(i);
                    ui->mParameters->setItem(i, 0, new QTableWidgetItem(name));
                    ui->mParameters->item(i, 0)->setTextAlignment(Qt::AlignCenter);
                }
            } else {
                LOG_ERR("invalid dataset index");
            }
        }
    }

    //read name of algorithm
    QVariant chosenAlgorithm;
    emit readFromStack(1, chosenAlgorithm);
    if(chosenAlgorithm.canConvert<QPointer<Algorithm>>()){
        QPointer<Algorithm> algo = chosenAlgorithm.value<QPointer<Algorithm>>();
		ui->mParameters->setItem(0, 1, new QTableWidgetItem(algo->getName()));
        ui->mParameters->item(0, 1)->setTextAlignment(Qt::AlignCenter);
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
            ui->mParameters->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        }
    } else {
        LOG_ERR("no parameter file");
    }

    ui->mParameters->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ConfirmationPageWidget::clearTable() {
    while(ui->mParameters->rowCount() > 0) {
        ui->mParameters->removeRow(0);
    }
}

void ConfirmationPageWidget::showEvent(QShowEvent* event) {
    if(!event->spontaneous()) {
        ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
    }
}

/*void ConfirmationPageWidget::resizeEvent(QResizeEvent* event) {
    ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
}*/

void ConfirmationPageWidget::on_mSearchButton_clicked()
{
    exit(EXIT_NEXT);
}

const int ConfirmationPageWidget::EXIT_NEXT = 0;
