/**
 * Project \
 */


#include "TestAlgorithm.h"

/**
 * TestAlgorithm implementation
 */


/**
 * @brief TestAlgorithm::TestAlgorithm
 * @param id
 */
TestAlgorithm::TestAlgorithm(QString id) {
	mId = id;
}

/**
 * @brief TestAlgorithm::run
 * @return
 */
QList<DataPacket> TestAlgorithm::run() {
    SearchResult res;
    QList<SearchResult> list;
    list.append(res);
    return list;
    //return (QList<DataPacket>)list;
}

/**
 * @brief TestAlgorithm::cancel terminate the algorithm
 */
void TestAlgorithm::cancel() {

}

/**
 * @brief TestAlgorithm::setInputs
 * @param inputDataList
 * @return
 */
bool TestAlgorithm::setInputs(QList<DataPacket> inputDataList) {
    Q_UNUSED(inputDataList);
    return false;
}

/**
 * @brief TestAlgorithm::setParameters
 * @param parameters
 * @return
 */
bool TestAlgorithm::setParameters(QJsonObject parameters) {
    Q_UNUSED(parameters);
    return false;
}

/**
 * @brief TestAlgorithm::getDescription
 * @return
 */
QString TestAlgorithm::getDescription() {
    return mDescription;
}

/**
 * @param description
 */
void TestAlgorithm::setDescription(QString description) {
	mDescription = description;
}

/**
 * @return QString
 */
QString TestAlgorithm::getName() {
    return mName;
}

/**
 * @brief TestAlgorithm::setName
 * @param name
 */
void TestAlgorithm::setName(QString name) {
	mName = name;
}

/**
 * @brief TestAlgorithm::supportsProgressInfo
 * @return
 */
bool TestAlgorithm::supportsProgressInfo() {
    return false;
}

/**
 * @brief TestAlgorithm::sendIntermediateResults
 * @param searchResult
 */
void TestAlgorithm::sendIntermediateResults(SearchResult searchResult) {
    Q_UNUSED(searchResult);
}

/**
 * @brief TestAlgorithm::sendProgress
 * @param progress
 * @param message
 */
void TestAlgorithm::sendProgress(double progress, QString message) {
    Q_UNUSED(progress);
    Q_UNUSED(message);

}
