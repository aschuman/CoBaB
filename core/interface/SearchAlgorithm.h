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
    
    virtual void setName(const QString& name) = 0;

    virtual void setDescription(const QString& description) = 0;
    
    virtual bool supportsProgressInfo() = 0;

    virtual void sendIntermediateResults(SearchResult& searchResult) = 0;
    
    virtual void sendProgress(double progress, QString message) = 0;
};

#endif //_SEARCHALGORITHM_H
