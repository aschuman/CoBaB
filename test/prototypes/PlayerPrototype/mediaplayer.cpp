#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include "medium.h"
#include <utility>


MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer),
    annotationPen(QColor(200,100,0)),
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
        for(auto it = currentAnnotations.begin(); it != currentAnnotations.end(); ++it){
            scene.removeItem(*it);
            delete *it;
        }
        currentAnnotations.clear();
    }

    QImage image(medium->getFile());
    scene.setSceneRect(image.rect()); // adjust visible area
    currentImageItem = scene.addPixmap(QPixmap::fromImage(std::move(image))); // don't know how many copies are made here

    for(auto it = medium->beginAnnotations(); it != medium->endAnnotatoins(); ++it){
        currentAnnotations.push_back(scene.addRect(it->getRect(), annotationPen));
    }
}
