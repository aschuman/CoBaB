#include "include/pageregistration.h"

PageRegistration::PageRegistration(std::unique_ptr<PageWidget> widget) : widget(move(widget))
{
}

void PageRegistration::addTransition(int exitCode, PageType type)
{
    transitions.insert(exitCode, type);
}

const PageWidget &PageRegistration::getWidget() const
{
    return *widget;
}

PageWidget &PageRegistration::getWidget()
{
    return *widget;
}

PageType PageRegistration::getTarget(int exitCode) const
{
    return transitions[exitCode];
}
