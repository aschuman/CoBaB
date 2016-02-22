#ifndef CLICKABLEGRAPHICSPIXMAPITEM_H
#define CLICKABLEGRAPHICSPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class ClickableGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ClickableGraphicsPixmapItem(const QPixmap& pixmap);
signals:
    void selected(const QPointF&);
public slots:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
};

#endif // CLICKABLEGRAPHICSPIXMAPITEM_H
