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

#include "QJsonItem.h"

/**
 * @brief QJsonTreeItem::QJsonTreeItem Creates a new QJsonTreeItem with the given parent.
 * @param parent The parent of this QJsonTreeItem.
 */
QJsonTreeItem::QJsonTreeItem(QJsonTreeItem *parent)
{

    mParent = parent;


}

QJsonTreeItem::~QJsonTreeItem()
{
    qDeleteAll(mChilds);

}

/**
 * @brief QJsonTreeItem::getChilds Returns the childs of this QJsonTreeItem
 * @return The list of childs.
 */
QList<QJsonTreeItem*> QJsonTreeItem::getChilds()
{
    return mChilds;
}

QJsonObject QJsonTreeItem::toJson() {
    QJsonObject object;
    object.insert(mKey, this->toJsonValue());
    return object;
}

QJsonValue QJsonTreeItem::toJsonValue() {
    QJsonValue value;
    switch (mType)
    {
    case QJsonValue::String:
    {
        value = QJsonValue(mValue);
        break;
    }
    case QJsonValue::Double:
    {
        value = QJsonValue(mValue.toDouble());
        break;
    }
    case QJsonValue::Bool:
    {
        bool boolvalue = false;
        if (mValue == "true") {
            boolvalue = true;
        }
        value = QJsonValue(boolvalue);
        break;
    }
    case QJsonValue::Object:
    {
        QJsonObject object;
        for (int i = 0; i < mChilds.size(); i++) {
            object.insert(mChilds.value(i)->key(), mChilds.value(i)->toJsonValue());
        }
        value = object;
        break;
    }
    case QJsonValue::Array:
    {
        QJsonArray array;
        for (int i = 0; i < mChilds.size(); i++) {
            array.append(mChilds.value(i)->toJsonValue());
        }
        break;
    }
    default:
        break;
    }
    return value;
}

/**
 * @brief QJsonTreeItem::appendChild Adds a child item to the QJsonTreeItem.
 * @param item The new child.
 */
void QJsonTreeItem::appendChild(QJsonTreeItem *item)
{
    mChilds.append(item);
}

/**
 * @brief QJsonTreeItem::child Returns the value of the childs at the given row.
 * @param row The row of the childs.
 * @return The value of the childs at the given row.
 */
QJsonTreeItem *QJsonTreeItem::child(int row)
{
    return mChilds.value(row);
}

/**
 * @brief QJsonTreeItem::parent Returns the parent of this QJsonTreeItem.
 * @return The parent of this QJsonTreeItem.
 */
QJsonTreeItem *QJsonTreeItem::parent()
{
    return mParent;
}

/**
 * @brief QJsonTreeItem::childCount Returns the number of childs.
 * @return The number of childs.
 */
int QJsonTreeItem::childCount() const
{
    return mChilds.count();
}

/**
 * @brief QJsonTreeItem::row Returns the row of this QJsonTreeItem.
 * @return The row.
 */
int QJsonTreeItem::row() const
{
    if (mParent)
        return mParent->mChilds.indexOf(const_cast<QJsonTreeItem*>(this));

    return 0;
}

/**
 * @brief QJsonTreeItem::setKey Sets the key for this QJsonTreeItem.
 * @param key The key for this QJsonTreeItem.
 */
void QJsonTreeItem::setKey(const QString &key)
{
    mKey = key;
}

/**
 * @brief QJsonTreeItem::setValue Sets the value for this QJsonTreeItem.
 * @param value The value for this QJsonTreeItem.
 */
void QJsonTreeItem::setValue(QString value)
{
    mValue = value;
}

/**
 * @brief QJsonTreeItem::setType Sets the type of this QJsonTreeItem.
 * @param type The type of this QJsonTreeItem.
 */
void QJsonTreeItem::setType(const QJsonValue::Type &type)
{
    mType = type;
}

/**
 * @brief QJsonTreeItem::key Returns the key.
 * @return The key.
 */
QString QJsonTreeItem::key() const
{
    return mKey;
}

/**
 * @brief QJsonTreeItem::value Returns the value.
 * @return The value.
 */
QString QJsonTreeItem::value() const
{
    return mValue;
}

/**
 * @brief QJsonTreeItem::type Returns the type.
 * @return The type.
 */
QJsonValue::Type QJsonTreeItem::type() const
{
    return mType;
}

/**
 * @brief QJsonTreeItem::load Loads the QJsonTree with all children.
 * @param value The value of the parent.
 * @param parent The parent of the tree item.
 * @return The root item.
 */
QJsonTreeItem* QJsonTreeItem::load(const QJsonValue& value, QJsonTreeItem* parent)
{


    QJsonTreeItem * rootItem = new QJsonTreeItem(parent);
    rootItem->setKey("root");
    rootItem->setType(value.type());

    if ( value.isObject())
    {

        //Get all QJsonValue childs
        foreach (QString key , value.toObject().keys()){
            QJsonValue v = value.toObject().value(key);
            QJsonTreeItem * child = load(v,rootItem);
            child->setKey(key);
            child->setType(v.type());
            rootItem->appendChild(child);

        }

    }

    else if ( value.isArray())
    {
        //Get all QJsonValue childs
        int index = 0;
        foreach (QJsonValue v , value.toArray()){

            QJsonTreeItem * child = load(v,rootItem);
            child->setKey(QString::number(index));
            child->setType(v.type());
            rootItem->appendChild(child);
            ++index;
        }
    }
    else
    {
        rootItem->setValue(value.toVariant().toString());
        rootItem->setType(value.type());
    }

    return rootItem;
}

