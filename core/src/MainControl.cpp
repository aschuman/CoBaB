#include "MainControl.h"

#include <QDir>
#include "MainWindow.h"
#include "LibraryPageWidget.h"
#include "ViewerPageWidget.h"
#include "ConfirmationPageWidget.h"

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

    QVariant dsList;
    dsList.setValue(std::make_shared<DatasetList>(findDatasets()));

    std::vector<QVariant> initialStack;
    initialStack.push_back(dsList);
    mNavi->start(PageType::LIBRARY, initialStack);
}

void MainControl::initNavigation()
{
    mNavi->registerPage(PageType::LIBRARY, std::make_unique<LibraryPageWidget>());
    mNavi->registerPage(PageType::VIEWER, std::make_unique<ViewerPageWidget>());
    mNavi->registerTransition(PageType::LIBRARY, LibraryPageWidget::EXIT_NEXT, PageType::VIEWER);
    mNavi->registerPage(PageType::CONFIRMATION, std::make_unique<ConfirmationPageWidget>());
    mNavi->registerTransition(PageType::CONFIRMATION, ConfirmationPageWidget::EXIT_NEXT, PageType::RESULTS);
}

DatasetList MainControl::findDatasets() const
{
    DatasetList list;
    QDir dir("../test/testdata");
    for(const QFileInfo& file : dir.entryInfoList(QDir::Filter::Dirs|QDir::Filter::NoDotAndDotDot)){
        list.addDataset(Dataset(file.absoluteFilePath()));
        //list.addDataset(Dataset("../test/testdata/SingleFrameVideo"));
        //list.addDataset(Dataset("../test/testdata/Video"));
        //list.addDataset(Dataset("../test/testdata/Fotos"));
    }
    return list;
}
