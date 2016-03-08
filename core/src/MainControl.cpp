#include "MainControl.h"

#include <QDir>
#include "MainWindow.h"
#include "LibraryPageWidget.h"
#include "ViewerPageWidget.h"
#include "PhotoViewer.h"
#include "SingleFrameVideoViewer.h"
#include "ConfirmationPageWidget.h"
#include "ParameterPageWidget.h"
#include "ResultsPageWidget.h"
#include "AlgorithmList.h"
#include "Configuration.h"

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


    std::vector<QVariant> initialStack;

    QVariant algoList;
    algoList.setValue(std::make_shared<AlgorithmList>("../plugins"));
    initialStack.push_back(algoList);

    QVariant dsList;
    dsList.setValue(std::make_shared<DatasetList>(findDatasets()));
    initialStack.push_back(dsList);

    mNavi->start(PageType::LIBRARY, initialStack);
}

void MainControl::initNavigation()
{
    mNavi->registerPage(PageType::LIBRARY, std::make_unique<LibraryPageWidget>());

    mNavi->registerPage(PageType::PHOTO_VIEWER, std::make_unique<PhotoViewer>());
    mNavi->registerTransition(PageType::LIBRARY, LibraryPageWidget::EXIT_PHOTO, PageType::PHOTO_VIEWER);

    mNavi->registerPage(PageType::SINGLE_FRAME_VIDEO_VIEWER, std::make_unique<SingleFrameVideoViewer>());
    mNavi->registerTransition(PageType::LIBRARY, LibraryPageWidget::EXIT_SINGLE_FRAME_VIDEO, PageType::SINGLE_FRAME_VIDEO_VIEWER);

    mNavi->registerPage(PageType::PARAMETER, std::make_unique<ParameterPageWidget>());
    mNavi->registerTransition(PageType::PHOTO_VIEWER, ViewerPageWidget::EXIT_NEXT, PageType::PARAMETER);
    mNavi->registerTransition(PageType::SINGLE_FRAME_VIDEO_VIEWER, ViewerPageWidget::EXIT_NEXT, PageType::PARAMETER);

    mNavi->registerPage(PageType::CONFIRMATION, std::make_unique<ConfirmationPageWidget>());
    mNavi->registerTransition(PageType::PARAMETER, ParameterPageWidget::EXIT_NEXT, PageType::CONFIRMATION);

    auto resultsPageWidget = std::make_unique<ResultsPageWidget>();
    mSearchManager = std::make_unique<SearchManager>(resultsPageWidget.get());
    mNavi->registerPage(PageType::RESULTS, move(resultsPageWidget));
    mNavi->registerTransition(PageType::CONFIRMATION, ConfirmationPageWidget::EXIT_NEXT, PageType::RESULTS);

    mNavi->registerTransition(PageType::RESULTS, ResultsPageWidget::EXIT_NEW_SEARCH, PageType::PARAMETER);
}

DatasetList MainControl::findDatasets() const
{
    QCommandLineParser parser;
    parser.addPositionalArgument("standard directory", "The directory with the standard datasets.");
    parser.process(*qApp);

    DatasetList list;
    list.load(DATASET_HISTORY_FILE);
    if(parser.positionalArguments().size() == 0) {
        return list; // no standard directory set
    }
    QDir dir(parser.positionalArguments().at(0));
    //QDir dir("../test/testdata");
    for(const QFileInfo& file : dir.entryInfoList(QDir::Filter::Dirs|QDir::Filter::NoDotAndDotDot)){
        Dataset dataset(file.absoluteFilePath());
        if(dataset.isValid()) {
            list.addDataset(dataset);
        }
    }
    return list;
}
