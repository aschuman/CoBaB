#ifndef _SEARCHALGORITHM_H
#define _SEARCHALGORITHM_H

#include "Algorithm.h"
#include "SearchResult.h"

/**
 * SearchAlgorithm interface
 * @author Tung
 */

class SearchAlgorithm: public Algorithm {
    Q_OBJECT
public:
    
    virtual bool supportsProgressInfo();

signals:
    void producedIntermediateResults(SearchResult& searchResult);
    
    void madeProgress(double progress, QString message);

protected:
    bool mSupportProgressInfo = false;

};

#endif //_SEARCHALGORITHM_H
