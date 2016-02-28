#ifndef _TESTALGORITHM_H
#define _TESTALGORITHM_H

#include <memory>
#include "SearchAlgorithm.h"
#include "SearchQuery.h"

/**
 * The TestAlgorithm implementation
 * @author Tung
 */

class TestAlgorithm : public QObject, public SearchAlgorithm {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.CoBaC.Algorithm" "testalgorithm.json")
    Q_INTERFACES(Algorithm)

public:

    TestAlgorithm(const QString& id = "default");
    
    QList<DataPacket*> run() override;
    
    void cancel() override;

    bool setInputs(const QList<DataPacket*>& inputDataList) override;
     
    bool setParameters(const QJsonObject& parameters) override;

    void setName(const QString& name) override;

    void setDescription(const QString& description) override;

    QString getId() const override;

    QString getName() const override;

    QString getDescription() const override;
    
    bool supportsProgressInfo() override;
    
    void sendIntermediateResults(SearchResult& searchResult) override;

    void sendProgress(double progress, QString message) override;

private: 
    SearchQuery mQuery;
    QString mDescription;
    QList<int> mParameterList;
    QString mName;
    QString mId;
};

#endif //_TESTALGORITHM_H
