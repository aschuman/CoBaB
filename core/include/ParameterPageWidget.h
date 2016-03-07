#ifndef PARAMETERPAGEWIDGET_H
#define PARAMETERPAGEWIDGET_H

#include <QWidget>
#include "PageWidget.h"
#include "DatasetList.h"
#include "DatasetModel.h"
#include "QJsonModel.h"

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
    void retranslateUi() override;

    static const int EXIT_NEXT;

public slots:
    void nextButtonClicked();

private slots:
    void on_mSearchDatasetListView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::ParameterPageWidget *ui;
    DatasetList* mSearchDatasetList;
    DatasetModel mModel;
    QJsonModel mParameterModel;
    QVector<QJsonObject> parameterList;
};

#endif // PARAMETERPAGEWIDGET_H
