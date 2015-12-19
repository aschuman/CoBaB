#include "imageplayer.h"
#include "ui_imageplayer.h"

ImagePlayer::ImagePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImagePlayer)
{
    ui->setupUi(this);
}

ImagePlayer::~ImagePlayer()
{
    delete ui;
}
