#include "libraryview.h"
#include "ui_libraryview.h"

LibraryView::LibraryView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibraryView)
{
    ui->setupUi(this);
}

LibraryView::~LibraryView()
{
    delete ui;
}

void LibraryView::on_pushButton_clicked()
{
    emit libraryChosen("defaul_libs/Frankreich 2010/");
}
