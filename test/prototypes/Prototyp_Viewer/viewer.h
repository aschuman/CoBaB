#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QPushButton>

namespace Ui {
class Viewer;
}

class Viewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Viewer(QWidget *parent = 0);
    ~Viewer();

private slots:
    void on_pushButton1_clicked(bool checked);

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::Viewer *ui;
    QPushButton *button;
    QGraphicsScene *scene;
    QGraphicsProxyWidget *proxy;


};

#endif // VIEWER_H
