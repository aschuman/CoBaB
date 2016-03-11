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
