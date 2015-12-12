#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::addView(QWidget* w)
{
    ui->stackedWidget->addWidget(w);
}

void MainWindow::showView(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
