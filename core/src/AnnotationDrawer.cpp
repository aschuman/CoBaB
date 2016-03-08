#include "AnnotationDrawer.h"

/**
 * @brief AnnotationDrawer::AnnotationDrawer Craetes a new Annotation Drawer with the given QGraphicsScene.
 * @param scene The QGraphicsScene on which the annotations are drawed.
 */
AnnotationDrawer::AnnotationDrawer(QGraphicsScene* scene) : mScene(scene)
{

}

/**
 * @brief AnnotationDrawer::setAnnotations Sets the annotations that should be drawed.
 * @param annotations The annotations that are drawed on the QGraphicsScene.
 */
void AnnotationDrawer::setAnnotations(QList<QPair<int, Annotation*>> annotations) {
    for(QPair<int, Annotation*> iter: annotations) {
        QGraphicsItem* item = mFactory.getAnnotationVisualizer(iter.second);
        mAnnotations.append(item);
        mScene->addItem(item);
        connect((ClickableGraphicsRectItem*)item, SIGNAL(selected(Annotation*, const QPointF&)),
                this, SIGNAL(selected(Annotation*, const QPointF&)));
    }
}

/**
 * @brief AnnotationDrawer::removeAnnotations Removes the annotations from the QGraphicsScene.
 */
void AnnotationDrawer::removeAnnotations() {
    for(auto it = mAnnotations.begin(); it != mAnnotations.end(); ++it){
        mScene->removeItem(*it);
        delete *it;
    }
    mAnnotations.clear();
}

