#include "include/AlgorithmThread.h"

/**
 * @brief Constructs an AlgorithmThread with the given Algorithm.
 * @param The Algorithm that will be startet on call to run.
 */
AlgorithmThread::AlgorithmThread(Algorithm *algo) : mAlgorithm(algo)
{
}

/**
 * @brief Runs the algorithm.
 */
void AlgorithmThread::run()
{
    mResults = mAlgorithm->run();
    emit resultsReady();
}

QList<DataPacket *> AlgorithmThread::getResults()
{
    return mResults;
}
