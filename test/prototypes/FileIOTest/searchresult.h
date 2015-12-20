#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include <QDateTime>

class SearchResult
{
public:
    SearchResult(QList<QString> list);
    QString getName();
    void setName(QString name);
    QDateTime getDate();
    void setDate(int sec);
    QList<QString> getSearchResultList();
private:
    QString name;
    QDateTime date;
    QList<QString> searchResultList;
};

#endif // SEARCHRESULT_H
