#ifndef ALGORITHMLISTTESTER_H
#define ALGORITHMLISTTESTER_H

#include <memory>
#include <QObject>
#include <AlgorithmList.h>

class AlgorithmListTester : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testLoadingOfAnyAlgorithm();
    void testLoadingOfTestAlgorithm();

private:
    std::unique_ptr<AlgorithmList> mAlgoList;
};

#endif // ALGORITHMLISTTESTER_H
