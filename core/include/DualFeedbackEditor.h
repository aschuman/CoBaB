#ifndef DUALFEEDBACKEDITOR_H
#define DUALFEEDBACKEDITOR_H

#include "FeedbackEditor.h"
#include "SearchResultElementFeedback.h"

/**
 * @brief Editor for dual type feedback.
 * @author Vincent Winkler
 */
class DualFeedbackEditor : public FeedbackEditor
{
    Q_OBJECT
public:
    explicit DualFeedbackEditor(QWidget* parent = nullptr);
    QSize sizeHint() const override;
    void setFeedback(int feedback) override;
    int getFeedback() const override;
    SearchFeedback::Type getFeedbackType() const override;

signals:
    void feedbackChanged();

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    int mFeedback;
};

#endif // DUALFEEDBACKEDITOR_H
