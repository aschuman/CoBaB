#include "include/PageStackFrame.h"

PageStackFrame::PageStackFrame(PageType type) : size(0), type(type){
}

void PageStackFrame::setSize(size_t size)
{
    this->size = size;
}

size_t PageStackFrame::getSize() const
{
    return size;
}

PageType PageStackFrame::getType() const
{
    return type;
}

