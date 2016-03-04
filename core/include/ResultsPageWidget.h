#ifndef RESULTSPAGEWIDGET_H
#define RESULTSPAGEWIDGET_H

#include <memory>
#include "PageWidget.h"
#include "SearchResultModel.h"
#include "FeedbackDelegate.h"
#include "Algorithm.h"

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

    void setResults(SearchResult result);

signals:
    void startAlgorithm(Algorithm* algo);

private:
    Ui::ResultsPageWidget *ui;
    SearchResultModel mModel;
    FeedbackDelegate mDelegate;
    SearchResult mResult;
};

#endif // RESULTSPAGEWIDGET_H
