#ifndef LIBRARYPAGEWIDGET_H
#define LIBRARYPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"
#include "DatasetList.h"
#include "DatasetModel.h"

namespace Ui {
class LibraryPageWidget;
}

/**
 * @brief Displays a library.
 * @author Vincent Winkler
 */
class LibraryPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit LibraryPageWidget();
    ~LibraryPageWidget();
    void reset() override;
    void retranslateUi() override;

    static const int EXIT_NEXT;

private slots:
    void on_mLibraryListView_doubleClicked(const QModelIndex &index);

private:
    Ui::LibraryPageWidget *ui;
    DatasetList* mDatasetList;
    DatasetModel mModel;
};

#endif // LIBRARYPAGEWIDGET_H
