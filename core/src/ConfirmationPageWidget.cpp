#include "ConfirmationPageWidget.h"
#include "ui_ConfirmationPageWidget.h"

ConfirmationPageWidget::ConfirmationPageWidget() :
    ui(new Ui::ConfirmationPageWidget)
{
    ui->setupUi(this);
}

ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

void ConfirmationPageWidget::reset()
{

}

void ConfirmationPageWidget::on_pushButton_clicked()
{
    emit exit(EXIT_NEXT);
}

const int ConfirmationPageWidget::EXIT_NEXT = 0;
