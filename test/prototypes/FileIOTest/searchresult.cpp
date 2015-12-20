#include "searchresult.h"
#include <QDateTime>

SearchResult::SearchResult(QList<QString> list)
{
    searchResultList = list;
    date = QDateTime::currentDateTime();
    name = QString::number(date.toTime_t());
}
QString SearchResult::getName() {
    return name;
}
void SearchResult::setName(QString name) {
    this->name = name;
}

QDateTime SearchResult::getDate() {
    return date;
}
void SearchResult::setDate(int sec) {
    date = QDateTime::fromTime_t(sec);
}
QList<QString> SearchResult::getSearchResultList() {
    return searchResultList;
}

