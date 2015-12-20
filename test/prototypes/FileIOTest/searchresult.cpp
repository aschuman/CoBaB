#include "searchresult.h"

SearchResult::SearchResult(QList<QString> list)
{
    searchResultList = list;
    date = QDateTime::currentDate();
    name = QString::number(date.toTime_t());
}
QString SearchResult::getName() {
    return name;
}
void SearchResult::setName(QString name) {
    this->name = name;
}

QDateTime getDate() {
    return date;
}
void setDate(int sec) {
    date = QDateTime::fromTime_t(sec);
}
QList<QString> SearchResult::getSearchResultList() {
    return searchResultList;
}

