#include "CustomGraphicsView.h"
#include <QWheelEvent>

/**
 * @author Anja
 * @brief CustomGraphicsView::CustomGraphicsView Constructs a CustomGraphicsView with the given parent.
 * @param parent The parent is passed to QGraphisView's constructor.
 */
CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QGraphicsView(parent), _numScheduledScalings(0)
{

}

/**
 * @brief CustomGraphicsView::wheelEvent Zooms the view with the intensity of the QWheelEvent.
 * @param event The QWheelEvent from the mouse wheel.
 */
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

/**
 * @brief CustomGraphicsView::scalingTime Scales the view.
 * @param x unused
 */
void CustomGraphicsView::scalingTime(qreal x)
{
    qreal factor = 1.0+ qreal(_numScheduledScalings) / 300.0;
    scale(factor, factor);
    emit zoomed(factor);
}

/**
 * @brief CustomGraphicsView::animFinished Is called when the animation is finished.
 */
void CustomGraphicsView::animFinished()
{
    if (_numScheduledScalings > 0)
        _numScheduledScalings--;
    else
        _numScheduledScalings++;
    sender()->~QObject();
}

/**
 * @brief CustomGraphicsView::showEvent Emits a signal, if the size of the GraphicsView is set.
 * @param event
 */
void CustomGraphicsView::showEvent(QShowEvent* event) {
    if(!event->spontaneous()) {
        emit resize();
    }
    QGraphicsView::showEvent(event);
}
