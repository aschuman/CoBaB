#include "PageStackFrame.h"

/**
 * @brief Constructs a PageStackFrame with a number of 0 data stack items.
 * @param type The PageType of the PageWidget this PageStackFrame holds information on.
 */
PageStackFrame::PageStackFrame(PageType type) : mSize(0), mType(type), mNoReturn(false){
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
 * @brief Sets whether or not a return from the page represented by this stack frame is allowed.
 *
 * Return by default allowed.
 * @param noReturn true if a return from this page is disallowed, false otherwise.
 */
void PageStackFrame::setNoReturn(bool noReturn)
{
    mNoReturn = noReturn;
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

/**
 * @brief Returns whether or not a return from the page represented by this stack frame is allowed.
 * @return true if a return is not allowd, false otherwise.
 */
bool PageStackFrame::getNoReturn() const
{
    return mNoReturn;
}

