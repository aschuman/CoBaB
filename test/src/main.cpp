#include <QtTest/QTest>

#define EXEC(Tester) {Tester tester; r |= QTest::qExec(&tester);}

int main(){
    int r = 0;

    // add test class 'ExampleTester' like this
    // (do not forget to include header):
    // EXEC(ExampleTester)

    return r;
}
