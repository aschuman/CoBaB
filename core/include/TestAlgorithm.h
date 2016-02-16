/**
 * Project \
 */


#ifndef _TESTALGORITHM_H
#define _TESTALGORITHM_H

#include <memory>
#include "SearchAlgorithm.h"

class TestAlgorithm: public SearchAlgorithm {
public: 
    
    TestAlgorithm(QString id);
    
    QList<DataPacket> run() override;
    
    void cancel();

    bool setInputs(QList<DataPacket> inputDataList);
     
    bool setParameters(QJsonObject parameters);
    
    QString getDescription();

    void setDescription(QString description);
    
    QString getName();

    void setName(QString name);
    
    bool supportsProgressInfo();
    
    void sendIntermediateResults(SearchResult searchResult);

    void sendProgress(double progress, QString message);

private: 
    std::unique_ptr<DataPacket> mInputData;
    QString mDescription;
    QList<int> mParameterList;
    QString mName;
    QString mId;
};

#endif //_TESTALGORITHM_H
