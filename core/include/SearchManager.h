#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include "ResultsPageWidget.h"
#include "Algorithm.h"

/**
 * @brief Handles an algorithm that will return a SearchResult during the algorithms runtime.
 * @author Vincent Winkler
 */
class SearchManager
{
public:
    SearchManager(ResultsPageWidget* resultsPageWidget);

public slots:
    void startSearch(Algorithm* algo);
    void terminateSearch();

private slots:
    void updateProgress(float progress, const QString &message);

private:
    ResultsPageWidget* mResultsPageWidget;
};

#endif // SEARCHMANAGER_H
