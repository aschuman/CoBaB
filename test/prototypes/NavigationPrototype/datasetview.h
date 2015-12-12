#ifndef DATASETVIEW_H
#define DATASETVIEW_H

#include <QWidget>

namespace Ui {
class DatasetView;
}

class DatasetView : public QWidget
{
    Q_OBJECT

public:
    explicit DatasetView(QWidget *parent = 0);
    ~DatasetView();

    void init(const QString& dataset);

signals:
    void algorithmChosen(QString dll, int annotation, QString searchTemplate);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DatasetView *ui;
};

#endif // DATASETVIEW_H
