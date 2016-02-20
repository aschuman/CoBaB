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

signals:
    /**
     * @brief Emitted when the user requests the previous page to be displayed.
     */
    void requestedPreviousPage();
    /**
     * @brief Emitted when the user requests the home page to be displayed.
     */
    void requestedHomePage();

private:
    Ui::MainWindow *ui;
    QWidget* currentWidget;
};

#endif // MAINWINDOW_H
