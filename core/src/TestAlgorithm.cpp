#include "TestAlgorithm.h"

/**
 * @brief TestAlgorithm::TestAlgorithm create new algorithm with given ID
 * @param id algorithm ID
 */
TestAlgorithm::TestAlgorithm(const QString& id) {
	mId = id;
    mName = "Test algorithm";
    mDescription = "an dummy algorithm that scores randomly";
}

/**
 * @brief TestAlgorithm::run start the search
 * @return a list of data packets containing results
 */
QList<DataPacket*> TestAlgorithm::run() {
    QList<DataPacket*> list;
    SearchResult* result = new SearchResult();

    for (QString& datasetPath : mQuery.getDatasets()) {
        Dataset dataset(datasetPath);

        for (Medium* medium : dataset.getMediaList()) {
            SearchObject* object = new SearchObject();
            object->setMedium(medium->getPath());

            //new result element
            SearchResultElement* resultElement = new SearchResultElement();
            resultElement->setSearchObject(*object);
            resultElement->setScore(std::rand() % 20);

            //add to result list
            result->addResultElement(*resultElement);
        }
    }

    list.append((DataPacket*)result);
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
    if (inputDataList.length() != 1) {  //illegal number of parameters
        return false;
    }

    DataPacket* packet = inputDataList.value(0);
    if (packet->getType() != DataPacket::Type::SEARCHQUERY) {   //invalid query
        return false;
    }

    mQuery = *(SearchQuery*)packet;
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
 * @brief TestAlgorithm::setName give the algorithm a new name
 * @param name new name
 */
void TestAlgorithm::setName(const QString& name) {
    mName = name;
}

/**
 * @brief TestAlgorithm::setDescription set algorithm description
 * @param description a text which explains what the algorith does
 */
void TestAlgorithm::setDescription(const QString& description) {
    mDescription = description;
}

/**
 * @brief TestAlgorithm::getDescription show algorithm description
 * @return a QString that describes the algorithm
 */
QString TestAlgorithm::getDescription() const {
    return mDescription;
}

/**
 * @brief TestAlgorithm::getName get name of the algorithm
 * @return algorithm name (must be unique)
 */
QString TestAlgorithm::getName() const {
    return mName;
}

/**
 * @brief TestAlgorithm::supportsProgressInfo
 * @return true if progress information will be sent to application when the search runs
 */
bool TestAlgorithm::supportsProgressInfo() {
    return false;
}

/**
 * @brief TestAlgorithm::sendIntermediateResults send a number of new search results
 * @param searchResult new output
 */
void TestAlgorithm::sendIntermediateResults(SearchResult& searchResult) {
    Q_UNUSED(searchResult);
}

/**
 * @brief TestAlgorithm::sendProgress send progress information
 * @param progress a real number between 0 and 1 show the progress
 * @param message warning message if available
 */
void TestAlgorithm::sendProgress(double progress, QString message) {
    Q_UNUSED(progress);
    Q_UNUSED(message);

}
