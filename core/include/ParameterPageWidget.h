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
    QString getName() override;

    static const int EXIT_NEXT = 0;

public slots:
    void nextButtonClicked();

private slots:
    //void on_mSearchDatasetListView_indexesMoved(const QModelIndexList &indexes);

    void on_mParameterWidget_clicked(const QModelIndex &index);

private:
    Ui::ParameterPageWidget *ui;
    DatasetList* mSearchDatasetList;
    DatasetModel mModel;
    QJsonModel* mParameterModel;
    QVector<QJsonObject> parameterList;
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<QModelIndexList>)

#endif // PARAMETERPAGEWIDGET_H
