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

/**
 * @brief The ConfirmationPageWidget class displays the current selection.
 *
 * The chosen photo/annotation/region of interest, the chosen datasets,
 * the chosen algorithm, and the values of the parameters are displayed.
 *
 * @author Marie
 */
class ConfirmationPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ConfirmationPageWidget();
    ~ConfirmationPageWidget();
    void reset() override;
    void retranslateUi() override;
    QString getName() override;
    void showEvent(QShowEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

    static const int EXIT_NEXT;

private slots:
    void on_mSearchButton_clicked();

private:
    Ui::ConfirmationPageWidget *ui;
    QPixmap pixmap;                     ///< This pixmap contains the chosen area of the Medium of the SearchObject.
    QStringList mParameterList;
    void clearTable();
    void readParameters(QJsonObject object);


};



#endif // CONFIRMATIONPAGEWIDGET_H
