#include "CustomGraphicsView.h"
#include <QWheelEvent>

/**
 * @author Anja
 * @brief CustomGraphicsView::CustomGraphicsView Constructs a CustomGraphicsView with the given parent.
 * @param parent The parent is passed to QGraphisView's constructor.
 */
CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QGraphicsView(parent), _numScheduledScalings(0), mZoomLevel(1.0)
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
    Q_UNUSED(x);
    qreal factor = 1.0+ qreal(_numScheduledScalings) / 300.0;
    zoom(factor);
}

/**
 * @brief CustomGraphicsView::zoom Zooms the view if the zoom level is between 0.01 and 10000.
 * @param factor The zooming factor.
 */
void CustomGraphicsView::zoom(double factor) {
    if((factor > 1 && mZoomLevel < 10000) || (factor < 1 && mZoomLevel > (double)0.01)) {
        scale(factor, factor);
        mZoomLevel *= factor;
        emit zoomed(mZoomLevel);
    }
}

/**
 * @brief CustomGraphicsView::resetZoom Sets the zoom level to 1.
 */
void CustomGraphicsView::resetZoom() {
    mZoomLevel = 1.0;
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
