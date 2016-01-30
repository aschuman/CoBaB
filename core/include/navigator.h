#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <memory>
#include <map>
#include <vector>
#include <stack>
#include <qvariant.h>
#include <mainwindow.h>
#include <pagestackframe.h>
#include <pageregistration.h>


class Navigator
{
public:
    Navigator(std::unique_ptr<MainWindow> mainWindow);
    void registerPage(PageType type, std::unique_ptr<PageWidget> widget);
    void registerTransition(PageType origin, int exitCode, PageType target);
    void start(PageType type, QList<QVariant> data);

private slots:
    void tryPush(QVariant item);
    void tryRead(size_t index, QVariant& value);
    void tryExit(int exitCode);

private:
    PageRegistration* checkSender();
    void displayPage(PageType type);
    PageType getCurrentPageType() const;

    std::stack<PageStackFrame> mPageStack;
    std::vector<QVariant> mDataStack;
    std::map<PageType, PageRegistration> mPageRegistrations;
    std::unique_ptr<MainWindow> mMainWindow;


};

#endif // NAVIGATOR_H
