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

/**
 * @brief The class displays the given parameters and enables the editing of chosen parameter values.
 * One may also select the datasets, in which the search will be done.
 * @author Violina, Georgi, Anja
 */
class ParameterPageWidget : public PageWidget
{
    Q_OBJECT

public:
    explicit ParameterPageWidget();
    ~ParameterPageWidget();

    void reset() override;
    void retranslateUi() override;
    QString getName() override;

    static const int EXIT_NEXT = 0;          ///< The number the widget exits with.

public slots:
    void nextButtonClicked();

private:
    Ui::ParameterPageWidget *ui;            ///< The ui for the ParameterPageWidget
    DatasetList* mSearchDatasetList;        ///< The list of datasets to display in the ParameterPageWidget
    DatasetModel mModel;                    ///< The model for the datasets
    QJsonModel* mParameterModel;            ///< The model for the parameters
    QVector<QJsonObject> parameterList;     ///< The list with the parameters to be displayed in the QTreeView
};

#include <memory>
Q_DECLARE_METATYPE(std::shared_ptr<QModelIndexList>)
Q_DECLARE_METATYPE(std::shared_ptr<QJsonObject>)

#endif // PARAMETERPAGEWIDGET_H
