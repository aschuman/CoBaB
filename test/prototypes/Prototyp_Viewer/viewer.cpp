#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Viewer)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    button = new QPushButton;

}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::on_pushButton1_clicked()
{
    button->setText(ui->pushButton1->text());
    proxy = scene->addWidget(button);
}

void Viewer::on_pushButton2_clicked()
{
    button->setText(ui->pushButton2->text());
    proxy = scene->addWidget(button);
}
