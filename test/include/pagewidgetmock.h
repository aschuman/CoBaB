#ifndef PAGEWIDGETMOCK_H
#define PAGEWIDGETMOCK_H
#include <pagewidget.h>


class PageWidgetMock : public PageWidget
{
public:
    virtual void reset();
    void emitPush(QVariant item);
    void emitRead(size_t index, QVariant& value);
    void emitExit(int exitCode);
};

#endif // PAGEWIDGETMOCK_H
