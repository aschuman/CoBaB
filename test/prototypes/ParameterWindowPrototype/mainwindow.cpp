#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parameterwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->addWidget(new ParameterWidget());
    ui->verticalLayout->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}
