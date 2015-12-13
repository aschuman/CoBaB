#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QObject>
#include <memory>
#include "mainwindow.h"
#include "libraryview.h"
#include "datasetview.h"

class Navigator : public QObject
{
    Q_OBJECT
public:
    explicit Navigator(QObject *parent = 0);

private slots:
    void onToHomeView();
    void onToPreviousView();
    void onLibraryChosen(QString dataset);
    void onAlgorithmChosen(QString algo, int anno, QString pic);

private:
    MainWindow w;

    std::unique_ptr<LibraryView> libView;
    std::unique_ptr<DatasetView> dataView;
};

#endif // NAVIGATOR_H
