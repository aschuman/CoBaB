#include "AnnotationDrawer.h"

AnnotationDrawer::AnnotationDrawer(QGraphicsScene* scene) : mScene(scene)
{

}

void AnnotationDrawer::setAnnotations(QList<QPair<int, Annotation*>> annotations) {
    for(QPair<int, Annotation*> iter: annotations) {
        QGraphicsItem* item = mFactory.getAnnotationVisualizer(iter.second);
        mAnnotations.append(item);
        mScene->addItem(item);
        connect((ClickableGraphicsRectItem*)item, SIGNAL(selected(Annotation*, const QPointF&)),
                this, SIGNAL(selected(Annotation*, const QPointF&)));
    }
}
void AnnotationDrawer::removeAnnotations() {
    for(auto it = mAnnotations.begin(); it != mAnnotations.end(); ++it){
        mScene->removeItem(*it);
        delete *it;
    }
    mAnnotations.clear();
}

