#include "include/PageRegistrationTester.h"
#include <QtTest>
#include "PageWidgetMock.h"

void PageRegistrationTester::init()
{
    std::unique_ptr<PageWidget> widget = std::make_unique<PageWidgetMock>();
    mPageRegistration = std::make_unique<PageRegistration>(move(widget));
    mPageRegistration->addTransition(0, PageType::CONFIRMATION);
    mPageRegistration->addTransition(-2, PageType::PHOTO_VIEWER);
    mPageRegistration->addTransition(1, PageType::LIBRARY);
    mPageRegistration->addTransition(32, PageType::NONE);
}

void PageRegistrationTester::testGetTransition0()
{
    QCOMPARE(mPageRegistration->getTarget(0).type, PageType::CONFIRMATION);
}

void PageRegistrationTester::testGetTransitionNeg2()
{
    QCOMPARE(mPageRegistration->getTarget(-2).type, PageType::PHOTO_VIEWER);
}

void PageRegistrationTester::testGetTransition32()
{
    QCOMPARE(mPageRegistration->getTarget(32).type, PageType::NONE);
}

void PageRegistrationTester::testGetNonExistingTransition()
{
    QCOMPARE(mPageRegistration->getTarget(144).type, PageType::NONE);
}
