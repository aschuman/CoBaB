/**
 * Project \
 */


#include "..\..\include\CoBaB.h"

/**
 * TestAlgorithm implementation
 */


TestAlgorithm::TestAlgorithm() {

}

/**
 * @return QList<DataPacket>
 */
QList<DataPacket> TestAlgorithm::run() {
    return null;
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
    return null;
}

/**
 * @param description
 */
void TestAlgorithm::setDescription(QString description) {

}

/**
 * @return QString
 */
QString TestAlgorithm::getName() {
    return null;
}

/**
 * @param name
 */
void TestAlgorithm::setName(QString name) {

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
