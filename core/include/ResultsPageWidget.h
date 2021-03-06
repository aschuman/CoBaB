#ifndef RESULTSPAGEWIDGET_H
#define RESULTSPAGEWIDGET_H

#include <memory>
#include "PageWidget.h"
#include "SearchResultModel.h"
#include "FeedbackDelegate.h"
#include "Algorithm.h"
#include <QtMultimedia>
#include <QSound>

#include <memory>

namespace Ui {
class ResultsPageWidget;
}

/**
 * @brief PageWidget that displays search results and supports user-defined feedback.
 * @author Vincent Winkler
 */
class ResultsPageWidget : public PageWidget
{
    Q_OBJECT

public:
    ResultsPageWidget();
    ~ResultsPageWidget();
    void reset() override;
    void retranslateUi() override;
    QString getName() override;

    void setResults(SearchResult result);

    static const int EXIT_NEW_SEARCH = 0;       ///< The number the widget exits with.

signals:
    /**
     * @brief startAlgorithm Is send when the algorithm should be started.
     * @param algo The chosen algorithm.
     */
    void startAlgorithm(Algorithm* algo);

public slots:
    void setProgress(double progress);

private slots:
    void on_btnNewSearch_clicked();

private:
    void updateProgressBar(double progress);

    Ui::ResultsPageWidget *ui;
    SearchResultModel mModel;
    FeedbackDelegate mDelegate;
    std::shared_ptr<SearchResult> mResult;
    Algorithm* mAlgorithm;
    bool mUseSimpleProgressBar;
};

#endif // RESULTSPAGEWIDGET_H
