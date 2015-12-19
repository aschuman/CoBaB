#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include "image.h"
#include <utility>


MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer),
    currentImageItem(nullptr)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}

void MediaPlayer::display(Medium *medium)
{
    if(currentImageItem != nullptr){
        scene.removeItem(currentImageItem);
        delete currentImageItem;
    }

    Image* img = dynamic_cast<Image*>(medium);
    QImage image = img->get();
    scene.setSceneRect(image.rect()); // adjust visible area
    currentImageItem = scene.addPixmap(QPixmap::fromImage(std::move(image))); // don't know how many copies are made here
}
