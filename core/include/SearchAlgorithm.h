#ifndef _SEARCHALGORITHM_H
#define _SEARCHALGORITHM_H

#include "Algorithm.h"
#include "SearchResult.h"

/**
 * SearchAlgorithm interface
 * @author Tung
 */

class SearchAlgorithm: public Algorithm {
public: 
    
    virtual void setName(QString& name);
    
    virtual bool supportsProgressInfo();

    virtual void sendIntermediateResults(SearchResult& searchResult);
    
    virtual void sendProgress(double progress, QString message);
};

#endif //_SEARCHALGORITHM_H
