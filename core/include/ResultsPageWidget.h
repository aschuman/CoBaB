#ifndef RESULTSPAGEWIDGET_H
#define RESULTSPAGEWIDGET_H

#include <memory>
#include "PageWidget.h"
#include "SearchResultModel.h"
#include "FeedbackDelegate.h"

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
    explicit ResultsPageWidget();
    ~ResultsPageWidget();
    void reset() override;

private:
    Ui::ResultsPageWidget *ui;
    SearchResultModel mModel;
    FeedbackDelegate mDelegate;
    std::unique_ptr<SearchResult> mResult;
};

#endif // RESULTSPAGEWIDGET_H
