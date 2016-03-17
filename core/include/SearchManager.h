#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include <QThread>
#include <QObject>
#include "ResultsPageWidget.h"
#include "Algorithm.h"
#include "AlgorithmThread.h"

/**
 * @brief Handles an algorithm that will return a SearchResult during the algorithms runtime.
 * @author Vincent Winkler
 */
class SearchManager : public QObject
{
    Q_OBJECT
public:
    explicit SearchManager(ResultsPageWidget* resultsPageWidget);

public slots:
    void startSearch(Algorithm* algo);
    void terminateSearch();

private slots:
    void submitResults();
    void updateProgress(float progress, const QString &message);

private:
    ResultsPageWidget* mResultsPageWidget;
    AlgorithmThread* mThread;
};

#endif // SEARCHMANAGER_H
