#include "ClickableGraphicsRectItem.h"
#include <QPen>

/**
 * @brief ClickableGraphicsRectItem::ClickableGraphicsRectItem Constructs a ClickableGraphicsRectItem with the given RectangleAnnotation.
 * @param annotation The item has the rectangle form of the RectangleAnnotation.
 */
ClickableGraphicsRectItem::ClickableGraphicsRectItem(RectangleAnnotation* annotation) : QGraphicsRectItem(), mAnnotation(annotation)
{
    setPen(QPen(QColor(255, 0, 0)));
    setRect(annotation->x(), annotation->y(), annotation->width(), annotation->height());
}

/**
 * @brief ClickableGraphicsRectItem::contextMenuEvent Emits a signal that the item was clicked with the right mouse button.
 * @param event The QGraphicsSceneContextMenuEvent.
 */
void ClickableGraphicsRectItem::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
    emit selected(mAnnotation, event->pos());
}


