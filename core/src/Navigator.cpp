#include "include/Navigator.h"
#include <cassert>

Navigator::Navigator(std::unique_ptr<MainWindow> mainWindow) : mMainWindow(move(mainWindow))
{
}

void Navigator::registerPage(PageType type, std::unique_ptr<PageWidget> widget)
{
    QObject::connect((PageWidget*)widget.get(), SIGNAL(pushToStack(QVariant)), this, SLOT(tryPush(QVariant)));
    QObject::connect((PageWidget*)widget.get(), SIGNAL(readFromStack(size_t, QVariant&)), this, SLOT(tryRead(size_t,QVariant&)));
    QObject::connect((PageWidget*)widget.get(), SIGNAL(exit(int)), this, SLOT(tryExit(int)));

    mPageRegistrations.insert(std::map<PageType, PageRegistration>::value_type(type, PageRegistration(move(widget))));
}

void Navigator::start(PageType type, QList<QVariant> data)
{
    for(QVariant& datum : data){
        mDataStack.push_back(datum);
        displayPage(type);
    }
}

void Navigator::tryPush(QVariant item)
{
    PageRegistration* registration = checkSender();
    if(registration){
        mDataStack.push_back(item);
    }
}

void Navigator::tryRead(size_t index, QVariant &value)
{
    PageRegistration* registration = checkSender();
    if(registration){
        value = mDataStack[index];
    }
}

void Navigator::tryExit(int exitCode)
{
    PageRegistration* registration = checkSender();
    if(registration){
        PageType targetType = registration->getTarget(exitCode);
        displayPage(targetType);
    }
}

PageRegistration *Navigator::checkSender()
{
    auto itRegistration = mPageRegistrations.find(getCurrentPageType());
    assert(itRegistration != mPageRegistrations.end());
    PageRegistration& registration = itRegistration->second;
    //PageWidget& widget = registration->getWidget();

    bool fail = false;
    /*if(&widget != QObject::sender()){ ToDo: find out sender
        // ToDo: write to log
        fail = true;
    }*/
    return fail ? nullptr : &registration;
}

void Navigator::displayPage(PageType type)
{
    auto itRegistration = mPageRegistrations.find(type);
    if(itRegistration != mPageRegistrations.end()){
        PageWidget& targetWidget = itRegistration->second.getWidget();
        targetWidget.reset();
        mMainWindow->setCentralWidget(&targetWidget);
        mPageStack.push(PageStackFrame(type));
    }else{
            // ToDo: write to log
    }
}

PageType Navigator::getCurrentPageType() const
{
    return mPageStack.top().getType();
}

void Navigator::registerTransition(PageType origin, int exitCode, PageType target)
{
    auto it = mPageRegistrations.find(origin);
    if(it != mPageRegistrations.end()){
        it->second.addTransition(exitCode, target);
    } else {
        // ToDo: write to log
    }
}
