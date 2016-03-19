#ifndef ALGORITHMTHREAD_H
#define ALGORITHMTHREAD_H

#include <QThread>
#include "Algorithm.h"

/**
 * @brief Thread that runs an Algroithm and returns results after it finished.
 */
class AlgorithmThread : public QThread
{
    Q_OBJECT
public:
    explicit AlgorithmThread(Algorithm* algo);
    void run() override;
    QList<DataPacket*> getResults();


signals:
    /**
     * @brief Is send when the results are ready.
     */
    void resultsReady();

private:
    Algorithm* mAlgorithm;
    QList<DataPacket*> mResults;
};

#endif // ALGORITHMTHREAD_H
