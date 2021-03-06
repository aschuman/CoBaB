#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "mediaplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<MediaPlayer> mediaPlayer;
    std::vector<Medium> media;
    std::vector<Medium>::iterator mediaIt;

    void updatePlayer();
};

#endif // MAINWINDOW_H
