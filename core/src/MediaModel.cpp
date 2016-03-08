#include "MediaModel.h"

/**
 * @brief MediaModel::MediaModel Constructs a MediaModel.
 */
MediaModel::MediaModel()
    : QAbstractListModel(nullptr),
      mDataset(nullptr)
{
    Q_INIT_RESOURCE(application);
}

/**
 * @brief MediaModel::setDataset Sets the dataset.
 * @param dataset
 */
void MediaModel::setDataset(const Dataset& dataset)
{
    mDataset = &dataset;
    emit layoutChanged();
    emit dataChanged(createIndex(0,0), createIndex(mDataset->getNumberOfMedia(), 0));
}

/**
 * @brief MediaModel::rowCount Returns the number of rows.
 * @param parent unused
 * @return The number of rows.
 */
int MediaModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mDataset ? mDataset->getNumberOfMedia() : 0;
}

/**
 * @brief MediaModel::data Returns the data stored under the given role for the item referred to by the index.
 * @param index
 * @param role
 * @return
 */
QVariant MediaModel::data(const QModelIndex &index, int role) const
{  
    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
        if(mDataset && index.row() < mDataset->getNumberOfMedia()) {
            QFileInfo file(mDataset->getMediaList().at(index.row())->getPath());
            result = file.baseName();
        }
        break;
    case Qt::DecorationRole:
        if(mDataset && index.row() < mDataset->getNumberOfMedia()) {
            Medium* medium = mDataset->getMediaList().at(index.row());
            switch(mDataset->getType()) {
                case Dataset::Type::PHOTO:
                    result = QImage(medium->getPath()).scaled(100, 100, Qt::KeepAspectRatio);
                    break;
                case Dataset::Type::VIDEO:
                    result = QImage(":/videoIcon.png").scaled(100, 100, Qt::KeepAspectRatio);
                    break;
                case Dataset::Type::SINGLE_FRAME_VIDEO:
                    result = QImage(medium->getPath() + "/" + ((SingleFrameVideo*)medium)->getFrameList().first()).scaled(100, 100, Qt::KeepAspectRatio);
                    break;
                default:
                    break;
            }
        }
        break;
    default:
        break;
    }
    return result;
}
