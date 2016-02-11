#include "Navigator.h"
#include <cassert>

#define LOGGING_LEVEL_1
#include "log.h"

Navigator::Navigator(std::unique_ptr<MainWindow> mainWindow) : mMainWindow(move(mainWindow))
{
    QObject::connect(mMainWindow.get(), SIGNAL(requestedPreviousPage()), this, SLOT(toPreviousPage()));
    QObject::connect(mMainWindow.get(), SIGNAL(requestedHomePage()), this, SLOT(toHomePage()));
}

void Navigator::registerPage(PageType type, std::unique_ptr<PageWidget> widget)
{
    assert(type != PageType::NONE);
    QObject::connect(widget.get(), SIGNAL(pushToStack(QVariant)), this, SLOT(tryPush(QVariant)));
    QObject::connect(widget.get(), SIGNAL(readFromStack(size_t, QVariant&)), this, SLOT(tryRead(size_t,QVariant&)));
    QObject::connect(widget.get(), SIGNAL(exit(int)), this, SLOT(tryExit(int)));

    mPageRegistrations.insert(std::map<PageType, PageRegistration>::value_type(type, PageRegistration(move(widget))));
}

void Navigator::start(PageType type, std::vector<QVariant> data)
{
    mDataStack = move(data);
    mPageStack.push_back(PageStackFrame(type));
    tryDisplayTopPage();
}

void Navigator::tryPush(QVariant item)
{
    PageRegistration* registration = checkSender();
    if(registration){
        mDataStack.push_back(item);
        mPageStack.back().incrementSize();
    }
}

void Navigator::tryRead(size_t index, QVariant &value)
{
    PageRegistration* registration = checkSender();
    if(registration){
        if(mDataStack.size() > index)
            value = mDataStack[mDataStack.size() - 1 - index];
        else
            LOG_ERR("tried to read data stack out of range");
    }
}

void Navigator::tryExit(int exitCode)
{
    PageRegistration* registration = checkSender();
    if(registration){
        PageType targetType = registration->getTarget(exitCode);
        mPageStack.push_back(PageStackFrame(targetType));
        tryDisplayTopPage();
    }
}

void Navigator::toPreviousPage()
{
    LOG("going to previous page");
    mDataStack.resize(mDataStack.size() - mPageStack.back().getSize());
    mPageStack.pop_back();

    tryDisplayTopPage();
}

void Navigator::toHomePage()
{
    LOG("going to home page");
    for(int i=0; i < mPageStack.size() - 1; ++i)
        mPageStack.pop_back();
    mDataStack.resize(mPageStack.back().getSize());

    tryDisplayTopPage();
}

PageRegistration *Navigator::checkSender()
{
    auto itRegistration = mPageRegistrations.find(getCurrentPageType());
    PageRegistration* registration = nullptr;

    if(itRegistration != mPageRegistrations.end()){
        registration = &itRegistration->second;
        //PageWidget& widget = registration->getWidget();

        /*if(&widget != QObject::sender()){ ToDo: find out sender
            // ToDo: write to log
            registration = nullptr;
        }*/
    }
    return registration;
}

bool Navigator::tryDisplayTopPage()
{
    bool success = false;
    if(!mPageStack.empty()){
        PageType type = mPageStack.back().getType();

        LOG("displaying ", to_String(type), " page..");
        auto itRegistration = mPageRegistrations.find(type);
        if(itRegistration != mPageRegistrations.end()){
            PageWidget& targetWidget = itRegistration->second.getWidget();
            targetWidget.reset();
            mMainWindow->display(&targetWidget);
            success = true;
        }else{
            LOG_ERR("could not display unregistered page ", to_String(type));
        }
    }
    return success;
}

PageType Navigator::getCurrentPageType() const
{
    return mPageStack.empty() ? PageType::NONE : mPageStack.back().getType();
}

void Navigator::reducePageStack(size_t n)
{

}

void Navigator::registerTransition(PageType origin, int exitCode, PageType target)
{
    auto it = mPageRegistrations.find(origin);
    if(it != mPageRegistrations.end()){
        it->second.addTransition(exitCode, target);
    } else {
        LOG_ERR("could not register transition from unregistered page ", to_String(origin));
    }
}
