#include "include/AlgorithmListTester.h"
#include <QTest>

void AlgorithmListTester::init()
{
    mAlgoList = std::make_unique<AlgorithmList>("../plugins");
}

void AlgorithmListTester::testLoadingOfAnyAlgorithm()
{
    QVERIFY(mAlgoList->getAlgorithmList().size() > 0);
}

void AlgorithmListTester::testLoadingOfTestAlgorithm()
{
    bool found = false;
    QList<Algorithm*> algos = mAlgoList->getAlgorithmList();
    for(Algorithm* algo : algos){
        if(algo->getName() == "Test algorithm")
            found = true;
    }
    if(!found)
        QFAIL("test algorithm not found");
}
