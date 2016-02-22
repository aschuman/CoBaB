#ifndef ANNOTATIONDRAWER_H
#define ANNOTATIONDRAWER_H

#include "AnnotationGraphicsItemFactory.h"
#include <QGraphicsScene>
#include <QObject>

/**
 * @brief The AnnotationDrawer class
 * @author Anja
 */
class AnnotationDrawer : public QObject
{
    Q_OBJECT

public:
    AnnotationDrawer(QGraphicsScene* scene);
    void setAnnotations(QList<QPair<int, Annotation*>> annotations);
    void removeAnnotations();
signals:
    void selected(Annotation*, const QPointF&);

private:
    AnnotationGraphicsItemFactory mFactory;
    QList<QGraphicsItem*> mAnnotations;
    QGraphicsScene* mScene;
};

#endif // ANNOTATIONDRAWER_H
