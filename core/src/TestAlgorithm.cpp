/**
 * Project \
 */


#include "TestAlgorithm.h"

/**
 * TestAlgorithm implementation
 */


TestAlgorithm::TestAlgorithm(QString id) {
	mId = id;
}

/**
 * @return QList<DataPacket>
 */
QList<DataPacket> TestAlgorithm::run() {

}

void TestAlgorithm::cancel() {

}

/**
 * @param inputDataList
 * @return bool
 */
bool TestAlgorithm::setInputs(QList<DataPacket> inputDataList) {
    return false;
}

/**
 * @param parameters
 * @return bool
 */
bool TestAlgorithm::setParameters(QJsonObject parameters) {
    return false;
}

/**
 * @return QString
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
 * @param name
 */
void TestAlgorithm::setName(QString name) {
	mName = name;
}

/**
 * @return bool
 */
bool TestAlgorithm::supportsProgressInfo() {
    return false;
}

/**
 * @param searchResult
 */
void TestAlgorithm::sendIntermediateResults(SearchResult searchResult) {

}

/**
 * @param progress
 * @param message
 */
void TestAlgorithm::sendProgress(double progress, QString message) {

}
