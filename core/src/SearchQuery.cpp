/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * SearchQuery implementation
 */


SearchQuery::SearchQuery() {

}

/**
 * @return QList<Dataset>
 */
QList<Dataset> * SearchQuery::getDatasets() {
    return createDatasetList(mDatasets);
}

/**
 * @param datasets
 */
void SearchQuery::setDatasets(QList<Dataset> *datasets) {
    datasets = createDatasetList(mDatasets);
}

/**
 * @return SearchObject
 */
SearchObject *SearchQuery::getSearchObject() {
    return mSearchObject;
}

/**
 * @param searchObject
 */
void SearchQuery::setSearchObject(SearchObject *searchObject) {
    mSearchObject = searchObject;
}

/**
 * @param out
 * @param searchQuery
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchQuery& searchQuery) {

    //write object to stream
    out << "(" << searchQuery.getDatasets() << ", "
        << searchQuery.getSearchObject() << ")";
    return out;
}

/**
 * @param in
 * @param searchQuery
 * @return QDataStream&
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
 * @param in
 */
void SearchQuery::toStream(QDataStream in) {
    in << *this;
}

/**
 * @param out
 */
void SearchQuery::fromStream(QDataStream out) {
    out >> *this;
}

QList<Dataset> * createDatasetList(QList<QString> *stringDatasets) {
    QList<Dataset> *datasets = new QList<Dataset>;
    QListIterator<QString> it(*stringDatasets);
    while (it.hasNext()) {
       datasets->push_back(*new Dataset(it.next()));
    }
    return datasets;
}
