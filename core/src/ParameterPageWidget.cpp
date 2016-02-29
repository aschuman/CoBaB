#include "include/ParameterPageWidget.h"
#include "ui_ParameterPageWidget.h"

const int ParameterPageWidget::EXIT_NEXT = 0;

ParameterPageWidget::ParameterPageWidget() :
    ui(new Ui::ParameterPageWidget)
{
    ui->setupUi(this);
    ui->mSearchDatasetListView->setModel(&mModel);
    ui->mParameterWidget->setModel(&mParameterModel);

    connect(ui->mNext, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
}

ParameterPageWidget::~ParameterPageWidget()
{
    delete ui;
}

void ParameterPageWidget::reset() {

    QVariant var;
    emit readFromStack(-2, var);
    if(var.canConvert<std::shared_ptr<DatasetList>>()){
        mModel.setDatasetList(var.value<std::shared_ptr<DatasetList>>()->getDatasetList());
        // save the parameters
    }

}

void ParameterPageWidget::nextButtonClicked() {

 //   pushToStack();
    exit(EXIT_NEXT);
}
