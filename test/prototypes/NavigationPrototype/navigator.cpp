#include "navigator.h"
#include <QMessageBox>

Navigator::Navigator(QObject *parent)
    : QObject(parent),
      libView(std::make_unique<LibraryView>(nullptr)),
      dataView(std::make_unique<DatasetView>(nullptr))
{
    w.show();
    w.setWindowTitle("CoBaB - Library");
    w.addView(libView.get());
    w.addView(dataView.get());

    QObject::connect(libView.get(), SIGNAL(libraryChosen(QString)), this, SLOT(onLibraryChosen(QString)));
    QObject::connect(dataView.get(), SIGNAL(algorithmChosen(QString, int, QString)), this, SLOT(onAlgorithmChosen(QString, int, QString)));
}

void Navigator::onLibraryChosen(QString dataset)
{
    w.showView(1);
    w.setWindowTitle(dataset);
    dataView->init(dataset);
}

void Navigator::onAlgorithmChosen(QString algo, int anno, QString pic)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Sorry");
    msgBox.setText("Not yet implemented.");
    msgBox.exec();
}

