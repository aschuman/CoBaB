#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QDateTime>
#include "searchresultio.h"

QTextStream stream(stdout);

void readWrite() {
    //read in
    QFile file("../FileIOTest/text.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        stream << line << endl;
    }
    file.close();

    //write out

    //to append the text
    //if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {

    //to overwrite the text
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);
    out << "Hello World!\n";

    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //readWrite();

    // bookmark tests
    SearchResultIO resultIO;
    qint64 start;
    qint64 end;

    if(QFile("../FileIOTest/bookmarks/resultTest.dat").exists()) {
        start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        SearchResult loaded2 = resultIO.loadSearchResult("3");
        stream << "read the third result, when the results are in one file:" << endl;
        stream << "loaded name: " << loaded2.getName() << endl;
        stream << "loaded date: " << loaded2.getDate().toTime_t() << endl;
        stream << "loaded last list element: " << loaded2.getSearchResultList().last() << endl;
        end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        stream << "time to read the third result (from the first start): " << (end-start) << endl << endl;

        start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        SearchResult loaded3 = resultIO.loadSearchResultManyFiles("3");
        stream << "read the third result, when the results are in their own files:" << endl;
        stream << "loaded name: " << loaded3.getName() << endl;
        stream << "loaded date: " << loaded3.getDate().toTime_t() << endl;
        stream << "loaded last list element: " << loaded3.getSearchResultList().last() << endl;
        end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        stream << "time to read the third result: " << (end-start) << endl << endl;
    }

    //write test with one file
    start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    for(int i = 0; i < 6; i++) {
        QList<QString> list;
        for(int j = 0; j < 300000; j++) {
            list.push_back(QString("Pfad/Pfad/Pfad/Pfad/Bilder/Datensatz%1/Bild%2").arg(i).arg(j));
        }
        SearchResult result(list);
        result.setName(QString::number(i));
        stream << "current date, which is saved in a result: " << result.getDate().toTime_t() << endl;
        resultIO.storeSearchResult(result);
    }
    end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "time to write the results in one file: " << (end-start) << endl << endl;

    //write test with many files
    start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    for(int i = 0; i < 6; i++) {
        QList<QString> list;
        for(int j = 0; j < 300000; j++) {
            list.push_back(QString("Pfad/Pfad/Pfad/Pfad/Bilder/Datensatz%1/Bild%2").arg(i).arg(j));
        }
        SearchResult result(list);
        result.setName(QString::number(i));
        stream << "current date, which is saved in result " << i << ": " << result.getDate().toTime_t() << endl;
        resultIO.storeSearchResultManyFiles(result);
    }
    end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "time to write the results in their own files: " << (end-start) << endl << endl;

    //that's the result from the list, not the file!
    SearchResult loaded = resultIO.loadSearchResult("5");
    stream << "the fifth result, that is still in the list: " << endl;
    stream << "loaded name: " << loaded.getName() << endl;
    stream << "loaded date: " << loaded.getDate().toTime_t() << endl;

    return a.exec();
}


