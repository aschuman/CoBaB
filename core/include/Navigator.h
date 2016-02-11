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


class Navigator : public QObject
{
    Q_OBJECT
public:
    Navigator(std::unique_ptr<MainWindow> mainWindow);
    void registerPage(PageType type, std::unique_ptr<PageWidget> widget);
    void registerTransition(PageType origin, int exitCode, PageType target);
    void start(PageType type, std::vector<QVariant> data);

signals:
    void finished();

private slots:
    void tryPush(QVariant item);
    void tryRead(size_t index, QVariant& value);
    void tryExit(int exitCode);
    void toPreviousPage();
    void toHomePage();

private:
    PageRegistration* checkSender();
    bool tryDisplayTopPage();
    PageType getCurrentPageType() const;
    void reducePageStack(size_t n);

    std::unique_ptr<MainWindow> mMainWindow;
    std::vector<PageStackFrame> mPageStack;
    std::vector<QVariant> mDataStack;
    std::map<PageType, PageRegistration> mPageRegistrations;
};

#endif // NAVIGATOR_H
