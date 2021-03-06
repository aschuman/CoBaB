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

    QObject::connect(ui->mGermanAction, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToGerman()));
    QObject::connect(ui->mEnglishAction, SIGNAL(triggered(bool)), this, SLOT(changeLanguageToEnglish()));

    QObject::connect(ui->mSoundAction, SIGNAL(triggered(bool)), this, SLOT(changeSound()));

    Q_INIT_RESOURCE(application);
    setWindowIcon(QIcon(":/logo.png"));

    //load config data with previously chosen language
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage(data->getLanguage());
    retranslate();

    Q_INIT_RESOURCE(application);
    QIcon home(":/homeIcon.png");
    ui->mHomeAction->setIcon(home);
    QIcon back(":/backIcon.png");
    ui->mBackAction->setIcon(back);
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

/**
 * @brief MainWindow::showAboutDialog Displays the about dialog in the current language.
 */
void MainWindow::showAboutDialog()
{
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, tr("Über CoBaB"), data->getAbout(), QMessageBox::NoButton, this);
    msgBox.addButton(tr("Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

/**
 * @brief MainWindow::showHelpDialog Displays the help dialog in the current language.
 */
void MainWindow::showHelpDialog()
{
    ConfigData* data = ConfigData::getInstance();
    QMessageBox msgBox(QMessageBox::Information, tr("Hilfe für CoBaB"), data->getHelp(), QMessageBox::NoButton, this);
    msgBox.addButton(tr("Schließen"), QMessageBox::DestructiveRole);
    msgBox.exec();
}

/**
 * @brief MainWindow::showOpenDataset Shows the menu entry to select another dataset.
 */
void MainWindow::showOpenDataset()
{
    ui->mDatasetAction->setVisible(true);
}

/**
 * @brief MainWindow::hideOpenDataset Hides the menu entry to select another dataset.
 */
void MainWindow::hideOpenDataset()
{
    ui->mDatasetAction->setVisible(false);
}

/**
 * @brief MainWindow::setMenuVisible Sets the menubar visible.
 * @param visible The menubar is only visible when the LibraryPageWidget is displayed.
 */
void MainWindow::setMenuVisible(bool visible)
{
    ui->mMenubar->setVisible(visible);
}

/**
 * @brief MainWindow::setReturnEnabled Enables the back action.
 * @param enabled The back action is disabled after starting a new search.
 */
void MainWindow::setReturnEnabled(bool enabled)
{
    ui->mBackAction->setEnabled(enabled);
}

/**
 * @brief MainWindow::changeLanguageToGerman Stores the language as "German" and retranslates the GUI.
 */
void MainWindow::changeLanguageToGerman()
{
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("German");
    retranslate();
}

/**
 * @brief MainWindow::changeLanguageToEnglish Stores the language as "English" and retranslates the GUI.
 */
void MainWindow::changeLanguageToEnglish()
{
    ConfigData* data = ConfigData::getInstance();
    data->setLanguage("English");
    retranslate();
}

/**
 * @brief MainWindow::changeSound Stores the current setting of the notification sound.
 */
void MainWindow::changeSound()
{
    ConfigData* data = ConfigData::getInstance();
    bool soundOn = data->getSoundOn();
    data->setSoundOn(!soundOn);
    if(soundOn) {
        ui->mSoundAction->setText(tr("Ton einschalten"));
    } else {
        ui->mSoundAction->setText(tr("Ton ausschalten"));
    }
}

/**
 * @brief MainWindow::retranslate Retranslates the MainWindow after changing the language.
 */
void MainWindow::retranslate()
{
    ConfigData* data = ConfigData::getInstance();
    ui->mAboutAction->setText(tr("Über CoBaB"));
    ui->mHelpAction->setText(tr("Hilfe für CoBaB"));
    ui->mFileMenu->setTitle(tr("Datei"));
    ui->mHelpMenu->setTitle(tr("Hilfe"));
    ui->mLanguageMenu->setTitle(tr("Sprache"));
    ui->mGermanAction->setText(tr("Deutsch"));
    ui->mEnglishAction->setText(tr("Englisch"));
    ui->mDatasetAction->setText(tr("Datenordner öffnen"));
    ui->mSettingsMenu->setTitle(tr("Einstellungen"));
    if(data->getSoundOn()) {
        ui->mSoundAction->setText(tr("Ton ausschalten"));
    } else {
        ui->mSoundAction->setText(tr("Ton einschalten"));
    }
    if(data->getLanguage() == "German") {
        ui->mGermanAction->setChecked(true);
        ui->mEnglishAction->setChecked(false);
    } else {
        ui->mGermanAction->setChecked(false);
        ui->mEnglishAction->setChecked(true);
    }

    PageWidget* pageWidget = dynamic_cast<PageWidget*> (currentWidget);
    if(pageWidget != nullptr) {
        pageWidget->retranslateUi();
        setWindowTitle(pageWidget->getName());
    }
}
