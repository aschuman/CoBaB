#include "include/SearchManager.h"

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief Constructs a SearchManager connecting it to the given ResultsPageWidget.
 * @param The ResultsPageWidget.
 */
SearchManager::SearchManager(ResultsPageWidget *resultsPageWidget)
    : mResultsPageWidget(resultsPageWidget)
{
    QObject::connect(resultsPageWidget, SIGNAL(startAlgorithm(Algorithm*)), this, SLOT(startSearch(Algorithm*)));
}

/**
 * @brief Runs the given Algorithm and sends the results to the ResultsPageWidget.
 * @param The Algorithm.
 */
void SearchManager::startSearch(Algorithm *algo)
{
    mThread = new AlgorithmThread(algo);
    connect(mThread, SIGNAL(resultsReady()), this, SLOT(submitResults()));
    connect(mThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    mThread->start();
}

/**
 * @brief Terminates the search.
 */
void SearchManager::terminateSearch()
{
}

void SearchManager::submitResults()
{
    QList<DataPacket*> results = mThread->getResults();
    if(results.size() > 0){
        SearchResult* searchResult = dynamic_cast<SearchResult*>(results.at(0));
        if(searchResult){
            mResultsPageWidget->setResults(std::move(*searchResult));
        } else {
            LOG_ERR("could not handle packet of type other than SearchResult in SearchManager");
        }
    } else {
        LOG("algorithm did not return any results");
    }
    qDeleteAll(results);
}

void SearchManager::updateProgress(float progress, const QString& message)
{
    Q_UNUSED(progress);
    Q_UNUSED(message);
}

