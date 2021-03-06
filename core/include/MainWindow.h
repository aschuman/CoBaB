#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief The main window of this application.
 * @author Vincent Winkler
 *
 * MainWindow provides space for a page (a QWidget), a menu and buttons to return to a previous page and the home page.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void display(QWidget* widget);
    void retranslate();
    void showOpenDataset();
    void hideOpenDataset();
    void setMenuVisible(bool visible);
    void setReturnEnabled(bool enabled);

public slots:
    void showAboutDialog();
    void showHelpDialog();
    void changeLanguageToGerman();
    void changeLanguageToEnglish();
    void changeSound();

signals:
    /**
     * @brief Emitted when the user requests the previous page to be displayed.
     */
    void requestedPreviousPage();
    /**
     * @brief Emitted when the user requests the home page to be displayed.
     */
    void requestedHomePage();
    /**
     * @brief requestedFileDialog Emitted when the user requests a file dialog to select another dataset.
     */
    void requestedFileDialog();

private:
    Ui::MainWindow *ui;
    QWidget* currentWidget;
};

#endif // MAINWINDOW_H
