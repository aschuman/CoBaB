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
    AlgorithmThread(Algorithm* algo);
    void run() override;
    QList<DataPacket*> getResults();


signals:
    void resultsReady();

private:
    Algorithm* mAlgorithm;
    QList<DataPacket*> mResults;
};

#endif // ALGORITHMTHREAD_H
