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

    QObject::connect(ui->mAboutAction, SIGNAL(triggered(bool)), this, SLOT(showAboutDialog()));
    QObject::connect(ui->mHelpAction, SIGNAL(triggered(bool)), this, SLOT(showHelpDialog()));

    QObject::connect(ui->mActionDeutsch, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToGerman()));
    QObject::connect(ui->mActionEnglish, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToEnglish()));

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
    }
}

void MainWindow::showAboutDialog() {
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, data->translate("MainWindow", "Über CoBaB"), data->getAbout(), QMessageBox::NoButton, this);
    msgBox.addButton(data->translate("MainWindow", "Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

void MainWindow::showHelpDialog() {
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, data->translate("MainWindow", "CoBaB - Hilfe"), data->getHelp(), QMessageBox::NoButton, this);
    msgBox.addButton(data->translate("MainWindow", "Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

void MainWindow::changeLanguageToGerman() {
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("German");
    retranslate();
}

void MainWindow::changeLanguageToEnglish() {
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("English");
    retranslate();
}

void MainWindow::retranslate() {
    ConfigData* data = ConfigData::getInstance();
    ui->mAboutAction->setText(data->translate("MainWindow", "Über CoBaB"));
    ui->mHelpAction->setText(data->translate("MainWindow", "CoBaB - Hilfe"));
    ui->mBackAction->setText(data->translate("MainWindow", "Zurück"));
    ui->mHomeAction->setText(data->translate("MainWindow", "Anfang"));
    ui->mBookmarkMenu->setTitle(data->translate("MainWindow", "Lesezeichen"));
    ui->mFileMenu->setTitle(data->translate("MainWindow", "Datei"));
    ui->mHelpMenu->setTitle(data->translate("MainWindow", "Hilfe"));
    ui->mHistoryMenu->setTitle(data->translate("MainWindow", "Chronik"));
    ui->mLanguageMenu->setTitle(data->translate("MainWindow", "Sprache"));
    ui->mActionDeutsch->setText(data->translate("MainWindow", "Deutsch"));
    ui->mActionEnglish->setText(data->translate("MainWindow", "Englisch"));

    PageWidget* pageWidget = dynamic_cast<PageWidget*> (currentWidget);
    if (pageWidget != nullptr) {
        pageWidget->retranslateUi();
    }

}
