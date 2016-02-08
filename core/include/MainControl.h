#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <memory>
#include<qobject.h>
#include "Navigator.h"


class MainControl : public QObject
{
    Q_OBJECT

public:
    MainControl();

public slots:
    void run();

signals:
    void finished();

private:
    void initNavigation();


    std::unique_ptr<Navigator> mNavi;
};

#endif // MAINCONTROL_H
