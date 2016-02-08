#include "include/LibraryPageWidget.h"
#include "ui_LibraryPageWidget.h"

LibraryPageWidget::LibraryPageWidget() :
    ui(new Ui::LibraryPageWidget)
{
    ui->setupUi(this);
}

LibraryPageWidget::~LibraryPageWidget()
{
    delete ui;
}

void LibraryPageWidget::reset()
{

}

void LibraryPageWidget::on_pushButton_clicked()
{
    emit exit(EXIT_NEXT);
}

const int LibraryPageWidget::EXIT_NEXT = 0;
