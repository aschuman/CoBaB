#include "PageRegistration.h"

PageRegistration::PageRegistration(std::unique_ptr<PageWidget> widget) : mWidget(move(widget))
{
}

PageRegistration::PageRegistration(PageRegistration&& p)
    : mWidget(move(p.mWidget)),
      mTransitions(move(p.mTransitions))
{
}

PageRegistration& PageRegistration::operator=(PageRegistration&& p)
{
    mWidget = move(p.mWidget);
    mTransitions = move(p.mTransitions);
    return *this;
}

void PageRegistration::addTransition(int exitCode, PageType type)
{
    mTransitions[exitCode] = type;
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
    auto it = mTransitions.find(exitCode);
    return it != mTransitions.end() ? it->second : PageType();
}
