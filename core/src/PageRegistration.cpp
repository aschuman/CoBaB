#include "PageRegistration.h"

/**
 * @brief Constructs a PageRegistration with the given PageWidget.
 * @param widget Registered widget.
 */
PageRegistration::PageRegistration(std::unique_ptr<PageWidget> widget) : mWidget(move(widget))
{
}

/**
 * @brief Move constructor.
 * @param p Old PageRegistration.
 */
PageRegistration::PageRegistration(PageRegistration&& p)
    : mWidget(move(p.mWidget)),
      mTransitions(move(p.mTransitions))
{
}

/**
 * @brief Move assignment constructor.
 * @param p Old PageRegistration
 * @return This PageRegistration after the assignment.
 */
PageRegistration& PageRegistration::operator=(PageRegistration&& p)
{
    mWidget = move(p.mWidget);
    mTransitions = move(p.mTransitions);
    return *this;
}

/**
 * @brief Adds a transitiont from the PageWidget.
 * @param exitCode Exit code to which this transition takes effect.
 * @param type Target Page
 * @param noReturn true if this transition can be returned from, false otherwise
 */
void PageRegistration::addTransition(int exitCode, PageType type, bool noReturn)
{
    mTransitions[exitCode].type = type;
    mTransitions[exitCode].noReturn = noReturn;
}

/**
 * @brief Returns the widget as const reference.
 * @return The widget.
 */
const PageWidget &PageRegistration::getWidget() const
{
    return *mWidget;
}

/**
 * @brief Returns the widget.
 * @return The widget.
 */
PageWidget &PageRegistration::getWidget()
{
    return *mWidget;
}

/**
 * @brief Returns the target the widget of this registration will transition to given the exit code.
 * @param exitCode The exit code.
 * @return target of the transition.
 */
PageRegistration::TransitionTarget PageRegistration::getTarget(int exitCode) const
{
    auto it = mTransitions.find(exitCode);
    return it != mTransitions.end() ? it->second : TransitionTarget();
}

/**
 * @brief Constructs a TransitionTarget with default type and allowed return.
 */
PageRegistration::TransitionTarget::TransitionTarget() : type(), noReturn(false)
{
}
