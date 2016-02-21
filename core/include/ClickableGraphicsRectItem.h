#ifndef CLICKABLEGRAPHICSRECTITEM_H
#define CLICKABLEGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include "RectangleAnnotation.h"

/**
 * @brief The ClickableGraphicsRectItem class
 * @author Anja
 */
class ClickableGraphicsRectItem : public QGraphicsRectItem
{
public:
    ClickableGraphicsRectItem(RectangleAnnotation* annotation);
    RectangleAnnotation* mAnnotation;
};

#endif // CLICKABLEGRAPHICSRECTITEM_H
