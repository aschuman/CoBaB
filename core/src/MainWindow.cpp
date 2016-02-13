#include "MainWindow.h"
#include "ui_MainWindow.h"

/**
 * @brief Constructs the MainWindow.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr)
{
    ui->setupUi(this);
    QObject::connect(ui->mHomeAction, SIGNAL(triggered(bool)), this, SIGNAL(requestedHomePage()));
    QObject::connect(ui->mBackAction, SIGNAL(triggered(bool)), this, SIGNAL(requestedPreviousPage()));
}

/**
 * @brief Destructs this MainWindow.
 */
MainWindow::~MainWindow()
{
    if(currentWidget)
        ui->verticalLayout->removeWidget(currentWidget);
    delete ui;
}

/**
 * @brief Displays the given widget as a page.
 * @param widget Widget to be displayed.
 */
void MainWindow::display(QWidget* widget)
{
    if(widget){
        if(currentWidget){
            currentWidget->hide();
            ui->verticalLayout->removeWidget(currentWidget);
        }
        ui->verticalLayout->addWidget(widget);
        currentWidget = widget;
        currentWidget->show();
    }
}
