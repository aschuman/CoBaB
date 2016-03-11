#include "TestAlgorithm.h"

/**
 * @brief TestAlgorithm::TestAlgorithm create new algorithm with given ID
 * @param id algorithm ID
 */
TestAlgorithm::TestAlgorithm() {
    mId = "default";
    mName = "Test algorithm";
    mDescription = "dummy algorithm that scores randomly";
}

/**
 * @brief TestAlgorithm::run start the search
 * @return a list of data packets containing results
 */
QList<DataPacket*> TestAlgorithm::run() {
    QList<DataPacket*> list;
    SearchResult* result = new SearchResult();

    for (QString& datasetPath : mQuery->getDatasets()) {
        Dataset dataset(datasetPath);

        for (Medium* medium : dataset.getMediaList()) {
            SearchObject* object = new SearchObject();
            object->setMedium(medium->getPath());
            object->setSourceDataset(dataset.getPath());

            //new result element
            SearchResultElement* resultElement = new SearchResultElement();
            resultElement->setSearchObject(*object);
            resultElement->setScore(std::rand() % 20);

            //add to result list
            result->addResultElement(*resultElement);
        }
    }

    list.append(dynamic_cast<DataPacket*>(result));
    return list;
}

/**
 * @brief TestAlgorithm::cancel terminate the algorithm
 */
void TestAlgorithm::cancel() {

}

/**
 * @brief TestAlgorithm::setInputs set input for algorithm
 * @param inputDataList input data
 * @return true if input data is accepted
 */
bool TestAlgorithm::setInputs(const QList<DataPacket*>& inputDataList) {
    if (inputDataList.length() < 1) {  //illegal number of parameters
        return false;
    }

    DataPacket* packet = inputDataList.value(0);
    if (packet->getType() != DataPacket::Type::SEARCHQUERY) {   //invalid query
        return false;
    }

    mQuery = dynamic_cast<SearchQuery*>(packet);
    return true;
}

/**
 * @brief TestAlgorithm::setParameters set algorithm parameters
 * @param parameters the parameters
 * @return true if the algorithm accepts the parameters
 */
bool TestAlgorithm::setParameters(const QJsonObject& parameters) {
    Q_UNUSED(parameters);
    return true;
}

/**
 * @brief TestAlgorithm::supportsProgressInfo
 * @return true if progress information will be sent to application when the search runs
 */
bool TestAlgorithm::supportsProgressInfo() {
    return false;
}
