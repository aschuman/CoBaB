#ifndef VIEWERPAGEWIDGET_H
#define VIEWERPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"

namespace Ui {
class ViewerPageWidget;
}

class ViewerPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ViewerPageWidget();
    ~ViewerPageWidget();

    void reset() override;

    static const int EXIT_NEXT;

private:
    Ui::ViewerPageWidget *ui;
};

#endif // VIEWERPAGEWIDGET_H
