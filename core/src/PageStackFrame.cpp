#include "PageStackFrame.h"

/**
 * @brief Constructs a PageStackFrame with a number of 0 data stack items.
 * @param type The PageType of the PageWidget this PageStackFrame holds information on.
 */
PageStackFrame::PageStackFrame(PageType type) : mSize(0), mType(type){
}

/**
 * @brief Sets the number of items the widget of this PageStackFrame has pushed.
 * @param size The number of pushed items.
 */
void PageStackFrame::setSize(size_t size)
{
    mSize = size;
}

/**
 * @brief Increases the number of items the widget of this PageStackFrame has pushed by one.
 */
void PageStackFrame::incrementSize()
{
    setSize(getSize() + 1);
}

/**
 * @brief Returns the number of items the widget of this PageStackFrame has pushed.
 * @return The number of pushed items.
 */
size_t PageStackFrame::getSize() const
{
    return mSize;
}

/**
 * @brief Returns the PageType of ths widget of this PageStackFrame.
 * @return The PageType of the widget.
 */
PageType PageStackFrame::getType() const
{
    return mType;
}

