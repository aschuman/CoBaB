#include "include/pagewidgetmock.h"

void PageWidgetMock::reset()
{
}

void PageWidgetMock::emitPush(QVariant item)
{
    emit pushToStack(item);
}

void PageWidgetMock::emitRead(size_t index, QVariant &value)
{
    emit readFromStack(index, value);
}

void PageWidgetMock::emitExit(int exitCode)
{
    emit exit(exitCode);
}
