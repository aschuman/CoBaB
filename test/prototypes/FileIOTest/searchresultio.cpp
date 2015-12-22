#include "searchresultio.h"
#include <QFile>
#include <QListIterator>
#include <QDataStream>
#include <QMessageBox>
#include <QTextStream>

QTextStream stream2(stdout);

SearchResultIO::SearchResultIO()
{
}
QDataStream &SearchResultIO::operator<<(SearchResult result) {
    return *this << result.getName() << (qint64)result.getDate().toTime_t() << result.getSearchResultList();
}
QDataStream &SearchResultIO::operator>>(SearchResult &result) {
    QString loadedString;
    qint64 loadedInt;
    QList<QString> loadedList;
    *this >> loadedString >> loadedInt >> loadedList;
    result.setSearchResultList(loadedList);
    result.setName(loadedString);
    result.setDate(loadedInt);
    return *this;
}

void SearchResultIO::storeSearchResult(SearchResult searchResult) {
    searchResultList.push_back(searchResult);

    QFile file("../FileIOTest/bookmarks/resultTest.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    this->setDevice(&file);
    *this << searchResult;
    file.close();
}

//to test if it is faster with all results in one file or all results in their own files
void SearchResultIO::storeSearchResultManyFiles(SearchResult searchResult) {
    searchResultList.push_back(searchResult);

    QFile file("../FileIOTest/bookmarks/resultTest"+searchResult.getName()+".dat");
    file.open(QIODevice::WriteOnly);
    this->setDevice(&file);
    *this << searchResult;
    file.close();
}

SearchResult SearchResultIO::loadSearchResult(QString name) {
    QListIterator<SearchResult> iterator(searchResultList);
    while(iterator.hasNext()) {
        SearchResult result = iterator.next();
        if(result.getName() == name) {
            return result;
        }
    }

    QFile file("../FileIOTest/bookmarks/resultTest.dat");
    file.open(QIODevice::ReadOnly);
    SearchResult result;
    this->setDevice(&file);
    while(!this->atEnd()) {
        *this >> result;
        if(result.getName() == name) {
            file.close();
            return result;
        }
    }
    file.close();
    throw;
}

SearchResult SearchResultIO::loadSearchResultManyFiles(QString name) {
    QListIterator<SearchResult> iterator(searchResultList);
    while(iterator.hasNext()) {
        SearchResult result = iterator.next();
        if(result.getName() == name) {
            return result;
        }
    }

    QFile file("../FileIOTest/bookmarks/resultTest"+name+".dat");
    file.open(QIODevice::ReadOnly);
    this->setDevice(&file);
    SearchResult result;
    *this >> result;
    file.close();
    return result;
}

QList<SearchResult> SearchResultIO::getSearchResultList() {
    return searchResultList;
}

