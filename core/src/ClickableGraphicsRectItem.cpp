#include "ClickableGraphicsRectItem.h"
#include <QPen>

ClickableGraphicsRectItem::ClickableGraphicsRectItem(RectangleAnnotation* annotation) : QGraphicsRectItem(), mAnnotation(annotation)
{
    setPen(QPen(QColor(255, 0, 0)));
    setRect(annotation->x(), annotation->y(), annotation->width(), annotation->height());
}

