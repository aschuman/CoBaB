#ifndef _TESTALGORITHM_H
#define _TESTALGORITHM_H

#include <memory>
#include "SearchAlgorithm.h"
#include "SearchQuery.h"

/**
 * The TestAlgorithm implementation
 * @author Tung
 */

class TestAlgorithm : public SearchAlgorithm {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.CoBaB.Algorithm" FILE "TestAlgorithm.json")
    Q_INTERFACES(Algorithm)

public:

    TestAlgorithm();

    bool setInputs(const QList<DataPacket*>& inputDataList) override;

public slots:
    QList<DataPacket*> run() override;

private: 
    SearchQuery* mQuery;
    QList<int> mParameterList;
};

#endif //_TESTALGORITHM_H
