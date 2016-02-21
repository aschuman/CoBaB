#ifndef QJSONMODEL_H
#define QJSONMODEL_H

#include <QAbstractItemModel>
#include "QJsonItem.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QIcon>

#include <QUrl>
#include <QVector>
#include <QPair>

/**
 * From 3DMuVi
 * @brief The QJsonModel class
 */
class QJsonModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    /*!
      * \brief QJsonModel constructs a new qjsonmodel
      * \param parent parent of the model
      * \param list vector with all the QJsonObject for the model
      */
     explicit QJsonModel(QObject *parent = 0, QVector<QJsonObject> list = QVector<QJsonObject>());
     /*!
      * \brief saveSettings saves an Algorithmsetting as Jsonfile
      * \param row which setting will be saved
      * \param filename url for the file
      */
     void saveSettings(int row, QUrl filename);
     /*!
      * \brief loadSettings loads an algorithmsettingform a Jsonfile
      * \param row where the new setting should go, delets the old ons
      * \param filename url for the file
      */
     void loadSettings(int row, QUrl filename);

     Qt::ItemFlags flags(QModelIndex& index);
     bool setData(QModelIndex& index, QVariant& value, int role);

    bool load(const QString& fileName);
    bool load(QIODevice * device);
    bool loadJson(const QByteArray& json);
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    void setIcon(const QJsonValue::Type& type, const QIcon& icon);

public slots:
    /*!
     * \brief loadQJson loads a qjsonobject into the model
     * \param data the QJsonObject
     */
    void loadQJson(QJsonObject data);
signals:
    void requestQJson(QUrl directory);
    void saveQJson(QJsonObject data, QUrl directory);

protected:
    QJsonTreeItem backtrack(QModelIndex &index);

    QJsonTreeItem * mRootItem;
    QJsonDocument mDocument;
    QStringList mHeaders;
    QHash<QJsonValue::Type, QIcon> mTypeIcons;


};

#endif // QJSONMODEL_H