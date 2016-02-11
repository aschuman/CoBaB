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
        if(currentWidget)
            ui->verticalLayout->removeWidget(currentWidget);
        ui->verticalLayout->addWidget(widget);
        currentWidget = widget;
    }
}
