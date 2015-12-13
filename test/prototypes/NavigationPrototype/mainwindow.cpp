#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addView(QWidget* w)
{
    ui->stackedWidget->addWidget(w);
}

void MainWindow::showView(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::on_btnHome_clicked()
{
    emit toHomeView();
}

void MainWindow::on_btnPrev_clicked()
{
    emit toPreviousView();
}
