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
    QString getName() override;

    static const int EXIT_PHOTO = 0;                    ///< indicates that the chosen dataset is a photo dataset
    static const int EXIT_SINGLE_FRAME_VIDEO = 1;       ///< indicates that the chosen dataset is a single frame video dataset
    static const int EXIT_VIDEO = 2;                    ///< indicates that the chosen dataset is a video dataset

public slots:
    void showFileDialog();

private slots:
    void on_mLibraryListView_doubleClicked(const QModelIndex &index);

private:
    Ui::LibraryPageWidget *ui;
    DatasetList* mDatasetList;
    DatasetModel mModel;
};

#endif // LIBRARYPAGEWIDGET_H
