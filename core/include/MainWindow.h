#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void display(QWidget* widget);

signals:
    void requestedPreviousPage();
    void requestedHomePage();

private:
    Ui::MainWindow *ui;
    QWidget* currentWidget;
};

#endif // MAINWINDOW_H
