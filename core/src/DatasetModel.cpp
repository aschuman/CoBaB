#include "DatasetModel.h"

/**
 * @brief Constructs a DatasetModel.
 */
DatasetModel::DatasetModel()
    : QAbstractListModel(nullptr),
      mDatasets(nullptr)
{
}

/**
 * @brief Sets the list of datasets.
 * @param datasets The list of datasets.
 */
void DatasetModel::setDatasetList(const QList<Dataset>& datasets)
{
    mDatasets = &datasets;
    emit layoutChanged();
    emit dataChanged(createIndex(0,0), createIndex(datasets.size(), 0));
}

/**
 * @brief DatasetModel::rowCount Returns the number of rows.
 * @param parent The model index.
 * @return The number of rows under the given parent.
 */
int DatasetModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mDatasets ? mDatasets->size() : 0;
}

/**
 * @brief DatasetModel::data Returns the data.
 * @param index The model index.
 * @param role The role.
 * @return The data stored under the given role for the item referred to by the index.
 */
QVariant DatasetModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
        if(mDatasets && index.row() < mDatasets->size())
            result = mDatasets->at(index.row()).getName();
        break;
    case Qt::DecorationRole:
        if(mDatasets && index.row() < mDatasets->size())
            result = mDatasets->at(index.row()).getPreviewPhoto();
        break;
    default:
        break;
    }
    return result;
}
