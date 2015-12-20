#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
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

private:
    Ui::MediaPlayer *ui;
    QGraphicsScene scene;
    QPen annotationPen;
    QGraphicsPixmapItem* currentImageItem;
    QList<QGraphicsRectItem*> currentAnnotations;
};

#endif // MEDIAPLAYER_H
