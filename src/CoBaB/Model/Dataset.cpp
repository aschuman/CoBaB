/**
 * Project \
 */


#include "Dataset.h"

/**
 * Dataset implementation
 */


/**
 * @param path
 */
void Dataset::Dataset(QString path) {
    mPath = path;
    createPreviewPhoto();
}

/**
 * @return QString
 */
QString Dataset::getName() {
    return mName;
}

/**
 * @return int
 */
int Dataset::getNumberOfMedia() {
    return mMediaList.size();
}

/**
 * @return QImage
 */
QImage Dataset::getPreviewPhoto() {
    return mPreviewPhoto;
}

/**
 * @return QList<Medium>
 */
QList<Medium> Dataset::getMediaList() {
    return mMediaList;
}

/**
 * @return QString
 */
QString Dataset::getPath() {
    return mPath;
}

/**
 * @return DatasetType
 */
DatasetType Dataset::getType() {
    return mDatasetType;
}

void Dataset::createPreviewPhoto() {

}
