#ifndef _TESTALGORITHM_H
#define _TESTALGORITHM_H

#include <memory>
#include "SearchAlgorithm.h"

/**
 * The TestAlgorithm implementation
 * @author Tung
 */

class TestAlgorithm: public SearchAlgorithm {
public: 
    TestAlgorithm(QString id);
    
    QList<DataPacket*> run() override;
    
    void cancel();

    bool setInputs(QList<DataPacket> inputDataList);
     
    bool setParameters(QJsonObject parameters);

    void setName(QString name);

    void setDescription(QString description);

    QString getName() const;
    
    QString getDescription() const;
    
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
