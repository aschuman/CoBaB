#include "AnnotationDrawer.h"

AnnotationDrawer::AnnotationDrawer(QGraphicsScene* scene) : mScene(scene)
{

}
#include <QDebug>
void AnnotationDrawer::setAnnotations(QList<QPair<int, Annotation*>> annotations) {
    for(QPair<int, Annotation*> iter: annotations) {
        QGraphicsItem* item = mFactory.getAnnotationVisualizer(iter.second);
        mAnnotations.append(item);
        mScene->addItem(item);
    }
}
void AnnotationDrawer::removeAnnotations() {
    for(auto it = mAnnotations.begin(); it != mAnnotations.end(); ++it){
        mScene->removeItem(*it);
        delete *it;
    }
    mAnnotations.clear();
}

