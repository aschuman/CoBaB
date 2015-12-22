#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include <QDateTime>

class SearchResult
{
public:
    SearchResult();
    SearchResult(QList<QString> list);
    QString getName();
    void setName(QString name);
    QDateTime getDate();
    void setDate(int sec);
    QList<QString> getSearchResultList();
    void setSearchResultList(QList<QString> list);
private:
    QString name;
    QDateTime date;
    QList<QString> searchResultList;
};

#endif // SEARCHRESULT_H
