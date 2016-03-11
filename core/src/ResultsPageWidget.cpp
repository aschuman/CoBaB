#include "include/ResultsPageWidget.h"
#include "ui_ResultsPageWidget.h"

#include <QPointer>
#include "SearchResult.h"
#include "SearchQuery.h"
#include "ConfigData.h"

#define LOGGING_LEVEL_1
#include "log.h"

const int ResultsPageWidget::EXIT_NEW_SEARCH = 0;

/**
 * @brief temporary
 * @return
 */
SearchResult generateReslut()
{
    QList<SearchResultElement> list;
    SearchObject obj1;
    obj1.setMedium("../test/testdata/Fotos/000_45.bmp");
    SearchObject obj2;
    obj2.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj3;
    obj3.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj4;
    obj4.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj5;
    obj5.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj6;
    obj6.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj7;
    obj7.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj8;
    obj8.setMedium("../test/testdata/Fotos/002_45.bmp");

    SearchResultElement element1;
    SearchResultElement element2;
    SearchResultElement element3;
    SearchResultElement element4;
    SearchResultElement element5;
    SearchResultElement element6;
    SearchResultElement element7;
    SearchResultElement element8;
    element1.setSearchObject(obj1);
    element2.setSearchObject(obj2);
    element3.setSearchObject(obj3);
    element4.setSearchObject(obj4);
    element5.setSearchObject(obj5);
    element6.setSearchObject(obj6);
    element7.setSearchObject(obj7);
    element8.setSearchObject(obj8);

    list.push_back(element1);
    list.push_back(element2);
    list.push_back(element3);
    list.push_back(element4);
    list.push_back(element5);
    list.push_back(element6);
    list.push_back(element7);
    list.push_back(element8);

    return SearchResult(list);
}

/**
 * @brief Constructs a ResultsPageWidget.
 *
 * Sets up user interface.
 */
ResultsPageWidget::ResultsPageWidget() :
    ui(new Ui::ResultsPageWidget)
{
    ui->setupUi(this);
    ui->mListView->setModel(&mModel);
    ui->mListView->setItemDelegate(&mDelegate);
}

/**
 * @brief Destructs a ResultsPageWidget.
 *
 * Frees user interface.
 */
ResultsPageWidget::~ResultsPageWidget()
{
    delete ui;
}

void ResultsPageWidget::reset()
{
    QVariant var;
    emit readFromStack(1, var);
    if(var.canConvert<QPointer<Algorithm>>()){
        mAlgorithm = var.value<QPointer<Algorithm>>().data();
        emit startAlgorithm(mAlgorithm);
    } else {
        LOG_ERR("could not find algorithm on stack");
    }
}

void ResultsPageWidget::setResults(SearchResult result)
{
    mResult = std::make_shared<SearchResult>(std::move(result));
    mResult->sortByScore();
    mModel.setSearchResult(mResult.get());

    ConfigData* data = ConfigData::getInstance();
    if(data->getSoundOn()) {
        Q_INIT_RESOURCE(application);
        QSound::play(":/sound.wav");
    }

    QVariant varQuery;
    emit readFromStack(2, varQuery);
    if(varQuery.canConvert<std::shared_ptr<SearchQuery>>()){
        SearchQuery* query = varQuery.value<std::shared_ptr<SearchQuery>>().get();
        SearchFeedback feedback = mModel.getFeedback();

        QList<DataPacket*> algoInputs;
        algoInputs.push_back(query);
        algoInputs.push_back(&feedback);

        if(mAlgorithm->setInputs(algoInputs)){
            ui->btnNewSearch->setEnabled(true);
        }

    } else {
        LOG_ERR("could not find search query on stack");
    }
}

void ResultsPageWidget::on_btnNewSearch_clicked()
{
    bool newSearchPossible = true;

    QVariant varDatasetNo;
    emit readFromStack(3, varDatasetNo);
    if(!varDatasetNo.canConvert<int>()){
        LOG_ERR("could not find dataset on stack");
    }

    QVariant varSearchQuery;
    emit readFromStack(2, varSearchQuery);
    if(!varSearchQuery.canConvert<std::shared_ptr<SearchQuery>>()){
        newSearchPossible = false;
        LOG_ERR("could not find search query on stack");
    }

    QVariant varAlgorithm;
    emit readFromStack(1, varAlgorithm);
    if(!varAlgorithm.canConvert<QPointer<Algorithm>>()){
        LOG_ERR("could not find algorithm on stack");
    }

    // ToDo: read parameters from stack

    QVariant varFeedback;
    if(newSearchPossible){
        SearchQuery* query = varSearchQuery.value<std::shared_ptr<SearchQuery>>().get();
        auto feedback = std::make_shared<SearchFeedback>(mModel.getFeedback());

        QList<DataPacket*> algoInputs;
        algoInputs.push_back(query);
        algoInputs.push_back(feedback.get());

        varFeedback.setValue(feedback);

        if(!mAlgorithm->setInputs(algoInputs)){
            newSearchPossible = false;
        }
    }

    if(newSearchPossible){
        emit pushToStack(varFeedback);
        emit pushToStack(varDatasetNo);
        emit pushToStack(varSearchQuery);
        emit pushToStack(varAlgorithm);
        //emit pushToStack(varParameter);
        emit exit(EXIT_NEW_SEARCH);
    }

}

void ResultsPageWidget::retranslateUi() {
    ui->btnNewSearch->setText(tr("Erneut suchen"));
}

QString ResultsPageWidget::getName() {
    return tr("CoBaB - Ergebnisse");
}
