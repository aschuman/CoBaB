#include "ClickableGraphicsPixmapItem.h"
#include <QGraphicsSceneContextMenuEvent>

ClickableGraphicsPixmapItem::ClickableGraphicsPixmapItem(const QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{

}

void ClickableGraphicsPixmapItem::contextMenuEvent(QGraphicsSceneContextMenuEvent * event) {
    emit selected(event->pos());
}

