#include "TestAlgorithmTester.h"

TestAlgorithm algo("testAlgo");

void TestAlgorithmTester::initTest() {

}

void TestAlgorithmTester::testGetters() {
    QCOMPARE(algo.getId(), (QString)"testAlgo");
    QCOMPARE(algo.getName(), (QString)"Test algorithm");
    QCOMPARE(algo.getDescription(), (QString)"dummy algorithm that scores randomly");
}

void TestAlgorithmTester::testSetInputs() {

}

void TestAlgorithmTester::testSetParameters() {

}

void TestAlgorithmTester::testRun() {

}
