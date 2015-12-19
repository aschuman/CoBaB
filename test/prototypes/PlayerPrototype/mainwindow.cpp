#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfileinfo.h>
#include "image.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mediaPlayer(std::make_unique<MediaPlayer>(nullptr)),
    fileNames({"../../dummyImage.jpg", "../../dummyImage_small.jpg", "../../dummyImage_big.jpg"}),
    fileNameIt(fileNames.begin())
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(mediaPlayer.get());

    updatePlayer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ++fileNameIt;
    if(fileNameIt == fileNames.end())
        fileNameIt = fileNames.begin();
    updatePlayer();
}

void MainWindow::updatePlayer()
{
    if(fileNameIt != fileNames.end()){
        QFileInfo file(*fileNameIt);
        Q_ASSERT(file.exists());
        Image img(*fileNameIt);
        mediaPlayer->display(&img);
    }
}
