#include "Navigator.h"
#include <cassert>

#define LOGGING_LEVEL_1
#include "log.h"

/**
 * @brief Consturcts the Navigator and connects it to mainWindow.
 * @param mainWindow MainWindow in which the Navigator will display PageWidgets.
 */
Navigator::Navigator(std::unique_ptr<MainWindow> mainWindow)
    : mMainWindow(move(mainWindow)),
      mInitialStackSize(0)
{
    QObject::connect(mMainWindow.get(), SIGNAL(requestedPreviousPage()), this, SLOT(toPreviousPage()));
    QObject::connect(mMainWindow.get(), SIGNAL(requestedHomePage()), this, SLOT(toHomePage()));
}

/**
 * @brief Enables a PageWidget to be inserted into the respective MainWindow by this Navigator.
 * @param type Type that will identify the PageWidget. Can not be PageWidget::None.
 *          An already registered Type will be overridden by this registration.
 * @param widget PageWidget that will be registered.
 */
void Navigator::registerPage(PageType type, std::unique_ptr<PageWidget> widget)
{
    assert(type != PageType::NONE);
    QObject::connect(widget.get(), SIGNAL(pushToStack(QVariant)), this, SLOT(tryPush(QVariant)));
    QObject::connect(widget.get(), SIGNAL(readFromStack(int, QVariant&)), this, SLOT(tryRead(int,QVariant&)));
    QObject::connect(widget.get(), SIGNAL(exit(int)), this, SLOT(tryExit(int)));

    mPageRegistrations.insert(std::map<PageType, PageRegistration>::value_type(type, PageRegistration(move(widget))));
}

/**
 * @brief Starts the Navigation.
 * @param type First page that will be registered.
 * @param data Initial data stack.
 */
void Navigator::start(PageType type, std::vector<QVariant> data)
{
    mInitialStackSize = data.size();
    mDataStack = move(data);
    mPageStack.push_back(PageStackFrame(type));
    tryDisplayTopPage();
}

/**
 * @brief Pushes to data stack.
 * @param item Value to be pushed to the stack
 */
void Navigator::tryPush(QVariant item)
{
    PageRegistration* registration = checkSender();
    if(registration){
        mDataStack.push_back(item);
        mPageStack.back().incrementSize();
    }
}

/**
 * @brief Reads from data stack.
 * @param index Position to be read from. (0 referes to the top of te stack)
 * @param value Reference to a valid QVariant object that will be equipped with the desired stack element.
 */
void Navigator::tryRead(int index, QVariant &value)
{
    PageRegistration* registration = checkSender();
    if(registration){
        if(index >= 0)
            index = mDataStack.size() - 1 - index;
        else
            index = -index - 1;

        if(index < mDataStack.size())
            value = mDataStack[index];
        else
            LOG_ERR("tried to read data stack out of range");
    }
}

/**
 * @brief Lets the current page exit and displays its successor
 *          according to the exit code and the registered transitions.
 * @param exitCode Arbitrary exit code.
 */
void Navigator::tryExit(int exitCode)
{
    PageRegistration* registration = checkSender();
    if(registration){
        PageType targetType = registration->getTarget(exitCode);
        mPageStack.push_back(PageStackFrame(targetType));
        tryDisplayTopPage();
    }
}

/**
 * @brief Returns to the previously displayed page
 *          and removes the elements from the data stack the current page has pushed.
 */
void Navigator::toPreviousPage()
{
    if(mPageStack.size() > 1){
        LOG("going to previous page");
        mDataStack.resize(mDataStack.size() - mPageStack.back().getSize());
        mPageStack.pop_back();
        mDataStack.resize(mDataStack.size() - mPageStack.back().getSize());
        mPageStack.back().setSize(0);

        tryDisplayTopPage();
    }
}

/**
 * @brief Returns to the initial page given by Navigator::start.
 *          Clears the data stack except the initial elements given by Navigator::start
 *          and elements added by the initial page.
 */
void Navigator::toHomePage()
{
    LOG("going to home page");
    mPageStack.resize(1);
    mDataStack.resize(mInitialStackSize);
    mPageStack.back().setSize(0);

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

/**
 * @brief Registers a transition. If during navigation origin exits with exitCode,
 *          target will be displayed.
 * @param origin PageWidget that during navigation has to be displayed for this transition to take effect.
 * @param exitCode Exit code that has to be emmited by origin for this transition to take effect.
 * @param target PageWidget that will be displayed as effect of this transition.
 */
void Navigator::registerTransition(PageType origin, int exitCode, PageType target)
{
    auto it = mPageRegistrations.find(origin);
    if(it != mPageRegistrations.end()){
        it->second.addTransition(exitCode, target);
    } else {
        LOG_ERR("could not register transition from unregistered page ", to_String(origin));
    }
}
