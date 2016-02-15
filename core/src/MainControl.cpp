#include "MainControl.h"
#include "MainWindow.h"
#include "LibraryPageWidget.h"
#include "ViewerPageWidget.h"

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief Constructs a MainControl.
 */
MainControl::MainControl()
{
}

/**
 * @brief Starts the core.
 */
void MainControl::run()
{
    LOG("Start CoBaB..");
    std::unique_ptr<MainWindow> mainWindow = std::make_unique<MainWindow>();
    mainWindow->show();
    mNavi = std::make_unique<Navigator>(move(mainWindow));
    initNavigation();
    mNavi->start(PageType::LIBRARY, std::vector<QVariant>());
}

void MainControl::initNavigation()
{
    mNavi->registerPage(PageType::LIBRARY, std::make_unique<LibraryPageWidget>());
    mNavi->registerPage(PageType::VIEWER, std::make_unique<ViewerPageWidget>());
    mNavi->registerTransition(PageType::LIBRARY, LibraryPageWidget::EXIT_NEXT, PageType::VIEWER);
}
