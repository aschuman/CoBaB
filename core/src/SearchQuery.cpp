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
    return null;
}

/**
 * @param datasets
 */
void SearchQuery::setDatasets(QList<Dataset> datasets) {

}

/**
 * @return SearchObject
 */
SearchObject SearchQuery::getSearchObject() {
    return null;
}

/**
 * @param searchObject
 */
void SearchQuery::setSearchObject(SearchObject searchObject) {

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