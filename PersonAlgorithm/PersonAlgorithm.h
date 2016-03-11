#ifndef PERSONALGORITHM_H
#define PERSONALGORITHM_H

#include <memory>
#include "SearchAlgorithm.h"
#include "SearchQuery.h"

/**
 * The PersonAlgorithm implementation
 * @author Tung
 */

class PersonAlgorithm : public SearchAlgorithm {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.CoBaB.Algorithm" FILE "PersonAlgorithm.json")
    Q_INTERFACES(Algorithm)

public:

    PersonAlgorithm();

    bool setInputs(const QList<DataPacket*>& inputDataList) override;

    bool setParameters(const QJsonObject& parameters) override;

public slots:
    QList<DataPacket*> run() override;

    void cancel() override;

private:
    SearchQuery* mQuery;
    QList<int> mParameterList;
    bool mAborted;
    SearchObject mSearchObject;
};

#endif // PERSONALGORITHM_H
