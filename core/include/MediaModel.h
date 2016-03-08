#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QAbstractListModel>
#include "Dataset.h"

/**
 * @brief The MediaModel class is a QAbstractListModel that can expose a list of media to a ListView.
 */
class MediaModel : public QAbstractListModel
{
    Q_OBJECT
public:
    MediaModel();
    void setDataset(const Dataset& dataset);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    const Dataset* mDataset; ///< The Dataset whose content is shown in the ListView.
};

#endif // MEDIAMODEL_H
