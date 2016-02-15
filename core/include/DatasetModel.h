#ifndef DATASETMODEL_H
#define DATASETMODEL_H

#include <QList>
#include <QAbstractListModel>
#include "Dataset.h"

class DatasetModel : public QAbstractListModel
{
    Q_OBJECT
public:
    DatasetModel();
    void setDatasetList(const QList<Dataset>& datasets);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    const QList<Dataset>* mDatasets;
};

#endif // DATASETMODEL_H
