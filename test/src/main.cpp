#include <QtTest/QTest>

#include "pagestackframetester.h"
#include "pageregistrationtester.h"
#include "navigatortester.h"

#define EXEC(Tester) {Tester tester; r |= QTest::qExec(&tester);}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    int r = 0;

    // add test class 'ExampleTester' like this
    // (do not forget to include header):
    // EXEC(ExampleTester)

    EXEC(PageStackFrameTester)
    EXEC(PageRegistrationTester)
    EXEC(NavigatorTester)

    return r;
}
