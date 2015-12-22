#ifndef SEARCHRESULTIO_H
#define SEARCHRESULTIO_H
#include "searchresult.h"
#include <QDataStream>
#include <QFile>

class SearchResultIO : public QDataStream
{
public:
    SearchResultIO();
    void storeSearchResult(SearchResult searchResult);
    SearchResult loadSearchResult(QString name);
    void storeSearchResultManyFiles(SearchResult searchResult);
    SearchResult loadSearchResultManyFiles(QString name);
    QDataStream &SearchResultIO::operator<<(SearchResult result);
    QDataStream &SearchResultIO::operator>>(SearchResult &result);
    QList<SearchResult> getSearchResultList();
private:
    QList<SearchResult> searchResultList;
};

#endif // SEARCHRESULTIO_H
