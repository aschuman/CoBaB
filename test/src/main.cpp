#include <QtTest/QTest>

#include "PageStackframeTester.h"
#include "PageRegistrationTester.h"
#include "NavigatorTester.h"
#include "SingleFrameVideoTester.h"
#include "DatasetTester.h"
#include "DatasetListTester.h"
#include "ConfigDataTester.h"

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

    EXEC(SingleFrameVideoTester)
    EXEC(DatasetTester)
    EXEC(DatasetListTester)
    EXEC(ConfigDataTester)

    return r;
}
