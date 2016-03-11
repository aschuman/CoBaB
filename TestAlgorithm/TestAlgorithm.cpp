#include "TestAlgorithm.h"

/**
 * @brief TestAlgorithm::TestAlgorithm create new algorithm with given ID
 * @param id algorithm ID
 */
TestAlgorithm::TestAlgorithm() {
    mId = "default";
    mName = "Test algorithm";
    mDescription = "dummy algorithm that scores randomly";
    mSupportProgressInfo = false;
    mAborted = false;
}

/**
 * @brief TestAlgorithm::run start the search
 * @return a list of data packets containing results
 */
QList<DataPacket*> TestAlgorithm::run() {
    QList<DataPacket*> list;
    SearchResult* result = new SearchResult();
    list.append(dynamic_cast<DataPacket*>(result));

    for (QString& datasetPath : mQuery->getDatasets()) {
        Dataset dataset(datasetPath);

        for (Medium* medium : dataset.getMediaList()) {
            if (mAborted == true) {
                return list;
            }

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

    return list;
}

/**
 * @brief TestAlgorithm::cancel terminate the algorithm
 */
void TestAlgorithm::cancel() {
    mAborted = true;
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
 * @brief TestAlgorithm::initialize Loads the corresponding QJsonObject for this algorithm
 * @param loader The plugin loader which loads the QJsonObject
 */
void TestAlgorithm::initialize(QPluginLoader *loader) {
    mParameters = loader->metaData().value("MetaData").toObject();
}

/**
 * @brief TestAlgorithm::getParameterJson Returns the parameter file for this algorithm
 * @return The QJsonObject parameter file for this algorithm
 */
QJsonObject TestAlgorithm::getParameterJson() {
    return mParameters;
}
