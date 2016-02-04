#ifndef PAGEREGISTRATIONTESTER_H
#define PAGEREGISTRATIONTESTER_H

#include <memory>
#include <QObject>
#include <PageRegistration.h>

class PageRegistrationTester : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testGetTransition0();
    void testGetTransitionNeg2();
    void testGetTransition32();
    void testGetNonExistingTransition();

private:
    std::unique_ptr<PageRegistration> mPageRegistration;
};

#endif // PAGEREGISTRATIONTESTER_H
