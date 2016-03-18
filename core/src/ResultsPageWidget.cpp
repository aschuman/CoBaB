#include "include/ResultsPageWidget.h"
#include "ui_ResultsPageWidget.h"

#include <cmath>
#include <QPointer>
#include "SearchResult.h"
#include "SearchQuery.h"
#include "ConfigData.h"
#include "SearchAlgorithm.h"

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief Constructs a ResultsPageWidget.
 *
 * Sets up user interface.
 */
ResultsPageWidget::ResultsPageWidget() :
    ui(new Ui::ResultsPageWidget),
    mUseSimpleProgressBar(true)
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
ResultsPageWidget::~ResultsPageWidget() {
    delete ui;
}

/**
 * @brief ResultsPageWidget::reset
 */
void ResultsPageWidget::reset()
{
    mModel.setSearchResult(nullptr);
    QVariant var;
    emit readFromStack(2, var);
    if(var.canConvert<QPointer<Algorithm>>()) {
        mAlgorithm = var.value<QPointer<Algorithm>>().data();
        SearchAlgorithm* searchAlgo = qobject_cast<SearchAlgorithm*>(mAlgorithm);
        mUseSimpleProgressBar = !(searchAlgo && searchAlgo->supportsProgressInfo());
        updateProgressBar(0.0);
        emit startAlgorithm(mAlgorithm);
    } else {
        LOG_ERR("could not find algorithm on stack");
    }
    ui->progressBar->setValue(0);
}

/**
 * @brief ResultsPageWidget::setResults
 * @param result
 */
void ResultsPageWidget::setResults(SearchResult result) {
    updateProgressBar(1.0);

    mResult = std::make_shared<SearchResult>(std::move(result));
    mResult->sortByScore();
    mModel.setSearchResult(mResult.get());

    ConfigData* data = ConfigData::getInstance();
    if (data->getSoundOn()) {
        Q_INIT_RESOURCE(application);
        QSound::play(":/sound.wav");
    }

    QVariant varQuery;
    emit readFromStack(3, varQuery);
    if (varQuery.canConvert<std::shared_ptr<SearchQuery>>()) {
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
    setCursor(QCursor(Qt::CursorShape::ArrowCursor));
}

/**
 * @brief ResultsPageWidget::setProgress
 * @param progress
 */
void ResultsPageWidget::setProgress(double progress) {
    updateProgressBar(progress);
}

/**
 * @brief ResultsPageWidget::on_btnNewSearch_clicked
 */
void ResultsPageWidget::on_btnNewSearch_clicked() {
    bool newSearchPossible = true;

    QVariant varDatasetNo;
    emit readFromStack(4, varDatasetNo);
    if (!varDatasetNo.canConvert<int>()) {
        LOG_ERR("could not find dataset on stack");
    }

    QVariant varSearchQuery;
    emit readFromStack(3, varSearchQuery);
    if(!varSearchQuery.canConvert<std::shared_ptr<SearchQuery>>()) {
        newSearchPossible = false;
        LOG_ERR("could not find search query on stack");
    }

    QVariant varAlgorithm;
    emit readFromStack(2, varAlgorithm);
    if(!varAlgorithm.canConvert<QPointer<Algorithm>>()) {
        LOG_ERR("could not find algorithm on stack");
    }

    // ToDo: read parameters from stack

    QVariant varFeedback;
    if (newSearchPossible) {
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

    if (newSearchPossible) {
        emit pushToStack(varFeedback);
        emit pushToStack(varDatasetNo);
        emit pushToStack(varSearchQuery);
        emit pushToStack(varAlgorithm);
        //emit pushToStack(varParameter);
        emit exit(EXIT_NEW_SEARCH);
    }

}

/**
 * @brief ResultsPageWidget::updateProgressBar
 * @param progress
 */
void ResultsPageWidget::updateProgressBar(double progress) {
    int value = (int)std::lround(progress*100);
    if (mUseSimpleProgressBar && value < 100) {
        ui->progressBar->setMaximum(0);
    }
    else {
        ui->progressBar->setMaximum(100);
    }

    ui->progressBar->setTextVisible(!mUseSimpleProgressBar);
    ui->progressBar->setValue(value);
}

/**
 * @brief ResultsPageWidget::retranslateUi
 */
void ResultsPageWidget::retranslateUi() {
    ui->btnNewSearch->setText(tr("Erneut suchen"));
}

/**
 * @brief ResultsPageWidget::getName
 * @return
 */
QString ResultsPageWidget::getName() {
    return tr("CoBaB - Ergebnisse");
}
