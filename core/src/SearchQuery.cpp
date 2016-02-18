/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * @brief SearchQuery standart constructor
 */
SearchQuery::SearchQuery() {
    mType = Type::SEARCHQUERY;

    QList<QString> mDatasets = new QList<QString>;

    SearchObject mSearchObject = new SearchObject();
}

/**
 * @brief gets the list of datasets
 * @return the list of datasets
 */
QList<QString> SearchQuery::getDatasets() const {
    return mDatasets;
}

/**
 * @brief sets the list of datasets
 * @param datasets to be set in the list
 */
void SearchQuery::setDatasets(const QList<QString> datasets) {
    mDatasets = datasets;
}

/**
 * @brief gets the searchobject
 * @return the searchobject
 */
SearchObject SearchQuery::getSearchObject() const {
    return mSearchObject;
}

/**
 * @brief sets the searchobject
 * @param searchObject to be set
 */
void SearchQuery::setSearchObject(const SearchObject searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief override << the operator so it calls fromStream
 * @param out the datastream
 * @param SearchQuery whose data will be sent
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery) {

}

/**
 * @brief override >> the operator so it calls toStream
 * @param in the datastream
 * @param searchObject to be changed
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {

}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchQuery::toStream(QDataStream& in) const {

    //read object from stream

    QList<QString> datasets;
    SearchObject searchobject;

    in >> datasets;
    this->setDatasets(datasets);


    in >> searchobject;
    this->setSearchObject(searchobject);


}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchQuery::fromStream(QDataStream& out) {
    //write object to stream
    out << this->mDatasets
        << this->mSearchObject;

}
