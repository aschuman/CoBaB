#include "ClickableGraphicsPixmapItem.h"
#include <QGraphicsSceneContextMenuEvent>

/**
 * @author Anja
 * @brief ClickableGraphicsPixmapItem::ClickableGraphicsPixmapItem Constructs a ClickableGraphicsPixmapItem with the given pixmap.
 * @param pixmap
 */
ClickableGraphicsPixmapItem::ClickableGraphicsPixmapItem(const QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{

}

/**
 * @brief ClickableGraphicsPixmapItem::contextMenuEvent Emits a signal that the item was clicked with the right mouse button.
 * @param event The QGraphicsSceneContextMenuEvent.
 */
void ClickableGraphicsPixmapItem::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
    emit selected(event->pos());
}

