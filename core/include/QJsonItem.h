#ifndef JSONITEM_H
#define JSONITEM_H
#include <QtCore>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

/**
 * @brief The class builds an QJsonTreeItem from a Jsonfile.
 * @author 3DMuVi-Team
 */
class QJsonTreeItem
{
public:
    explicit QJsonTreeItem(QJsonTreeItem * parent = 0);
    ~QJsonTreeItem();
    void appendChild(QJsonTreeItem * item);
    QJsonTreeItem *child(int row);
    QJsonTreeItem *parent();
    int childCount() const;
    int row() const;
    void setKey(const QString& key);
    void setValue(QString value);
    void setType(const QJsonValue::Type& type);
    QString key() const;
    QString value() const;
    QJsonValue::Type type() const;

    QList<QJsonTreeItem *> getChilds();
    /*!
     * \brief toJson converts a treeitem to a jsonobject
     * \return the treeitem as QJsonObject
     */
    QJsonObject toJson();

    static QJsonTreeItem* load(const QJsonValue& value, QJsonTreeItem * parent = 0);

protected:
    /*!
     * \brief toJsonValue converts the treeitem to a jsonvlaue
     * \return  the treeitem as QJsonValue
     */
    QJsonValue toJsonValue();

private:
    QString mKey;
    QString mValue;
    QJsonValue::Type mType;

    QList<QJsonTreeItem*> mChilds;
    QJsonTreeItem * mParent;


};

#endif // JSONITEM_H
