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
    
    QString getDescription() const;
    
    QString getName() const;

    void setName(QString name);
    
    bool supportsProgressInfo();

    void sendIntermediateResults(SearchResult searchResult);
    
    void sendProgress(double progress, QString message);
};

#endif //_SEARCHALGORITHM_H
