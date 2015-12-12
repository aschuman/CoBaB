#include "datasetview.h"
#include "ui_datasetview.h"

DatasetView::DatasetView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatasetView)
{
    ui->setupUi(this);
}

DatasetView::~DatasetView()
{
    delete ui;
}

void DatasetView::init(const QString& dataset)
{
    ui->lblDataset->setText(dataset);
}

void DatasetView::on_pushButton_clicked()
{
    emit algorithmChosen("someAlgorithm.dll", 12, "2010-05-14.jpg");
}
