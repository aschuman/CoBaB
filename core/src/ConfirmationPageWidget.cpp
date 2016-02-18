#include "ConfirmationPageWidget.h"
#include "ui_ConfirmationPageWidget.h"

ConfirmationPageWidget::ConfirmationPageWidget() :
    ui(new Ui::ConfirmationPageWidget)
{
    ui->setupUi(this);
    ui->mSearchButton->setText(tr("start search"));


    ui->mParameters->setRowCount(2);
    ui->mParameters->setColumnCount(3);
    QTableWidgetItem* datasets = new QTableWidgetItem(tr("datasets"));
    QTableWidgetItem* algorithm = new QTableWidgetItem(tr("algorithm"));
    QTableWidgetItem* parameters = new QTableWidgetItem(tr("parameters"));
    ui->mParameters->setItem(1, 1, datasets);
    ui->mParameters->setItem(1, 2, algorithm);
    ui->mParameters->setItem(1, 3, parameters);

}

ConfirmationPageWidget::~ConfirmationPageWidget()
{
    delete ui;
}

void ConfirmationPageWidget::reset()
{

}

void ConfirmationPageWidget::on_startSearchButton_clicked()
{
    emit exit(EXIT_NEXT);
}

const int ConfirmationPageWidget::EXIT_NEXT = 0;
