#ifndef PAGEREGISTRATION_H
#define PAGEREGISTRATION_H
#include <map>
#include <memory>
#include "PageType.h"
#include "PageWidget.h"


/**
 * @brief A PageRegistration holds a PageWidget and all transitions from it.
 */
class PageRegistration
{
public:
    PageRegistration(std::unique_ptr<PageWidget> widget);
    PageRegistration(PageRegistration&& p);
    PageRegistration& operator=(PageRegistration&& p);

    void addTransition(int exitCode, PageType type);
    const PageWidget& getWidget() const;
    PageWidget& getWidget();
    PageType getTarget(int exitCode) const;

private:
    std::unique_ptr<PageWidget> mWidget;
    std::map<int, PageType> mTransitions;
};

#endif // PAGEREGISTRATION_H
