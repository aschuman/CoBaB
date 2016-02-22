#include <QtTest/QTest>

#include "PageStackframeTester.h"
#include "PageRegistrationTester.h"
#include "NavigatorTester.h"
#include "SingleFrameVideoTester.h"
#include "DatasetTester.h"
#include "DatasetListTester.h"
#include "ConfigDataTester.h"
#include "DataPacketTester.h"
#include "SearchObjectTester.h"
#include "SearchQueryTester.h"
#include "SearchResultElementTester.h"
#include "SearchResultTester.h"
#include "AnnotationTester.h"
#include "RectangleAnnotationTester.h"
#include "SearchFeedbackTester.h"
#include "BookmarkTester.h"
#include "BookmarkListTester.h"
#include "TestAlgorithmTester.h"

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

    EXEC(DataPacketTester)
    EXEC(SearchObjectTester)
    EXEC(SearchQueryTester)
    EXEC(SearchResultElementTester)
    EXEC(SearchResultTester)

    EXEC(AnnotationTester)
    EXEC(RectangleAnnotationTester)
    EXEC(SearchFeedbackTester)
    EXEC(BookmarkTester)
    EXEC(BookmarkListTester)
    EXEC(TestAlgorithmTester)

    return r;
}
