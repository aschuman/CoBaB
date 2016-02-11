#ifndef NAVIGATORTESTER_H
#define NAVIGATORTESTER_H

#include <memory>
#include <QObject>
#include "Navigator.h"
#include "PageWidgetMock.h"


class NavigatorTester : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testInitialState();
    void testReadStackTop();
    void testReadStackOutOfRange();
    void testReadStackSecondFromTop();
    void testLibraryViewerTransition();
    void testPushToStack();
    void testHomePage();
    void testPreviousPage();

private:
    std::unique_ptr<Navigator> mNavigator;

    MainWindow* mMainWindow;

    PageWidgetMock* mLibraryMock;
    PageWidgetMock* mViewerMock;
    PageWidgetMock* mParametersMock;
};

#endif // NAVIGATORTESTER_H
