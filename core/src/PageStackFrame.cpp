#include "include/PageStackFrame.h"

PageStackFrame::PageStackFrame(PageType type) : mSize(0), mType(type){
}

void PageStackFrame::setSize(size_t size)
{
    mSize = size;
}

size_t PageStackFrame::getSize() const
{
    return mSize;
}

PageType PageStackFrame::getType() const
{
    return mType;
}

