#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QTimeLine>
#include <QObject>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget* parent=0);
public slots:
    void scalingTime(qreal x);
    void animFinished();
signals:
    void resize();
protected:
    void wheelEvent(QWheelEvent* event);
    void showEvent(QShowEvent *event);
private:
    int _numScheduledScalings;
};

#endif // CUSTOMGRAPHICSVIEW_H
