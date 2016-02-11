/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * SearchQuery implementation
 */

/**
 * @brief SearchQuery::SearchQuery
 */
SearchQuery::SearchQuery() {

}

/**
 * @brief SearchQuery::getDatasets
 * @return
 */
QList<Dataset>* SearchQuery::getDatasets() {
    return createDatasetList(mDatasets);
}

/**
 * @brief SearchQuery::setDatasets
 * @param datasets
 */
void SearchQuery::setDatasets(QList<Dataset>* datasets) {
    Q_UNUSED(datasets);
    datasets = createDatasetList(mDatasets);
}

/**
 * @brief SearchQuery::getSearchObject
 * @return
 */
SearchObject* SearchQuery::getSearchObject() {
    return mSearchObject;
}

/**
 * @brief SearchQuery::setSearchObject
 * @param searchObject
 */
void SearchQuery::setSearchObject(SearchObject* searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief operator <<
 * @param out
 * @param searchQuery
 * @return
 */
QDataStream& operator<<(QDataStream& out, SearchQuery& searchQuery) {

    //write object to stream
    out << "(" << searchQuery.getDatasets() << ", "
        << searchQuery.getSearchObject() << ")";
    return out;
}

/**
 * @brief operator >>
 * @param in
 * @param searchQuery
 * @return
 */
QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {
    //read object from stream

    QList<QString> datasets;
    SearchObject searchobject;

    //skip opening bracket
    in.skipRawData(1);

    in >> datasets;
    searchQuery.mDatasets = &datasets;

    //skip coma
    in.skipRawData(2);

    in >> searchobject;
    searchQuery.setSearchObject(&searchobject);

    in.skipRawData(1);

    return in;
}

/**
 * @brief SearchQuery::toStream
 * @param in
 */
void SearchQuery::toStream(QDataStream in) {
    in << *this;
}

/**
 * @brief SearchQuery::fromStream
 * @param out
 */
void SearchQuery::fromStream(QDataStream out) {
    out >> *this;
}
/**
 * @brief createDatasetList
 * @param stringDatasets
 * @return
 */
QList<Dataset>* createDatasetList(QList<QString>* stringDatasets) {
    QList<Dataset>* datasets = new QList<Dataset>;
    QListIterator<QString> it(*stringDatasets);
    while (it.hasNext()) {
       datasets->push_back(*new Dataset(it.next()));
    }
    return datasets;
}
