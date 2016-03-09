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
    CustomGraphicsView(QWidget* parent=0);

public slots:
    void scalingTime(qreal x);
    void animFinished();

signals:
    /**
     * @brief resize This signal is emitted if the size of the view changes.
     */
    void resize();
    void zoomed(double factor);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void showEvent(QShowEvent *event) override;

private:
    int _numScheduledScalings; ///< The total number of scalings that have to be done.
};

#endif // CUSTOMGRAPHICSVIEW_H
