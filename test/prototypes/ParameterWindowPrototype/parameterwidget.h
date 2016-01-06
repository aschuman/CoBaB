#ifndef PARAMETERWIDGET_H
#define PARAMETERWIDGET_H

#include <QWidget>

namespace Ui {
class ParameterWidget;
}

class ParameterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterWidget(QWidget *parent = 0);
    ~ParameterWidget();

private:
    Ui::ParameterWidget *ui;
};

#endif // PARAMETERWIDGET_H
