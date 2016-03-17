#ifndef PAGEREGISTRATION_H
#define PAGEREGISTRATION_H
#include <map>
#include <memory>
#include "PageType.h"
#include "PageWidget.h"


/**
 * @brief A PageRegistration holds a PageWidget and all transitions from it.
 * @author Vincent Winkler
 */
class PageRegistration
{
public:
    /**
     * @brief Denotes the target of a transition.
     */
    struct TransitionTarget{
        TransitionTarget();
        PageType type; ///< PageType of the target
        bool noReturn; ///< true if this transition can not be returned from, false otherwise
    };

    explicit PageRegistration(std::unique_ptr<PageWidget> widget);
    PageRegistration(PageRegistration&& p);
    PageRegistration& operator=(PageRegistration&& p);

    void addTransition(int exitCode, PageType type, bool noReturn = false);
    const PageWidget& getWidget() const;
    PageWidget& getWidget();
    TransitionTarget getTarget(int exitCode) const;

private:
    std::unique_ptr<PageWidget> mWidget;
    std::map<int, TransitionTarget> mTransitions;
};

#endif // PAGEREGISTRATION_H
