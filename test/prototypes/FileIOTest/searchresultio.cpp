#include "searchresultio.h"
#include <QFile>
#include <QListIterator>
#include <QDataStream>
#include <QMessageBox>

SearchResultIO::SearchResultIO()
{
}

QDataStream & SearchResultIO::operator<<(SearchResult result) {
    QDataStream::setDevice(device);
    QDataStream::operator<<(&result.getName());
    return QDataStream::operator<<(&result.getSearchResultList());
}
void SearchResultIO::storeSearchResult(SearchResult searchResult) {
    searchResultList.push_back(searchResult);

    QFile file("../FileIOTest/bookmarks/resultTest.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    device = &file;
    *this << searchResult;
    file.close();
}

//to test if it is faster with all results in one file or all results in their own files
void SearchResultIO::storeSearchResultManyFiles(SearchResult searchResult) {
    searchResultList.push_back(searchResult);

    QFile file2("../FileIOTest/bookmarks/resultTest"+searchResult.getName()+".dat");
    file2.open(QIODevice::WriteOnly);
    device = &file2;
    *this << searchResult;
    file2.close();
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
    QString name2;
    int date;
    QList<QString> list;
    QDataStream in(&file);
    while(!in.atEnd()) {
        in >> name2 >> date >> list;
        if(name2 == name) {
            SearchResult result(list);
            result.setName(name);
            result.setDate(date);
            return result;
        }
    }
    QMessageBox::information(0, "error", "loading of the file not possible");
    throw 0;
}
SearchResult SearchResultIO::loadSearchResultManyFiles(QString name) {
    QListIterator<SearchResult> iterator(searchResultList);
    while(iterator.hasNext()) {
        SearchResult result = iterator.next();
        if(result.getName() == name) {
            return result;
        }
    }

    QFile file2("../FileIOTest/bookmarks/resultTest"+name+".dat");
    QString name2;
    int date;
    QList<QString> list;
    file2.open(QIODevice::ReadOnly);
    QDataStream in2(&file2);
    in2 >> name2 >> date >> list;
    SearchResult result(list);
    result.setName(name);
    result.setDate(date);
    return result;
}

QList<SearchResult> SearchResultIO::getSearchResultList() {
    return searchResultList;
}

