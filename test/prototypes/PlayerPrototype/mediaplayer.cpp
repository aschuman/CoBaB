#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include "medium.h"
#include <utility>
#include <QMouseEvent>


MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer),
    annotationPen(QColor(200,100,0)),
    selectionPen(QColor(255,0,0)),
    currentImageItem(nullptr),
    currentSelection(nullptr)
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
        currentImageItem = nullptr;
    }

    if(currentSelection != nullptr){
        scene.removeItem(currentSelection);
        delete currentSelection;
        currentSelection = nullptr;
    }

    QImage image(medium->getFile());
    currentImageItem = scene.addPixmap(QPixmap::fromImage(std::move(image))); // don't know how many copies are made here
    scene.setSceneRect(0,0, image.width(), image.height()); // adjust visible area

    for(auto it = medium->beginAnnotations(); it != medium->endAnnotatoins(); ++it){
        currentAnnotations.push_back(scene.addRect(it->getRect(), annotationPen));
    }
    fit();
}

void MediaPlayer::resizeEvent(QResizeEvent *event)
{
    fit();
}

void MediaPlayer::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
    if(fromScenePoint.x() == 0 && fromScenePoint.y() == 0){
        if(currentSelection != nullptr){
            scene.removeItem(currentSelection);
            delete currentSelection;
        }
        currentSelection = scene.addRect(currentRubberBand, selectionPen);
    } else {
        currentRubberBand.setLeft(fromScenePoint.x());
        currentRubberBand.setTop(fromScenePoint.y());
        currentRubberBand.setRight(toScenePoint.x());
        currentRubberBand.setBottom(toScenePoint.y());
    }
}

void MediaPlayer::fit()
{
    qreal width = currentImageItem->sceneBoundingRect().width();
    qreal height = currentImageItem->sceneBoundingRect().height();
    ui->graphicsView->fitInView(QRect(0,0, qMax(width, (qreal)ui->graphicsView->width()), qMax(height, (qreal)ui->graphicsView->height())), Qt::KeepAspectRatio);
}
