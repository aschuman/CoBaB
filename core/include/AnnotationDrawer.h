#ifndef ANNOTATIONDRAWER_H
#define ANNOTATIONDRAWER_H

#include "AnnotationGraphicsItemFactory.h"
#include <QGraphicsScene>

/**
 * @brief The AnnotationDrawer class
 * @author Anja
 */
class AnnotationDrawer
{
public:
    AnnotationDrawer(QGraphicsScene* scene);
    void setAnnotations(QList<QPair<int, Annotation*>> annotations);
    void removeAnnotations();
private:
    AnnotationGraphicsItemFactory mFactory;
    QList<QGraphicsItem*> mAnnotations;
    QGraphicsScene* mScene;
};

#endif // ANNOTATIONDRAWER_H
