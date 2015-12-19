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
    QGraphicsPixmapItem* currentImageItem;
};

#endif // MEDIAPLAYER_H
