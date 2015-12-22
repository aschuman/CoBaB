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
        stream << loaded2.getName() << endl;
        stream << loaded2.getDate().toTime_t() << endl;
        stream << loaded2.getSearchResultList().last() << endl;
        end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        stream << "one (read) " << (end-start) << endl;

        start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        SearchResult loaded3 = resultIO.loadSearchResultManyFiles("3");
        stream << loaded3.getName() << endl;
        stream << loaded3.getDate().toTime_t() << endl;
        stream << loaded3.getSearchResultList().last() << endl;
        end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
        stream << "many (read) " << (end-start) << endl;
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
        stream << result.getDate().toTime_t() << endl;
        resultIO.storeSearchResult(result);
    }
    end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "one (write) " << (end-start) << endl;

    //write test with many files
    start = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    for(int i = 0; i < 6; i++) {
        QList<QString> list;
        for(int j = 0; j < 300000; j++) {
            list.push_back(QString("Pfad/Pfad/Pfad/Pfad/Bilder/Datensatz%1/Bild%2").arg(i).arg(j));
        }
        SearchResult result(list);
        result.setName(QString::number(i));
        stream << result.getDate().toTime_t() << endl;
        resultIO.storeSearchResultManyFiles(result);
    }
    end = (QDateTime::currentDateTime()).toMSecsSinceEpoch();
    stream << "many (write) " << (end-start) << endl;

    //that's the result from the list, not the file!
    SearchResult loaded = resultIO.loadSearchResult("5");
    stream << loaded.getName() << endl << loaded.getDate().toTime_t() << endl;

    return a.exec();
}


