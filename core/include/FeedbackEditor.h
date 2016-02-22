#ifndef FEEDBACKEDITOR_H
#define FEEDBACKEDITOR_H

#include <QWidget>
#include "SearchFeedback.h"

/**
 * @brief Abstract base class for widgets that will be displayed to allow user-feedback to search results.
 * @author Vincent Winkler
 */
class FeedbackEditor : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a FeedbackEditor.
     * @param Parent of this widget.
     */
    FeedbackEditor(QWidget* parent = nullptr) : QWidget(parent){};

    /**
     * @brief Returns the user defined feedback.
     * @return The user defined feedback.
     */
    virtual int getFeedback() const = 0;

    /**
     * @brief Sets the feedback.
     * @param The feedback.
     */
    virtual void setFeedback(int feedback) = 0;

    /**
     * @brief Returns the FeedbackType this editor produces.
     * @return The FeedbackType.
     */
    virtual SearchFeedback::Type getFeedbackType() const = 0;
};

#endif // FEEDBACKEDITOR_H
