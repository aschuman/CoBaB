#ifndef SEARCHRESULTIO_H
#define SEARCHRESULTIO_H
#include "searchresult.h"

class SearchResultIO : public QDataStream
{
public:
    SearchResultIO();
    void storeSearchResult(SearchResult searchResult);
    SearchResult loadSearchResult(QString name);
    QDataStream &SearchResultIO::operator<<(SearchResult result);
    QList<SearchResult> getSearchResultList();
private:
    QList<SearchResult> searchResultList;
};

#endif // SEARCHRESULTIO_H
