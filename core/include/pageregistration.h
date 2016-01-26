#ifndef PAGEREGISTRATION_H
#define PAGEREGISTRATION_H
#include <QMap>
#include <memory>
#include <pagetype.h>
#include <pagewidget.h>


class PageRegistration
{
    std::unique_ptr<PageWidget> widget;
    QMap<int, PageType> transitions;

public:
    PageRegistration(std::unique_ptr<PageWidget> widget);
    void addTransition(int exitCode, PageType type);
    const PageWidget& getWidget() const;
    PageType getTarget(int exitCode) const;
};

#endif // PAGEREGISTRATION_H
