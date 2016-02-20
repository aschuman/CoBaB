#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"

const int ParameterPageWidget::EXIT_NEXT = 0;

ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget)
{
    ui->setupUi(this);
    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
}

ParameterPageWidget::~ParameterPageWidget()
{
    delete ui;
}

void ParameterPageWidget::reset() {

}

void ParameterPageWidget::nextButtonClicked() {
    exit(EXIT_NEXT);
}
