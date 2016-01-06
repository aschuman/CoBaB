#include "parameterwidget.h"
#include "ui_parameterwidget.h"
#include <qlineedit.h>
#include <cstddef>

ParameterWidget::ParameterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterWidget)
{
    ui->setupUi(this);
    ui->nameLabel->setText("TestParameter");
    QLineEdit* line = new QLineEdit("defaultText");
    ui->variableLayout->addWidget(line);
}

ParameterWidget::~ParameterWidget()
{
    delete ui;
}
