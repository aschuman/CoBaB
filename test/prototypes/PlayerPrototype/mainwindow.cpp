#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfileinfo.h>
#include "medium.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mediaPlayer(std::make_unique<MediaPlayer>(nullptr))
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(mediaPlayer.get());

    media.emplace_back("../../dummyImage.jpg", QList<Medium::Annotation>({Medium::Annotation(0, QRect(100,200,100,50))}));
    media.emplace_back("../../dummyImage_small.jpg", QList<Medium::Annotation>());
    media.emplace_back("../../dummyImage_big.jpg", QList<Medium::Annotation>({Medium::Annotation(0, QRect(965,200,115,400)), Medium::Annotation(0, QRect(310,310,225,175))}));

    mediaIt = media.begin();

    updatePlayer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ++mediaIt;
    if(mediaIt == media.end())
        mediaIt = media.begin();
    updatePlayer();
}

void MainWindow::updatePlayer()
{
    if(mediaIt != media.end()){
        //QFileInfo file(*fileNameIt);
        //Q_ASSERT(file.exists());
        mediaPlayer->display(&*mediaIt);
    }
}
