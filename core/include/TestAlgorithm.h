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
    TestAlgorithm(QString& id);
    
    QList<DataPacket*> run() override;
    
    void cancel() override;

    bool setInputs(QList<DataPacket*>& inputDataList);
     
    bool setParameters(QJsonObject& parameters) override;

    void setName(QString& name) override;

    void setDescription(QString& description);

    QString getName() const override;

    QString getDescription() const override;
    
    bool supportsProgressInfo() override;
    
    void sendIntermediateResults(SearchResult& searchResult) override;

    void sendProgress(double progress, QString message) override;

private: 
    std::unique_ptr<DataPacket> mInputData;
    QString mDescription;
    QList<int> mParameterList;
    QString mName;
    QString mId;
};

#endif //_TESTALGORITHM_H
