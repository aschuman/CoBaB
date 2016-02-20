#include "TestAlgorithm.h"

/**
 * @brief TestAlgorithm::TestAlgorithm create new algorithm with given ID
 * @param id algorithm ID
 */
TestAlgorithm::TestAlgorithm(const QString& id) {
	mId = id;
    mName = "Test algorithm";
    mDescription = "an dummy algorithm that returns all search objects in the correct input order";
}

/**
 * @brief TestAlgorithm::run start the search
 * @return a list of data packets containing results
 */
QList<DataPacket*> TestAlgorithm::run() {

    QList<DataPacket*> list;
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
    Q_UNUSED(inputDataList);
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
