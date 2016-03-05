#include "CustomGraphicsView.h"
#include <QWheelEvent>

CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QGraphicsView(parent), _numScheduledScalings(0)
{

}

void CustomGraphicsView::wheelEvent (QWheelEvent* event)
{
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15; // see QWheelEvent documentation
    _numScheduledScalings += numSteps;
    if (_numScheduledScalings * numSteps < 0) // if user moved the wheel in another direction, we reset previously scheduled scalings
    _numScheduledScalings = numSteps;

    QTimeLine *anim = new QTimeLine(350, this);
    anim->setUpdateInterval(20);

    connect(anim, SIGNAL (valueChanged(qreal)), SLOT (scalingTime(qreal)));
    connect(anim, SIGNAL (finished()), SLOT (animFinished()));
    anim->start();
}

void CustomGraphicsView::scalingTime(qreal x)
{
    qreal factor = 1.0+ qreal(_numScheduledScalings) / 300.0;
    scale(factor, factor);
}

void CustomGraphicsView::animFinished()
{
    if (_numScheduledScalings > 0)
        _numScheduledScalings; //?
    else
        _numScheduledScalings++;
    sender()->~QObject();
}

void CustomGraphicsView::showEvent(QShowEvent* event) {
    if(!event->spontaneous()) {
        emit resize();
    }
    QGraphicsView::showEvent(event);
}
