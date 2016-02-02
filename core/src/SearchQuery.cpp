/**
 * Project \
 */


#include "CoBaB.h"

/**
 * SearchQuery implementation
 */


SearchQuery::SearchQuery() {

}

/**
 * @return QList<Dataset>
 */
QList<Dataset> SearchQuery::getDatasets() {
    return mDatasets;
}

/**
 * @param datasets
 */
void SearchQuery::setDatasets(QList<Dataset> datasets) {
    mDatasets = datasets;
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
    return null;
}

/**
 * @param in
 * @param searchQuery
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchQuery& searchQuery) {
    return null;
}

/**
 * @param in
 */
void SearchQuery::toStream(QDataStream in) {

}

/**
 * @param out
 */
void SearchQuery::fromStream(QDataStream out) {

}
