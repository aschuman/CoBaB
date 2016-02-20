#include "PhotoViewer.h"
#include "ui_PhotoViewer.h"

PhotoViewer::PhotoViewer() :
    ViewerPageWidget()
{
    /*ui->setupUi(this);
    ui->listWidget->setFlow(QListWidget::LeftToRight);
    ui->listWidget->setWrapping(true);*/
}

PhotoViewer::~PhotoViewer()
{
    delete ui;
}
