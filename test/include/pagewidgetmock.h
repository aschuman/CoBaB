#ifndef PAGEWIDGETMOCK_H
#define PAGEWIDGETMOCK_H
#include <pagewidget.h>


class PageWidgetMock : public PageWidget
{
public:
    PageWidgetMock();
    virtual void reset();
    void emitPush(QVariant item);
    void emitRead(size_t index, QVariant& value);
    void emitExit(int exitCode);
    void setReset(bool shown);
    bool isReset() const;

private:
    bool mReset;
};

#endif // PAGEWIDGETMOCK_H
