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
 * @return True, if all went well.
 */
bool Algorithm::initialize(QPluginLoader *loader) {
    if (!loader) return false;
    QJsonObject tmp = loader->metaData();
    if (tmp.isEmpty()) return false;
    QJsonValue v = tmp.value("MetaData");
    if (v.isUndefined()) return false;
    QJsonObject o = v.toObject();
    if (o.isEmpty()) return false;

    mId = "";
    mName = "";
    mDescription = "";

    QString version = "";
    if (o.contains("Author")) {}
    if (o.contains("Date")) {}
    if (o.contains("Name")) mName = o.value("Name").toString();
    else {} //LOG WARNING
    if (o.contains("Version")) version = o.value("Version").toString();
    else {} //LOG WARNING
    if (o.contains("Description")) mDescription = o.value("Description").toString();
    else {} //LOG WARNING
    mId = mName + " " + version;
    if (mId.trimmed() == "") {} //LOG WARNING

    if (o.contains("Properties")) mDefaultParameters = o.value("Properties").toObject();
    else {} //LOG WARNING

    return true;
}

/**
 * @brief Algorithm::setParameters Set the algorithm's parameters.
 * @param parameters The new parameters as Json object.
 * @return True, if all went well.
 */
bool Algorithm::setParameters(const QJsonObject& parameters)
{
    mParameters = parameters;
    return true;
}

/**
 * @brief Algorithm::getParameters Returns the parameters set for this algorithm.
 * @return The current parameters for this algorithm.
 */
QJsonObject Algorithm::getParameters() {
    return mParameters;
}

/**
 * @brief Algorithm::getDefaultParameters Returns the parameter file for this algorithm.
 * @return The QJsonObject parameter file for this algorithm.
 */
QJsonObject Algorithm::getDefaultParameters() {
    return mDefaultParameters;
}

/**
 * @brief Cancel running algorithm.
 */
void Algorithm::cancel()
{
    mCancel = true;
}
