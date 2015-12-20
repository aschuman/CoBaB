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
    SearchResultIO resultIO();
    for(int i = 0; i < 10; i++) {
        QList<QString> list;
        for(int j = 0; j < 10000; j++) {
            list.push_back(QString("Pfad/Pfad/Pfad/Pfad/Bilder/Datensatz%1/Bild%2").arg(i).arg(j));
        }
        SearchResult result(list);
        result.setName(QString::number(i));
        resultIO.storeSearchResult(result);
    }

    return a.exec();
}


