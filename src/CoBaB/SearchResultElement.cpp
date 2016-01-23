/**
 * Project \
 */


#include "..\..\include\CoBaB.h"

/**
 * SearchResultElement implementation
 */


SearchResultElement::SearchResultElement() {

}

/**
 * @return int
 */
int SearchResultElement::getScore() {
    return 0;
}

/**
 * @param score
 */
void SearchResultElement::setScore(int score) {

}

/**
 * @return SearchObject
 */
SearchObject SearchResultElement::getSearchObject() {
    return null;
}

/**
 * @param searchObject
 */
void SearchResultElement::setSearchObject(SearchObject searchObject) {

}

/**
 * @param out
 * @param searchResultElement
 * @return QDataStream&
 */
QDataStream& operator<<(QDataStream& out, SearchResultElement& searchResultElement) {
    return null;
}

/**
 * @param in
 * @param searchResultElement
 * @return QDataStream&
 */
QDataStream& operator>>(QDataStream& in, SearchResultElement& searchResultElement) {
    return null;
}

/**
 * @param in
 */
void SearchResultElement::toStream(QDataStream in) {

}

/**
 * @param out
 */
void SearchResultElement::fromStream(QDataStream out) {

}
