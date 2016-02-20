#include "MediaModel.h"

MediaModel::MediaModel()
    : QAbstractListModel(nullptr),
      mDataset(nullptr)
{
    Q_INIT_RESOURCE(application);
}

void MediaModel::setDataset(const Dataset& dataset)
{
    mDataset = &dataset;
    emit dataChanged(createIndex(0,0), createIndex(mDataset->getNumberOfMedia(), 0));
}

int MediaModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mDataset ? mDataset->getMediaList().size() : 0;
}

QVariant MediaModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch (role) {
    case Qt::DisplayRole:
        if(mDataset && index.row() < mDataset->getMediaList().size()) {
            QFileInfo file(mDataset->getMediaList().at(index.row())->getPath());
            result = file.baseName();
        }
        break;
    case Qt::DecorationRole:
        if(mDataset && index.row() < mDataset->getMediaList().size()) {
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
