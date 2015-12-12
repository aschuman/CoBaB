#ifndef LIBRARYVIEW_H
#define LIBRARYVIEW_H

#include <QWidget>

namespace Ui {
class LibraryView;
}

class LibraryView : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryView(QWidget *parent = 0);
    ~LibraryView();

signals:
    void libraryChosen(QString name);

private slots:
    void on_pushButton_clicked();

private:
    Ui::LibraryView *ui;
};

#endif // LIBRARYVIEW_H
