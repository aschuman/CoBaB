#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRubberBand>
#include "medium.h"

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = 0);
    ~MediaPlayer();

    void display(Medium* medium);
    void play();
    void pause();
    void stop();
    bool isPlaying();
    void showAnnotations(bool show);

private slots:
    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

private:
    Ui::MediaPlayer *ui;
    QGraphicsScene scene;
    QPen annotationPen;
    QPen selectionPen;
    QGraphicsPixmapItem* currentImageItem;
    QList<QGraphicsRectItem*> currentAnnotations;
    QGraphicsRectItem* currentSelection;
    QRect currentRubberBand;
};

#endif // MEDIAPLAYER_H
