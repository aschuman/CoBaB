#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QAbstractListModel>
#include "Dataset.h"

class MediaModel : public QAbstractListModel
{
    Q_OBJECT
public:
    MediaModel();
    void setDataset(const Dataset& dataset);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    const Dataset* mDataset;
};

#endif // MEDIAMODEL_H
