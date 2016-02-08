#include "include/ViewerPageWidget.h"
#include "ui_ViewerPageWidget.h"

ViewerPageWidget::ViewerPageWidget() :
    ui(new Ui::ViewerPageWidget)
{
    ui->setupUi(this);
}

ViewerPageWidget::~ViewerPageWidget()
{
    delete ui;
}

void ViewerPageWidget::reset()
{

}

const int ViewerPageWidget::EXIT_NEXT = 0;
