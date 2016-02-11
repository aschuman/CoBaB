#include "Navigator.h"
#include <cassert>

#define LOGGING_LEVEL_1
#include "log.h"

Navigator::Navigator(std::unique_ptr<MainWindow> mainWindow) : mMainWindow(move(mainWindow))
{
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
    displayPage(type);
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
        value = mDataStack[mDataStack.size() - 1 - index];
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

void Navigator::displayPage(PageType type)
{
    LOG("displaying ", to_String(type), " page..");
    if(type == PageType::NONE){
        mMainWindow->display(nullptr);
    } else {
        auto itRegistration = mPageRegistrations.find(type);
        if(itRegistration != mPageRegistrations.end()){
            PageWidget& targetWidget = itRegistration->second.getWidget();
            targetWidget.reset();
            mMainWindow->display(&targetWidget);
            mPageStack.push(PageStackFrame(type));
        }else{
                // ToDo: write to log
        }
    }
}

PageType Navigator::getCurrentPageType() const
{
    return mPageStack.empty() ? PageType::NONE : mPageStack.top().getType();
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
