#ifndef CLICKABLEGRAPHICSPIXMAPITEM_H
#define CLICKABLEGRAPHICSPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
 * @brief The ClickableGraphicsPixmapItem class is a QGraphicsPixmapItem which is clickable.
 */
class ClickableGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit ClickableGraphicsPixmapItem(const QPixmap& pixmap);

signals:
    /**
     * @brief selected This signal is emitted when the item was selected at the specified point.
     */
    void selected(const QPointF&);

public slots:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
};

#endif // CLICKABLEGRAPHICSPIXMAPITEM_H
