/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * SearchQuery implementation
 */

/**
 * @brief SearchQuery::SearchQuery
 * @author Georgi
 */
SearchQuery::SearchQuery() {

}

/**
 * @brief gets the list of datasets
 * @return the list of datasets
 */
QList<Dataset>* SearchQuery::getDatasets() {
    return createDatasetList(mDatasets);
}

/**
 * @brief sets the list of datasets
 * @param datasets to be set in the list
 */
void SearchQuery::setDatasets(QList<Dataset>* datasets) {
    Q_UNUSED(datasets);
    datasets = createDatasetList(mDatasets);
}

/**
 * @brief gets the searchobject
 * @return the searchobject
 */
SearchObject* SearchQuery::getSearchObject() {
    return mSearchObject;
}

/**
 * @brief sets the searchobject
 * @param searchObject to be set
 */
void SearchQuery::setSearchObject(SearchObject* searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief override << the operator
 * @param out - the datastream
 * @param SearchQuery whose data will be sent
 * @return out - the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery) {

    //write object to stream
    out << searchQuery.mDatasets
        << searchQuery.mSearchObject;
    return out;
}

/**
 * @brief override >> the operator
 * @param in - the datastream
 * @param searchObject to be changed
 * @return in - the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {
    //read object from stream

    QList<QString> datasets;
    SearchObject searchobject;

    in >> datasets;
    searchQuery.mDatasets = &datasets;


    in >> searchobject;
    searchQuery.setSearchObject(&searchobject);

    return in;
}

/**
 * @brief calls the << operator
 * @param in - the datastream
 */
void SearchQuery::toStream(QDataStream& in) {
    in << *this;
}

/**
 * @brief calls the >> operator
 * @param out - the datastream
 */
void SearchQuery::fromStream(QDataStream& out) {
    out >> *this;
}
/**
 * @brief creates the list of datasets from Strings
 * @param stringDatasets the paths to the datasets
 * @return the list of datasets
 */
QList<Dataset>* createDatasetList(QList<QString>* stringDatasets) {
    QList<Dataset>* datasets = new QList<Dataset>;
    for(auto it = stringDatasets->begin(); it != stringDatasets->end(); ++it) {
       datasets->push_back(Dataset(*it));
    }
    return datasets;
}
