#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(currentWidget)
        ui->verticalLayout->removeWidget(currentWidget);
    delete ui;
}

void MainWindow::display(QWidget* widget)
{
    if(currentWidget)
        ui->verticalLayout->removeWidget(currentWidget);
    ui->verticalLayout->addWidget(widget);
    currentWidget = widget;
}
