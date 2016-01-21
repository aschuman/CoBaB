/**
 * Project \
 */


#ifndef _TESTALGORITHM_H
#define _TESTALGORITHM_H

#include "SearchAlgorithm.h"


class TestAlgorithm: public SearchAlgorithm {
public: 
    
    void TestAlgorithm();
    
    QList<DataPacket> run();
    
    void cancel();
    
    /**
     * @param inputDataList
     */
    bool setInputs(QList<DataPacket> inputDataList);
    
    /**
     * @param parameters
     */
    bool setParameters(QJsonObject parameters);
    
    QString getDescription();
    
    /**
     * @param description
     */
    void setDescription(QString description);
    
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
private: 
    DataPacket mInputData;
    QString mDescription;
    QList<int> mParameterList;
    QString mName;
};

#endif //_TESTALGORITHM_H