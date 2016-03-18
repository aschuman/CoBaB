/***********************************************
    Copyright (C) 2014  Schutz Sacha
    This file is part of QJsonModel (https://github.com/dridk/QJsonmodel).

    QJsonModel is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QJsonModel is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QJsonModel.  If not, see <http://www.gnu.org/licenses/>.

**********************************************/

#include "QJsonModel.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QIcon>
#include <QFont>

QJsonModel::QJsonModel(QObject *parent, QVector<QJsonObject> list) :
    QAbstractItemModel(parent)
{
    mRootItem = new QJsonTreeItem;
    mHeaders.append(tr("Parameter"));
    mHeaders.append(tr("Wert"));
    for (int i = 0; i < list.size(); i++) {
        loadQJson(list.value(i));
    }

}

/**
 * @brief QJsonModel::getParameters Returns the parameters of the json model.
 * @return The parameters of the json model.
 */
QJsonObject QJsonModel::getParameters() {
    return mRootItem->getChilds().value(0)->toJson();
}

/**
 * @brief QJsonModel::flags Returns the item flags for the given index.
 * @param index The model index.
 * @return The item flags for the given index.
 */
Qt::ItemFlags QJsonModel::flags(const QModelIndex& index) const
{
  if(index.column() == 1)
  {
      QJsonTreeItem* temp = static_cast<QJsonTreeItem*>(index.internalPointer());
      if (temp->type() != QJsonValue::Array && temp->type() != QJsonValue::Object) {
          return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
      }
  }
  return QAbstractItemModel::flags(index);
}

/**
 * @brief QJsonModel::setData Sets the role data for the item at index to value.
 * @param index The model index.
 * @param value The value.
 * @param role The role.
 * @return true if successful; otherwise returns false.
 */
bool QJsonModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid())
        return false;
    if (role == Qt::EditRole) {
        QJsonTreeItem* temp = static_cast<QJsonTreeItem*>(index.internalPointer());
        temp->setValue(value.toString());
        return true;
    }
    return false;
}

/**
 * @brief QJsonModel::backtrack Returns the parent of the index.
 * @param index The model index.
 * @return The parent of the index.
 */
QJsonTreeItem* QJsonModel::backtrack(QModelIndex& index)
{
    if (index.parent().isValid() == false) //one row under root
        {
            return mRootItem->getChilds().at(index.row());
        }
        else {
            QModelIndex tempindex = index.parent();
            QModelIndex& parent = tempindex;
            QJsonTreeItem* temp = backtrack(parent);
            return temp;
        }
}

/**
 * @brief QJsonModel::loadQJson Loads the QJsonObject into the model by calling loadJson.
 * @param data The QJsonObject.
 */
void QJsonModel::loadQJson(QJsonObject data)
{
    QJsonDocument docu = QJsonDocument(data);
    loadJson(docu.toJson());
}

/**
 * @brief QJsonModel::load Checks whether the file can be opened.
 * @param fileName The path to the json file.
 * @return true if the file can be opened.
 */
bool QJsonModel::load(const QString &fileName)
{
    QFile file(fileName);
    bool success = false;
    if (file.open(QIODevice::ReadOnly)) {
        success = load(&file);
        file.close();
    }
    else success = false;

    return success;
}

/**
 * @brief QJsonModel::load Loads the json device into the model by calling loadJson.
 * @param device The io device.
 * @return true if loadJson was successful
 */
bool QJsonModel::load(QIODevice *device)
{
    return loadJson(device->readAll());
}

/**
 * @brief QJsonModel::loadJson Loads the json bytearray into the model.
 * @param json The bytearray.
 * @return true if the corresponding document is not empty
 */
bool QJsonModel::loadJson(const QByteArray &json)
{
    mDocument = QJsonDocument::fromJson(json);

    if (!mDocument.isNull())
    {

        if (mDocument.isArray()) {
            mRootItem->appendChild(QJsonTreeItem::load(QJsonValue(mDocument.array()), mRootItem));
        } else {
            mRootItem->appendChild(QJsonTreeItem::load(QJsonValue(mDocument.object()), mRootItem));
        }

        return true;
    }
    return false;
}

/**
 * @brief QJsonModel::data Returns the data stored under the given role for the item referred to by the index.
 * @param index The model index.
 * @param role The role.
 * @return The data stored under the given role for the item referred to by the index.
 */
QVariant QJsonModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();


    QJsonTreeItem *item = static_cast<QJsonTreeItem*>(index.internalPointer());


    if ((role == Qt::DecorationRole) && (index.column() == 0)){

        return mTypeIcons.value(item->type());
    }


    if (role == Qt::DisplayRole) {

        if (index.column() == 0)
            return QString("%1").arg(item->key());

        if (index.column() == 1)
            return QString("%1").arg(item->value());
    }



    return QVariant();

}

/**
 * @brief QJsonModel::headerData Returns the data for the given role and section in the header with the specified orientation.
 * @param section The section.
 * @param orientation The orientation.
 * @param role The role.
 * @return The data for the given role and section in the header with the specified orientation.
 */
QVariant QJsonModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {

        return mHeaders.value(section);
    }
    else
        return QVariant();
}

/**
 * @brief QJsonModel::index Returns the index of the item in the model specified by the given row, column and parent index.
 * @param row The row.
 * @param column The column.
 * @param parent The parent.
 * @return The index of the item in the model specified by the given row, column and parent index.
 */
QModelIndex QJsonModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    QJsonTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = mRootItem;
    else
        parentItem = static_cast<QJsonTreeItem*>(parent.internalPointer());

    QJsonTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

/**
 * @brief QJsonModel::parent Returns the parent of the model item with the given index.
 * @param index The model index.
 * @return The parent of the model item with the given index. If the item has no parent, an invalid QModelIndex is returned.
 */
QModelIndex QJsonModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    QJsonTreeItem *childItem = static_cast<QJsonTreeItem*>(index.internalPointer());
    QJsonTreeItem *parentItem = childItem->parent();

    if (parentItem == mRootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

/**
 * @brief QJsonModel::rowCount Returns the number of rows under the given parent.
 * @param parent The parent.
 * @return The number of rows under the given parent. When the parent is valid it means that rowCount is returning the number of children of parent.
 */
int QJsonModel::rowCount(const QModelIndex &parent) const
{
    QJsonTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = mRootItem;
    else
        parentItem = static_cast<QJsonTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

/**
 * @brief QJsonModel::columnCount Returns the number of columns under the given parent.
 * @param parent The parent.
 * @return 2
 */
int QJsonModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

/**
 * @brief QJsonModel::setIcon Inserts an icon into the mapping.
 * @param type the type to which this icon belongs
 * @param icon the icon
 */
void QJsonModel::setIcon(const QJsonValue::Type &type, const QIcon &icon)
{
    mTypeIcons.insert(type,icon);
}
