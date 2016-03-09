#ifndef RESULTSPAGEWIDGET_H
#define RESULTSPAGEWIDGET_H

#include <memory>
#include "PageWidget.h"
#include "SearchResultModel.h"
#include "FeedbackDelegate.h"
#include "Algorithm.h"

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

    static const int EXIT_NEW_SEARCH;

signals:
    void startAlgorithm(Algorithm* algo);

private slots:
    void on_btnNewSearch_clicked();

private:
    Ui::ResultsPageWidget *ui;
    SearchResultModel mModel;
    FeedbackDelegate mDelegate;
    std::shared_ptr<SearchResult> mResult;
};

#endif // RESULTSPAGEWIDGET_H
