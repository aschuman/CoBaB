#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include<qobject.h>


class MainControl : public QObject
{
    Q_OBJECT

public slots:
    void run();

signals:
    void finished();

private:
    void initNavigation();
};

#endif // MAINCONTROL_H
