#include "include/PageWidgetMock.h"

PageWidgetMock::PageWidgetMock() : mReset(false)
{
}

void PageWidgetMock::reset()
{
    mReset = true;
}

void PageWidgetMock::emitPush(QVariant item)
{
    emit pushToStack(item);
}

void PageWidgetMock::emitRead(int index, QVariant &value)
{
    emit readFromStack(index, value);
}

void PageWidgetMock::emitExit(int exitCode)
{
    emit exit(exitCode);
}

void PageWidgetMock::setReset(bool reset)
{
    mReset = reset;
}

bool PageWidgetMock::isReset() const
{
    return mReset;
}

void PageWidgetMock::retranslateUi()
{

}
