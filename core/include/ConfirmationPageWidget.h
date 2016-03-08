#ifndef CONFIRMATIONPAGEWIDGET_H
#define CONFIRMATIONPAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include "PageWidget.h"

namespace Ui {
class ConfirmationPageWidget;
}

class ConfirmationPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ConfirmationPageWidget();
    ~ConfirmationPageWidget();
    void reset() override;
    void retranslateUi() override;
    void showEvent(QShowEvent* event);
    //void resizeEvent(QResizeEvent* event);

    static const int EXIT_NEXT;

private slots:
    void on_mSearchButton_clicked();


private:
    Ui::ConfirmationPageWidget *ui;
    QPixmap pixmap;
    void clearTable();

};



#endif // CONFIRMATIONPAGEWIDGET_H
