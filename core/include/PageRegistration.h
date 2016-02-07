#ifndef PAGEREGISTRATION_H
#define PAGEREGISTRATION_H
#include <QMap>
#include <memory>
#include "PageType.h"
#include "PageWidget.h"


class PageRegistration
{
    std::unique_ptr<PageWidget> mWidget;
    QMap<int, PageType> mTransitions;

public:
    PageRegistration(std::unique_ptr<PageWidget> widget);
    void addTransition(int exitCode, PageType type);
    const PageWidget& getWidget() const;
    PageWidget& getWidget();
    PageType getTarget(int exitCode) const;
};

#endif // PAGEREGISTRATION_H
