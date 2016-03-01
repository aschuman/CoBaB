#include "DatasetList.h"
#include <QTextStream>
#include "log.h"

/**
 * @brief DatasetList::getDatasetList Returns the list of Dataset.
 * @return The list of Dataset.
 */
const QList<Dataset>& DatasetList::getDatasetList() const {
    return mDatasetList;
}

/**
 * @brief DatasetList::addDataset Adds the given Dataset to the list.
 * @param dataset The Dataset which is added to the list.
 */
void DatasetList::addDataset(const Dataset& dataset) {
    mDatasetList.append(dataset);
}

/**
 * @brief DatasetList::load Loads the list of Dataset from the file with the given path.
 * @param path The path of the file in which the Dataset list is stored.
 */
void DatasetList::load(const QString& path) {
    mDatasetList.clear();
    QFile file(path);
    if(!file.open(QFile::ReadOnly)) {
        LOG_ERR("couldn't open file");
        return;
    }
    QTextStream stream(&file);
    QString line;
    while (stream.readLineInto(&line)) {
        QDir dir(line);
        if(dir.exists()) {
            Dataset dataset(line);
            mDatasetList.append(dataset);
        }
    }
    file.close();
}

/**
 * @brief DatasetList::store Stores the Dataset list in the file with the given path.
 * @param path The path of the file in which the Dataset list is stored.
 */
void DatasetList::store(const QString path) const {
    QFile file(path);
    if(!file.open(QFile::WriteOnly)) {
        LOG_ERR("couldn't open file");
        return;
    }
    QTextStream stream(&file);
    for(const Dataset& iter: mDatasetList) {
        stream << iter.getPath() << endl;
    }
    file.close();
}
