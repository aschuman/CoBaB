/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * @brief SearchQuery standart constructor
 */
SearchQuery::SearchQuery() {
    mType = DataPacket::Type::SEARCHQUERY;
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

///**
// * @brief override << the operator so it calls fromStream
// * @param out the datastream
// * @param SearchQuery whose data will be sent
// * @return out the datastream
// */
//QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery) {
//    searchQuery.toStream(out);
//    return out;
//}

///**
// * @brief override >> the operator so it calls toStream
// * @param in the datastream
// * @param searchObject to be changed
// * @return in the datastream
// */
//QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {
//    searchQuery.fromStream(in);
//    return in;
//}

/**
 * @brief calls the << operator
 * @param in the datastream
 */
void SearchQuery::toStream(QDataStream& out) const {
    //write object to stream
    DataPacket::toStream(out); //write uuid and type
    out << mDatasets
        << mSearchObject;
}

/**
 * @brief calls the >> operator
 * @param out the datastream
 */
void SearchQuery::fromStream(QDataStream& in) {

    //read object from stream
    DataPacket::fromStream(in); //write uuid and type
    in >> mDatasets;
    in >> mSearchObject;

}
