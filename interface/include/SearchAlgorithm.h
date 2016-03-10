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
    
    virtual void setName(const QString& name) = 0;

    virtual void setDescription(const QString& description) = 0;
    
    virtual bool supportsProgressInfo() = 0;

signals:
    void producedIntermediateResults(SearchResult& searchResult);
    
    void madeProgress(double progress, QString message);
};

#endif //_SEARCHALGORITHM_H
