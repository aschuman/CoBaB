#ifndef LIBRARYPAGEWIDGET_H
#define LIBRARYPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"

namespace Ui {
class LibraryPageWidget;
}

class LibraryPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit LibraryPageWidget();
    ~LibraryPageWidget();
    void reset() override;

    static const int EXIT_NEXT;

private slots:
    void on_pushButton_clicked();

private:
    Ui::LibraryPageWidget *ui;
};

#endif // LIBRARYPAGEWIDGET_H
