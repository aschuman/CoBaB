/**
 * Project \
 */


#ifndef _SEARCHALGORITHM_H
#define _SEARCHALGORITHM_H

#include "Algorithm.h"


class SearchAlgorithm: public Algorithm {
public: 
    
    QString getDescription();
    
    QString getName();
    
    /**
     * @param name
     */
    void setName(QString name);
    
    bool supportsProgressInfo();
    
    /**
     * @param searchResult
     */
    void sendIntermediateResults(SearchResult searchResult);
    
    /**
     * @param progress
     * @param message
     */
    void sendProgress(double progress, QString message);
};

#endif //_SEARCHALGORITHM_H
