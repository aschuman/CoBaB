#include "include/DualFeedbackEditor.h"

#include <QMouseEvent>

/**
 * @brief Constructs a DualFeedbackEditor with the given parent.
 * @param Parent of this widget.
 */
DualFeedbackEditor::DualFeedbackEditor(QWidget *parent) : FeedbackEditor(parent)
{
}

/**
 * @brief Returns the recommended size for this widget.
 * @return The recommended size for this widget.
 */
QSize DualFeedbackEditor::sizeHint() const
{
    return QSize(100, 100);
}

void DualFeedbackEditor::setFeedback(int feedback)
{
    mFeedback = feedback;
}

int DualFeedbackEditor::getFeedback() const
{
    return mFeedback;
}

/**
 * @brief Returns SearchFeedback::DUAL.
 * @return SearchFeedback::DUAL.
 */
SearchFeedback::Type DualFeedbackEditor::getFeedbackType() const
{
    return SearchFeedback::Type::DUAL;
}

void DualFeedbackEditor::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton){
        mFeedback = (mFeedback + 2) % 3 - 1;
        emit feedbackChanged();
        update();
    }
}

