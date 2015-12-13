#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //read in
    QFile file("../FileIOTest/text.txt");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0, "error", file.errorString());

     QTextStream in(&file);
     while (!in.atEnd()) {
         QString line = in.readLine();
         QMessageBox::information(0, "information", line);
     }
    file.close();

    //write out
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
       QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);
        out << "Hello World!\n";

    file.close();

    return a.exec();
}
