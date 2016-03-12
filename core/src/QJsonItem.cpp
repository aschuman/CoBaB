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

QJsonTreeItem::QJsonTreeItem(QJsonTreeItem *parent)
{

    mParent = parent;


}

QJsonTreeItem::~QJsonTreeItem()
{
    qDeleteAll(mChilds);

}
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


void QJsonTreeItem::appendChild(QJsonTreeItem *item)
{
    mChilds.append(item);
}

QJsonTreeItem *QJsonTreeItem::child(int row)
{
    return mChilds.value(row);
}

QJsonTreeItem *QJsonTreeItem::parent()
{
    return mParent;
}

int QJsonTreeItem::childCount() const
{
    return mChilds.count();
}

int QJsonTreeItem::row() const
{
    if (mParent)
        return mParent->mChilds.indexOf(const_cast<QJsonTreeItem*>(this));

    return 0;
}

void QJsonTreeItem::setKey(const QString &key)
{
    mKey = key;
}

void QJsonTreeItem::setValue(QString value)
{
    mValue = value;
}

void QJsonTreeItem::setType(const QJsonValue::Type &type)
{
    mType = type;
}

QString QJsonTreeItem::key() const
{
    return mKey;
}

QString QJsonTreeItem::value() const
{
    return mValue;
}

QJsonValue::Type QJsonTreeItem::type() const
{
    return mType;
}

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

