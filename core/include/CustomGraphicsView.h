#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QTimeLine>
#include <QObject>

/**
 * @brief The CustomGraphicsView class is a QGraphicsView which provides zooming functionality.
 */
class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget* parent=0);
    void zoom(double);
    void resetZoom();

public slots:
    void scalingTime(qreal x);
    void animFinished();

signals:
    /**
     * @brief resize This signal is emitted if the size of the view changes.
     */
    void resize();
    /**
     * @brief zoomed This signal is emitted if the view is zoomed
     * @param factor The zooming factor.
     */
    void zoomed(double factor);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void showEvent(QShowEvent *event) override;

private:
    int _numScheduledScalings; ///< The total number of scalings that have to be done.4
    double mZoomLevel;         ///< The level how much the view is zoomed.
};

#endif // CUSTOMGRAPHICSVIEW_H
