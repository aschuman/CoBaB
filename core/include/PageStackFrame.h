#ifndef PAGESTACKFRAME_H
#define PAGESTACKFRAME_H

#include <stddef.h>
#include "PageType.h"


class PageStackFrame
{
    size_t mSize;
    PageType mType;
public:
    PageStackFrame(PageType type);
    void setSize(size_t size);
    size_t getSize() const;
    PageType getType() const;
};

#endif // PAGESTACKFRAME_H
