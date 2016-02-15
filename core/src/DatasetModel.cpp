#include "include/DatasetModel.h"

DatasetModel::DatasetModel() : mDatasets(nullptr)
{
}

void DatasetModel::setDatasetList(const QList<Dataset>& datasets)
{
    mDatasets = &datasets;
    emit dataChanged(createIndex(0,0), createIndex(datasets.size(), 0));
}

int DatasetModel::rowCount(const QModelIndex &parent) const
{
    return mDatasets ? mDatasets->size() : 0;
}

int DatasetModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant DatasetModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
        if(mDatasets && index.row() < mDatasets->size())
            result = mDatasets->at(index.row()).getName();
        break;
    default:
        break;
    }
    return result;
}
