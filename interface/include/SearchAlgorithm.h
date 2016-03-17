#ifndef _SEARCHALGORITHM_H
#define _SEARCHALGORITHM_H

#include "Algorithm.h"
#include "SearchResult.h"

/**
 * @brief SearchAlgorithm The implementation of this interface allows CoBaB to show detailed information about the algorithm.
 * @author Tung
 */

class SearchAlgorithm: public Algorithm {
    Q_OBJECT
public:
    
    virtual bool supportsProgressInfo();

signals:
    /**
     * @brief producedIntermediateResults Is send when the algorithm produced intermediate results.
     * @param searchResult The intermediate result.
     */
    void producedIntermediateResults(SearchResult& searchResult);
    
    /**
     * @brief madeProgress Is send when the algorithm made progress.
     * @param progress
     * @param message
     */
    void madeProgress(double progress, QString message="");

protected:
    bool mSupportProgressInfo = false;      ///< indicates whether progress information will be sent to application when the search runs

};

#endif //_SEARCHALGORITHM_H
