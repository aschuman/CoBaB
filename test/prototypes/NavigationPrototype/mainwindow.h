#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addView(QWidget* w);
    void showView(int index);

signals:
    void toHomeView();
    void toPreviousView();

private slots:
    void on_btnHome_clicked();

    void on_btnPrev_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
