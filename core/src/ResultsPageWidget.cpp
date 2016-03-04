#include "include/ResultsPageWidget.h"
#include "ui_ResultsPageWidget.h"

#include "SearchResult.h"

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief temporary
 * @return
 */
SearchResult generateReslut()
{
    QList<SearchResultElement> list;
    SearchObject obj1;
    obj1.setMedium("../test/testdata/Fotos/000_45.bmp");
    SearchObject obj2;
    obj2.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj3;
    obj3.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj4;
    obj4.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj5;
    obj5.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj6;
    obj6.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj7;
    obj7.setMedium("../test/testdata/Fotos/002_45.bmp");
    SearchObject obj8;
    obj8.setMedium("../test/testdata/Fotos/002_45.bmp");

    SearchResultElement element1;
    SearchResultElement element2;
    SearchResultElement element3;
    SearchResultElement element4;
    SearchResultElement element5;
    SearchResultElement element6;
    SearchResultElement element7;
    SearchResultElement element8;
    element1.setSearchObject(obj1);
    element2.setSearchObject(obj2);
    element3.setSearchObject(obj3);
    element4.setSearchObject(obj4);
    element5.setSearchObject(obj5);
    element6.setSearchObject(obj6);
    element7.setSearchObject(obj7);
    element8.setSearchObject(obj8);

    list.push_back(element1);
    list.push_back(element2);
    list.push_back(element3);
    list.push_back(element4);
    list.push_back(element5);
    list.push_back(element6);
    list.push_back(element7);
    list.push_back(element8);

    return SearchResult(list);
}

/**
 * @brief Constructs a ResultsPageWidget.
 *
 * Sets up user interface.
 */
ResultsPageWidget::ResultsPageWidget() :
    ui(new Ui::ResultsPageWidget)
{
    ui->setupUi(this);
    ui->mListView->setModel(&mModel);
    ui->mListView->setItemDelegate(&mDelegate);
}

/**
 * @brief Destructs a ResultsPageWidget.
 *
 * Frees user interface.
 */
ResultsPageWidget::~ResultsPageWidget()
{
    delete ui;
}

void ResultsPageWidget::reset()
{
    QVariant var;
    emit readFromStack(0, var);
    if(var.canConvert<std::shared_ptr<Algorithm>>()){
        emit startAlgorithm(var.value<std::shared_ptr<Algorithm>>().get());
    } else {
        LOG_ERR("could not find algorithm on stack");
    }
}

void ResultsPageWidget::setResults(SearchResult result)
{
    mResult = std::move(result);
    mModel.setSearchResult(&mResult);
}

void ResultsPageWidget::retranslateUi() {

}
