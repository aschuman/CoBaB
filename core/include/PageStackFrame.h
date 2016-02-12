#ifndef PAGESTACKFRAME_H
#define PAGESTACKFRAME_H

#include <stddef.h>
#include "PageType.h"


/**
 * @brief Holds information on displayed PageWidgets.
 *
 * A PageStackFrame can be used by the Navigator to keep track of which
 * PageWidget has been displayed and how many items it has pushed to the data stack.
 */
class PageStackFrame
{
    size_t mSize;
    PageType mType;
public:
    PageStackFrame(PageType type);
    void setSize(size_t size);
    void incrementSize();
    size_t getSize() const;
    PageType getType() const;
};

#endif // PAGESTACKFRAME_H
