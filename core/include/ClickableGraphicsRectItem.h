#ifndef CLICKABLEGRAPHICSRECTITEM_H
#define CLICKABLEGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include "RectangleAnnotation.h"
#include <QGraphicsSceneMouseEvent>
#include <QObject>

/**
 * @brief The ClickableGraphicsRectItem class
 * @author Anja
 */
class ClickableGraphicsRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ClickableGraphicsRectItem(RectangleAnnotation* annotation);
signals:
    void selected(Annotation*, const QPointF&);
public slots:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
private:
    RectangleAnnotation* mAnnotation;
};

#endif // CLICKABLEGRAPHICSRECTITEM_H
