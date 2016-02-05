/**
 * Project \
 */


#include "CoBaB.h"
#include <QTextStream>


/**
 * DatasetList implementation
 */


DatasetList::DatasetList() {

}

/**
 * @return QList<Dataset>
 */
QList<Dataset> DatasetList::getDatasetList() {
    return mDatasetList;
}

/**
 * @param dataset
 */
void DatasetList::addDataset(Dataset dataset) {
    mDatasetList.append(dataset);
}

/**
 * @param path
 */
void DatasetList::load(QString path) {
    QFile file(path);
    file.open(QFile::ReadOnly);
    QTextStream stream(&file);
    QString line;
    while (stream.readLineInto(&line)) {
        QDir dir(line);
        if(dir.exists()) {
            Dataset dataset(line);
            mDatasetList.append(dataset);
        }
    }
}

/**
 * @param path
 */
void DatasetList::store(QString path) {
    QFile file(path);
    file.open(QFile::WriteOnly);
    QTextStream stream(&file);
    for(Dataset iter: mDatasetList) {
        stream << iter.getPath();
    }
}
