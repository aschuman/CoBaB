/**
 * Project \
 */


#ifndef _SEARCHALGORITHM_H
#define _SEARCHALGORITHM_H

#include "Algorithm.h"
#include "SearchResult.h"

class SearchAlgorithm: public Algorithm {
public: 
    
    QString getDescription();
    
    QString getName();

    void setName(QString name);
    
    bool supportsProgressInfo();

    void sendIntermediateResults(SearchResult searchResult);
    
    void sendProgress(double progress, QString message);
};

#endif //_SEARCHALGORITHM_H
