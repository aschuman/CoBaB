#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ConfigData.h"
#include "PageWidget.h"
#include <QMessageBox>

/**
 * @brief Constructs the MainWindow.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr)
{
    ui->setupUi(this);
    QObject::connect(ui->mHomeAction, SIGNAL(triggered(bool)), this, SIGNAL(requestedHomePage()));
    QObject::connect(ui->mBackAction, SIGNAL(triggered(bool)), this, SIGNAL(requestedPreviousPage()));
    QObject::connect(ui->mDatasetAction, SIGNAL(triggered(bool)), this, SIGNAL(requestedFileDialog()));

    QObject::connect(ui->mAboutAction, SIGNAL(triggered(bool)), this, SLOT(showAboutDialog()));
    QObject::connect(ui->mHelpAction, SIGNAL(triggered(bool)), this, SLOT(showHelpDialog()));

    QObject::connect(ui->mActionDeutsch, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToGerman()));
    QObject::connect(ui->mActionEnglish, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToEnglish()));

    //load config data with previously chosen language
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(data->getLanguage());
    retranslate();
}

/**
 * @brief Destructs this MainWindow.
 */
MainWindow::~MainWindow()
{
    if(currentWidget)
        ui->verticalLayout->removeWidget(currentWidget);
    delete ui;
}

/**
 * @brief Displays the given widget as a page.
 * @param widget Widget to be displayed.
 */
void MainWindow::display(QWidget* widget)
{
    if(widget){
        if(currentWidget){
            currentWidget->hide();
            ui->verticalLayout->removeWidget(currentWidget);
        }
        ui->verticalLayout->addWidget(widget);
        currentWidget = widget;
        currentWidget->show();
        retranslate();
    }
}

void MainWindow::showAboutDialog()
{
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, tr("Über CoBaB"), data->getAbout(), QMessageBox::NoButton, this);
    msgBox.addButton(tr("Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

void MainWindow::showHelpDialog()
{
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, tr("Hilfe für CoBaB"), data->getHelp(), QMessageBox::NoButton, this);
    msgBox.addButton(tr("Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

void MainWindow::showOpenDataset()
{
    ui->mDatasetAction->setVisible(true);
}

void MainWindow::hideOpenDataset()
{
    ui->mDatasetAction->setVisible(false);
}

void MainWindow::changeLanguageToGerman()
{
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("German");
    retranslate();
}

void MainWindow::changeLanguageToEnglish()
{
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("English");
    retranslate();
}

void MainWindow::retranslate()
{
    ui->mAboutAction->setText(tr("Über CoBaB"));
    ui->mHelpAction->setText(tr("Hilfe für CoBaB"));
    ui->mBackAction->setText(tr("Zurück"));
    ui->mHomeAction->setText(tr("Anfang"));
    ui->mBookmarkMenu->setTitle(tr("Lesezeichen"));
    ui->mFileMenu->setTitle(tr("Datei"));
    ui->mHelpMenu->setTitle(tr("Hilfe"));
    ui->mHistoryMenu->setTitle(tr("Chronik"));
    ui->mLanguageMenu->setTitle(tr("Sprache"));
    ui->mActionDeutsch->setText(tr("Deutsch"));
    ui->mActionEnglish->setText(tr("Englisch"));
    ui->mDatasetAction->setText(tr("Datenordner öffnen"));

    PageWidget* pageWidget = dynamic_cast<PageWidget*> (currentWidget);
    if(pageWidget != nullptr) {
        pageWidget->retranslateUi();
    }

}
