#include "Algorithm.h"

/**
 * @brief Algorithm::getId get the algorithm ID
 * @return algorithm ID
 */
QString Algorithm::getId() const {
    return mId;
}

/**
 * @brief Algorithm::getName get name of the algorithm
 * @return algorithm name (must be unique)
 */
QString Algorithm::getName() const {
    return mName;
}

/**
 * @brief Algorithm::getDescription show algorithm description
 * @return a QString that describes the algorithm
 */
QString Algorithm::getDescription() const {
    return mDescription;
}

/**
 * @brief Algorithm::initialize Loads the corresponding QJsonObject for this algorithm
 * @param loader The plugin loader which loads the QJsonObject
 */
void Algorithm::initialize(QPluginLoader *loader) {
    mParameters = loader->metaData().value("MetaData").toObject();
}

/**
 * @brief Algorithm::getParameters Returns the parameter file for this algorithm
 * @return The QJsonObject parameter file for this algorithm
 */
QJsonObject Algorithm::getParameters() {
    return mParameters;
}
