#include "include/PageRegistration.h"

PageRegistration::PageRegistration(std::unique_ptr<PageWidget> widget) : mWidget(move(widget))
{
}

void PageRegistration::addTransition(int exitCode, PageType type)
{
    mTransitions.insert(exitCode, type);
}

const PageWidget &PageRegistration::getWidget() const
{
    return *mWidget;
}

PageWidget &PageRegistration::getWidget()
{
    return *mWidget;
}

PageType PageRegistration::getTarget(int exitCode) const
{
    return mTransitions[exitCode];
}
