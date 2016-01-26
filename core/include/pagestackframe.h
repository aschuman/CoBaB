#ifndef PAGESTACKFRAME_H
#define PAGESTACKFRAME_H

#include <stddef.h>
#include <pagetype.h>


class PageStackFrame
{
    size_t size;
    PageType type;
public:
    PageStackFrame(PageType type);
    void setSize(size_t size);
    size_t getSize() const;
    PageType getType();
};

#endif // PAGESTACKFRAME_H
