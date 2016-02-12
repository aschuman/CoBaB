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
 */
void PageRegistration::addTransition(int exitCode, PageType type)
{
    mTransitions[exitCode] = type;
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
 * @return PageType of the target page.
 */
PageType PageRegistration::getTarget(int exitCode) const
{
    auto it = mTransitions.find(exitCode);
    return it != mTransitions.end() ? it->second : PageType();
}
