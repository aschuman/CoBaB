#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <memory>
#include <map>
#include <vector>
#include <stack>
#include <qvariant.h>
#include "MainWindow.h"
#include "PageStackFrame.h"
#include "PageRegistration.h"

/**
 * @brief The Navigator decides which PageWidget will be displayed in the MainWindow.
 *
 * It contains PageWidgets and information on to which PageWidget will be transitioned in case a PageWidget exits
 * taking account of the current PageWidget and the its exitCode.
 * It also contains data that is needed to be shared by PageWidgets (i.e. produced by one PageWidget, used by another).
 * PageWidgets and data are organized as a stack.
 *
 * @author Vincent Winkler
 */
class Navigator : public QObject
{
    Q_OBJECT
public:
    Navigator(std::unique_ptr<MainWindow> mainWindow);
    void registerPage(PageType type, std::unique_ptr<PageWidget> widget);
    void registerTransition(PageType origin, int exitCode, PageType target, bool noReturn = false);
    void start(PageType type, std::vector<QVariant> data);

signals:
    /**
     * @brief Emitted when this Navigator has no pages left to display.
     */
    void finished();

private slots:
    void tryPush(QVariant item);
    void tryRead(int index, QVariant& value);
    void tryExit(int exitCode);
    void toPreviousPage();
    void toHomePage();

private:
    PageRegistration* checkSender();
    bool tryDisplayTopPage();
    PageType getCurrentPageType() const;

    std::unique_ptr<MainWindow> mMainWindow;
    std::vector<PageStackFrame> mPageStack;
    std::vector<QVariant> mDataStack;
    size_t mInitialStackSize;
    std::map<PageType, PageRegistration> mPageRegistrations;
};

#endif // NAVIGATOR_H
