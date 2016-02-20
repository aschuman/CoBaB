#ifndef PARAMETERPAGEWIDGET_H
#define PARAMETERPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"

namespace Ui {
class ParameterPageWidget;
}

class ParameterPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ParameterPageWidget();
    ~ParameterPageWidget();

    void reset() override;

    static const int EXIT_NEXT;

public slots:
    void nextButtonClicked();

private:
    Ui::ParameterPageWidget *ui;
};

#endif // PARAMETERPAGEWIDGET_H
