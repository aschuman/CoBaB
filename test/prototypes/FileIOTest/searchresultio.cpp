#include "searchresultio.h"
#include <QTextStream>

QTextStream stream(stdout);
QIODevice device;
SearchResultIO::SearchResultIO()
{
}

void storeSearchResult(SearchResult searchResult) {
    searchResultList.push_back(&searchResult);

    //to test if it is faster with all results in one file or all results in their own files
    //one file
    qint64 start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();

    QFile file("../FileIOTest/bookmarks/resultTest.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    device = file;
    out << searchResult;
    file.close();

    qint64 middle = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "one (write) " << (middle-start) << endl;

    //many files
    QFile file2("../FileIOTest/bookmarks/resultTest"+searchResult.getName()+".dat");
    file2.open(QIODevice::WriteOnly);
    device = file2;
    out2 << searchResult;
    file2.close();

    qint64 end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "many (write) " << (end-middle) << endl;
}

SearchResult SearchResultIO::loadSearchResult(QString name) {
    QListIterator iterator(searchResultList);
    while(iterator.hasNext()) {
        SearchResult result = iterator.next();
        if(result.getName() == name) {
            return result;
        }
    }

    //one file
    qint64 start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();

    QFile file("../FileIOTest/bookmarks/resultTest.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    QString name2;
    int date;
    QList<QString> list;
    while(!in.atEnd) {
        in >> name2 >> date >> list;
        if(name2 == name) {
            SearchResult result(list);
            result.setName(name);
            result.setDate(date);

            qint64 middle = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
            stream << "one (read) " << (middle-start) << endl;

            return result;
        }
    }

    qint64 middle = (QDateTime::currentDateTime()).toMSecsSinceEpoch();

    //many files
    QFile file2("../FileIOTest/bookmarks/resultTest"+name+".dat");
    file2.open(QIODevice::ReadOnly);
    QDataStream in2(&file2);
    in2 >> name2 >> date >> list;
    SearchResult result(list);
    result.setName(name);
    result.setDate(date);

    qint64 end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "many (read) " << (end-middle) << endl;

    return result;
}

QList<SearchResult> SearchResult::getSearchResultList() {
    return SearchResultList;
}

QDataStream &SearchResultIO::operator<<(SearchResult result) {
    QDataStream::setDevice(&device);
    QDataStream::operator<<(this, &result.getName());
    QDataStream::operator<<(this, &result.getSearchResultList());
}

