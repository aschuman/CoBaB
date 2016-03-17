#ifndef ANNOTATIONDRAWER_H
#define ANNOTATIONDRAWER_H

#include "AnnotationGraphicsItemFactory.h"
#include <QGraphicsScene>
#include <QObject>

/**
 * @brief The AnnotationDrawer class draws annotations on a QGraphicsScene dependent on their form.
 * @author Anja
 */
class AnnotationDrawer : public QObject
{
    Q_OBJECT

public:
    explicit AnnotationDrawer(QGraphicsScene* scene);
    void setAnnotations(QList<QPair<int, Annotation*>> annotations);
    void removeAnnotations();

signals:
    /**
     * @brief selected This signal is emitted, when the specified Annotation was selected. The mouse position is specified by PointF.
     */
    void selected(Annotation*, const QPointF&);

private:
    AnnotationGraphicsItemFactory mFactory; ///< The AnnotationGrahicsItemFactory which creates QGraphicsItems with the right form.
    QList<QGraphicsItem*> mAnnotations;     ///< The Annotations on the QGraphicsScene.
    QGraphicsScene* mScene;                 ///< The QGraphicsScene on which the Annotations are drawed.
};

#endif // ANNOTATIONDRAWER_H
