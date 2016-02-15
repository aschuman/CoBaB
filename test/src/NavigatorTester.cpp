#include "include/NavigatorTester.h"
#include <QTest>


void NavigatorTester::init()
{
    auto mainWnd = std::make_unique<MainWindow>();
    mMainWindow = mainWnd.get();
    mNavigator = std::make_unique<Navigator>(move(mainWnd));

    auto lib = std::make_unique<PageWidgetMock>();
    mLibraryMock = lib.get();
    mNavigator->registerPage(PageType::LIBRARY, move(lib));

    auto viewer = std::make_unique<PageWidgetMock>();
    mViewerMock = viewer.get();
    mNavigator->registerPage(PageType::VIEWER, move(viewer));

    auto parameters = std::make_unique<PageWidgetMock>();
    mParametersMock = parameters.get();
    mNavigator->registerPage(PageType::PARAMETER, move(parameters));

    mNavigator->registerTransition(PageType::LIBRARY, 0, PageType::VIEWER);
    mNavigator->registerTransition(PageType::LIBRARY, -1, PageType::PARAMETER);
    mNavigator->registerTransition(PageType::VIEWER, 0, PageType::PARAMETER);

    std::vector<QVariant> initialStack;
    initialStack.push_back(QVariant(123));
    initialStack.push_back("What is your major malfunction?");

    mNavigator->start(PageType::LIBRARY, initialStack);
}

void NavigatorTester::testInitialState()
{
    QCOMPARE(mLibraryMock->isReset(), true);
    QCOMPARE(mViewerMock->isReset(), false);
    QCOMPARE(mParametersMock->isReset(), false);
}

void NavigatorTester::testReadStackTop()
{
    QVariant item;
    mLibraryMock->emitRead(0, item);
    QCOMPARE(item.type(), QVariant::Type::String);
    QCOMPARE(item.toString(), QString("What is your major malfunction?"));
}

void NavigatorTester::testReadStackOutOfRange()
{
    QVariant item;
    mLibraryMock->emitRead(2, item);
    QCOMPARE(item.type(), QVariant::Type::Invalid);
}

void NavigatorTester::testReadStackSecondFromTop()
{
    QVariant item;
    mLibraryMock->emitRead(1, item);
    QCOMPARE(item.type(), QVariant::Type::Int);
    QCOMPARE(item.toInt(), 123);
}

void NavigatorTester::testLibraryViewerTransition()
{
    mLibraryMock->setReset(false);
    mLibraryMock->emitExit(0);
    QCOMPARE(mViewerMock->isReset(), true);
    QCOMPARE(mLibraryMock->isReset(), false);
}

void NavigatorTester::testPushToStack()
{
    mLibraryMock->emitPush(QVariant(3.141592));
    QVariant item;
    mLibraryMock->emitRead(0, item);
    QCOMPARE(item.type(), QVariant::Type::Double);
    QCOMPARE(item.toDouble(), 3.141592);
}

void NavigatorTester::testHomePage()
{
    mLibraryMock->setReset(false);
    mMainWindow->requestedHomePage();
    QCOMPARE(mLibraryMock->isReset(), true);
}

void NavigatorTester::testPreviousPage()
{
    mLibraryMock->setReset(false);
    mLibraryMock->emitExit(0);
    mMainWindow->requestedPreviousPage();
    QCOMPARE(mLibraryMock->isReset(), true);
}

void NavigatorTester::testRemainingInitialStackAfterReturnHome()
{
    mMainWindow->requestedHomePage();
    QVariant item;
    mLibraryMock->emitRead(1, item);
    QCOMPARE(item.type(), QVariant::Type::Int);
    QCOMPARE(item.toInt(), 123);
}

void NavigatorTester::testRemainingInitialStackAfterReturnBack()
{
    mMainWindow->requestedPreviousPage();
    QVariant item;
    mLibraryMock->emitRead(1, item);
    QCOMPARE(item.type(), QVariant::Type::Int);
    QCOMPARE(item.toInt(), 123);
}
