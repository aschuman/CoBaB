/**
 * Project \
 */


#include "SearchQuery.h"

/**
 * @brief SearchQuery::SearchQuery Constructs a default SearchQuery.
 */
SearchQuery::SearchQuery() {
    mType = DataPacket::Type::SEARCHQUERY;
}

/**
 * @brief SearchQuery::getDatasets Gets the list of datasets.
 * @return the list of datasets
 */
QList<QString> SearchQuery::getDatasets() const {
    return mDatasets;
}

/**
 * @brief SearchQuery::setDatasets Sets the list of datasets.
 * @param datasets to be set in the list
 */
void SearchQuery::setDatasets(const QList<QString> datasets) {
    mDatasets = datasets;
}

/**
 * @brief SearchQuery::getSearchObject Gets the searchobject.
 * @return the searchobject
 */
SearchObject SearchQuery::getSearchObject() const {
    return mSearchObject;
}

/**
 * @brief SearchQuery::setSearchObject Sets the searchobject.
 * @param searchObject to be set
 */
void SearchQuery::setSearchObject(const SearchObject& searchObject) {
    mSearchObject = searchObject;
}

/**
 * @brief operator << Overrides the operator <<.
 * @param out the datastream
 * @param searchQuery whose data will be written
 * @return out the datastream
 */
QDataStream& operator<<(QDataStream& out, const SearchQuery& searchQuery) {
    searchQuery.toStream(out);
    return out;
}

/**
 * @brief operator >> Overrides the operator >>.
 * @param in the datastream
 * @param searchQuery whose data will be read
 * @return in the datastream
 */
QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {
    searchQuery.fromStream(in);
    return in;
}

/**
 * @brief SearchQuery::toStream Writes the SearchQuery to a datastream.
 * @param out the datastream
 */
void SearchQuery::toStream(QDataStream& out) const {

    //write object to stream
    DataPacket::toStream(out); //write uuid and type
    out << mDatasets
        << mSearchObject;
}

/**
 * @brief SearchQuery::fromStream Reads the SearchQuery from a datastream.
 * @param in the datastream
 */
void SearchQuery::fromStream(QDataStream& in) {

    //read object from stream
    DataPacket::fromStream(in); //write uuid and type
    in >> mDatasets;
    in >> mSearchObject;

}
