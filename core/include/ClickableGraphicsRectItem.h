#ifndef CLICKABLEGRAPHICSRECTITEM_H
#define CLICKABLEGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include "RectangleAnnotation.h"
#include <QGraphicsSceneMouseEvent>
#include <QObject>

/**
 * @brief The ClickableGraphicsRectItem class is a QGraphicsRectItem with a RectangleAnnotation and is clickable.
 * @author Anja
 */
class ClickableGraphicsRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit ClickableGraphicsRectItem(RectangleAnnotation* annotation);

signals:
    /**
     * @brief selected This signal is emitted when the item associatied with the Annotation was selected at the specified point.
     */
    void selected(Annotation*, const QPointF&);

public slots:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);

private:
    RectangleAnnotation* mAnnotation; ///< The item has the form of the RectangleAnnotation.
};

#endif // CLICKABLEGRAPHICSRECTITEM_H
