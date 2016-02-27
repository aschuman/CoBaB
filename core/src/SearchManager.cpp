#include "include/SearchManager.h"

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief Constructs a SearchManager connecting it to the given ResultsPageWidget.
 * @param The ResultsPageWidget.
 */
SearchManager::SearchManager(ResultsPageWidget *resultsPageWidget) : mResultsPageWidget(resultsPageWidget)
{
    QObject::connect(resultsPageWidget, SIGNAL(startAlgorithm(Algorithm*)), this, SLOT(startSearch(Algorithm*)));
}

/**
 * @brief Runs the given Algorithm and sends the results to the ResultsPageWidget.
 * @param The Algorithm.
 */
void SearchManager::startSearch(Algorithm *algo)
{
    QList<DataPacket*> results = algo->run();
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

/**
 * @brief Terminates the search.
 */
void SearchManager::terminateSearch()
{
}

void SearchManager::updateProgress(float progress, const QString& message)
{
}

