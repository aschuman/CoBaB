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
#include "SearchFeedback.h"

/**
 * @brief ConfirmationPageWidget::ConfirmationPageWidget Constructs a ConfirmationPageWidget.
 */
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
    ui->mParameters->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

/**
 * @brief ConfirmationPageWidget::~ConfirmationPageWidget Destructs a ConfirmationPageWidget.
 */
ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

/**
 * @brief ConfirmationPageWidget::reset
 */
void ConfirmationPageWidget::reset()
{
    clearTable();
    std::shared_ptr<DatasetList> list = nullptr;
    const Dataset* chosenDataset = nullptr;

    //read available datasets from the stack
    QVariant varDatasets;
    emit readFromStack(-2, varDatasets);
    if(varDatasets.canConvert<std::shared_ptr<DatasetList>>()){
        list = varDatasets.value<std::shared_ptr<DatasetList>>();
    } else {
        LOG_ERR("no datasets");
    }

    //read the index of the chosen dataset in the dataset list from the stack
    QVariant varChosenDataset;
    emit readFromStack(4, varChosenDataset);
    if(varChosenDataset.canConvert<int>()) {
        int indexOfChosenDataset = varChosenDataset.value<int>();

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

    //read the SearchObject from the stack
    QVariant varSearchQuery;
    emit readFromStack(3, varSearchQuery);
    std::shared_ptr<SearchQuery> searchQuery = nullptr;
    if(varSearchQuery.canConvert<std::shared_ptr<SearchQuery>>()) {
        searchQuery = varSearchQuery.value<std::shared_ptr<SearchQuery>>();
        SearchObject searchObject = searchQuery->getSearchObject();

        QImage chosenImage;
        if(searchObject.getMediumIndex() == 0) {
            chosenImage.load(searchObject.getMedium());
        } else if(searchObject.getMediumIndex() == 1) {
            Dataset dataset(searchObject.getMedium());
            chosenImage.load(dataset.getPath() + "/" +
                ((SingleFrameVideo*)dataset.getMediaList().at(0))->getFrameList().at(searchObject.getFrameIndex()));
        } else {
            LOG_ERR("No valid medium");
        }
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

        if(!pixmap.isNull()) {
            ui->mImageToSearchLabel->setMinimumSize(1, 1);
            ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
        } else {
            ui->mImageToSearchLabel->setText(tr("Bild kann nicht geöffnet werden."));
            LOG_ERR("medium of search object cannot be opened");
        }
    } else {
        LOG_ERR("no searchQuery");
    }

    // add names of chosen datasets
    QVariant varDatasetIndices;
    emit readFromStack(1, varDatasetIndices);
    if(varDatasetIndices.canConvert<std::shared_ptr<QModelIndexList>>()) {
        std::shared_ptr<QModelIndexList> indices = varDatasetIndices.value<std::shared_ptr<QModelIndexList>>();
        QList<QString> datasetList;
        datasetList.append(chosenDataset->getPath());
        for(int i = 0; i < indices.get()->size(); i++) {
            int index = indices.get()->at(i).row();
            if((list != nullptr) && (index < list->getDatasetList().size())) {
                QString name = list->getDatasetList().at(index).getName();
                if(name != chosenDataset->getName()) {
                    ui->mParameters->insertRow(i);
                    ui->mParameters->setItem(i, 0, new QTableWidgetItem(name));
                    ui->mParameters->item(i, 0)->setTextAlignment(Qt::AlignCenter);
                    datasetList.append(list->getDatasetList().at(index).getPath());
                }
            } else {
                LOG_ERR("invalid dataset index");
            }
        }
        searchQuery->setDatasets(datasetList);
    }

    //read name of algorithm
    QVariant chosenAlgorithm;
    QPointer<Algorithm> algo = nullptr;
    emit readFromStack(2, chosenAlgorithm);
    if(chosenAlgorithm.canConvert<QPointer<Algorithm>>()){
        algo = chosenAlgorithm.value<QPointer<Algorithm>>();
		ui->mParameters->setItem(0, 1, new QTableWidgetItem(algo->getName()));
        ui->mParameters->item(0, 1)->setTextAlignment(Qt::AlignCenter);
    } else {
        LOG_ERR("no algorithm");
    }

    //read parameters and their values
    QVariant varParameters;
    std::shared_ptr<QJsonObject> parameters = nullptr;
    emit readFromStack(0, varParameters);
    if(varParameters.canConvert<std::shared_ptr<QJsonObject>>()) {
        parameters = varParameters.value<std::shared_ptr<QJsonObject>>();
        QJsonObject::const_iterator iter;
        int i = 0;
        for(iter = parameters->begin(); iter != parameters->end(); ++iter) {
            ui->mParameters->setRowCount(std::max(parameters->keys().size(), ui->mParameters->rowCount()));
            ui->mParameters->setItem(i, 2, new QTableWidgetItem(iter.key() + " = " + iter.value().toVariant().toString()));
			
            ui->mParameters->item(i, 2)->setTextAlignment(Qt::AlignCenter);
            i++;
        }
    } else {
        LOG_ERR("no parameters");
    }

    // check if tere is feedback
    QVariant varFeedback;
    SearchFeedback* feedback = nullptr;
    emit readFromStack(5, varFeedback);
    if(varFeedback.canConvert<std::shared_ptr<SearchFeedback>>()) {
        feedback = varFeedback.value<std::shared_ptr<SearchFeedback>>().get();
    }

    ui->mParameters->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if(parameters != nullptr) {
        if(!algo->setParameters(*(parameters.get()))) {
            LOG_ERR("could not set parameters");
        }
    }
    if(searchQuery != nullptr) {
        QList<DataPacket*> dplist;
        dplist.push_back(searchQuery.get());
        dplist.push_back(feedback);
        if(!algo->setInputs(dplist)) {
            dplist.pop_back();
            if(!algo->setInputs(dplist)){
                LOG_ERR("Could not set search query");
            }
        }
    }
}

/**
 * @brief ConfirmationPageWidget::clearTable Resets the QTableWidget which contains the parameters.
 */
void ConfirmationPageWidget::clearTable() {
    while(ui->mParameters->rowCount() > 0) {
        ui->mParameters->removeRow(0);
    }
}

/**
 * @brief ConfirmationPageWidget::retranslateUi
 */
void ConfirmationPageWidget::retranslateUi() {
    ui->mSearchButton->setText(tr("Suche starten"));
    ui->mParameters->horizontalHeaderItem(0)->setText(tr("Datenordner"));
    ui->mParameters->horizontalHeaderItem(1)->setText(tr("Algorithmus"));
    ui->mParameters->horizontalHeaderItem(2)->setText(tr("Parameter"));
    if(pixmap.isNull()) {
        ui->mImageToSearchLabel->setText(tr("Bild kann nicht geöffnet werden."));
    }
}

/**
 * @brief ConfirmationPageWidget::getName
 * @return
 */
QString ConfirmationPageWidget::getName() {
    return tr("CoBaB - Bestätigung");
}

/**
 * @brief ConfirmationPageWidget::showEvent Sets the label with the photo to the correct size
 * when showing the label for the first time.
 * @param event Is sent when the widget is shown.
 */
void ConfirmationPageWidget::showEvent(QShowEvent* event) {
    if(!event->spontaneous() && !pixmap.isNull()) {
        ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
    }
}

/**
 * @brief ConfirmationPageWidget::resizeEvent Resizes the label with the photo when the size of the GUI changed.
 * @param event The resizeEvent when the size of the GUI changed.
 */
void ConfirmationPageWidget::resizeEvent(QResizeEvent* event) {
    Q_UNUSED(event);
    ui->mImageToSearchLabel->setMinimumSize(1, 1);
    ui->mImageToSearchLabel->setPixmap(pixmap.scaled(ui->mImageToSearchLabel->size(), Qt::KeepAspectRatio));
}

/**
 * @brief ConfirmationPageWidget::on_mSearchButton_clicked Sends the signal that the ConfirmationPageWidget
 * wants to exit and the ResultsPageWidget should be shown.
 */
void ConfirmationPageWidget::on_mSearchButton_clicked()
{
    exit(EXIT_NEXT);
}
