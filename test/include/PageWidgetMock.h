#ifndef PAGEWIDGETMOCK_H
#define PAGEWIDGETMOCK_H

#include "PageWidget.h"

class PageWidgetMock : public PageWidget
{
public:
    PageWidgetMock();
    virtual void reset() override;
    virtual void retranslateUi() override;
    virtual QString getName() override;
    void emitPush(QVariant item);
    void emitRead(int index, QVariant& value);
    void emitExit(int exitCode);
    void setReset(bool shown);
    bool isReset() const;

private:
    bool mReset;
};

#endif // PAGEWIDGETMOCK_H
